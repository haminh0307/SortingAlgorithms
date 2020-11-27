// 0-based
void InsertionSort(int arr[], int n)
{
	int tmp, j;
	for (int i = 1; i < n; ++i) {
		j = i - 1;
		tmp = arr[i];
		while (j >= 0 && tmp < arr[j]) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = tmp;
	}
}