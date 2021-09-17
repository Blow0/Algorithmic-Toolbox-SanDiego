//Count sort is
// running time: O(n)


#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

pair<int, int> partition3(vector<int>& arr, int l, int r, int k)
{
	int x = arr[l];
	pair<int, int> p;
	p.first = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (arr[i] <= x)
		{
			p.first++;
			swap(arr[i], arr[p.first]);
		}
	}
	swap(arr[p.first], arr[l]);
	p.second = p.first;
	for (int i = l; i < p.first && p.second > i;)
	{
		if (arr[i] == x)
			swap(arr[i], arr[--p.second]);
		else
			i++;
	}
	return p;
}

void QuickSort(vector<int>& arr, int l, int r)
{
	if (l >= r)
		return;
	srand(0);
	int k = (rand() % (r - l + 1)) + l;
	swap(arr[k], arr[l]);
	pair<int, int> p;
	p = partition3(arr, l, r, k);

	QuickSort(arr, l, p.second - 1);
	QuickSort(arr, p.first + 1, r);
}

int main(void)
{
	int n; cin >> n;
	vector<int> Arr(n);
	for (int i = 0; i < n; i++)
		cin >> Arr[i];
	QuickSort(Arr, 0, Arr.size() - 1);
	for (auto i : Arr)
		cout << i << " ";
	cout << endl;

	return 0;
}

