#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
void read(ifstream & fin , vector<int> &arr)
{
	int i = 0;
	while (!fin.eof())
	{
		fin >> arr[i];
		i++;
	}
}
void printArray(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void bubbleUp(vector<int> &arr , int size)//45 3 12 65 1
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i]>arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}
}
void bubbleSort_a(vector<int> &arr)
{
	cout << "Before Sorting : ";
	printArray(arr);
	for (int i = 0; i < arr.size() - 1; i++)
	{
		bubbleUp(arr,arr.size());
	}
	cout << "After Sorting : ";
	printArray(arr);

}
void bubbleSort_b(vector<int> &arr)
{
	cout << "Before Sorting : ";
	printArray(arr);
	for (int i =arr.size(); i > 0; i--)
	{
		bubbleUp(arr, i);
	}
	cout << "After Sorting : ";
	printArray(arr);
}
bool bubbleUp_c(vector<int> &arr , int size)//45 3 12 65 1
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
void bubbleSort_c(vector<int> &arr)
{
	int tem = arr.size();
	cout << "Before Sorting : ";
	printArray(arr);
	while (bubbleUp_c(arr, tem--));
	cout << "After Sorting : ";
	printArray(arr);
}
int SelectMinIndexWithinRange(vector<int> &arr, int si, int ei)
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
void SelectionSort(vector<int> &arr)
{
	int mi = 0;
	cout << "Before Sorting : ";
	printArray(arr);
	for (int i = 0; i < arr.size(); i++)
	{
		mi = SelectMinIndexWithinRange(arr, i, arr.size() - 1);
		swap(arr[mi], arr[i]);
	}
	cout << "After Sorting : ";
	printArray(arr);
}
void InsertinSortedSubArray(vector<int> &arr, int j)
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
void insertionSort(vector<int> &arr)
{
	cout << "Before Sorting : ";
	printArray(arr);
	for (int i = 1; i < arr.size(); i++)
	{
		InsertinSortedSubArray(arr, i);
	}
	cout << "After Sorting : ";
	printArray(arr);
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
	ifstream fin;
	int size = 0;
	fin.open("data.txt", ios::in);
	fin >> size;
	vector <int> arr(size);
	read(fin,arr);
	menu();
	while (true)
	{
		cout << "Enter option : ";
		cin >> option;
		if (option == 1)
		{
			bubbleSort_a(arr);
		}
		else if (option == 2)
		{
			bubbleSort_b(arr);
		}
		else if (option == 3)
		{
			bubbleSort_c(arr);
		}
		else if (option == 4)
		{
			SelectionSort(arr);
		}
		else if (option == 5)
		{
			insertionSort(arr);
		}
		else
		{
			break;
		}
	}
	fin.close();
}
