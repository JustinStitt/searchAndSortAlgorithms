#include <iostream>
#include <span>
#include <cassert>

using namespace std;

/*
	Quick Sort
*/

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];//set pivot to last element
	int slow = low - 1;//slow index starts at low - 1
	int fast = low;//fast index starts at low
	for (; fast < high ; ++fast)//[low...high-1]
	{
		if (arr[fast] <= pivot)
		{
			++slow;
			int tmp = arr[slow];//swap places of arr[slow] and arr[fast]
			arr[slow] = arr[fast];
			arr[fast] = tmp;
		}
	}
	//last swap to get pivot to its correct index
	++slow;
	int tmp = arr[slow];
	arr[slow] = arr[fast];
	arr[fast] = tmp;
	return slow;
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int partition_index = partition(arr, low, high);
		//quickSort left half
		quickSort(arr, low, partition_index - 1);
		//quickSort right half
		quickSort(arr, partition_index + 1, high);
	}
}

//helper function
void quickSort(span<int> window)
{
	int l = 0;
	int h = window.size();
	assert(("Array cannot be empty.\n", h > 0));
	quickSort(window.data(), l, h - 1);
}

int main()
{
	int a[]{ 2,7,1,3,8,4,0 };

	quickSort(a);

	cout << "After quickSort: " << endl;
	span<int> print(a);
	for (auto it = print.begin(); it != print.end(); ++it)
		cout << " " << *it;
	cout << endl;

	cin.get();
	return 0;
}