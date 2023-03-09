# Smart_calc
## Платформы: Windows, Mac OS
## Среда разработки: QT 6, 5 
## Язык, стандарт: C++17

* Запуск происходит после открытия calc.pro в QtCreator (Windows, Mac OS), либо ввод команды make в терминале находясь в папке src(Mac OS)

* Данный калькулятор выполняет базовые арифмитические операции такие как сложение,
умножение, деление, вычитание, остаток от деления, возведение в степень, а также 
вычисление функций косинус, синус, тангес, арктангенс, арксинус, арккосинус,
логарифм натуральный, логорифм десятичный, квадратный корень.
***
* Ввод происходит через графический интерфейс.
* Программа принимает на вход как целые так и дробные числа.
* Вычисления арифметических выражений происходят после нажатия "=".
* Учитываются унарные плюс и минус.
* Операция 'mod' имеет такой же приоритет как и функция.
* При ошибке ввода выводиться сообщение "Error calc".
* Вычисления с перменной происходят после нажатия кнопки "set_x" и ввода значения.
***
* Если в выходной строке присутствует 'x', то программа ожидает нажатия кнопок 'Graff' или 'set x'.
* После нажатия 'draw', при корректном выражении, содержащим 'x', открывается окно с предложением ввода
границ области определения графика. Границы можно задать в переделах от -1000000 до 1000000. Шаг - 0.01.
* После утсановления границ и нажатия кнопки
"Graff", окно с вводом границ закрывается и открывается окно с построенным графиком функции. Линия графика синего цвета.
***
* При нажатии "Credit" откывается форма для ввода данных о кредите: сумма, период, процентная ставка и тип платежа(ануитетный или дифферинцированный). После нажатия "Calc Credit" расчитывается и выводится пользователю таблица с суммой кредита, ежемесячным платежем и переплатой по кредиту.