#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
long long fib_rec(int x) {
	if (x == 0)
		return 0;

	if (x == 1)
		return 1;

	return fib_rec(x - 1) + fib_rec(x - 2);
}
long long fibonacci(int n)
{
	long long n_1 = 0, n_2 = 1, sum = 0;

	switch (n)
	{
	case 0:
		return 0;

	case 1:
		return 1;

	default:
		for (int counter = 0; counter < n; counter++)
		{
			sum = n_1 + n_2;
			n_2 = n_1;
			n_1 = sum;
		}
	}
	return sum;
}
long long helper(vector <long long>&v, int n)
{
	if (v[n] != -1)
	{
		return v[n];
	}
	v[n] = helper(v, n - 1) + helper(v, n - 2);
	return v[n];
}
long long fib_mem(int x) {
	vector <long long> v(x + 1, { -1 });
	v[0] = 0, v[1] = 1;
	return helper(v,x);
}
long long Trisum(int x)
{
	if (x == 0)
		return -1;

	if (x == 1 || x == 2 || x == 3)
	{
		return x;
	}

	return Trisum(x - 1) + Trisum(x - 2) + Trisum(x-3);
}
long long TS_helper(vector <long long>&v, int n)
{
	if (v[n] != -1)
	{
		return v[n];
	}
	v[n] = TS_helper(v, n - 1) + TS_helper(v, n - 2) + TS_helper(v,n-3);
	return v[n];
}
long long TS_mem(int x) {
	vector <long long> v(x + 1, { -1 });
	v[0] = 1, v[1] = 2 , v[2] = 3;
	return TS_helper(v, x);
}
long long Nth_sum(int n)
{
	if (n <= 0)
		return 0;

	return n + Nth_sum(n - 1);
}

long long odd_sum(int n)
{
	if (n <= 0)
		return 0;

	return n + odd_sum(n - 2);
}
long long Nth_sum_odd(int n)
{
	if (n % 2 == 0)
		return odd_sum(n - 1);
	else
		return odd_sum(n);
}

long long two_pow_sum(int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return 2;

	return 2 * two_pow_sum(n - 1);
}
long long three_pow_sum(int n)
{
	if (n == 0)
		return 1;

	if (n == 1)
		return 3;

	return 3 * three_pow_sum(n - 1);
}

long long three_pow_div_helper(int n,int x)
{
	int dv = 0;
	dv = three_pow_sum(x);

	if (n/dv <= 1)
		return 1;
		
	return n/dv + three_pow_div_helper(n, x + 1);
}
long long three_pow_div(int n)
{
	int count = 0;
	return three_pow_div_helper(n,count);
}
long long two_pow_div_helper(int n, int x)
{
	int dv = 0;
	dv = two_pow_sum(x);

	if (n / dv <= 1)
		return 1;

	return n / dv + two_pow_div_helper(n, x + 1);
}
long long two_pow_div(int n)
{
	int count = 0;
	return two_pow_div_helper(n, count);
}


long long combination(int n, int r)
{
	if (n < r)
		return 0;

	if (r == 0 || n == r)
		return 1;

	return combination(n - 1, r - 1) + combination(n - 1, r);

}
long long permutation(int n, int r)
{
	if (n < r)
		return 0;

	if (r == 0)
		return 1;

	return n * permutation(n - 1, r - 1);
}

int linearSearch_sizeShrinking(vector<int> & v, int size, int value)
{
	if (v[size] != value && size == 0)
		return -1;

	if (v[size] == value)
		return size;

	return linearSearch_sizeShrinking(v, size - 1, value);
}

int searchHelper(vector<int> &v, int si, int ei, int value)
{
	if (si > ei)
		return -1;

	if (v[si] == value)
		return si;

	if (v[ei] == value)
		return ei;

	return searchHelper(v, si + 1, ei - 1, value);
}

int linearSearch_helperwala(vector<int> &v, int size, int value)
{
	return searchHelper(v, 0, v.size()-1, value);
}

int b_search_element(vector <int>&arr, int s, int e, int value)
{
	if (s <= e)
	{
		int m = (s + e) / 2;
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

bool BubbleUp_array(int A[], int n)
{
	if (n == 1)
		return false;

	bool SwapHappened = false;
	if (A[n - 1] < A[n - 2])
	{
		swap(A[n - 1], A[n - 2]);
		SwapHappened = true;
	}

	return BubbleUp_array(A, n - 1) || SwapHappened;
}
void BubbleSortRec_array(int A[],int size)
{
	if (BubbleUp_array(A, size))
		return BubbleSortRec_array(A,size);
}

bool BubbleUp(vector<int> & A, int n)
{
	if (n == 1)
		return false;

	bool SwapHappened = false;
	if (A[n - 1] < A[n - 2])
	{
		swap(A[n - 1], A[n - 2]);
		SwapHappened = true;
	}

	return BubbleUp(A, n - 1) || SwapHappened;
}
void BubbleSortRec(vector<int> & Vs)
{
	if (BubbleUp(Vs, Vs.size()))
		return BubbleSortRec(Vs);
}

int minIndex_arr(int arr[], int si, int ei)
{
	if (si == ei)
		return ei;

	int min = minIndex_arr(arr, si + 1, ei);
	if (arr[si] < arr[min])
		min = si;

	return min;
}
void recSelectionSortHelper(int arr[], int si, int ei)
{
	if (si < ei)
	{
		swap(arr[minIndex_arr(arr, si, ei)], arr[si]);
		recSelectionSortHelper(arr, si + 1, ei);
	}
}
void selectionSort(int arr[], int size)
{
	recSelectionSortHelper(arr, 0, size - 1);
}


int minIndex_vec(vector<int>&v, int si, int ei)
{
	if (si == ei)
		return ei;

	int min = minIndex_vec(v, si + 1, ei);
	if (v[si] < v[min])
		min = si;

	return min;
}
void recSelectionSortHelper_vec(vector<int>&v, int si, int ei)
{
	if (si < ei)
	{
		swap(v[minIndex_vec(v, si, ei)], v[si]);
		recSelectionSortHelper_vec(v, si + 1, ei);
	}
}
void selectionSort_vec(vector<int>&v)
{
	recSelectionSortHelper_vec(v, 0, v.size() - 1);
}

void insertionInSortedArray(int arr[], int index)
{
	if (index <= 0)
		return;

	if (arr[index -	1] > arr[index])
		swap(arr[index - 1], arr[index]);

	insertionInSortedArray(arr, index - 1);
}
void insertionInSortedArrayHelper(int arr[], int size)
{
	if (size > 1)
	{
		insertionInSortedArrayHelper(arr, size - 1);
		insertionInSortedArray(arr, size);
	}
}
void insertionSort_arr(int arr[], int size)
{
	insertionInSortedArrayHelper(arr, size-1);
}


void insertionInSortedvector(vector<int>&arr, int index)
{
	if (index <= 0)
		return;

	if (arr[index - 1] > arr[index])
		swap(arr[index - 1], arr[index]);

	insertionInSortedvector(arr, index - 1);
}
void insertionInSortedvectorHelper(vector<int>&arr,int size)
{
	if (size > 1)
	{
		insertionInSortedvectorHelper(arr, size - 1);
		insertionInSortedvector(arr, size);
	}
}
void insertionSort_vector(vector<int>&arr)
{
	insertionInSortedvectorHelper(arr, arr.size() - 1);
}

long long slowPower(int b , int p , int m)
{
	if (p == 0)
		return 1;

	return (b * slowPower(b, p - 1, m)) % m;
}

long long fastPower(int b, int p, int m)
{
	if (p == 0)
		return 1;

	int res = fastPower(b, p / 2, m);

	if (p % 2 == 0)
		return (res*res) % m;
	else
		return (b*(res*res) % m) % m;
}

long long slowMul(int x, int y)
{
	if (x == 0 || y == 0)
		return 0;

	return x + slowMul(x, y - 1);
}
long long fastMul(int x, int y)
{
	if (x == 0 || y == 0)
		return 0;

	int count = 1;
	int result = x;
	while (count + count <= y)
	{
		result += result;
		count += count;
	}
	return result + fastMul(x, y - count);
}

void slowQuotientAndRemainder(long long &quo, long long &rem, int x, int y)
{
	if (rem < y)
		return;

	rem -= y;
	quo++;
	slowQuotientAndRemainder(quo,rem,x,y);
}
void fastQuotientAndRemainder(long long &quo,long long &rem, int x, int y)
{
	if (rem < y)
		return;

	quo += 1;
	int res = y;

	while (quo + quo <= y)
	{
		res += res;
		quo += quo;
	}
	rem = rem - res;
	fastQuotientAndRemainder(quo,rem,x,y);
}
void menu()
{
	cout << "Press 1 for recursive Fib \n";
	cout << "Press 2 for iterative Fib \n";
	cout << "Press 3 for Memorization of Fib\n";
	cout << "Press 4 for Trisum\n";
	cout << "Press 5 for Trisum with memory\n";
	cout << "Press 6 for N sum\n";
	cout << "Press 7 for N sum N must be Odd\n";
	cout << "Press 8 for N sum in 2^N\n";
	cout << "Press 9 for N sum in 3^N\n";
	cout << "Press 10 for N sum in N/3\n";
	cout << "Press 11 for N sum in N/2\n";
	cout << "Press 12 for Permutations \n";
	cout << "Press 13 for Combinations \n";
	cout << "Press 14 for Linear search Size shrinking\n";
	cout << "Press 15 for Linear search with helper\n";
	cout << "Press 16 for Binary search\n";
	cout << "Press 17 for Bubble Sort for vector\n";
	cout << "Press 18 for Bubble sort for array\n";
	cout << "Press 19 for Selection sort for array\n";
	cout << "Press 20 for Selection sort for vector\n";
	cout << "Press 21 for Insertion sort for array \n";
	cout << "Press 22 for Insertion sort for vector\n";
	cout << "Press 23 for SlowPower\n";
	cout << "Press 24 for FastPower\n";
	cout << "Press 25 for Slow Multiplication\n";
	cout << "Press 26 for Fast Multiplication\n";
	cout << "Press 27 to get Slow Quotient and Remainder \n";
	cout << "Press 28 to get Fast Quotient and Remainder \n";
	cout << "press 29 Exit\n";
}
void initialVector(vector <int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 10;
	}
}
void printVector(vector <int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
void printarray(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void main()
{
	int option  = 0, num = 0, num2 = 0 , num3 = 0, size = 10;
	vector <int> v(10, -1);
	int arr[10] = { 5, 1, 2, 3, 5, 10, 11, 21, 7 , 9 };
	menu();
	while (true)
	{
		cout << "Enter Option : ";
		cin >> option;
		if (option == 1)
		{
			cout << "Enter No to get fib: ";
			cin >> num;
			cout << fib_rec(num) << "\n";
		}
		else if (option == 2)
		{
			cout << "Enter No to get fib: ";
			cin >> num;
			cout << fibonacci(num) << "\n";
		}
		else if (option == 3)
		{
			cout << "Enter No to get fib: ";
			cin >> num;
			cout << fib_mem(num) << "\n";
		}
		else if (option == 4)
		{
			cout << "Enter No to get Trisum: ";
			cin >> num;
			cout << Trisum(num) << "\n";
		}
		else if (option == 5)
		{
			cout << "Enter No to get Trisum: ";
			cin >> num;
			cout << TS_mem(num) << "\n";
		}
		else if (option == 6)
		{
			cout << "Enter No to get Nth Sum: ";
			cin >> num;
			cout << Nth_sum(num) << "\n";
		}
		else if (option == 7)
		{
			cout << "Enter No to get Nth Odd sum ";
			cin >> num;
			cout << Nth_sum_odd(num) << "\n";
		}
		else if (option == 8)
		{
			cout << "Enter No to get 2 power N ";
			cin >> num;
			cout << two_pow_sum(num) << "\n";
		}
		else if (option == 9)
		{
			cout << "Enter No to get 3 power N ";
			cin >> num;
			cout << three_pow_sum(num) << "\n";
		}
		else if (option == 10)
		{
			cout << "Enter No to get N/3 Sum ";
			cin >> num;
			cout << three_pow_div(num) << "\n";
		}
		else if (option == 11)
		{
			cout << "Enter No to get N/2 Sum ";
			cin >> num;
			cout << two_pow_div(num) << "\n";
		}
		else if (option == 12)
		{
			cout << "Enter N and R to get Permutation ";
			cin >> num >> num2 ;
			cout << permutation(num,num2) << "\n";
		}
		else if (option == 13)
		{
			cout << "Enter N and R to get Combinations ";
			cin >> num >> num2;
			cout << combination(num, num2) << "\n";
		}
		else if (option == 14)
		{
			cout << "Enter Value u want to search ";
			cin >> num;
			num2 = linearSearch_sizeShrinking(v, v.size() - 1, num);
			if (num2 != -1)
				cout << "Value found at index " << num2<<endl;
			else
				cout << "Value Not found "<< endl;
		}
		else if (option == 15)
		{
			initialVector(v);
			printVector(v);
			cout << "Enter Value u want to search ";
			cin >> num;
			num2 = linearSearch_helperwala(v, v.size() - 1, num);
			if (num2 != -1)
				cout << "Value found at index " << num2 << endl;
			else
				cout << "Value Not found " << endl;
		}
		else if (option == 16)
		{
			initialVector(v);
			BubbleSortRec(v);
			printVector(v);
			cout << "Enter Value u want to search ";
			cin >> num;
			num2 = b_search_element(v,0, v.size() - 1, num);
			if (num2 != -1)
				cout << "Value found at index " << num2 << endl;
			else
				cout << "Value Not found " << endl;
		}
		else if (option == 17)
		{
			initialVector(v);
			cout << "Before Sorting \n";
			printVector(v);
			BubbleSortRec(v);
			cout << "After Sorting \n";
			printVector(v);
		}
		else if (option == 18)
		{
			cout << "Before Sorting \n";
			printarray(arr,size);
			BubbleSortRec_array(arr,size);
			cout << "After Sorting \n";
			printarray(arr,size);
		}
		else if (option == 19)
		{
			cout << "Before Sorting \n";
			printarray(arr, size);
			selectionSort(arr, size);
			cout << "After Sorting \n";
			printarray(arr, size);
		}
		else if (option == 20)
		{
			initialVector(v);
			cout << "Before Sorting \n";
			printVector(v);
			selectionSort_vec(v);
			cout << "After Sorting \n";
			printVector(v);
		}
		else if (option == 21)
		{
			cout << "Before Sorting \n";
			printarray(arr, size);
			insertionSort_arr(arr, size);
			cout << "After Sorting \n";
			printarray(arr, size);
		}
		else if (option == 22)
		{
			initialVector(v);
			cout << "Before Sorting \n";
			printVector(v);
			insertionSort_vector(v);
			cout << "After Sorting \n";
			printVector(v);
		}
		else if (option == 23)
		{
			cout << "Enter Base and Power and Modulo to get total : ";
			cin >> num >> num2 >> num3;
			cout << slowPower(num, num2, num3)<<endl;
		}
		else if (option == 24)
		{
			cout << "Enter Base and Power and Modulo to get total : ";
			cin >> num >> num2 >> num3;
			cout << fastPower(num, num2, num3) << endl;
		}
		else if (option == 25)
		{
			cout << "Enter two values to multiple ";
			cin >> num >> num2;
			cout << slowMul(num, num2) << endl;
		}
		else if (option == 26)
		{
			cout << "Enter two values to fast multiple ";
			cin >> num >> num2;
			cout << fastMul(num, num2) << endl;
		}
		else if (option == 27)
		{
			long long q = 0, r = 0;
			cout << "Enter two values to get Quotient and Remainder ";
			cin >> num >> num2;
			r = num;
			slowQuotientAndRemainder(q,r,num, num2);
			cout << " Quotient = " << q << " Remainder = " << r << "\n";

		}
		else if (option == 28)
		{
			long long q = 0, r = 0;
			cout << "Enter two values to get Quotient and Remainder ";
			cin >> num >> num2;
			r = num;
			fastQuotientAndRemainder(q, r, num, num2);
			cout << " Quotient = " << q << " Remainder = " << r << "\n";
		}
		else
		{
			break;
		}
	}
}