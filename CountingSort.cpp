// 0-based
void CountingSort(int arr[], int n)
{
	int amax(arr[0]), amin(arr[0]);
	for (int i = 1; i < n; ++i) {
		amax = max(amax, arr[i]);
		amin = min(amin, arr[i]);
	}
	
	int* F = new int[amax - amin + 1]{0};
	for (int i = 0; i < n; ++i) {
		++F[arr[i] - amin];
	}
	
	for (int i = 1; i <= amax - amin; ++i) {
		F[i] += F[i - 1];
	}
	
	int* res = new int[n];
	for (int i = n - 1; i >= 0; --i) {
		res[--F[arr[i] - amin]] = arr[i];
	}
	
	for (int i = 0; i < n; ++i) {
		arr[i] = res[i];
	}
	
	delete[] F;
	delete[] res;
}