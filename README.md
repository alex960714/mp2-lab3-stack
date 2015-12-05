# Лабораторная работа №3: создание простейшего стека

Создан класс T_Stack, в котором реализованы операции:

- Записи элемента в стек;
- Чтения верхнего элемента стека с удалением;
- Чтения верхнего элемента стека без удаления;
- Проверка на пустоту стека;
- Проверка на заполненность стека;
- Очистка стека.

Для проверки правильности работы класса, реализован класс "арифметическое выражение" - TParser. 
Арифметическое выражение вводится с клавиатуры. В этом классе реализованы такие методы, как:

- Проверка правильности расстоновки скобок;
- Расстановка приоритетов арифметических операций;
- Проверка, является ли данный символ строки оператором;
- Проверка, является ли данный символ строки числом;
- Конвертация данного арифметического выражения из инфиксной формы в постфиксную;
- Вычисление выражения в постфиксной форме;
- Распознование вещественного числа в вводимой строке;
- Вычисление выражения с вещественными числами в инфиксной форме;
- Вычисление значений функции одной переменной - диапазон значений и шаг неизвестного вводится с клавиатуры.
 
К проекту подключена библиотека Google Test для тестирования работоспособности классов T_Stack и TParser.
