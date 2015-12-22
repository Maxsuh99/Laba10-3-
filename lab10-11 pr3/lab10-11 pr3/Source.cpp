#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <windows.h>
#include <algorithm>
#include "masiv.h"
#include<time.h>
using namespace std;
bool f(Massiv &a,Massiv &b)
{
	
	return (a.summ()<b.summ());
}

bool f1(Massiv *a, Massiv *b)
{

	return (a->summ()<b->summ());
}

void main()
{
	srand(time(0));
	Massiv a,b,c,d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	stack<Massiv> my_stack;//������� ��������� ���� stack
	my_stack.push(a);//��������� ������ � ����� ����������
	my_stack.push(b);
	my_stack.push(c);
	my_stack.push(d);
	stack<Massiv> my_stack2 = my_stack;//������� ����� ����������, �.�. ��� ��������� �� ����� ��������� ���� ���������

	cout << "----------------------- Stack ----------------------" << endl;
	while (my_stack2.size()>0)//������� �� ����� �������� �����
	{
		cout << my_stack2.top();
		cout<< endl;
		my_stack2.pop();
	}
	//��� ����� ��� ����������!!!!!!!!!!!!!!!!!!!!!!!!!!

	cout << "----------- Sort stack by the sum numbers of the massiv -------------" << endl;
	vector<Massiv> for_sort;
	int k = 0;
	while (my_stack.size()>0)//��������� ������� �� ����� � ������ ��� ����������
	{
		for_sort.push_back( my_stack.top());		
		my_stack.pop();
	}

	sort(for_sort.begin(), for_sort.end(), f); // ��������� ������ �� ������� f(�� ����� ��������� �������)

	for (int i = 0; i < for_sort.size(); i++)//��������� ������� ����� �� ������� � ����
	{
		my_stack.push( for_sort[i]);
		
	}
	my_stack2 = my_stack;
	while (my_stack2.size()>0)//������� �� ����� �������� �����
	{
		cout << my_stack2.top();
		cout << endl;
		my_stack2.pop();
	}
	
	cout << "-------------- Search 5 on the Stack  -------------" << endl;
	my_stack2 = my_stack;
	bool flag = 0;
	while (my_stack2.size()>0)//���� 5 �� ���� �������� �����
	{
		if(my_stack2.top().search(5))
		flag = 1;

		my_stack2.pop();
	}
	if (flag)
	{
		cout << "Yes"<<endl;
	}
	else
	{
		cout << "No"<<endl;
	}



	cout << "------ Move on the set elements sum numbers of the massiv < 20  ------" << endl;
	set<Massiv*> my_set;//������� ���������
	my_stack2 = my_stack;
	while (my_stack2.size()>0)//��������� � ��������� ��� �������� �����, ����� ��������� ������� <20
	{
		if (my_stack2.top().searchEx(20))
			my_set.insert(&my_stack2.top());
			
		my_stack2.pop();
	}
	for (auto it = my_set.begin(); it != my_set.end(); it++)//������� ��������� �� ����� ����� ���������
	{
		cout << *(*it);
		cout << endl;
	}


	cout << "----------- Sort stack by the sum numbers of the massiv -------------" << endl;
	my_stack2 = my_stack;
	while (my_stack2.size()>0)//������� �� ����� �������� �����
	{
		cout << my_stack2.top();
		cout << endl;
		my_stack2.pop();
	}
	cout << "----------- Sort set by the sum numbers of the massiv -------------" << endl;
	for (auto it = my_set.begin(); it != my_set.end(); it++)//������� ��������� �� ����� ����� ���������
	{
		cout << *(*it);
		cout << endl;
	}

	cout << "---- Create a third container and insert into it elements of the previous two ----" << endl;
	vector<Massiv> my_vector;//������ ���������
	my_stack2 = my_stack;
	while (my_stack2.size()>0)//������� �� ����� �������� �����
	{
		my_vector.push_back(my_stack2.top());
		my_stack2.pop();
	}
	for (auto it = my_set.begin(); it != my_set.end(); it++)//������� ��������� �� ����� ����� ���������
	{
		my_vector.push_back(*(*it));
	}


	for (int i = 0; i < my_vector.size(); i++)//������� �� ����� �������� �������, ������� ������� ����� ������ i
	{
		cout << my_vector[i];
		cout<< endl;
	}

	cout << "----------------------- amount of elements sum >25  ----------------------" << endl;
	int num = 0;

	for (int i = 0; i < my_vector.size(); i++)//������� ���-�� ��������� � ���������� > 25
	{
		if (my_vector[i].summ()>25)num++;

	}
	cout << num << endl;
}
