/**
 * Selection Sort : O(n^2)
 * -----------------------
 * 
 * It sorts an array by repeatedly finding the minimum element (ascending order), and putting it in the beginning
 * The Good Of The Selection Sort is it never makes more than O(n) swaps
 * and can be useful when memory write is a costly operation.
 */

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

void SelectionSort(vector<int>& Arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] < Arr[min])
				min = j;
		}
		swap<int>(Arr[i], Arr[min]);
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
	SelectionSort(Arr, n);
	cout << "after sort" << endl;
	for (auto i : Arr)
		cout << i << " ";
	cout << endl;
	return 0;
}

