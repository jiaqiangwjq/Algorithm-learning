/*
* 已知一个整数序列 A = (a0, a1,···,an-1), 其中 0 <= ai < n(0 <= i < n)。
* 若存在 ap1 = ap2 = ··· = apm = x 且 m > n/2(0 <= pk < n, 1 <= k <= n),则
* 称 x 为 A 的主元素。例如 A = (0, 5, 5, 3, 7, 5, 5)，则 5 为主元素；又如
* A = (0, 5, 5, 3, 5, 1, 5, 7)，则 A 中没有主元素。假设 A 中的 n 个元素保存
* 在一个一维数组中。设计算法，找出 A 的主元素。若存在主元素，则输出该元素；
* 否则输出 -1。
*
* 思路一： 
*   1. 依次扫描所给数组中的每个整数，将遇到的第一个整数 num 保存到变量 c 
* 中，记录 num 出现的次数为 1；若遇到下一个整数仍等于 num，则计数加 1，否则计数减 1，
* 当计数减到 0 时，将遇到的下一个整数保存到 c 中，计数重新为 1，开始新一轮计数。
*   2. 判断 c 是否是真正的主元素。再次扫描该数组，统计 c 出现的次数，若大于 n/2, 
* 则为主元素；否则返回 -1。
*
* 思路二： 桶排序
*/
int solution_1(int A[], int n){
	int i, c, count = 0;
	c = A[0];
	for(i = 1; i < n; ++i){
		if(A[i] == c)
			count++;
		else{
			if(count > 0)
				count--;
			else{
				c = A[i];
				count = 1;
			}
		}	
	}
	if(count > 0)
		for(i = count = 0; i < n; ++i)
			if(A[i] == c)
				count++；
	if(count > n/2)
		return c;
	else
		return -1;
}


int solution_2(int A[], int n){
	int *temp = (int *)calloc(n, sizeof(int));
	int i, max, index;
	for(i = 0; i < n; ++i)
		temp[A[i]]++;
	max = temp[0];
	for(i = 0; i < n; i++){
		if(temp[i] > max){
			max = temp[i];
			index = i;
		}
	}
	if(max > n/2)
		return index;
	else
		return -1;
}
