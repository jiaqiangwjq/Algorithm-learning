/* 快速选择算法 */

/*
* 利用快速排序的思想，但不需要对所有元素都进行排序。
* 一般用来求解第 K 个最小/大元素的问题。
*/

#include<cstdio>
#include<algorithm>
using namespace std;

int findKthLargest(int a[], int k, int n){		/* n 为元素个数, k 为待求参数 */
	
	k = n - k;
	
	int left = 0, right = n - 1;
	
	while(left < right){
		int j = partition(a, left, right);
		if(j == k)
			break;
		else if(j < k)
			left = j + 1;
		else
			right = j - 1;
	}
	
	return a[k];
}

/* 快速排序的 partition 部分 */
int partition(int a[], int left, int right){
	
	int i, j, t, temp;
	
	if(left > right)
		return;
	
	temp = a[left];
	i = left;
	j = right;
	
	while(i != j){
		while(a[j] >= temp && i < j)
			j--;

		while(a[i] <= temp && i < j)
			i++;
		
		if(i < j)
			swap(a[i], a[j]);
	}
	
	a[left] = a[i];
	a[i] = temp;
	
	return i;
}