//Merge sort is a divide and conquer algorithm with
// running time: O(nlogn)
//Basically we divide the array into halves sort them then merge the two halves by sorting them.

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Merge(vector<int>& Arr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	vector<int> merged(Arr.size());
	while (i <= m && j <= r)
	{
		if (Arr[i] < Arr[j])
		{
			merged[k] = Arr[i];
			k++; i++;
		}
		else
		{
			merged[k] = Arr[j];
			k++;  j++;
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
	}
}

void MergeSort(vector<int>& Arr, int l, int r)
{
	if (r == l)
		return;
	if (r > l)
	{
		int m = (r - l) / 2 + l;
		MergeSort(Arr, l, m);
		MergeSort(Arr, m + 1, r);
		Merge(Arr, l, m, r);
	}

}

int main(void)
{
	int n; cin >> n;
	vector<int> Arr(n);
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	cout << "before sort" << endl;
	for (auto i : Arr)
		cout << i << " ";
	cout << endl;
	MergeSort(Arr, 0, n - 1);
	cout << "after sort" << endl;
	for (auto i : Arr)
		cout << i << " ";
	cout << endl;

	return 0;
}

