// Очень часто для работы со строками нам нужно сначала вычислить длину строки. Для C-style строк
// длина нигде явно не хранится, но её можно вычислить. Напишите функцию, которая вычисляет
// длину C-style строки. Учтите, что завершающий нулевой символ считать не нужно.
//
// Требования к реализации: при выполнении этого задания вы можете создавать любые вспомогательные
// функции. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.

unsigned strlen(const char *str)
{
   unsigned c = 0;
   while(*(str++) != 0) c++;
   return c;
}

// Вам требуется реализовать функцию конкатенации (склейки) двух C-style строк. Функция конкатенации 
// принимает на вход две C-style строки и дописывает вторую в конец первой так, чтобы первая строка
// представляла из себя одну C-style строку равную конкатенации двух исходных.
// 
// Не забудьте, что в результирующей строке должен быть только один нулевой символ — тот, что 
// является маркером конца строки.
// 
// Гарантируется, что в первой строке достаточно памяти (т.е. она располагается в массиве 
// достаточной длины), чтобы разместить конкатенацию обеих строк, но не больше.
// 
// Требования к реализации: при выполнении задания вы можете определять любые вспомогательные функции, 
// если они вам нужны. Выводить или вводить что-либо не нужно. Функцию main определять не нужно.

void strcat(char *to, const char *from){
    int l1 = strlen(to);
    while(*from != '\0'){
        to[l1++] = *from;
        from++;
    }
    to[l1++] = '\0';
}

void strcat(char *to, const char *from)
{
    while(*to) to++;
    while(*(to++) = *(from++));
}

// Напишите функцию поиска первого вхождения шаблона в текст. В качестве первого параметра
// функция принимает текст (C-style строка), в которой нужно искать шаблон. В качестве второго
// параметра строку-шаблон (C-style строка), которую нужно найти. Функция возвращает позицию
// первого вхождения строки-шаблона, если он присутствует в строке (помните, что в C++ принято
// считать с 0), и -1, если шаблона в тексте нет.
//
// Учтите, что пустой шаблон (строка длины 0) можно найти в любом месте текста.

int strstr(const char *text, const char *pattern)
{
  if(*pattern == 0){
    return 0;
  }

  for(unsigned i = 0; *text != 0; i++){
    if(*text == *pattern){
      const char* pattern_it = pattern;
      const char* source_it = text;
      while(*pattern_it != 0){
        if(*pattern_it != *source_it){
          break;
        }
        pattern_it++; source_it++;
      }

      if(*pattern_it == 0){
        return i;
      }
    }
    text++;
  }
  return -1;
}







