//Quck сортировка 
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

	cout << "Если вы хотите считать значения из файла, введите 1. Если хотите ввести значения из клавиатуры, введите 0: " << endl;		//
	int r;
	int a[30];
	int n;
	char p;
	int i, j;
	cin >> r;
	char YorN;
	if (r == 0)
	{
		cout << "Введите количество чисел (до 30 шт) :" << endl;
		cin >> n;
		int a[30];	//задаем массив для хранения данных

		cout << "Введите числа в произвольном порядке:" << endl;
		for (int i = 0; i < n; ++i)
		{
			int mass;
			cin >> mass;
			a[i] = mass;

		}


		cout << endl;
		cout << endl;

		cout << "Вы ввели массив: ";
		for (int i = 0; i < n; ++i)
		{
			cout << a[i] << " ";

		}

		cout << endl;
		cout << endl;

		sort(a, 0, n - 1);

		cout << "Результат сортировки: ";
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		cout << endl;
		cout << "Сохранить данные в файл? (y/n)" << endl;
		
		cin >> YorN;	
		if (YorN = 'y')
		{
			ofstream f("Sortirovka.txt");
			for (int i = 0; i < n; ++i)
			{

				cout << a[i] << " ";
				f << a[i];
			}
			cout << "Файл успешно сохранён" << endl;
		}
		else
			cout << "Сортировка завершена" << endl;
	}
	else if (r == 1)
	{
		cout << "Расположите файл fi.txt в корневой системе или измените сущесвующий файл" << endl;

		cout << "Введите количество чисел (до 30 шт) :" << endl;
		cin >> n;
		cout << "Файл сохранён? (y/n)" << endl;

		cin >> YorN;
		if (YorN = 'y')
		{
			ifstream f("fi.txt");
			cout << "Содержимое файла: " << endl;
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
			cout << "Результат сортировки: ";
			for (int i = 0; i < n; ++i)
				cout << a[i] << " ";
			cout << endl;

			cout << "Сохранить данные в файл? (y/n)" << endl;
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
				cout << "Файл успешно сохранён в Sortirovka.txt" << endl;
			}
			else
				cout << "Сортировка завершена" << endl;
		}
		else
		{
			cout << "Некорректный ввод!" << endl;
		}

		system("pause");
		return 0;
	}
}

