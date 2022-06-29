#include <iostream>


struct list
{
	int field; // поле данных
	struct list* next; // указатель на следующий элемент
	struct list* prev; // указатель на предыдущий элемент
};


struct list* init(int a)  // а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = lst; // указатель на следующий узел
	lst->prev = lst; // указатель на предыдущий узел
	return(lst);
}

struct list* ADD(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	p->prev = temp;
	return(temp);
}

struct list* DELETE(list* lst)
{
	struct list* prev, * next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	prev->next = lst->next; // переставляем указатель
	next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
	return(prev);
}


void PRINT(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != lst); // условие окончания обхода
}


void PRINTR(list* lst)
{
	struct list* p;
	p = lst;
	do {
		p = p->prev;  // переход к предыдущему узлу
		printf("%d ", p->field); // вывод значения элемента p
	} while (p != lst); // условие окончания обхода
}


int main()
{
	list* list = init(12);
	ADD(list, 5);
	ADD(list, 6);
	ADD(list, 17);
	
	PRINT(list);
	std::cout<<""<< std::endl;
	PRINTR(list);
	std::cout << "" << std::endl;

	DELETE(list->next);
	PRINT(list);


}