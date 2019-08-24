/*
* 给定一个含 n 个整数的数组，设计算法，找出数组中未出现的最小正整数。
* 例如，数组 {-5, 3, 2, 3} 中未出现的最小正整数是 1；数组 {1, 2, 3} 中未
* 出现的最小正整数是 4。
*
* 思路： 桶排序
*/
void solution(int A[], int n){
	int i;
	int *temp = (int *)calloc(n+1, sizeof(int));
	for(i = 0; i < n; ++i){
		if(A[i] > 0 && A[i] <= n)
			temp[A[i]+1] = 1;
	}
	for(i = 1; i < n+1; ++i)
		if(temp[i] == 0)
			break;
	return i;
}