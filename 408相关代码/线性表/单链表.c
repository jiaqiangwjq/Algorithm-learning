/* 链表结点定义 */
struct ListNode{
	ElemType data;
	ListNode *next;
};


/* 链表的定义 */
struct List{
	ListNode *head;    /* 头结点 */
	int length;       /* 链表长度 */
}*LinkList;			 

/* 链表初始化 */
void Init(int n){
	head.data = 0;	/* 初始化头结点 */
	length = n;
	ListNode *tail = &head;

	for(int i = 0; i < n; ++i){
		ListNode *newNode = (ListNode *)malloc(sizeof(ListNode) * n);
		newNode -> data = 0;
		*tail -> next = newNode;	/* 每个新结点都把它当作是最后一个结点 */
		tail = newNode;
	}
	tail -> next = NULL;
}

/* 插入操作 */
void Insert(ElemType x, int n){
	ListNode *p = &head;
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode -> data = x;
	int count = 0;
	
	while(p -> next != NULL){
		count++;
		if(count == n)
			break;
		p = p -> next;
	}/* 循环结束时，p 指向带插入位置的前一个结点 */

	/* p == NULL 说明直接在 head 后插入 */
	if(p == NULL){
		newNode -> next = head -> next;
		head -> next = newNode;
	}

	newNode -> next = p -> next;
	p -> next = newNode;
	++length;
}

/* 删除操作 */
void Delete(int n){
	/* 删除指定位置的结点 */
	if(n < 1 || n > length)
		return;
	int count = 0;
	ListNode *p = &head;

	while(p -> next != NULL){
		count++;
		if(count == n)
			break;
		p = p -> next;
	}
	ListNode *temp = p -> next;
	p -> next = temp -> next;
	free(temp);
	--length;
}

/* 遍历链表 */
void Print(){
	ListNode *p = head -> next;
	while(p -> next != NULL){
		printf("%ElemType ", p -> data);
		p = p -> next;
	}
	printf("%ElemType ", p -> data);	/* 最后一个结点 */
}

/* 查找某个元素的位置 */
int Locate(ElemType x){
	ListNode *p = head -> next;
	int location = 0;
	while(p -> data != NULL){
		location++;
		if(p -> data == x)
			return location;
		p = p -> next;
	}
	/* 前面都没找到, 找到最后一个结点了 */
	if(p -> data == x)
		return length;
	else
		return -1;		/* 未找到 */
}

/* 链表反转 */
/* 用指针 p 扫描原单链表，先将头节点的 next 域设置为 NULL，然后将 p 节点采用头插法进行插入 */

void Reverse(){
	ListNode *p = head -> next, *q;
	head -> next = NULL;
	
	while(p != NULL){
		q = p -> next;
		p -> next = head -> next;
		head -> next = p;
		p = q;
	}
}

/* 计算链表长度 */
int getLengh(){
	int count = 0;
	ListNode *p = &head;
	while(p -> next != NULL){
		count++;
		p = p -> next;
	}
	count++;
	return count;
}

/* 交换链表结点 */
void exChange(int n, int m){
	ListNode *p_n = &head;
	ListNode *p_m = &head;
	for(int i = 0; i < n; ++i)
		p_n = p_n -> next;
	for(int i = 0; i < m; ++i)
		p_m = p_m -> next;
	
	ListNode *temp = p_n;
	p_n -> next = p_m -> next;
	p_m -> next = temp;
}