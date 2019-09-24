/*
* 用单链表保存 m 个整数，结点的结构为 [data][link], 且 |data| <= n,
* n 为正整数。设计一个算法，对于链表中 data 的绝对值相等的结点，仅保留
* 第一次出现的结点，而删除其余绝对值相等的结点。
*
* 思路： 用桶排序法。每遇到一个数，就将该数的绝对值下标中的内容置 1。
*/
void solution(ListNode *head, int n){
	int *temp = (int *)malloc(n+1, sizeof(int));
	ListNode *p = head;
	ListNode *q;
	while(p->link != NULL){
		int number = p->link->data > 0 ? p->link->data : -(p->link->data);
		if(temp[number] == 0){
			temp[number] = 1;
			p = p -> link;
		}
		else{
			q = p -> link;		/* q 指向被删除结点 */
			p -> link = q -> link;		/* 重新拉链 */
			free(q);
		}
	}
	free(temp);
}