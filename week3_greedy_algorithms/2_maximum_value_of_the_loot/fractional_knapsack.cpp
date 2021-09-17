#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
int n;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
	double value = 0.0;
	double max = 0.0;
	vector<double> vwRatio(n);
	for (int i = 0; i < n; i++)
	{
		vwRatio[i] = (double)values[i] / weights[i];
	}
	while (capacity)
	{
		int i;
		int a = 0;
		for (i = 0; i < n; i++)
		{
			if (vwRatio[i] > max)
			{
				max = vwRatio[i];
				a = i;
			}
		}
		if (max == 0)
			break;
		if (capacity > weights[a])
		{
			value += weights[a] * vwRatio[a];
			capacity -= weights[a];
		}
		else
		{
			value += capacity * vwRatio[a];
			capacity = 0;
		}
		vwRatio[a] = 0.0;
		max = 0.0;
	}
	return value;
}

int main() {
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
