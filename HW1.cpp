#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
void read(int arr[], int &size)
{
	ifstream fin;
	int in = 0, i = 0;
	fin.open("data.txt", ios::in);
	while (fin >> in)
	{
		cout << in << "\n";
		arr[i] = in;
		i++;
	}
	size = i;
	fin.close();
}
bool search_element(int arr[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (value == arr[i])
		{
			return false;
		}
	}
	return true;
}
void main1(int arr[],int size)
{
	for (int i = 1; i <= size; i++)
	{
		if (search_element(arr, size, i))
		{
			cout << "Missing Value is " << i << "\n";
			return;
		}
	}
	cout << "Nothing is Missing" << "\n";
}
int b_search_element(int arr[], int s, int e, int value)
{
	int m = (s + e) / 2;
	if (s <= e)
	{
		if (arr[m] == value)
		{
			return m;
		}
		if (arr[m] > value)
		{
			return b_search_element(arr, s, m - 1, value);
		}
		else
		{
			return b_search_element(arr, m + 1, e, value);
		}
	}
	else
	{
		return -1;
	}

}
void main2(int arr[],int size,int f_size)
{
	sort(arr, arr + f_size);
	for (int i = 1; i <= size; i++)
	{
		if (b_search_element(arr, 0, size, i) == -1)
		{
			cout << "Missing Value is " << i << "\n";
			return;
		}
	}
	cout << "Nothing is Missing" << "\n";
	return;
}
void main3(int arr[], int size, int f_size)
{
	sort(arr, arr + f_size);
	for (int i = 1; i <= size; i++)
	{
		if (arr[i - 1] != i)
		{
			cout << "Missing value is " << i << "\n";
			return;
		}
		if (arr[i] - arr[i - 1] != 1)
		{
			cout << "Missing value is " << arr[i - 1] + 1 << "\n";
			return;
		}
	}
	cout << "Nothing is Missing" << "\n";
	return;
}
void read2(bool chk[], int size)
{
	ifstream fin;
	int in = 0;
	fin.open("data.txt", ios::in);
	while (fin >> in)
	{
		chk[in - 1] = true;
	}
	fin.close();
}
void main4(int size)
{
	bool check[10] = { false };
	read2(check, size);
	for (int i = 0; i < size; i++)
	{
		if (check[i] == false)
		{
			cout << "Missing Value is " << i + 1 << endl;
			return;
		}
	}
	cout << "Nothing is Missing" << "\n";
	return;
}
void main5(int arr[],int size,int f_size)
{
	int sum = 0;
	for (int i = 0; i < f_size; i++)
	{
		sum = sum + arr[i];
	}
	for (int i = 1; i <= size; i++)
	{
		sum = sum - i;
	}
	cout << "Missing Value is : " << sum * -1 << "\n";
	return;
}
int fibonacci(int x) {
	if (x == 0)
	{
		return 0;
	}

	if (x == 1)
	{
		return 1;
	}
	return fibonacci(x - 1) + fibonacci(x - 2);
}
void menu(){
	cout << "Press 1 for N^2\n";
	cout << "Press 2 for NlogN + NlogN\n";
	cout << "Press 3 for NlogN + N\n";
	cout << "Press 4 for N + N\n";
	cout << "Press 5 for N + N + N\n";
	cout << "Press 6 for fabonacci\n";
	cout << "Press 7 for Exit\n";
}
void main(){
	int option = 0;
	int size = 0, f_size = 0;
	int *arr = nullptr;
	cout << "Enter Size of array : ";
	cin >> size;
	arr = new int[size];
	read(arr, f_size);
	menu();
	while (true)
	{
		cout << "Enter option : ";
		cin >> option;
		if (option == 1)
		{
			main1(arr, size);
		}
		else if (option == 2)
		{
			main2(arr, size, f_size);
		}
		else if (option == 3)
		{
			main3(arr, size, f_size);
		}
		else if (option == 4)
		{
			main4(size);
		}
		else if (option == 5)
		{
			main5(arr, size, f_size);
		}
		else if (option == 6)
		{
			cout << "Enter Value for fabonacci :";
			cin >> option;
			cout << fibonacci(option)<<"\n";
		}
		else
		{
			break;
		}
	}
}