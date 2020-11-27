// 0-based
void BinaryInsertionSort(int arr[], int n)
{
	int tmp, l, r, mid;
	for (int i = 1; i < n; ++i) {
		tmp = arr[i];
		// BinarySearch in [l, r]
		l = 0; r = i;
		while (r > l) {
			mid = (l + r) / 2;
			if (arr[mid] > tmp) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		for (r = i; r > l; --r) {
			arr[r] = arr[r - 1];
		}
		arr[l] = tmp;
	}
}