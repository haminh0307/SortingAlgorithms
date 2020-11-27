// 0-based
void Sift(int arr[], int l, int r)
{
	int x(arr[l]);
	int i(2 * l + 1);
	while (i <= r) {
		if (i < r && arr[i] < arr[i + 1]) {
			++i;
		}
		if (x >= arr[i]) return;
		
		arr[l] = arr[i];
		l = i; i = 2 * l + 1;
	}
	arr[l] = x;
}

void Heapsort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i) {
		Sift(arr, i, n - 1);
	}
	
	for (int i = n - 1; i >= 1; --i) {
		swap(arr[0], arr[i]);
		Sift(arr, 0, i - 1);
	}
}