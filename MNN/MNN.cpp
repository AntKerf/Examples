#include "stdafx.h"
#include "MNN.h"

MNN::MNN(int inputs, int outputs, int layers, ...)
{
	I_inputs = inputs;
	I_outputs = outputs;
	I_layers = layers;
	//резервация места для векторов
	hiden_neirons.reserve(I_layers);
	na_hiden_neirons.reserve(I_layers);
	delta_neirons.reserve(I_layers);
	bias.reserve(I_layers + 1);
	weights.reserve(I_layers + 1);
	delta_bias.reserve(I_layers + 1);
	delta_weights.reserve(I_layers + 1);
	activation = vector<string>(I_layers + 1, "sigmoid");
	out_neirons =vector<long double>(I_outputs,0);
	na_out_neirons = vector<long double>(I_outputs, 0);
	delta_out = vector<long double>(I_outputs, 0);
	//чтение нейронов в слоях(динамические параметры)
	int *tmp = new int;
	va_list(ap);
	va_start(ap, layers);
	while (layers--)//инцилизация скрытых нейронов и биасов(нейронов смещения)
	{
		*tmp = va_arg(ap, int);
		hiden_neirons.push_back(vector<long double>(*tmp, 0));
		na_hiden_neirons.push_back(vector<long double>(*tmp, 0));
		delta_neirons.push_back(vector<long double>(*tmp, 0));
		bias.push_back(vector<long double>(*tmp, 0));
		delta_bias.push_back(vector<long double>(*tmp, 0));
	}
	delete tmp;
	bias.push_back(vector<long double>(I_outputs, 0));
	delta_bias.push_back(vector<long double>(I_outputs, 0));


	for (int i = 0; i < weights.capacity(); i++)//инцилизация и рандомизация весов
	{
		if (i == 0)//веса от входов к 1 слою
		{
			vector<long double> *vtmp = new vector<long double>(I_inputs*hiden_neirons[0].size(),0);
			delta_weights.push_back(*vtmp);
			random_insert(*vtmp);
			//xavier_insert(*vtmp,I_inputs,hiden_neirons[0].size());//инилизация Завьера
			weights.push_back(*vtmp);
			delete vtmp;
		}
		else if (i != weights.capacity() - 1)//веса между скрытыми нейронами
		{
			vector<long double> *vtmp = new vector<long double>(hiden_neirons[i - 1].size()*hiden_neirons[i].size(),0);
			delta_weights.push_back(*vtmp);
			random_insert(*vtmp);
			//xavier_insert(*vtmp, hiden_neirons[i-1].size(), hiden_neirons[i].size());
			weights.push_back(*vtmp);
			delete vtmp;
		}
		else //веса от последнего слоя к выходу
		{
			vector<long double> *vtmp = new vector<long double>(hiden_neirons[i - 1].size()*I_outputs,0);
			delta_weights.push_back(*vtmp);
			//random_insert(*vtmp);
			xavier_insert(*vtmp, hiden_neirons[i-1].size(),I_outputs);
			weights.push_back(*vtmp);
			delete vtmp;
		}
	}
	for (int i = 0; i < bias.size(); i++)//рандомизация весов нейронов смещения
	{
		random_insert(bias[i]);
	}

	//PREoutputset = new vector<vector<long double>>(33);
	//PREoutputset->reserve(33);
	//PREinputset = new vector<vector<long double>>(33);
	//PREinputset->reserve(33);
	
}

long double MNN::sigmoid(long double x)
{
	return 1 / (1 + exp(-x));
}

long double MNN::derivate_sigmoid(long double x)
{
	return (1 - x)*x;
}

void MNN::softmax(vector<long double>& x)
{
	long double tmp = 0;
	for (auto &el : x)
	{
		if (el > 500)
		{
			cout << "ERROR 1\n";
			system("PAUSE");
		}
		tmp += exp(el);
	}
	for (auto &el : x)
	{
		if (el > 500)
		{
			cout << "ERROR 2\n";
			system("PAUSE");
		}
		el = exp(el) / tmp;
	}
	tmp = 0;
}

long double MNN::derivate_softmax(int n_out)
{
	long double tmp = 0;
	long double summ = 0;
	tmp = 0;
	summ = 0;
	for (auto &el : na_out_neirons)
	{
		if (el > 500)
		{
			cout << "ERROR 3\n";
			system("PAUSE");
		}
		summ += exp(el);
	}
	tmp = summ - na_out_neirons[n_out];
	tmp *= na_out_neirons[n_out];
	pow(summ, 2);
	tmp /= summ;
	tmp = sigmoid(tmp);
	if (isnan(tmp)) return 0.999999;
	if (isinf(tmp)) return 0.000001;
	//cout << "derivate: " << tmp << "\n";
	return tmp;

}

long double MNN::derivate_softmax(vector<long double> out,int n_out)
{
	long double tmp = 0;
	long double summ = 0;
	tmp = 0;
	summ = 0;
	for (auto &el : out)
	{
		summ += exp(el);
	}
	tmp = summ - out[n_out];
	tmp *= out[n_out];
	pow(summ, 2);
	tmp /= summ;

	return tmp;
}

void MNN::xavier_insert(vector<long double> &v, double n_in, double n_out)
{
	for (auto &el:v) 
	{
		el *= 1 / (n_in + n_out);
	}
}

void MNN::calculate_hiden_neirons(vector<long double> input)
{
	/*если на входе 576 параметров(пикселей(фото 24*24)), то первые 576 весов относятся к 1 нейрону
	вторые 576 весов ко 2 нейрону, и так до конца нейронов на первом слое, соотвествнно так и дальше со
	скрытыми нейронами и выходом
	P.S каждый биас соотвествуем своему нейрону, bias[0][0] относится к первому нейрону на первом слое и тд*/
	long double summ = 0;
	summ = 0;
	for (int i = 0; i < hiden_neirons.size(); i++)
	{
		if (i == 0)//первый скрытый слой
		{
			for (int j = 0; j < hiden_neirons[i].size(); j++)
			{
				int index = j*input.size();
				for (int t = 0; t < input.size(); t++)
				{
					summ += input[t] * weights[0][index+t];
				}
				hiden_neirons[i][j] = summ+bias[i][j];//записываем сумму, не активируем
				na_hiden_neirons[i][j] = hiden_neirons[i][j];
				summ = 0;
			}
		}
		else//скрытые слои
		{
			for (int j = 0; j < hiden_neirons[i].size(); j++)
			{
				int index = j*hiden_neirons[i-1].size();
				for (int t = 0; t < hiden_neirons[i - 1].size(); t++)
				{
					summ += hiden_neirons[i - 1][t] * weights[i][index + t];
				}
				hiden_neirons[i][j] = summ+bias[i][j];
				na_hiden_neirons[i][j] = hiden_neirons[i][j];
				summ = 0;
			}
		}
	activating(i);//активация нейронов на слое когда записанна сумма всех нейронов
	}
}

void MNN::calculate_output()
{
	long double summ = 0;
	for (int i = 0; i < out_neirons.size(); i++)
	{
		int index = i*hiden_neirons.back().size();
		for (int j = 0; j < hiden_neirons.back().size(); j++)
		{
			summ += hiden_neirons.back()[j] * weights.back()[index + j];
		}
		out_neirons[i] = (summ + bias.back()[i]);
		na_out_neirons[i] = out_neirons[i];
		summ = 0;
	}
	activating(I_layers);
	summ = 0;
}

void MNN::calculate_d_output(vector<long double> ideal_out) //расчет дельт выходных нейронов
{
	for (size_t i = 0; i <I_outputs; i++)
	{
		//здесь можно задать функцию потерь для нахождения дельт выходных весов
		delta_out[i] = (ideal_out[i] - out_neirons[i])*derivate(I_layers,i);
	}
}

void MNN::calculate_d_neirons()//расчет дельт скрытых нейронов
{
	for (size_t i = I_layers-1; i!=-1; i--)
	{
		for (size_t j = 0; j < hiden_neirons[i].size(); j++)
		{
			long double summ = 0;
			summ = 0;
			delta_neirons[i][j] = derivate(i, j);
			//расчет суммы весов умноженых на дельты нейронов
			if (i == I_layers - 1)//последний скрытый слой, берем дельты выходов
			{
				for (int g = 0; g < I_outputs; g++)//перебор выходов
				{
					summ += delta_out[g] * weights.back()[(g*hiden_neirons[i].size())+j];
				}
			}
			else//берем дельты скрытых слоев
			{
				for (size_t g = 0; g < delta_neirons[i+1].size(); g++)//перебор нейронов у предыдущего слоя(двигаемся в обратную сторону)
				{
					summ += delta_neirons[i+1][g] * weights[i+1][(g*hiden_neirons[i].size()) + j];
				}
			}
			delta_neirons[i][j] *= summ;
			summ = 0;
		}
	}
}

void MNN::calculate_d_weights(int n_set)
{
	//находим градиент для всех весов(прямой проход)
	for (size_t i = 0; i < I_layers+1; i++)
	{
		for (size_t j = 0; j < weights[i].size(); j++)
		{
			if (i == 0)//первый слой
			{
				delta_weights[i][j] = (inputset[n_set][j % I_inputs] * delta_neirons[0][j / I_inputs])*E + A * delta_weights[i][j];
				weights[i][j] += delta_weights[i][j];
			}
			else if (i != I_layers)//средние слои
			{
				delta_weights[i][j] = (hiden_neirons[i-1][j % hiden_neirons[i - 1].size()] * delta_neirons[i][j / delta_neirons[i-1].size()])*E + A * delta_weights[i][j];
				weights[i][j] += delta_weights[i][j];
			}
			else//выходной слой
			{
				delta_weights[i][j] = (hiden_neirons[i - 1][j % hiden_neirons[i - 1].size()] * delta_out[j / delta_neirons[i-1].size()])*E + A * delta_weights[i][j];
				weights[i][j] += delta_weights[i][j];
			}
		}
	}
}

void MNN::calculate_d_bias()
{
	for (size_t i = 0; i < bias.size(); i++)
	{
		for (size_t j = 0; j < bias[i].size(); j++)
		{
			if (i!=bias.size()-1)	delta_bias[i][j] = E*(1 * delta_neirons[i][j])+A*delta_bias[i][j];//если слой не последний

			else	delta_bias[i][j] = E * (1 * delta_out[j]) + A * delta_bias[i][j];

			bias[i][j] += delta_bias[i][j];
		}
	}
}

void MNN::loadpngthread(size_t begin_t, size_t end_t, vector<long double>& vec, rgb8_image_t & img)
{
	for (size_t i = begin_t; i < end_t; i++)
	{
		auto it = i * img.width();
		for (size_t j = 0; j < img.width(); j++)
		{
			vec[it + j] = (view(img)(i, j)[0]);
		}
	}
}

void MNN::activating(int n_layer)//активация слоев НС
{
	string func = activation[n_layer];
	if (func == "sigmoid")
	{
		if (n_layer < I_layers)
		{
			for (int i=0;i<hiden_neirons[n_layer].size();i++)
			{
				hiden_neirons[n_layer][i] = sigmoid(hiden_neirons[n_layer][i]);
			}
		}
		else if (n_layer == I_layers)
		{
			for (int i = 0; i<out_neirons.size(); i++)
			{
				out_neirons[i] = sigmoid(out_neirons[i]);
			}
		}
	}
	else if (func == "softmax")
	{
		if (n_layer < I_layers)
		{
			softmax(hiden_neirons[n_layer]);
		}
		else if (n_layer == I_layers)
		{
			softmax(out_neirons);
		}
	}
	else 
	{
		cout << "Функция активации не найдена";
		system("PAUSE");
	}
}

long double MNN::derivate(int n_layer, int neirons)
{
	string func = activation[n_layer];
	if (func == "sigmoid")
	{
		if (n_layer < I_layers)
		{
			return derivate_sigmoid(hiden_neirons[n_layer][neirons]);
		}
		else if (n_layer == I_layers)
		{
			return derivate_sigmoid(out_neirons[neirons]);
		}
	}
	else if (func == "softmax")
	{
		if (n_layer < I_layers)
		{
			return derivate_softmax(na_hiden_neirons[n_layer],neirons);
		}
		else if (n_layer == I_layers)
		{
			return derivate_softmax(neirons);
		}
	}
	else
	{
		cout << "Функция активации не найдена";
		system("PAUSE");
	}
}

long double MNN::mse(vector<long double> ideal_out)//функция потерь MSE(средне квадротическое отклонение)
{
	long double mse = 0;
	mse = 0;
	for (size_t i = 0; i < out_neirons.size(); i++)
	{
		mse += pow((ideal_out[i] - out_neirons[i]), 2);
	}
	mse /= I_outputs;
	return mse;
}

long double MNN::SCCE(vector<long double> ideal_out)//функция потерь SCCE(Разреженная категориальная перекрестная энтропия)
{
	long double scce = 0;
	scce = 0;
	for (size_t i = 0; i < I_outputs; i++)
	{
			if (out_neirons[i] != 0 && ideal_out[i]!=0 ) scce += ideal_out[i] * log(out_neirons[i]);
			if (out_neirons[i]!=1 && ideal_out[i]!=1) scce += ((1 - ideal_out[i])*(log(1 - out_neirons[i])));
	}
	return -scce;
}
//функции потерь для определенного выхода используются при нахождении дельт выходных нейронов с разными функциями потерь
long double MNN::d_mse(int out, vector<long double> ideal_out)//функция потерь MSE для нахождения отклонения определнного выхода
{
	long double mse = 0;
	mse = 0;
	mse += pow((ideal_out[out] - out_neirons[out]), 2);
	mse /= I_outputs;
	return mse;
}

long double MNN::d_SCCE(int out, vector<long double> ideal_out)//SCCE для определенного выхода
{
	long double scce = 0;

		if(out_neirons[out]!=0)	scce += (ideal_out[out] * log(out_neirons[out]));

		if(out_neirons[out]!=1)	scce += 1.0/((1 - ideal_out[out])*(log(1 - out_neirons[out])));

	return -scce;
}

void MNN::SetDataDirectory(string Path)
{
	this->path = Path;
	main_threads.push_back(thread([&](MNN* view) { view->loadDataSet(); }, this));
}

void MNN::loadDataSet()
{
	rgb8_image_t img;
	string path;
	char filename;
	vector<thread> vt(4);
	vector<long double> vec(this->I_inputs, 0);
	vector <long double> outputv(this->I_outputs, 0);

	boost::filesystem::path letters(this->path);
	boost::filesystem::directory_iterator it(letters);

	//int iter = 0;
	for (auto el : it)
	{
		//формирование сета правильных ответов исходя из названия папки с нахождением фото
		//cout << el << endl;
		filename = el.path().filename().string().at(0);
		if (filename == 'Ё') filename = 32 - 64;
		outputv[int(filename) + 64] = 1;
		PREoutputset.push_back(outputv);
		outputv[int(filename) + 64] = 0;
		
		//перебор фото в папке
		boost::filesystem::directory_iterator it2(el);
		
		for (size_t i = 0; i < rand() % 400; i++)
		{
			it2++;
		}
		path = it2.operator->()->path().string();
		//cout << path << endl;
		read_and_convert_image(path, img, png_tag{});
		for (size_t i = 0; i < vt.size(); i++)
		{
			size_t b = i * (img.height() / vt.size());
			size_t e = 0;
			if (i < vt.size() - 1) e = b + (img.height() / vt.size());
			else  e = img.height();
			vt[i] = thread([&](MNN* view) { view->loadpngthread(b, e, ref(vec), ref(img));},this);
		}
		for (size_t i = 0; i < vt.size(); i++)
		{
			vt[i].join();
		}
		PREinputset.push_back(vec);
		//iter++;
	}
}

void MNN::start(int iter)//обучение по определенному количеству итераций обучения
{
	long double tmp = 0;
	for (size_t i = 0; i < iter; i++)
	{
		main_threads[0].join();
		inputset = PREinputset;
		PREinputset.clear();
		outputset = PREoutputset;
		PREoutputset.clear();
		main_threads[0] = thread([&](MNN* view) { view->loadDataSet(); }, this);
		for (size_t j = 0; j < inputset.size(); j++)
		{
			calculate_hiden_neirons(inputset[j]);
			calculate_output();
			tmp += mse(outputset[j]);
			if (j == inputset.size() - 1)
			{
				cout << "\nIter:" << i << "\tMSE:" << tmp / inputset.size();
				tmp = 0;
			}
			//if (j==0)
			//{
			//	cout <<"\nIter:"<<i<< "\tMSE:" << mse(outputset[j]);
			////	cout << "\nSCCE:" << SCCE(outputset[j]) << "\n";
			//}
			//for (size_t t = 0; t < I_outputs; t++)
			//{
			//	cout << "\nt:" << d_SCCE(t, outputset[j]);
			//}
			calculate_d_output(outputset[j]);
			calculate_d_neirons();
			calculate_d_weights(j);
			calculate_d_bias();
			//for (size_t i = 0; i < weights.size(); i++)
			//{
			//	for (size_t j = 0; j < weights[i].size(); j++)
			//	{
			//		weights[i][j] = sigmoid(weights[i][j]);
			//	}
			//	//softmax(weights[i]);
			//}
		}
	}

}
void MNN::start(double acc)//обучение до определенной точности
{
	int i = 0;
	long double tmp = 0;
	sq_mse = vector<long double> (inputset.size(),0);
	for (;;)
	{
		i++;
		main_threads[0].join();
		inputset = PREinputset;
		PREinputset.clear();
		outputset = PREoutputset;
		PREoutputset.clear();
		main_threads[0] = thread([&](MNN* view) { view->loadDataSet(); }, this);
		for (size_t j = 0; j < inputset.size(); j++)
		{
			calculate_hiden_neirons(inputset[j]);
			calculate_output();
			tmp += mse(outputset[j]);
			if (j == inputset.size()-1)
			{
				cout << "\nIter:" << i << "\tMSE:" << tmp/inputset.size();
				//cout << "\nIter:" << i << "\tMSE:" << mse(outputset[j]);
				if ((tmp / inputset.size()) + acc <= 1)
				{ cout << "\nAccuracy achieved!\n"; save_weight(); return; }
				tmp = 0;
			}
			calculate_d_output(outputset[j]);
			calculate_d_neirons();
			calculate_d_weights(j);
			calculate_d_bias();
		}
	}
}
/*
Задание функии активации на слой(слои нумеруются с 0, не учитывая входной слой)
Реализованные функции: sigmoid, softmax;
*/
void MNN::set_activasion(int n_layer, string name_function)
{
	activation[n_layer] = name_function;
}

void MNN::shuffle()
{
	int tmp = 0, tmp2 = 0;
	for (int i = 0; i < inputset.size() / 2; i++)
	{
		tmp = rand() % (inputset.size() - 1);
		tmp2 = rand() % (inputset.size() - 1);
		inputset[tmp].swap(inputset[tmp2]);
		outputset[tmp].swap(outputset[tmp2]);
	}

}

void MNN::save_weight()
{
	cout << "\nSAVING...";
	std::ofstream file;
	file.clear();
	string name = std::to_string(I_inputs);
	for (auto n:hiden_neirons)
	{
		name.push_back('_');
		name.append(to_string(n.size()));
	}
	name.push_back('_');
	name.append(to_string(I_outputs));
	file.open("weigth/" + name +".txt");
	for (size_t n=0;n<weights.size();n++)
	{
		for (size_t v=0;v<weights[n].size();v++)
		{
			file << weights[n][v] << " ";
		}
		file << "\n\n";
		for (size_t v = 0; v < bias[n].size(); v++)
		{
			file << bias[n][v] << " ";
		}
		file << "\n\n";
	}
	file.close();
	cout << "\rSAVING SUCCESFUL\n";
}

MNN::~MNN()
{
}
