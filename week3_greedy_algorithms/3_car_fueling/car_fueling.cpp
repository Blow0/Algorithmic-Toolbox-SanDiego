#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int>& stops)
{
	int minRefills = 0, nextStop = 0, temp = 0;

	while (dist - nextStop > tank)
	{
		temp = 0;
		for (int i = 0; i < stops.size(); i++)
			if (stops[i] - nextStop <= tank)
				temp = stops[i];
		
		if (temp <= nextStop)
			return -1;
		else
			nextStop = temp;

		minRefills++;

	}
	return minRefills;
}


int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
