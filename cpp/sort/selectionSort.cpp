#include <iostream>
#include <span>
#include <algorithm>
#include <cassert>

using namespace std;

size_t findSmallest(span<int> window)
{
	int smallest = 0;
	auto it = window.begin();
	size_t index = 0;
	for (; it != window.end(); ++it, ++index)
	{
		if (*it < window[smallest])
			smallest = index;
	}
	return smallest;
}

void selectionSort(span<int> window)
{
	int l = 0, N = window.size();

	assert(("Array cannot be empty.", !window.empty()));

	while (l < N - 1)
	{
		//smallest index in subspan [l...N-1]
		size_t smallest_index = findSmallest(window.subspan(l)) + l;// + l to counter offset from subspan implementation
		//swap
		int temp = window[l];
		window[l] = window[smallest_index];
		window[smallest_index] = temp;

		++l;
	}

}

int main()
{
	int a[]{ 2,1,7,5,3,6,0 };

	selectionSort(a);
	span<int> sorted(a);

	for_each(sorted.begin(), sorted.end(), [&](const auto& elem) {
		cout << elem << " "; });
	cout << endl;

	cin.get();
	return 0;
}