// neiroCPP.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "MNN.h"

using namespace std;
int main()
{
	srand(time(0));

        MNN MNN(278*278, 33, 2, 64,64);     //�������� ����������� ��//(����, �����, ���-�� �����, ����...)
        MNN.set_activasion(2, "softmax");   //������� ������� ��������� �� 2�� (��������) ����
        MNN.SetDataDirectory("dataset");    //�������� ��������� ������, ������������
        MNN.start(0.99);                    //������ ��������, ��������� �� ���������� �������� ��������
       // MNN.start(1000);                    //������ ��������, ��������� �� ���������� ��������� ���������� ���������
        MNN.save_weight()                   //���������� ��������� �����
	system("PAUSE");
    return 0;
}

