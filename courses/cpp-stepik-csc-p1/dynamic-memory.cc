// В этой задаче вам нужно реализовать функцию resize. Функция resize принимает на вход три
// аргумента: указатель на область памяти, выделенную с помощью оператора new[], размер области
// (size) и новый размер (new_size). Функция должна выделить память размера new_size,
// скопировать в нее данные из переданной области памяти, освободить старую область памяти и
// вернуть выделенную область памяти нового размера со скопированными данными.  
// 
// Обратите внимание, что память, возвращенная из функции, будет освобождена с помощью оператора
// delete[]. Несмотря на то, что входной тип данных — это const char *, не стоит рассчитывать,
// что там хранится C-style строка. При выполнении задания также учтите, что new_size может 
// быть меньше size.

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *new_str = new char[new_size];
    for(size_t i = 0; i < new_size; *(new_str+i) = *(str+i), i++);
    delete [] str;
    return new_str;
}

// Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет
// конца потока или не встретит символ переноса строки ('\n'), и возвращает C-style строку
// с прочитанными символами.
// 
// Обратите внимание, что так как размер ввода заранее неизвестен, то вам нужно будет перевыделять
// память в процессе чтения, если в потоке ввода оказалось больше символов, чем вы ожидали.
// 
// Память, возвращенная из функции будет освобождена оператором delete[]. Символ переноса строки
// ('\n') добавлять в строку не нужно, но не забудьте, что в конце C-style строки должен быть
// завершающий нулевой символ.

char *getline()
{
    size_t size = 64;
    size_t i = 0;
    char c;
    char* string = new char[size];
    for(; (std::cin.get(c)) && c != '\n'; string[i] = c, i++){
      if(i == size){
        string = resize(string, size, size *= 2);
      }
    }
    string[i] = '\0';
    return string;
}
