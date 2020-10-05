/*
	Linear Search
	https://www.geeksforgeeks.org/linear-search/

	to run: include 'Item Type' as C++ compiler build
*/
#include <iostream>
#include <array>
#include <span>
#include <cassert>

using namespace std;

size_t linearSearch(span<int> search_window, const int to_find);

int main()
{
	{//case 0: finds element
		const size_t N = 8;
		array<int, N> arr = { 7,2,-1,4,6,0,1,8 };

		size_t ret = linearSearch(arr, 4);
		cout << "Found at index: " << ret << endl;
	}
	{//case 1: doesnt find element (ret = arr.size())
		const size_t N = 8;
		array<int, N> arr = { 7,2,-1,4,6,0,1,8 };

		size_t ret = linearSearch(arr, 12);
		cout << "Found at index: " << ret << endl;
	}
	{//case 2: arr is empty
		const size_t N = 0;
		array<int, N> arr = {};

		size_t ret = linearSearch(arr, 6);
		cout << "Found at index: " << ret << endl;
	}

	cin.get();
	return 0;
}

size_t linearSearch(span<int> search_window, const int to_find)
{
	/*
		Linearly search through given array span 
		return: 0-based index corresponding to the 
		first occurence of 'to_find'
	*/
	assert(("Array cannot be empty",!search_window.empty()));//check to see if arr span is empty
	
	size_t index = 0;
	auto it = search_window.begin();
	for (; it != search_window.end(); ++it, ++index)
		if (*it == to_find)
			return index;
	return search_window.size();
}
