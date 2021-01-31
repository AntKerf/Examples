Просмотр звездных систем(в database/ed.db загружнно ~1млн звездных систем в радиусе 1000с.л. от Sol, полную информацию имеют лишь системы в радиусе 100c.л.) Построенна QSqlTableModel для взаимодействия qml и sql. Добаленны классы для просмотра бд и парсинга Json для добавления новых данных из dump файлов базы данных EDSM или через Api. Данные получены с помощью API EDSM.

Сборка через qmake: qmake.exe -o Makefile "Source\EDLocal.pro"

Скачать приложение: [![Actual](https://img.shields.io/badge/Build-0.5-green)](https://github.com/AntKerf/Examples/releases/tag/EDL_0.5)

Если возникает ошибка отсутвия базы данных, переместите папку database на уровень с папкой bin
### Скриншот
![screen](https://i.ibb.co/gj8nTDT/image.png)
