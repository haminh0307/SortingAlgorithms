// 0-based
void ShakerSort(int arr[], int n)
{
	int l(0), r(n - 1), k(0);
	while (l < r) {
		for (int i = l; i < r; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				k = i;
			}
		}
		r = k;
		
		for (int i = r; i > l; --i) {
			if (arr[i] < arr[i - 1]) {
				swap(arr[i], arr[i - 1]);
				k = i;
			}
		}
		l = k;
	}
}