// 0-based
void MergeSort(int arr[], int l, int r)
{
	// MergeSort on [l, r]
	if (l >= r) return;
	
	int mid((l + r) / 2);
	
	MergeSort(arr, l, mid);
	MergeSort(arr, mid + 1, r);
	
	int* res = new int[r - l + 1];
	
	int p1(l), p2(mid + 1), p(0);
	while (p1 <= mid && p2 <= r) {
		if (arr[p1] < arr[p2]) {
			res[p++] = arr[p1++];
		}
		else {
			res[p++] = arr[p2++];
		}
	}
	
	while (p1 <= mid) {
		res[p++] = arr[p1++];
	}
	
	while (p2 <= r) {
		res[p++] = arr[p2++];
	}
	
	while (p--) {
		arr[p + l] = res[p];
	}
	
	delete[] res;
}