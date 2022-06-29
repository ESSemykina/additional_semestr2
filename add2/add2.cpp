//Сортировка слиянием

//сложность Ѳ(n*log n) 
/* Лучшее время работы О = n*log(n)
  Худшее время работы O = n*log(n)
*/

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& a, size_t start, size_t end)
{
    if (end - start < 2)//кол-во 0,1 сортировать не надо
        return;
    if (end - start == 2)//если 2 эл-та, можем отсорт, поменяв местами
    {
        if (a[start] > a[start + 1])
            swap(a[start], a[start + 1]);
        return;
    }

    mergeSort(a, start, start + (end - start) / 2);
    mergeSort(a, start + (end - start) / 2, end);
    //слить в массив две половинки 
    vector<int> b;
    size_t b1 = start;
    size_t e1 = start + (end - start) / 2;
    size_t b2 = e1;
    while (b.size() < end - start)
    {
        if (b1 >= e1 || (b2 < end && a[b2] <= a[b1]))
        {
            b.push_back(a[b2]);
            ++b2;
        }
        else
        {
            b.push_back(a[b1]);
            ++b1;
        }
    }
    for (size_t i = start; i < end; ++i)
        a[i] = b[i - start];
}

int main()
{
    srand(time(0));

    vector<int> v;//создаю массив
    for (int i = 0; i < 20; ++i)//заполняю
        v.push_back(i);
    for (size_t i = 0; i < v.size(); ++i)//перемешиваю
        swap(v[i], v[rand() % (v.size() - i) + i]);
    for (auto i : v)//вывожу
        cout << i << " ";
    cout << endl;
    mergeSort(v, 0, v.size());//сортирую
    for (auto i : v)//вывожу отсотрированный 
        cout << i << " ";
    cout << endl;
}

