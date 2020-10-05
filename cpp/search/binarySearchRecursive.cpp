#include <iostream>
#include <algorithm>
#include <span>

using namespace std;


template <typename T>
int binarySearchRecursive(T* arr, int l, int r, int f)
{
	if (r < l) return -1;
	size_t mp = (1 + l + r) / 2;
	T& middle = arr[mp];
	if (middle == f) return mp;
	else if (middle < f)//find is larger than middle, search right half
		return binarySearchRecursive(arr,  mp + 1, r, f);
	else if (f < middle)//find is smaller than middle, search left half
		return binarySearchRecursive(arr, l, mp - 1, f);
}

template <typename T, size_t N, typename U >
int binarySearch(span<T, N> window, U find)
{
	sort(window.begin(), window.end(), less<U>());//will first sort the array
	return binarySearchRecursive(window.data(), 0, N - 1, find);
}

int main()
{
	{//case 0
		int a[] = { 5,4,6,2,1,3,7,0 };
		int ret = binarySearch(span{ a }, 5);

		cout << "Found at index (ascending sort): " << ret << endl;
	}
	cin.get();
	return 0;
}