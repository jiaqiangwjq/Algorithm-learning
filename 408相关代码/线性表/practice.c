/*
* 将顺序表 L 的所有元素逆置，要求算法复杂度为 O(1)
* 
* 思路: 扫描顺序表 L 的前半部分元素，将其与后半部分的对应元素交换
*/
void Reverse(Sqlist &L){
    ElemType temp;
    for(int i = 0; i < L.length/2; ++i){
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

/* ===================== 分隔符 ================================ */

/*
* 对长度为 n 的顺序表 L, 编写一个时间复杂度 O(n), 空间复杂度 O(1) 的算法，
* 该算法删除线性表中所有值为 x 的元素
*/
void delete(Sqlist &L, ElemType x){
	int k = 0;
	for(int i = 0; i < L.length; ++i){
		if(L.data[i] != x)
			L.data[k++] = L.data[i];	/* 与 x 相等的元素都被覆盖了 */
	}
	L.length = k;
}

/* ===================== 分隔符 ================================ */

/*
* 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
*/
void merge(Sqlist A, Sqlist B, Sqlist &C){
	int i = 0, j = 0, k = 0;
	while(i < A.length && j < B.length){
		if(A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while(i < A.length)
		C.data[k++] = A.data[i++];
	while(j < B.length)
		C.data[k++] = B.data[j++];
}

/* ===================== 分隔符 ================================ */

/*
* 已知在一维数组 A[m+n] 中依次存放两个线性表 (a1,a2,···,am) 和 (b1,b2,···,bn)。
* 编写一个函数，将数组中的两个顺序表的位置互换，即将 (b1,b2,···,bn) 放在 
* (a1,a2,···,am) 的前面
*
* 思路: 首先将数组中的全部元素逆置为 (bn,···,b2,b1,am,···,a2,a1), 再对前 n 个元素
* 和后 m 个元素分别使用逆置算法
*/
void reverse(int A[], int left, int right){		/* 数组元素逆置 */
	int mid = (left + right) / 2;
	for(int i = 0; i <= mid - 1; i++){
		int temp = A[left+i];
		A[left+i] = A[right-i];
		A[right-i] = temp;
	}
}

void Exchange(int A[], int m, int n){
	Reverse(A, 0, m+n-1);	/* 整体逆置 */
	Reverse(A, 0, n-1);		/* 左半逆置 */
	Reverse(A, n, m+n-1);	/* 右半逆置 */
}
