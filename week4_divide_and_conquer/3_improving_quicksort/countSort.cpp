//Count sort is
// running time: O(n)
// we use it when we know the range of values in the array we count how many duplicates of each value then 
// sort them

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

void CountSort(vector<int>& Arr, int m)
{
	vector<int> Count(m + 1);
	for (int i = 0; i < m + 1; i++)
		Count[i] = 0;
	for (int i = 0; i < Arr.size(); i++)
	{
		Count[Arr[i]] += 1;
	}
	int j = 1;
	int stop = Count[j];
	for (int i = 0; i < Arr.size(); i++)
	{
		if (i < stop)
			Arr[i] = j;
		else
		{
			j++;
			if (j > m)
				break;
			stop += Count[j];
			i--;
		}
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
	CountSort(Arr, 3);
	cout << "after sort" << endl;
	for (auto i : Arr)
		cout << i << " ";
	cout << endl;

	return 0;
}

