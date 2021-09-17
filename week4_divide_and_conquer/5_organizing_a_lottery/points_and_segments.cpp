//Merge sort is a divide and conquer algorithm with
// running time: O(nlogn)
//Basically we divide the array into halves sort them then merge the two halves by sorting them.

#include<iostream>
#include <algorithm>
#include <vector>
#include <map>
using std::map;
using namespace std;

int Merge(vector<pair<int, char>>& Arr, int l, int m, int r)
{
	int num = 0;
	int i = l, j = m + 1, k = l;
	vector<pair<int, char>> merged(Arr.size());
	while (i <= m && j <= r)
	{
		if (Arr[i].first <= Arr[j].first)
		{
			merged[k].first = Arr[i].first;
			merged[k++].second = Arr[i++].second;
			
		}
		else
		{
			merged[k].first = Arr[j].first;
			merged[k++].second = Arr[j++].second;
			num+= m - i + 1;
		}
	}
	while (j <= r)
	{
		merged[k].first = Arr[j].first;
		merged[k++].second = Arr[j++].second;
	}
	while (i <= m)
	{
		merged[k].first = Arr[i].first;
		merged[k++].second = Arr[i++].second;
	}
	for (int i = l; i <= r; i++)
	{
		Arr[i].first = merged[i].first;
		Arr[i].second = merged[i].second;
		//num++;
	}
	return num;
}

int MergeSort(vector<pair<int, char>>& Arr, int l, int r)
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

map<int, int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
	map<int, int> cnt;
	//write your code here
	vector<pair<int, char>> pairs(starts.size() + ends.size() + points.size());
	for (unsigned int i = 0; i < starts.size(); i++)
	{
		pairs[i].first = starts[i];
		pairs[i].second = 'l';
	}
	for (unsigned int i = 0; i < ends.size(); i++)
	{
		pairs[i + starts.size()].first = ends[i];
		pairs[i + starts.size()].second = 'r';
	}
	for (unsigned int i = 0; i < points.size(); i++)
	{
		pairs[i + starts.size() + ends.size()].first = points[i];
		pairs[i + starts.size() + ends.size()].second = 'p';
	}
	MergeSort(pairs, 0, pairs.size() - 1);
	int j = 0;
	int count = 0;
	for (int i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].second == 'l')
			count++;
		else if (pairs[i].second == 'r')
			count--;
		else
		{
			cnt.insert(pair<int, int>(pairs[i].first, count));
		}
	}
	return cnt;
}
int main() {
	int n, m;
	std::cin >> n >> m;
	vector<int> starts(n), ends(n);
	for (size_t i = 0; i < starts.size(); i++) {
		std::cin >> starts[i] >> ends[i];
	}
	vector<int> points(m);
	vector<int> segments(m);
	for (size_t i = 0; i < points.size(); i++) {
		std::cin >> points[i];
		segments[i] = points[i];
	}
	//use fast_count_segments
	map<int, int> cnt = fast_count_segments(starts, ends, points);
	
	for (size_t i = 0; i < segments.size(); i++) {
		map<int, int>::iterator itr = cnt.find(segments[i]);
		std::cout << itr->second << ' ';
	}
}
