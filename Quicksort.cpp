// 0-based
void Quicksort(int arr[], int l, int r)
{
	if (l >= r) return;
	
	int i(l), j(r), pivot(arr[(i + j) / 2]);
	do {
		while (arr[i] < pivot) ++i;
		while (arr[j] > pivot) --j;
		if (i <= j) {
			if (i < j) {
				swap(arr[i], arr[j]);
			}
			++i;
			--j;
		}
	} while (i <= j);
	QuickSort(arr, l, j);
	QuickSort(arr, i, r);
}