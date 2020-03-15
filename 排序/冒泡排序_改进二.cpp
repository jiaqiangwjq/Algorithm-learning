/** 冒泡排序__改进二
*
* 思路： 对于只有前面一小部分存在逆序对的数组，我们只需要记录其最右侧逆序对的位置，
*        然后只对这一小部分序列进行排序
*
*/

int BubbleSort(int a[], int left, int right);
void swap(int* a, int* b);

int last, left, right;
int a[];

int main() {

	while (left < (right = BubbleSort(a, left, right)));

	return 0;
}

int BubbleSort(int a[], int left, int right)
{
	last = left;
	while (++left < right)
	{
		if (a[left - 1] > a[left])
		{
			last = left;
			swap(&a[left - 1], &a[left]);
		}
	}
	return last;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}