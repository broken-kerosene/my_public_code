

Вам надо написать класс Date для хранения даты григорианского календаря. Используйте три переменных типа int для хранения дня, месяца и года. В вашем классе должнен быть следующий публичный интерфейс:

    Конструктор, принимающий на вход три числа, — день, месяц и год. В случае некорректной даты генерируйте исключение std::invalid_argument, определенное в заголовочном файле stdexcept.
    Константные функции GetDay, GetMonth и GetYear.
    Префиксные операторы ++ и -- для перехода к следующей и предыдущей дате.
    Бинарные операторы + и -, где вторым аргументом является целое число — количество дней. Эти операторы должны вернуть новую дату, отстоящую от заданной на указанное число дней.
    Бинарный опретор -, вычисляющий разность между двумя датами и возвращающий int - количество дней.

Считайте, что все обрабатываемые даты будут лежать в пределах от 1 января 1970 года до 31 декабря 2099 года.
