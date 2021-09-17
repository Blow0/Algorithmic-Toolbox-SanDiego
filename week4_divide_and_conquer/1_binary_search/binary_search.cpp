#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<long long >& a, long long x) {
	int left = 0, right = (int)a.size();
	//write your code here
	while (left <= right)
	{
		int med = (left + right) / 2;
		if (a[med] == x)
			return med;
		else if (x > a[med])
			left = med + 1;
		else if (x < a[med])
			right = med - 1;
	}
	return -1;
}

int linear_search(const vector<int>& a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<long long > a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
  size_t  m;
	std::cin >> m;
	vector<long long> b(m);
	for (size_t i = 0; i < m; ++i) {
		std::cin >> b[i];
	}
	for (size_t i = 0; i < m; ++i) {
		//replace with the call to binary_search when implemented
		std::cout << binary_search(a, b[i]) << ' ';
	}
}
