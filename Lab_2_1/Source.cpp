#include <iostream>
#include "Header.h"

using namespace std;

void delete_list(listptr& l)
{
	// Удаляет список 

	listptr p;
	while (l != nullptr)
	{
		p = l->next;
		delete l;
		l = p;
	}
	return;
}


inline void print_list(listptr l)
{
	// Печатает список

	cout << "List: ";
	while (l != nullptr) {
		cout << l->val << " — ";
		l = l->next;
	}
	cout << endl;
}


int listlen(listptr l)
{
	// Возвращает длину списка

	int count = 0;
	while (l != nullptr) {
		++count;
		l = l->next;
	}
	return count;
}


int count_nums(listptr l, int target)
{
	// Считает кол-во элементов списка, совпавших с target

	int count = 0;
	while (l != nullptr) {
		if (l->val == target)
			++count;
		l = l->next;
	}
	return count;
}


listptr find_num(listptr l, int target) 
{
	// Находит элемент = target и возвращает указатель на него

	listptr p = nullptr;
	while (l != nullptr) {
		if (l->val == target) {
			p = l;
			return p;
		}
		l = l->next;
	}
	return p;
}


void insert(listptr l, int elem)
{
	// Вставляет новый элемент после введённого элемента

	while (l != nullptr) {
		if (l->val == elem) {
			listptr t = new elem_list;
			t->next = l->next;
			cout << "Enter elem: ";
			cin >> t->val;
			l->next = t;
			return;
		}
		l = l->next;
	}

	throw 100;
}


void delete_elem(listptr& l, int target)
{
	// Удаляет элемент из списка

	listptr pre = nullptr;
	if (l->val == target) {
		pre = l;
		l = l->next;
		delete pre;
		return;
	}
	listptr beg = l;
	while (l != nullptr) {
		if (l->val == target) {
			pre->next = l->next;
			delete l;
			l = beg;
			return;
		}

		pre = l;
		l = l->next;
	}
	l = beg;  // ?
	return;
}


void delete_elems(listptr& l, int target)
{
	// Удаляет все вхождения элемента из списка
	// Весь список из target'ов?
	listptr pre = nullptr;

	while (l->val == target && l != nullptr) {
		pre = l;
		l = l->next;
		delete pre;
		pre = nullptr;
		
	}

	listptr beg = l;
	
	while (l != nullptr) {
		if (l->val == target) {
			pre->next = l->next;
			delete l;
			l = pre->next;
			continue;
		}

		pre = l;
		l = l->next;
	}
	l = beg;  // ?
	return;
}


listptr create_list_from_array(int* arr, int size)
{
	// Создаёт новый список из массива

	listptr l = nullptr;
	for (int i{ size - 1 }; i >= 0; --i) {
		listptr p = new elem_list;
		p->val = arr[i];
		p->next = l;
		l = p;
	}
	return l;
}


int elems_sum_rec(listptr l, int sum = 0)
{
	// Посчитать сумму всех элементов списка (рекурсивно)

	sum += l->val;

	if (l->next != nullptr)
		return elems_sum_rec(l->next, sum);

	return sum;
}


int find_max_in_list_rec(listptr l, int apex = INT_MIN)
{
	// Найти максимальное значение в списке (рекурсивно)

	if (l->val > apex)
		apex = l->val;

	if (l->next != nullptr)
		return find_max_in_list_rec(l->next, apex);

	return apex;
}


void print_rev_list_rec(listptr l)
{
	// Вывести список в обратном порядке (рекурсивно)

	if (l != nullptr) {
		print_rev_list_rec(l->next);
		cout << l->val << " — ";
		return;
	}

	cout << "RevList: ";
	return;
}


int count_nums_rec(listptr l, int target, int count = 0)
{
	// Считает кол-во вхождений target'а в список (рекурсивно)

	if (l->val == target)
		++count;

	if (l->next != nullptr) {
		return count_nums_rec(l->next, target, count);
	}

	return count;
}


void create_list(listptr& l)
{
	// Создаёт новый список

	if (l != nullptr) {
		cout << "error";
		throw 404;
		return;
	}
	else {
		int n;
		cout << "Кол-во элементов: ";
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			listptr p = new elem_list;
			int num;
			cout << "Enter elem: ";
			cin >> num;
			p->val = num;
			p->next = l;
			l = p;
		}
		}
	return;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	listptr l1, l2;  // elem_list* l1,*l2;
	listptr p, t;
	
	l1 = nullptr; 
	for (int i = 0; i < 10; ++i) {
		p = new elem_list;
		p->val = i;
		p->next = l1;
		l1 = p;
	}


	l2 = nullptr; t = nullptr;
	t = l2 = new elem_list;
	l2->val = 0;
	l2->next = nullptr;
	for (int i = 1; i < 10; ++i) {
		t->next = new elem_list;
		t = t->next;
		t->val = i;
		t->next = nullptr;
	}

	// #1
	print_list(l1);
	cout << "Length: " << listlen(l1) << endl;
	cout << "Count of 5: " << count_nums(l1, 5) << endl;
	listptr res = nullptr;
	res = find_num(l1, 20);  // или 5, чтобы найти элемент
	if (res != nullptr)
		cout << "res = " << res->val << endl;
	else
		cout << "res = nullptr" << endl;


	insert(l1, 5);  // Вставить после 5
	print_list(l1);
	delete_elem(l1, 5);  // Удалить 5 из списка
	print_list(l1);

	// #2
	cout << endl;
	print_list(l2);
	print_rev_list_rec(l2);
	cout << endl;
	cout << "Elems summary: " << elems_sum_rec(l2) << endl;

	// #3
	listptr l3 = nullptr;
	create_list(l3);
	print_list(l3);
	cout << "Length: " << listlen(l3) << endl;
	delete_elems(l3, 5);
	print_list(l3);

	// #4
	listptr l4 = nullptr;
	int* arr = new int[10]{ 7, 7, 3, 5, 7, 7, 1, 2, 7, 7 };
	l4 = create_list_from_array(arr, 10);
	print_list(l4);
	cout << "MaxElem in l4: " << find_max_in_list_rec(l4) << endl;
	
	cout << "Length: " << listlen(l4) << endl;
	cout << "Count of 7: " << count_nums_rec(l4, 7) << endl;
	

	delete[] arr;
	delete_list(l1);
	delete_list(l2);
	delete_list(l3);
	delete_list(l4);

	
	return EXIT_SUCCESS;
}