#include <iostream>
#include <span>
#include <algorithm>
#include <cassert>

using namespace std;


void linearSort(span<int> window)//O(N^2) time. in-place space.
{

	const size_t N = window.size();
	assert(("Array cannot be empty.", !window.empty()));

	for (int x{}; x < N - 1; ++x)
		for (int y{}; y < N - 1; ++y)
			if (window[y] > window[y + 1])
			{
				int temp = window[y];
				window[y] = window[y + 1];
				window[y + 1] = temp;
			}
}

int main()
{
	int a[]{ 2,3,1,7,5,4,6,0 };
	linearSort(a);

	span<int> sorted(a);
	for_each(sorted.begin(), sorted.end(), [&](const auto& elem) {
		cout << elem << " "; });
	cout << endl;

	cin.get();
	return 0;
}