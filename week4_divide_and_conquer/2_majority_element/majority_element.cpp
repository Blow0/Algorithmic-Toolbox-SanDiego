#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int countFreq(vector<int>& a, int left, int right, int num)
{
	int count = 0;
	if (right == a.size())
		right--;
	for (int i = left; i <= right; i++)
	{
		if (num == a[i])
			count++;
	}
	return count;
}
int get_majority_element(vector<int>& a, int left, int right) {
	if (left == right) return a[left];
	if (left + 1 == right) return a[left];

	int med = (right - left) / 2 + left;
	int lo = get_majority_element(a, left, med);
	int hi = get_majority_element(a, med, right);

	if (lo == hi)
	{
		if (left == 0 && right == a.size())
		{
			if (lo = countFreq(a, left, right, lo) > right/2)
				return 1;
			return -1;
		}
		return lo;
	}

	else
	{
		int leftCount = countFreq(a, left, right, lo);
		int rightCount = countFreq(a, left, right, hi);
		if (left == 0 && right == a.size())
		{
			if (rightCount > right / 2 || leftCount > right / 2)
				return 1;
			return -1;
		}
		return (rightCount > leftCount ? hi : lo);
	}

	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
//	sort(a.begin(), a.end());

	std::cout << (get_majority_element(a, 0, n) != -1) << '\n';
}
