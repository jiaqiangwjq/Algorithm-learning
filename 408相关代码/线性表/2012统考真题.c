/*
* 假定采用带头节点的单链表保存单词，当两个单词有相同的后缀时，可共享相同的
* 后缀存储空间，例如 "loading" 和 "being" 可以共享 后缀 "ing" 的存储部分。
* 设 str1 和 str2 分别指向两个单词所在单链表的头结点，链表结构为 data|next 。
* 设计算法，找出由 str1 和 str2 所指向两个链表共同后缀的起始位置。
*
* 思路： 分别求出两个单链表的长度，让长单链表的指针先开始走，一直走到其剩余
*        长度与短单链表的长度相等时为止。然后两个指针一同向后走，直到走到相同
*        的后缀位置
*/

/* 先求链表的长度 */
int getLength(ListNode *head){
	int len = 0;
	while(head->next != NULL){
		len++;
		head = head -> next;
	}
	return len;
}

ListNode *search(ListNode *str1, ListNode *str2){
	int len_1 = getLength(str1);
	int len_2 = getLength(str2);
	ListNode *p, *q;
	for(p = str1; len_1 > len_2; --len_1)
		p = p -> next;
	for(q = str2; len_2 > len_1; --len_2)
		q = q -> next;
	while((p->next != NULL) && (q->next != NULL) && (p-> next != q->next)){
		p = p -> next;
		q = q -> next;
	}
	return p -> next;
}