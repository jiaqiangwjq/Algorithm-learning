int binarySearch(int A[], int left, int right, int x) {
	int mid;
	
	while(left <= right) {
		mid = (left + right) / 2;
		if(A[mid] == x) {
			return mid;
		}
		else if(A[mid] > x) {
			right = mid - 1;
		} 
		else {
			left = mid + 1;
		}
	}
	
	return -1; // 返回 -1，表示查找失败
}
	