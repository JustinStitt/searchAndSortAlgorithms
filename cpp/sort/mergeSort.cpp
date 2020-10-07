#include <iostream>
#include <span>

using namespace std;


	/*
		Merge Sort
	*/

int* interlace(span<int> lh, span<int> rh)
{
	const size_t N = lh.size() + rh.size();
	int* laced = new int[N];

	int index = 0, lhi = 0, rhi = 0;

	while (index < N)
	{
		if (lhi > lh.size() - 1)
			laced[index] = rh[rhi++];
		else if (rhi > rh.size() - 1)
			laced[index] = lh[lhi++];
		else
			laced[index] = (lh[lhi] < rh[rhi] ? lh[lhi++] : rh[rhi++]);
		++index;
	}
	return laced;
}

void mergeSort(span<int> window)
{
	if (window.size() == 1)
		return;
	size_t mp = window.size() / 2;
	span<int> lh = window.subspan(0, mp);
	span<int> rh = window.subspan(mp);
	mergeSort(lh);//sort left half (including midpoint)
	mergeSort(rh);//sort right half starting one after the midpoint
	//merge halves
	int* sorted = interlace(lh, rh);
	for (int x{}; x < window.size(); ++x)
		window[x] = sorted[x];
	delete[] sorted;
	return;
}

int main()
{
	const uint32_t N = 9;
	int a[]{ 8,2,5,7,6,1,0,3,4 };

	mergeSort(a);

	span<int> print(a);
	for (auto it = print.begin(); it != print.end(); ++it)
		cout << " " << *it;
	cout << endl;

	cin.get();
	return 0;
}