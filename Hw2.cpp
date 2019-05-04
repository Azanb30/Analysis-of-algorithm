#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int * read(int *arr, int &size)
{
	ifstream fin;
	int i = 0;
	fin.open("data.txt", ios::in);
	fin >> size;
	arr = new int[size];
	while (fin >> arr[i])
	{
		i++;
	}
	fin.close();
	return arr;
}
void printArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void bubbleUp(int *arr, int size)//45 3 12 65 1
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i]>arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}
}
void bubbleSort_a(int *arr, int size)
{
	cout << "Before Sorting : ";
	printArray(arr, size);
	for (int i = 0; i < size - 1; i++)
	{
		bubbleUp(arr, size);
	}
	cout << "After Sorting : ";
	printArray(arr, size);

}
void bubbleSort_b(int *arr, int size)
{
	cout << "Before Sorting : ";
	printArray(arr, size);
	for (int i = size; i > 0; i--)
	{
		bubbleUp(arr, i);
	}
	cout << "After Sorting : ";
	printArray(arr, size);
}
bool bubbleUp_c(int *arr, int size)//45 3 12 65 1
{
	bool check = false;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i]>arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
			check = true;
		}
	}
	return check;
}
void bubbleSort_c(int *arr, int size)
{
	int tem = size;
	cout << "Before Sorting : ";
	printArray(arr, size);
	while (bubbleUp_c(arr, tem--));
	cout << "After Sorting : ";
	printArray(arr, size);
}
int SelectMinIndexWithinRange(int *arr, int si, int ei)
{
	int minIndex = si;
	for (int i = si + 1; i <= ei; i++)
	{
		if (arr[minIndex] > arr[i])
		{
			minIndex = i;
		}
	}
	return minIndex;
}
void SelectionSort(int *arr, int size)
{
	int mi = 0;
	cout << "Before Sorting : ";
	printArray(arr, size);
	for (int i = 0; i < size; i++)
	{
		mi = SelectMinIndexWithinRange(arr, i, size - 1);
		swap(arr[mi], arr[i]);
	}
	cout << "After Sorting : ";
	printArray(arr, size);
}
void InsertinSortedSubArray(int *arr, int j)
{
	for (int i = j; i > 0; i--)
	{
		if (arr[i - 1] > arr[i])
		{
			swap(arr[i - 1], arr[i]);
		}
		else
		{
			break;
		}
	}
}
void insertionSort(int *arr, int size)
{
	cout << "Before Sorting : ";
	printArray(arr, size);
	for (int i = 1; i < size; i++)
	{
		InsertinSortedSubArray(arr, i);
	}
	cout << "After Sorting : ";
	printArray(arr, size);
}
void menu(){
	cout << "Press 1 For Bubble Sort (A) \n";
	cout << "Press 2 For Bubble Sort (B) \n";
	cout << "Press 3 For Bubble Sort (C) \n";
	cout << "Press 4 For Selection Sort \n";
	cout << "Press 5 For Insertion Sort \n";
}
void main(){
	int option = 0;
	int size = 0;
	int *arr = nullptr;
	arr = read(arr, size);
	menu();
	while (true)
	{
		cout << "Enter option : ";
		cin >> option;
		if (option == 1)
		{
			bubbleSort_a(arr, size);
		}
		else if (option == 2)
		{
			bubbleSort_b(arr, size);
		}
		else if (option == 3)
		{
			bubbleSort_c(arr, size);
		}
		else if (option == 4)
		{
			SelectionSort(arr, size);
		}
		else if (option == 5)
		{
			insertionSort(arr, size);
		}
		else if (option == 6)
		{
			
		}
		else
		{
			break;
		}
	}
}
