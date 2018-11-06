#include <iostream>
#include <vector>

using namespace std;

//Решите задачу «Средняя температура» в других ограничениях на входные данные.
//
//Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите
//номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.
//
//Гарантируется, что среднее арифметическое значений температуры является целым числом.
//
//Формат ввода
//Вводится число N, затем N целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.
//Гарантируется, что N не превышает миллиона (10^6), а значения температуры, измеряющиеся в
//миллионных долях градусов по Цельсию, лежат в диапазоне от −10^8 до 10^8. Проверять соблюдение
//этих ограничений не нужно: вы можете ориентироваться на них при выборе наиболее подходящих
//типов для переменных.

//Формат вывода
//Первое число K — количество дней, значение температуры в которых выше среднего арифметического.
//Затем K целых чисел — номера этих дней.

int main() {
  int n;
  cin >> n;
  vector<int> temperatures(n);
  int64_t sum = 0;
  for (int& temperature : temperatures) {
    cin >> temperature;
    sum += temperature;
  }

  int average = sum / n;

  vector<int> above_average_indices;
  for (int i = 0; i < n; ++i) {
    if (temperatures[i] > average) {
      above_average_indices.push_back(i);
    }
  }

  cout << above_average_indices.size() << endl;
  for (int i : above_average_indices) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}

