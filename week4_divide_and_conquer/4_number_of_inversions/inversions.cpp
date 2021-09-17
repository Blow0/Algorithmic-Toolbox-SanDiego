//Merge sort is a divide and conquer algorithm with
// running time: O(nlogn)
//Basically we divide the array into halves sort them then merge the two halves by sorting them.

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Merge(vector<int>& Arr, int l, int m, int r)
{
	int num = 0;
	int i = l, j = m + 1, k = l;
	vector<int> merged(Arr.size());
	while (i <= m && j <= r)
	{
		if (Arr[i] <= Arr[j])
		{
			merged[k++] = Arr[i++];
		}
		else
		{
			merged[k++] = Arr[j++];
			num+= m - i + 1;
		}
 	}
	while (j <= r)
	{
		merged[k] = Arr[j];
		j++; k++;
	}
	while (i <= m)
	{
		merged[k] = Arr[i];
		i++; k++;
	}
	for (int i = l; i <= r; i++)
	{
		Arr[i] = merged[i];
		//num++;
	}
	return num;
}

int MergeSort(vector<int>& Arr, int l, int r)
{
	if (r == l)
		return 0;
	int num = 0;
	if (r > l)
	{
		int m = (r - l) / 2 + l;
		//int m = l;
		num = MergeSort(Arr, l, m);
		num += MergeSort(Arr, m + 1, r);
		num += Merge(Arr, l, m, r);
	}
	return num;

}

int main(void)
{
	int n; cin >> n;
	vector<int> Arr(n);
	vector<int> B(n);
	for (int i = 0; i < n; i++)
		cin >> Arr[i];

	cout << MergeSort(Arr, 0, n - 1) << endl;

	return 0;
}

