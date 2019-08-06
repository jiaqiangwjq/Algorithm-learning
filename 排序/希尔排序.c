/* 希尔排序 */
void shellSort(ElemType arr[], int n){
	int h = 1;
	while(h < n / 3)
		h = 3 * h + 1;
	
	while(h >= 1){
		for(int i = h; i < n; i++){
			
			/* 这一部分其实就是插入排序 */
			ElemType e = arr[i];
			int j;
			for(j = i; j >= h && e > arr[j-h]; j -= h)
				arr[j] = arr[j - h];	/* 按从小到大顺序排序 */
			arr[j] = e;
		}
		h /= 3;
	}
}