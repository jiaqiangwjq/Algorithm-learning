/*
* 快速排序 QuickSort
* 
* 最后数组中的元素按照从小到大的顺序排列
*/

#include<cstdio>

int a[101], n;  //定义两个全局变量，需要在子函数中使用它们

void QuickSort(int left, int right)
{
    int i, j, t, temp;

    //temp 中存放的就是基准数    
    temp = a[left];

    i = left;
    j = right;
	 
    while(i != j)		//当哨兵 i 和哨兵 j 没有相遇时，交换两个数的位置
    {   
        /* 
		 * 顺序很重要,要先从右往左找，保证最后与 temp 交换的值一定比它小
		 * 如果先从左向右找，那么最后与 temp 交换的值就比 temp 大了
		 */
        while(a[j] >= temp && i < j)
            j--;
		a[left] = a[right];
        
        //再从左往右找
        while(a[i] <= temp && i < j)
            i++;
		a[right] = a[left];
       
    }

    //将基准数归位
    a[left] = temp;

    QuickSort(left, i-1);   //递归处理 左 半部分
    QuickSort(i+1, right);  //递归处理 右 半部分
}

int main()
{
    int i, t;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    QuickSort(1, n);

    //输出排序后的结果
    for(i = 1; i <= n; i++)
        printf("%d ",a[i]);

    return 0;

}
