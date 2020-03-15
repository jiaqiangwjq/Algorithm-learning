/** 冒泡排序__改进一 
*
* 思路： 当某一趟排序过程中没有发生交换时，说明数组已有序  
*
*/

void BubbleSort(int a[], int left, int right) {
	
	for (int i = 0; i < right-1; i++)
	{
		bool sorted = true;
		for (int j = 0; j < right-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				sorted = false;
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		if (sorted)
			break;
	}
}