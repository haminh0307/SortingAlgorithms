// 0-based
void Flashsort(int arr[], int n, int m)
{
	// find min, max of array
	int amax(arr[0]), amin(arr[0]);
	for (int i = 1; i < n; ++i) {
		amax = max(amax, arr[i]);
		amin = min(amin, arr[i]);
	}
	
	// classification
	int* L = new int[m + 1]{0};
	int k;
	for (int i = 0; i < n; ++i) {
		k = 1 + (m - 1) * (arr[i] - amin) / (amax - amin);
		++L[k];
	}
	
	for (int i = 1; i <= m; ++i) {
		L[i] += L[i - 1];
	}
	
	// permutation
	int i(0), x, cnt(0);
	k = m;
	
	while (cnt < n) {
		while (i >= L[k]) {
			++i;
			k = 1 + (m - 1) * (arr[i] - amin) / (amax - amin);
		}
		
		x = arr[i];
		while (i < L[k]) {
			k = 1 + (m - 1) * (x - amin) / (amax - amin);
			--L[k];
			swap(x, arr[L[k]]);
			++cnt;
		}
	}
	
	// apply insertion sort to classified set
	int j;
	for (int k = 1; k < m; ++k) {
		for (int i = L[k + 1] - 2; i >= L[k]; --i) {
			if (arr[i] <= arr[i + 1]) continue;
			x = arr[i];
			j = i;
			while (arr[j + 1] < x) {
				arr[j] = arr[j + 1];
				++j;
			}
			arr[j] = x;
		}
	}
	
	// release memory
	delete[] L;
}