/*
* 已知一个带有头结点的单链表。假设该链表只给出了头指针 list。
* 在不改变链表的前提下，设计一个算法，查找链表中倒数第 k 个
* 位置上的结点(k 为正整数)。若查找成功，输出该结点的 data 域
* 的值，并返回 1；否则，返回 0。
*
* 思路： 双指针，一个先走 k 步，当它走到尾时，另外一个刚好处于
*        倒数第 k 个位置 
*/
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *link;
} LNode, *Linklist;

void solution(Linklist list, int k){
	LNode *p = list -> link, *q = list -> link;
	int count = 0;
	while(q != NULL && count < k)
		q = q -> link;
	while(q != NULL && p != NULL){
		q = q -> link;
		p = p -> link;
	}
	if(count < k)
		return 0;
	else{
		printf("%d\n", p->data);
		return 1;
	}
}