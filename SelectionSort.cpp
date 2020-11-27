// 0-based
void SelectionSort(int arr[], int n)
{
	int pos;
	for (int i = 0; i < n; ++i) {
		pos = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[pos]) {
				pos = j;
			}
		}
		
		if (pos != i) {
			swap(arr[pos], arr[i]);
		}
	}
}