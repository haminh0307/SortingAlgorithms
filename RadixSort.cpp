// 0-based
int const BASE = 10;

int digit(int num, int k)
{
	while (k--) {
		num /= BASE;
	}
	return num % BASE;
}

void RadixSort(int arr[], int n)
{
	int amax(arr[0]), d(0);
	for (int i = 1; i < n; ++i) {
		amax = max(amax, arr[i]);
	}
	while (amax) {
		++d;
		amax /= BASE;
	}
	
	int* F = new int[BASE];
	int* res = new int[n];
	for (int k = 0; k < d; ++k) {
		memset(F, 0, BASE * sizeof(F[0]));
		
		for (int i = 0; i < n; ++i) {
			++F[digit(arr[i], k)];
		}
		
		for (int i = 1; i < BASE; ++i) {
			F[i] += F[i - 1];
		}
		
		for (int i = n - 1; i >= 0; --i) {
			res[--F[digit(arr[i], k)]] = arr[i];
		}
		
		for (int i = 0; i < n; ++i) {
			arr[i] = res[i];
		}
	}
	
	delete[] F;
	delete[] res;
}