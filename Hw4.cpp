#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
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
void printarray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

class Node
{
public:
	Node* next;
	int data;
};
class LinkedList
{
private:
	int length;
	Node *head;
	Node *tail;
public:
	LinkedList();
	~LinkedList();
	void add(int data);
	void print();
	int getSize();
	void setSize();
	Node *getHead();
	void setHead(Node *);
	Node *getTail();
	void setTail(Node *);
};
LinkedList::LinkedList(){
	this->length = 0;
	this->head = NULL;
	this->tail = NULL;
}
LinkedList::~LinkedList(){
	this->head = NULL;
	this->tail = NULL;
	/*std::cout << "LIST DELETED\n";*/
}
void LinkedList::add(int data){
	Node* node = new Node();
	node->data = data;
	node->next = NULL;
	if (this->head == NULL)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		this->tail->next = node;
		this->tail = node;
	}
	this->length++;
}
int LinkedList::getSize()
{
	return length;
}
void LinkedList::setSize()
{
	length++;
}
Node * LinkedList::getHead()
{
	return head;
}
void LinkedList::setHead(Node *n)
{
	this->head = n;
}
Node *LinkedList::getTail()
{
	return tail;
}
void LinkedList::setTail(Node *n)
{
	this->tail = n;
}
void LinkedList::print(){
	Node* temp = this->head;
	int i = 1;
	while (temp){
		cout << i << ": " << temp->data << endl;
		temp = temp->next;
		i++;
	}
}
void mergeLinkedList(LinkedList & obj, LinkedList & L, LinkedList & R)
{
	Node *tempL = L.getHead(), *tempR = R.getHead(), *tempObj = obj.getHead();
	int as = L.getSize();
	int bs = R.getSize();
	int ai = 0, bi = 0;
	int cs = as + bs;
	if (tempL->data < tempR->data)
	{
		obj.setHead(tempL);
		tempObj = obj.getHead();
		tempL = tempL->next;
		ai++;
	}
	else
	{
		obj.setHead(tempR);
		tempObj = obj.getHead();
		tempR = tempR->next;
		bi++;
	}
	for (int i = 1; i < cs; i++)
	{
		if (bi == bs || (as > ai && tempL->data<tempR->data))
		{

			tempObj -> next = tempL;
			tempObj = tempL;
			tempL = tempL->next;
			ai++;
		}
		else
		{
			tempObj->next = tempR;
			tempObj = tempR;
			tempR = tempR->next;
			bi++;
		}
	}
	obj.setTail(tempObj);
}
void mergeSortLinkedList(LinkedList &obj)
{
	int size = obj.getSize();
	if (size > 1)
	{
		LinkedList L, R;
		Node *temp;
		L.setHead(obj.getHead());
		L.setSize();
		temp = L.getHead();
		for (int i = 1; i < size/2; i++)
		{
			temp = temp->next;
			L.setSize();
		}
		L.setTail(temp);
		temp = temp->next;
		L.getTail()->next = NULL;
		R.setHead(temp);
		R.setSize();
		for (int i = size / 2 + 1; i < size; i++)
		{
			temp = temp->next;
			R.setSize();
		}
		R.setTail(temp);
		mergeSortLinkedList(L);
		mergeSortLinkedList(R);
		mergeLinkedList(obj, L, R);
	}
}

void Copy(int *des, int *res, int size)
{
	for (int i = 0; i < size; i++)
	{
		des[i] = res[i];
	}
}
void merge(int c[], int &cs, int a[], int as, int b[], int bs)
{
	int ai = 0, bi = 0;
	cs = as + bs;
	for (int i = 0; i < cs; i++)
	{
		if (bi == bs||(as > ai && a[ai]<b[bi]))
		{
			c[i] = a[ai];
			ai++;
		}
		else
		{
			c[i] = b[bi];
			bi++;
		}
	}
}
void mergeSort(int a[], int size)
{
	if (size > 1)
	{
		int *L = new int[size / 2];
		int *R = new int[size - size / 2];
		Copy(L, a, size / 2);
		Copy(R, a + size / 2, size - size / 2);
		mergeSort(L, size / 2);
		mergeSort(R, size - size / 2);
		merge(a, size, L, size / 2, R, size - size / 2);
	}
}
vector<int>* mergeVector(vector<int> &a, vector<int> &b)
{
	int size = a.size() + b.size();
	vector<int> *c = new vector<int>(size);
	int ai = 0, bi = 0;
	for (int i = 0; i < size; i++)
	{
		if (bi == b.size() || (a.size() > ai && a[ai]<b[bi]))
		{
			c->at(i) = a[ai];
			ai++;
		}
		else
		{
			c->at(i) = b[bi];
			bi++;
		}
	}
	return c;
}
void mergeSortvector(vector<int>&a)
{
	if (a.size() > 1)
	{
		vector<int> L(a.begin(),a.begin()+a.size()/2);
		vector<int> R(a.begin() + a.size() / 2, a.end());
		mergeSortvector(L);
		mergeSortvector(R);
		a = *mergeVector(L,R); 
	}
}

void initalizeMatrix(vector<vector <int>>& arr,int num)
{
	int val = num * num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			arr[i][j] = val;
			val--;
		}
		val--;
	}
}
void display(vector<vector <int>>& arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
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
		if (arr[m] < value)
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
void SearchInMatrix(vector<vector <int>>& arr, int num,int val)
{
	int check = 0;
	for (int i = 0; i < num; i++)
	{
		check = b_search_element(arr[i], 0, num - 1, val);
		if (check != -1)
		{
			cout << "Value found in Row : "<< i + 1 << " and Col : " << check + 1<<"\n";
			return;
		}
	}
	cout << "Value not Found\n";
}

void SearchInMatrixN(vector<vector <int>>& arr, int num, int val)
{
	int i = 0, j = num - 1;
	while (i < num && j >= 0)
	{
		if (arr[i][j] == val)
		{
			cout << "Value found in Row : " << i + 1 << " and Col : " << j + 1 << "\n";
			return;
		}
		else if (arr[i][j]<num)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
}
void question4()
{
	cout << "A : N log(N)\n";
	cout << "B : N log(N)\n";
	cout << "C : N log(N)\n";
	cout << "D : N^2 log(N)\n";
	cout << "E : N^2 log(N)\n";
	cout << "F : N^14 log(N)\n";

}


long long determinant(vector<vector<int>>mat, int n)
{
	static int d = 0;
	int c = 0, sub_i = 0, i = 0, j = 0, sub_j = 0;
	vector< vector<int> > sub_matrix(n, vector<int>(n));
	if (n == 1 || n == 0)
	{
		return 0;
	}
	if (n > 2)
	{
		for (c = 0; c < n; c++)
		{
			sub_i = 0;
			for (i = 1; i < n; i++)
			{
				sub_j = 0;
				for (j = 0; j < n; j++)
				{
					if (j == c)
					{
						continue;
					}
					sub_matrix[sub_i][sub_j] = mat[i][j];
					sub_j++;
				}
				sub_i++;
			}
			d = d + (pow(-1, c) * mat[0][c] * determinant(sub_matrix, n - 1));
		}
	}
	else
	{
		return((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
	}
	return d;
}//help from Google

void helper(vector<int>&A, int t, int s, int e)
{
	int si = s, ei = e;
	while (ei - si >= 0)
	{
		if (A[si] >= t && A[ei] <= t && A[si] != A[ei])
		{
			swap(A[si], A[ei]);
			//si++;
		}
		else if (A[si] <= t)
		{
			si++;
		}
		else if (A[ei] > t)
		{
			ei--;
		}
	}
}
void Segregation_s_m_l(vector<int>&A, int t, int s, int e)
{
	int si = s, ei = e;
	while (ei - si >= 0)
	{
		if (A[si] >= t && A[ei] <= t && A[si] != A[ei])
		{
			swap(A[si], A[ei]);
		}
		else if (A[si] < t)
		{
			si++;
		}
		else if (A[ei] >= t)
		{
			ei--;
		}
	}
	helper(A, t, si, e);
}
void Segregation(vector <int>& arr)
{
	int i = 0, j = 0;
	while (j < arr.size())
	{
		if (arr[i] == 1 && arr[j] == 0)
		{
			swap(arr[i], arr[j]);
			i++;
		}
		else if (arr[i] == 1 && arr[j] == 1)
		{
			j++;
		}
		else
		{
			i++, j++;
		}
	}
}
void Segregation_method2(vector <int>& arr)
{
	int i = 0, j = arr.size() - 1;
	while (j - i >= 0)
	{
		if (arr[i] == 1 && arr[j] == 0)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else if (arr[i] == 1 && arr[j] == 1)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
}
void SegregationEvenOdd(vector <int>& arr)
{
	int i = 0, j = 0;
	while (j < arr.size())
	{
		if (arr[i] % 2 == 1 && arr[j] % 2 == 0)
		{
			swap(arr[i], arr[j]);
			i++;
		}
		else if (arr[i] % 2 == 1 && arr[j] % 2 == 1)
		{
			j++;
		}
		else
		{
			i++, j++;
		}
	}
}
void read(ifstream &fin, vector<int>&arr)
{
	int val = 0;
	fin.open("data.txt", ios::in);
	while (fin >> val)
	{
		arr.push_back(val);
	}
}
void menu2()
{
	cout << "Question 1 Segregation (sort)\n";
	cout << "Question 2 Segregation (sort) Method 2\n";
	cout << "Question 3 Segregation (sort) with Range\n";
	cout << "Question 4 Segregation (sort) 0 1 2\n";
	cout << "Question 5 Segregation (sort) Even Odd\n";
}
void main2()
{
	vector<int> A({ 5, 5, 5, 1, 2, 3, 4, 11, 9, 2, 3 });
	vector<int> arr({0,1,0,1,0,1,0,1,0,1});
	vector<int> arr2({ 0, 1, 2, 0, 1, 2, 0, 1, 2 });
	vector<int> EO({ 0, 1, 2, 3, 4, 5, 6, 7, 8 });
	int op = 0, ch = 0, n = 0;
	ifstream fin;
	//read(fin, arr);//for Fike use this
	do
	{
		menu2();
		cout << "Enter Option : ";
		cin >> op;
		switch (op)
		{
		case 1:
			printVector(arr);
			Segregation(arr);
			printVector(arr);
			break;
		case 2:
			printVector(arr);
			Segregation_method2(arr);
			printVector(arr);
			break;
		case 3:
			printVector(A);
			cout << "Enter a number to set Vector smaller on left equal on mid or larger on left : ";
			cin >> n;
			Segregation_s_m_l(A, n, 0, A.size() - 1);
			printVector(A);
			break;
		case 4:
			printVector(arr2);
			Segregation_s_m_l(arr2, 1, 0, arr2.size() - 1);
			printVector(arr2);
			break;
		case 5:
			printVector(EO);
			SegregationEvenOdd(EO);
			printVector(EO);
			break;
		}
		cout << "press 0 to exit: ";
		cin >> ch;
	} while (ch != 0);
}

int Partition(vector<int>&A, int s, int e)
{	
	int si = s, ei = e;
	int ri = si + rand() % (ei - si + 1);
	int t = A[ri];
	while (ei - si >= 0)
	{
		if (A[si] >= t && A[ei] <= t && A[si] != A[ei])
		{
			swap(A[si], A[ei]);
			si++;
		}
		else if (A[si] < t)
		{
			si++;
		}
		else if (A[ei] >= t)
		{
			ei--;
		}
	}
	return si;
}
void Quicksort(vector<int>&arr, int si, int ei)
{
	int pi = 0;
	if (si >= ei)
		return;

	pi = Partition(arr, si, ei);
	Quicksort(arr, si, pi - 1);
	Quicksort(arr, pi + 1,ei);
}

int removeDuplicate(vector<int> &arr)
{
	int size = arr.size() - 1;
	if (size == 0 || size == 1)
		return size;

	int j = 0;

	for (int i = 0; i < size ; i++)
	if (arr[i] != arr[i + 1])
		arr[j++] = arr[i];

	arr[j++] = arr[size];

	return j;
}
void removeDuplicateLinkedList(LinkedList & obj)
{
	Node *temp = obj.getHead();
	while (true)
	{
		if (temp->next == NULL)
			break;
		if (temp->data == temp->next->data)
		{
			temp->next = temp->next->next;
		}
		temp = temp->next;
	}
}


int Partition2(vector<int>&A, int s, int e)
{
	int si = s, ei = e;
	int ri = (si + ei) /2;
	ri++;
	int t = A[ri];
	while (ei - si >= 0)
	{
		if (A[si] >= t && A[ei] <= t && A[si] != A[ei])
		{
			cout << "{(" << A[si] << "," << A[ei] << ")} \n";
			si++;
		}
		else if (A[si] < t)
		{
			si++;
		}
		else if (A[ei] >= t)
		{
			ei--;
		}
	}
	return si;
}
void Entropy(vector<int>&arr, int si, int ei)
{
	int pi = 0;
	if (si >= ei)
		return;

	pi = Partition2(arr, si, ei);
	Entropy(arr, si, pi - 1);
	Entropy(arr, pi + 1, ei);
}

int b_search_element(vector <int>&arr, int s, int e)
{
	if (s <= e)
	{
		int m = (s + e) / 2;
		if (arr[m] == m)
		{
			return m;
		}
		if (arr[m] > m)
		{
			return b_search_element(arr, s, m - 1);
		}
		else
		{
			return b_search_element(arr, m + 1, e);
		}
	}
	else
	{
		return -1;
	}
}
int binarySearch(vector<int>&arr)
{
	return b_search_element(arr, 0, arr.size() - 1);
}
void menu()
{
	cout << "Question 1 part a Press 1 for Merging two Sorted Arrays \n";
	cout << "Question 1 part b Press 2 for Merging two Sorted Vectors \n";
	cout << "Question 2 Press 3 for Merging with Linkedlist\n";
	cout << "Question 3 parta Press 4 for Merging N X N Matrix Search Value in O(N log N)\n";
	cout << "Question 3 part b Press 5 for Merging N X N Matrix Search Value in O(N)\n";
	cout << "Question 4 Press 6 \n";
	cout << "Question 5 Press 7 Matrix Determinant \n";
	cout << "Question 6 press 8 for Entropy with n log n\n";
	cout << "Question 7 Press 9 Segregation\n";
	cout << "Question 8 Press 10 QuickSort\n";
	cout << "QUestion 9 part a Press 11 for Remove Duplicate in O(N log n)\n";
	cout << "QUestion 9 part b Press 12 for Remove Duplicate from LinkedList Only take O(N)\n";
	cout << "Question 10 part 1 Search in Log N\n";
}


void main()
{
	int option = 0, num = 0, size = 10, val = 0;
	int arr[10] = {5,4,1,2,1,2,12,5,4,2};
	vector <int> v(arr, arr + 10);
	LinkedList obj , obj1 , obj2;
	while (true)
	{
		menu();
		cout << "Enter Option : ";
		cin >> option;
		if (option == 1)
		{
			printarray(arr, 4);
			mergeSort(arr, 4);
			printarray(arr, 4);
			//part 3 n log n is time complexity for merge sort
			//part 4 in bubble sort take n^2 time or merge sort it will take n log n
			// or n^2 >>>> n log n also in merge sort it will take 1 Tb extra memory 
		}
		else if (option == 2)
		{
			printVector(v);
			mergeSortvector(v);
			printVector(v);
			//N log n Is time complexity for linked list merge sort
		}
		else if (option == 3)
		{
			obj.add(2);
			obj.add(1);
			obj.add(4);
			obj.add(6);
			obj.add(2);
			obj.add(5);
			obj.add(10);
			obj.add(11);
			obj.add(10);
			obj.print();
			mergeSortLinkedList(obj);
			obj.print();
		}
		else if (option == 4)
		{
			cout << "Matrix Size : ";
			cin >> num;
			vector< vector<int> > matrix(num, vector<int>(num));
			initalizeMatrix(matrix, num);
			display(matrix, num);
			cout << "Which Value Index u want to get from given matrix : ";
			cin >> val;
			SearchInMatrix(matrix, num,val);
		}
		else if (option == 5)
		{
			cout << "Matrix Size : ";
			cin >> num;
			vector< vector<int> > matrix(num, vector<int>(num));
			initalizeMatrix(matrix, num);
			display(matrix, num);
			cout << "Which Value Index u want to get from given matrix : ";
			cin >> val;
			SearchInMatrixN(matrix, num, val);
		}
		else if (option == 6)
		{
			question4();
		}
		else if (option == 7)
		{
			cout << "Matrix Size : ";
			cin >> num;
			vector< vector<int> > matrix(num, vector<int>(num));
			initalizeMatrix(matrix, num);
			display(matrix, num);
			cout << "Determinant : "<< determinant(matrix,num)<<"\n";
		}
		else if (option == 8)
		{
			//part a N^2 sequence
			vector<int> A({ 3, 10, 2, 5, 12 });
			printVector(A);
			Entropy(A, 0, A.size() - 1);
		}
		else if (option == 9)
		{
			main2();
		}
		else if (option == 10)
		{
			printVector(v);
			Quicksort(v, 0, v.size() - 1);
			printVector(v);
			//part c Average is N log N or Worst Is N^2
		}
		else if (option == 11)
		{
			printVector(v);
			Quicksort(v, 0, v.size()-1);
			printVector(v);

			int sizee = removeDuplicate(v);
			for (int i = 0; i < sizee; i++)
			{
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		else if (option == 12)
		{
			obj.add(2);
			obj.add(1);
			obj.add(4);
			obj.add(6);
			obj.add(2);
			obj.add(5);
			obj.add(10);
			obj.add(11);
			obj.add(10);
			obj.print();
			mergeSortLinkedList(obj);
			obj.print();
			removeDuplicateLinkedList(obj);
			obj.print();
		}
		else if (option == 13)
		{
			vector <int> b({ -9, -7, -1, 0, 2, 3});
			cout << "Index : " << binarySearch(b)<<"\n";
		}
		else
		{
			break;
		}
	}
}



