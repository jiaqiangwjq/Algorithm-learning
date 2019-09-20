/*
* 一个长度为 L(L >= 1)的升序序列 S, 处在第 L/2 个位置的数称为 S 的中位数。
* 例如，若序列 S1 = (11, 13, 15, 17, 19),则 S1 的中位数是 15，两个序列的中位数是含
* 它们所有元素的升序序列的中位数。例如，若 S2 = (2, 4, 6, 8, 20),则 S1 和 S2 的中位数是
* 11。现在有两个等长升序序列 A 和 B，设计一个算法找出 A 和 B 的中位数。
*
* 思路一： 分别求两个升序序列 A 和 B 的中位数 a 和 b。
*       1. 若 a = b, 则 a 或 b 即为所求中位数;
*       2. 若 a < b, 则舍弃 A 中较小的一半，舍弃 B 中较大的一半，要求舍弃的长度一致；
*       3. 若 a > b, 则舍弃 A 中较大的一半，舍弃 B 中较小的一半，要求舍弃的长度一致；
* 在保留的升序序列中重复上述过程，直到两个序列中均只含一个元素为止，较小者即为所求中位数。
*
* 思路二： 按照从小到大的顺序，同时读 A 和 B 中的数字，当顺序读到第 n 个数时，即为所求中位数。
*/
int solutionOne(int A[], int B[], int n){
	int left_A = 0, right_A = n-1;
	int left_B = 0, right_B = n-1;
	int middle_A, middle_B;
	while(left_A != right_A || left_B != right_B){
		middle_A = (left_A + right_A) / 2;
		middle_B = (left_B + right_B) / 2;
		
		if(A[middle_A] == B[middle_B])
			return A[middle_A];
		else if(A[middle_A] > B[middle_B]){
			if(n & 1){		/* 若元素个数为奇数，两个中间点可以都保留(不保留也没事) */
				right_A = middle_A;
				left_B = middle_B;
			}
			else{		   /* 若元素个数为偶数,舍弃 A 的中间点并保留 B 的中间点(必须) */
				right_A = middle_A + 1;
				left_B = middle_B;
			}
		}
		else{
			if(n &1){
				left_A = middle_A;
				right_B = middle_B;
			}
			else{
				left_A = middle_A + 1;
				right_B = middle_B;
			}
		}
	}
	return A[left_A] < B[left_B] ? A[left_A] : B[left_B];
}


int solutionTwo(int A[], int B[], int n){
	int count = 1;
	int i = 0, j = 0;
	int result;
	while(count <= n){
		if(A[i] < B[j]){
			result = A[i];
			++i;
			++count;
		}
		else{
			result = B[j];
			++j;
			++count;
		}
	}
	return result;
}