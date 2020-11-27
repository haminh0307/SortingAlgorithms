// 0-based
void Shellsort(int arr[], int n)
{
	int gap(1);
	while (gap < n / 3) {
		gap = gap * 3 + 1;
	}
	
	int x, j;
	while (gap) {
		for (int i = gap; i < n; ++i) {
			x = arr[i];
			for (j = i; j >= gap && arr[j - gap] > x; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = x;
		}
		
		gap /= 3;
	}
}