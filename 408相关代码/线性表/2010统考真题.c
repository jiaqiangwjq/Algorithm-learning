/*
* 设将 n(n > 1) 个整数存放到一维数组 R 中。设计一个在时间和空间两方面都尽可能高效
* 的算法。将 R 中保存的序列循环左移 p(0 < p < n)个位置，即将 R 中的数据由(X0,X1,···,Xn)
* 变换为 (Xp,Xp+1,···,Xn-1,X0,X1,···,Xp-1)

* 思路一： 分别先将数组的前 p 个和后 n-p 个元素逆置，再将数组所有元素逆置
* 思路二： 将数组的前 R 个元素先放在一个辅助数组中，再将后 n-p 个元素整体左移
*/

void reverse(int R[], int left, int right){
	int i, temp;
	for(i = 0; i < (right-left+1)/2; ++i){
		temp = R[left+i];
		R[left+i] = R[right-i];
		R[right-i] = temp;
	}
}

void solution_1(int R[], int n, int p){
	reverse(R, 0, p-1);		/* 左半逆置 */
	reverse(R, p, n-1);		/* 右半逆置 */
	R(R, 0, n-1);			/* 整体逆置 */
	/* 也可以先整体逆置，再分别左右逆置 */
}

void solution_2(int R[], int n, int p){
	int *temp = (int *)calloc(p, sizeof(int));		/* 辅助数组 */
	int i, j, k;
	for(i = 0; i < p; ++i)
		temp[i] = R[i];
	for(j = p; j < n; ++j)
		R[j-p] = R[j];
	for(k = n-p, i = 0; i < p; ++i, ++k)
		R[k] = temp[i];
}