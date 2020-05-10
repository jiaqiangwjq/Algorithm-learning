/* 插入排序 InsertSort */

void insertSort(int A[], int n){
	int i, j;
	for(i = 1; i < n; ++i){		/* 从第二个元素开始，第一个元素看作一个有序序列 */
		int temp = A[i];
		j = i;
		while(j > 0 && temp < A[j-1]){		/* 找到第一个比 temp 大的元素 */
			A[j] = A[j-1];		/* 比 temp 小的元素都后移 */
			j--;
		}
		A[j] = temp;	/* 插入位置 */
	}
}