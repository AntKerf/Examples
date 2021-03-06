# Examples
Репозиторий с примерами моих работ.

# [ConvertMe](https://github.com/AntKerf/Examples/tree/master/ConvertMe) ![Lang](https://img.shields.io/badge/Language-C%2B%2B%2FQml-blue) [![Actual](https://img.shields.io/badge/Release-1.0-green)](https://github.com/AntKerf/Examples/releases/tag/CM_v1.0)
Приложение конвертер валют, работает на API центробанка.
Позволяет переводить все валюты в рубль РФ или любую другую валюту.

Управление: ЛКМ - чтобы выбрать первую валюту для перевода. ПКМ - выбрать вторую валюту для перевода. Чтобы зафиксировать значение первой или второй валюты достаточно активировать нажатием это поле, после чего при изменении валют значение выбраного полня не изменится.

Создано на QT С++ и Qml


# [EDLocal](https://github.com/AntKerf/Examples/tree/master/EDLocal) ![Lang](https://img.shields.io/badge/Language-C%2B%2B%2FQml-blue)
Просмотр звездных систем(в database/ed.db загружнно ~1млн звездных систем в радиусе 1000с.л. от Sol, полную информацию имеют лишь системы в радиусе 100c.л.)
Построенна QSqlTableModel для взаимодействия qml и sql.
Добаленны классы для просмотра бд и парсинга Json для добавления новых данных из dump файлов базы данных EDSM или через Api.
Данные получены с помощью API EDSM.

# [WebScrap](https://github.com/AntKerf/Examples/tree/master/WebScrap) ![Lang](https://img.shields.io/badge/Language-Java-blue)
Веб-скрапер котировок. Первый мой проект написанный на Java. 
В основе лежит HtmlUnit. Поиск на страницах осуществляется с помощью XPath.

# [MNN](https://github.com/AntKerf/Examples/tree/master/MNN) ![Lang](https://img.shields.io/badge/Language-C%2B%2B-blue)
Библиотека для обучения многослойного перцептрона. Позволяет создать перцептрон любой архитектуры. Имеет возможность задания нескольких функций активаций.
Написана на С++ с помощью Boost.Gil. Поддерживает многопоточность.

# [IFromBook](https://github.com/AntKerf/Examples/tree/master/IFromBook) ![Lang](https://img.shields.io/badge/Language-Qml-blue)
Интерфейс приложения для оцифровки сканов.

Создано в Qt, Qml.

# [MoonVisor](https://github.com/AntKerf/Examples/tree/master/MoonVisor) ![Lang](https://img.shields.io/badge/Language-C%2B%2B%2FQml-blue) ![Stage](https://img.shields.io/badge/Stage-Concept-red) [![Actual](https://img.shields.io/badge/Build-0.1-green)](https://github.com/AntKerf/Examples/releases/tag/MV_0.1)
Приложение-концепт показывает как будет видно луну в телескоп с определенными настройками.
Создано в Qt на С++ и Qml.
Можно легко добавлять новые виды телескопов и объектов наблюдения.
