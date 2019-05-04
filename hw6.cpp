#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<list>
#include<map>
using namespace std;
void towerOfHanoi(string src, string helper, string des, int slabs)//a b c
{
	if (slabs == 0){
		return;
	}
	towerOfHanoi(src, des , helper, slabs - 1);
	cout << "Slab " << slabs << " from Tower " << src << " to Tower " << des << endl;
	towerOfHanoi(helper, src , des, slabs - 1);
	return;
}
void towerOfHanoi2(string src, string helper, string des, int slabs)//a b c
{
	if (slabs == 0){
		return;
	}
	towerOfHanoi(src, helper , des , slabs - 1);
	cout << "Slab " << slabs << " from Tower " << src << " to Tower " << helper << endl;
	towerOfHanoi(des,helper,src, slabs - 1);
	cout << "Slab " << slabs << " from Tower " << helper << " to Tower " << des << endl;
	towerOfHanoi(src, helper, des , slabs - 1);
	return;
}
int detectRotation(vector<int>&arr , int si, int ei)
{
	if (ei < si)
		return 0;

	if (si == ei)
		return ei;

	int mid = (si + ei)/2;

	if (arr[si]<arr[mid] && arr[ei]>arr[mid])
		return 0;

	if (ei > mid && arr[mid + 1] < arr[mid])
		return (mid + 1);
	else if (si < mid && arr[mid - 1]>arr[mid])
		return mid;
	else if (arr[ei] < arr[mid])
		return detectRotation(arr, mid + 1, ei);
	else
		return detectRotation(arr, si, mid - 1);
}
int MaX(vector<int>&arr, int si, int ei)
{
	if (ei < si)
		return 0;

	if (si == ei)
		return ei;

	int mid = (si + ei) / 2;

	if (arr[si]<arr[mid] && arr[ei]>arr[mid])
		return arr[ei];

	if (ei > mid && arr[mid + 1] < arr[mid])
		return arr[mid];
	else if (si < mid && arr[mid - 1]>arr[mid])
		return arr[mid - 1];
	else if (arr[ei] < arr[mid])
		return MaX(arr, mid + 1, ei);
	else
		return MaX(arr, si, mid - 1);
}
void removeRotation(vector<int>&arr, int rCount)
{
	vector <int> temp(rCount);
	for (int i = 0; i < rCount; i++)
	{
		temp[i] = arr[i];
	}
	int j = 0, k = 0;
	for (int i = rCount; i < arr.size(); i++)
	{
		arr[j] = arr[i];
		j++;
	}
	for (int i = j; i < arr.size(); i++)
	{
		arr[i] = temp[k];
		k++;
	}
}
int getSum(vector<int>&arr, int si, int ei)
{
	int sum = 0;
	for (int i = si; i <= ei; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}
int GeneralizedVersionN3(vector <int> & arr, int si, int ei, int & ssi, int &sei)
{
	int max = arr[si];
	int subSum = 0;
	ssi = si;
	sei = si;
	for (int i = si; i <= ei; i++)
	{
		if (subSum > max)
		{
			max = subSum;
			ssi = i;
		}
		for (int j = i; j <= ei; j++)
		{
			subSum = getSum(arr, i, j);
			if (subSum > max)
			{
				max = subSum;
				ssi = i;
				sei = j;
			}
		}
	}
	return max;
}
int GeneralizedVersionN2(vector <int> & arr, int si, int ei, int & ssi, int &sei)
{
	int max = arr[si];
	int subSum = 0;
	ssi = si;
	sei = si;
	for (int i = si; i <= ei; i++)
	{
		subSum = 0;
		for (int j = i; j <= ei; j++)
		{
			subSum = subSum + arr[j];
			if (subSum > max)
			{
				max = subSum;
				ssi = i;
				sei = j;
			}
		}
	}
	return max;
}
void findMaxCrossingSubarray(vector<int >&arr ,int low,int mid ,int high , int &max_left,int &max_right,int &t_sum)
{
	int left_sum = -9999999;
	int sum = 0;
	for (int i = mid; i >= 0; i--)
	{
		sum = sum + arr[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = -9999999;
	sum = 0;
	for (int i = mid+1; i < high; i++)
	{
		sum = sum + arr[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	t_sum = left_sum + right_sum;
}
int right_low = 0, right_high = 0, right_sum = 0;
int left_low = 0, left_high = 0, left_sum = 0;
int cross_low = 0, cross_high = 0, cross_sum = 0;
int mid = 0;
void findMaxSubArray(vector<int >&arr, int low, int high, int & _low ,int & _high , int & _sum)
{
	if (low == high)
	{
		_low = low;
		_high = high;
		_sum = arr[low];
	}
	else
	{
		mid = (low + high) / 2;
		findMaxSubArray(arr, low, mid, left_low, left_high, left_sum);
		findMaxSubArray(arr, mid+1, high, right_low, right_high, right_sum);
		findMaxCrossingSubarray(arr, low, mid , high, cross_low, cross_high, cross_sum);
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			_low = left_low;
			_high = left_high;
			_sum = left_sum;
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum)
		{
			_low = right_low;
			_high = right_high;
			_sum = right_sum;
		}
		else
		{
			_low = cross_low;
			_high = cross_high;
			_sum = cross_sum;
		}
	}
}
int b_search_element(vector <int>&arr, int s, int e , int val)
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
			return b_search_element(arr, s, m - 1, m);
		}
		else
		{
			return b_search_element(arr, m + 1, e, m);
		}
	}
	else
	{
		return -1;
	}
}
void binarySearch(vector<int>&arr)
{
	if (b_search_element(arr, 0, arr.size() - 1 , 0) != -1)
		cout << "Found \n";
	else
		cout << "Not Found\n";
}
void logI(vector<int>&arr)
{
	if (arr[0] == 0)
	{
		cout << "Value found at " << 0 << "i th index :" << arr[0] << "\n";
		return;
	}

	int j = 0 , i = 1;
	while (i < arr.size())
	{
		
		if (arr[i] == i)
		{
			cout << "Value found at " << i << "i th index :" << arr[i] << "\n";
			return;
		}
		else if (arr[i] > i)
		{
			break;
		}
		else
		{
			j = i;
			i *= 2;
		}
	}
	if (i < arr.size())
	{
		int index = b_search_element(arr, j, i ,0);
		if (index != -1)
			cout << "Found at index "<<index<<"\n";
		else
			cout << "Not Found\n";
		return;
	}
	else
	{
		return;
	}
}
void Print(vector <int >&arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
void findPairUnSorted(vector<int>&arr, int val)
{
	int i = 0, j = arr.size() - 1;
	sort(arr.begin(), arr.end());
	Print(arr);
	while (i < j)
	{
		if (arr[i] + arr[j] < val)
		{
			i++;
		}
		else if (arr[i] + arr[j] == val)
		{
			cout << "Indexes are " << i << " and " << j << " \n";
			break;
		}
		else
		{
			j--;
		}
	}
}
void findPairSorted(vector<int>&arr, int val)
{
	int i = 0, j = arr.size() - 1;
	sort(arr.begin(), arr.end());
	Print(arr);
	while (i < j)
	{
		if (arr[i] + arr[j] < val)
		{
			i++;
		}
		else if (arr[i] + arr[j] == val)
		{
			cout << "Indexes are " << i << " and " << j << " \n";
			break;
		}
		else
		{
			j--;
		}
	}
}
void overLappingUnSorted(vector <int> &A, vector <int> &B, list <int> &common)
{
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int size = 0;
	if (A.size() > B.size())
	{
		size = A.size();
	}
	else
	{
		size = B.size();
	}
	for (int i = 0; i < size; i++)
	{
		if (binary_search(A.begin(), A.end(), B[i]))
		{
			common.push_back(B[i]);
		}
	}
}
void overLappingSorted(vector <int> &A, vector <int> &B, list <int> &common)
{
	int inA = 0, inB = 0;
	while (inA < A.size() && inB < B.size())
	{
		if (A[inA] < B[inB])
		{
			inA++;
		}	
		else if (A[inA] > B[inB])
		{
			inB++;
		}
		else
		{
			common.push_back(B[inB]);
			inA++;
			inB++;
		}
	}
}
int binarySEARCH(vector <int>&arr, int s, int e , int val)
{
	if (s <= e)
	{
		int m = (s + e) / 2;
		if (arr[m] == val)
		{
			return m;
		}
		if (arr[m] > m)
		{
			return binarySEARCH(arr, s, m - 1, val);
		}
		else
		{
			return binarySEARCH(arr, m + 1, e, val);
		}
	}
	else
	{
		return -1;
	}
}
void sumChecker(vector<int>& a, vector<int>& b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int size = 0;
	int aSum = 0, bSum = 0;
	for (int k = 0; k < a.size(); k++)
	{
		aSum += a[k];
	}
	for (int k = 0; k < b.size(); k++)
	{
		bSum += b[k];
	}
	if (a.size() > b.size())
	{
		size = b.size();
	}
	else
	{
		size = a.size();
	}
	int i = 0, j = 0 , k = 0;
	while (i < a.size())
	{
		j = binarySEARCH(b,0,b.size()-1 ,a[i]);
		if (j != -1)
		{
			if (aSum - a[i] + b[j] && bSum - b[j] + a[i])
			{
				cout << "Swap " << a[i] << " from A and swap " << b[j] << " From B sum of both the vector remains same\n";
			}
		}
		j = 0;
		i++;
	}
}

void menu()
{
	cout << "1 Q1\n";
	cout << "2 Q2\n";
	cout << "3 Q3\n";
	cout << "4 Q4\n";
	cout << "5 Q5\n";
	cout << "7 Q7\n";
	cout << "8 Q8\n";
}	
void main()
{
	int op = 0, ch = 0, slabs = 0, rCount = 0, si = 0, ei = 0, ssi = 0, sei = 0, sum = 0, val = 0, temp = 0;
	string A = "A", B = "B", C = "C";
	vector <int> Arr0({ 1, 3, 4, 2, 53, 1, 3, 6, 2, 6, 7 });
	vector <int> arr({ 8, 9, 10, 1, 2, 3, 4, 5, 6, 7 });
	vector <int> arr2({ 2, 3, -6, 1, 5, -10, 7 });
	vector <int> arr3({ -2, -1, 0, 2, 3, 7 });
	vector <int>arr4;
	vector<int>Aa({ 1, 2, 3, 4, 5, 6 });
	vector<int>Bb({ 4, 5, 6 });
	list <int >l, l2;
	vector<vector<int>>  Num{ { { 7, 8, 9 }, { 1, 2, 3 } } };
	int N = 0, K = 0;
	map<int, int> Maps;
	vector<int> mArr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 6, 4, 2, 1, 5, 7, 8, 3, 2, 5, 7, 9, 1, 5, 2, 4, 3, 9, 8, 7, 1, 4, 3 };
	vector<int>a({ 1, 2, 1, 2, 5, 9 }), b({ 14, 2, 3, 1 });
	int value = 7;
	do
	{
		menu();
		cout << "Enter Option : ";
		cin >> op;
		switch (op)
		{
			case 1:
				cout << "Enter the number of rings : ";
				cin >> slabs;
				towerOfHanoi(A, B, C, slabs);
				cout << "2nd Approch\n";
				towerOfHanoi2(A, B, C, slabs);
				break;
			case 2:
				cout << "Enter Value :\t";
				cin >> val;
				findPairUnSorted(arr, val);
				sort(Arr0.begin(), Arr0.end());
				findPairSorted(Arr0, val);
				overLappingUnSorted(arr, Arr0, l);
				cout << "Same Elements are : ";
				for (auto iterator = l.begin(); iterator != l.end(); iterator++)
				{
					cout << " " << *iterator;
				}
				cout << "\n";
				overLappingSorted(Aa, Bb, l2);
				cout << "Same Elements are: ";
				for (auto iterator = l2.begin(); iterator != l2.end(); iterator++)
				{
					cout << " " << *iterator;
				}
				cout << "\n";
				break;
			case 3:
				while (K < mArr.size())
				{
					if (Maps.find(mArr[K]) == Maps.end())
					{
						Maps[mArr[K]] = 1;
					}
					else
					{
						Maps[mArr[K]]++;
					}
					K++;
				}
				cout << "Sorted array is :\t";
				for (map<int ,int >::iterator it = Maps.begin(); it != Maps.end(); ++it)
				{
					temp = it->second;
					for (int i = 0; i < temp; i++)
					{
						cout << it->first << " ";
					}
				}
				cout << "\n";
				break;
			case 4:
				rCount = detectRotation(arr, 0, arr.size() - 1);
				cout << "Rotation Count = " << rCount << "\n";
				cout << "Max = " << MaX(arr, 0, arr.size() - 1) << "\n";
				removeRotation(arr, rCount);
				Print(arr);
				break;
			case 5:
				cout << GeneralizedVersionN3(arr2, si, arr2.size() - 1, ssi, sei) << "\n";
				cout << ssi << " " << sei << "\n";
				cout << GeneralizedVersionN2(arr2, si, arr2.size() - 1, ssi, sei) << "\n";
				cout << ssi << " " << sei << "\n";
				findMaxSubArray(arr2, 0, arr2.size() - 1, ssi, sei, sum);
				cout << ssi << " " << sei << "\n";
				break;
			case 7:
				binarySearch(Aa);
				for (int i = 0; i < 10000; i++)//TEST CASE for log I
				{
					if (i == 1023)
					{
						arr4.push_back(1023);
						arr4.push_back(1025);
						i++;
					}
					else
						arr4.push_back(i - 1);
				}
				logI(arr4);
				break;
			case 8:
				sumChecker(a, b);
				break;
			}
		cout << "press 0 to exit: ";
		cin >> ch;
	}
	while (ch != 0);
	return;
}