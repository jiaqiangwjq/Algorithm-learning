/* 选择排序 */

void selectSort(int *a)
{
	for(int i = 0; i < n; ++i)
	{
		int min = i;
		for(int j = i; j < n; ++j)	/* 选择 [i,n] 中最小的元素 */
		{
			if(a[j] < a[min])
				min = j;
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}