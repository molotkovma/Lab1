//Quck ���������� 
#include <iostream>										
#include <locale.h>
#include<fstream>
using namespace std;									


void sort(int *numbers, int left, int right)			
{
	int pivot;											
	int l_hold = left;									
	int r_hold = right;									
	pivot = numbers[left];
	while (left < right)								 
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;									
		if (left != right)								
		{
			numbers[left] = numbers[right];				
			left++;										
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;										
		if (left != right)								
		{
			numbers[right] = numbers[left];				
			right--;									
		}
	}
	numbers[left] = pivot;								
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)									
		sort(numbers, left, pivot - 1);
	if (right > pivot)
		sort(numbers, pivot + 1, right);
}


int main()												
{
	setlocale(LC_ALL, "Russian");						

	cout << "���� �� ������ ������� �������� �� �����, ������� 1. ���� ������ ������ �������� �� ����������, ������� 0: " << endl;		//
	int r;
	int a[30];
	int n;
	char p;
	int i, j;
	cin >> r;
	char YorN;
	if (r == 0)
	{
		cout << "������� ���������� ����� (�� 30 ��) :" << endl;
		cin >> n;
		int a[30];	//������ ������ ��� �������� ������

		cout << "������� ����� � ������������ �������:" << endl;
		for (int i = 0; i < n; ++i)
		{
			int mass;
			cin >> mass;
			a[i] = mass;

		}


		cout << endl;
		cout << endl;

		cout << "�� ����� ������: ";
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << " ";

		}

		cout << endl;
		cout << endl;

		sort(a, 0, n - 1);

		cout << "��������� ����������: ";
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		cout << "��������� ������ � ����? (y/n)" << endl;
		
		cin >> YorN;	
		if (YorN = 'y')
		{
			ofstream f("Sortirovka.txt");
			for (int i = 0; i < n; ++i)
			{

				cout << a[i] << " ";
				f << a[i];
			}
			cout << "���� ������� �������" << endl;
		}
		else
			cout << "���������� ���������" << endl;
	}
	else if (r == 1)
	{
		cout << "����������� ���� fi.txt � �������� ������� ��� �������� ����������� ����" << endl;

		cout << "������� ���������� ����� (�� 30 ��) :" << endl;
		cin >> n;
		cout << "���� �������? (y/n)" << endl;

		cin >> YorN;
		if (YorN = 'y')
		{
			ifstream f("fi.txt");
			cout << "���������� �����: " << endl;
			for (int i = 0; i < 5; ++i)
			{
				int fileSod;
				f >> fileSod;
				a[i] = fileSod;
				cout << a[i] << " ";

			}

			cout << endl;
			cout << endl;

			sort(a, 0, n - 1);
			cout << "��������� ����������: ";
			for (int i = 0; i < n; ++i)
				cout << a[i] << " ";
			cout << endl;

			cout << "��������� ������ � ����? (y/n)" << endl;
			char YorN;
			cin >> YorN;
			if (YorN = 'y')
			{
				ofstream f("Sortirovka.txt");
				for (int i = 0; i < n; ++i)
				{
					cout << a[i] << " ";
					f << a[i];
				}
				cout << "���� ������� ������� � Sortirovka.txt" << endl;
			}
			else
				cout << "���������� ���������" << endl;
		}
		else
		{
			cout << "������������ ����!" << endl;
		}

		system("pause");
		return 0;
	}
}

