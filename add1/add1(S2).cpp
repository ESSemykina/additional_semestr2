/*Вариант 4.
Дана последовательность {Ai} (Ai < 1000) длины N<1000. Найти максимальное число в последовательности*/
#include <iostream>

int findMax(int *array, int count, int i, int MAX)
{
	if(array[i] > MAX)
	{
		MAX = array[i];
	}

	i++;
	if (i == count)
	{
		return MAX;
	}
	findMax(array, count, i, MAX);
}

int main()
{
	int count = 1000; //Сколько элементов будет в массиве

	int *array = new int[count]; //Выделяю память под динамический массив

	for (int i = 0; i < count; i++) //Заполняю массив элементами от 1 до 1000
	{
		array[i] = i;
		std::cout << array[i] <<std::endl;
	}

	std::cout << "MAX ELEMENT IS " << findMax(array, count, 0, INT_MIN) << std::endl; //Вывожу минимальный элемент
}