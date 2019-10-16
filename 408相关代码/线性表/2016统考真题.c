/*
* 已知由 n (n >= 2) 个正整数构成的集合 A, 将其划分为两个不相交的
* 子集 A1、A2, 元素个数分别是 n1 和 n2, A1 和 A2 中元素之和分别为 S1、
* S2。设计算法, 满足 |n1 - n2| 最小且 |S1 - S2| 最大。
*
* 思路： 依照快速排序的思想，将数组中的元素划分为两半，一半是最小的
*        n/2(向下取整) 个，一半是最大的 n/2 个。
*/
int solution(int A[], int n){
	int pivot, i;
	int low = low_1 = 0, high = high_1 = n-1;
	int flag = 1, k = n/2;
	
	while(flag){
		pivot = a[low];        /* 选择枢纽 */
		while(low != high){
			while(a[high] >= pivot)    /* 先从右往左找第一个比它小的元素 */
				high--;
			while(a[low] <= pivot)    /* 再从左往右找第一个比它大的元素 */
				low++;
			if(low < high){
				int temp = a[low];
				a[low] = a[high];
				a[high] = temp;
			}
			
			/* 基准数归位 */
			a[low_1] = a[low];
			a[low] = pivot;
		}
		
		if(low == k-1)
			flag = 0;
		else{
			if(low < k-1){
				low = (++low_1);
				high = high_1;
			}
			else{
				high = (--high_1);
				low = low_1;
			}
		}
	}
	
	for(i = 0; i < k; ++i)
		s1 += a[i];
	for(i = k; i < n; ++i)
		s2 += a[i];
	return s2 - s1;
}