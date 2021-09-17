#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
typedef std::pair<int, int> pair;

struct Segment 
{
	int start, end;
};

vector<int> optimal_points(vector<pair>& v) {
	vector<int> points;
	//write your code here
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i].second > v[j].first) //intersecting
			{
				v[i].first = std::max<int>(v[i].first, v[j].first);
				v[i].second = std::min<int>(v[i].second, v[j].second);
			}
		}
	}

	for (size_t i = 0; i < v.size() && i != v.size() - 1; i += 2) {
	//	points.push_back(v[i].first);
		points.push_back(v[i].second);
	}
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<pair> v(n);
	for (size_t i = 0; i < v.size(); ++i) {
		std::cin >> v[i].first >> v[i].second;
	}
	std::sort(v.begin(), v.end());
	vector<int> points = optimal_points(v);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
	return 0;
}
