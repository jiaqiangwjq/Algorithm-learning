#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/*将数组下标范围 [l1,r1] 和 [l2,r2]的有序序列合并成一个有序序列*/
void merge(vector<int>& nums, int l1, int r1, int l2, int r2)
{
	int i = l1;
	int j = l2;
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);	//要合并的元素个数
	vector<int> temp(n);	//辅助数组
	int k = 0;
	while (i <= r1 && j <= r2)
	{
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}

	//如果还有剩余，直接放入到辅助数组中
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];

	//更新原始数组元素
	for (int i = 0; i < n; i++)
		nums[l1 + i] = temp[i];
}

//归并排序
void mergeSort(vector<int> &nums, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(nums, start, mid);
		mergeSort(nums, mid + 1, end);
		merge(nums, start, mid, mid + 1, end);
	}
}

int main()
{
	vector<int> nums{ 1,4,3,2,5,6,3 };
	mergeSort(nums, 0, 6);
	for (int i = 0; i < 7; i++)
		printf("%d ", nums[i]);
}