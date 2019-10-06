/* 二叉树结点定义 */
typedef ElemType int;	/* data 数据类型 */
struct BinTreeNode{
	ElemType data;
	BinTreeNode *lchild, *rchild;
}*BinTree;


/* 计算二叉树的高度 */
int Height(BinTreeNode *root){
	if(root == NULL)
		return 0;
	else{
		int i = Height(root -> lchild);
		int j = Height(root -> rchild);
		return (i < j) ? j+1 : i+1;
	}
}

/* 先序遍历 */
void preOrder(BinTreeNode *root){
	if(root == NULL)
		return;
	else{
		printf("%d", root->data);
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

/* 中序遍历 */
void inOrder(BinTreeNode *root){
	if(root == NULL)
		return;
	else{
		inOrder(root->lchild);
		printf("%d", root->data);
		inOrder(root->rchild);
	}
}

/* 后序遍历 */
void postOrder(BinTreeNode *root){
	if(root == NULL)
		return;
	else{
		postOrder(root->lchild);
		postOrder(root-rchild);
		printf("%d", root->data);
	}
}

/* 层次遍历 */
void levelOrder(BinTreeNode *root){
	InitQueue Q;
	if(root != NULL){
		EnQueue(root);		/* 根节点入队 */
		while(!IsEmpty(Q)){
			BinTreeNode *p = DeQueue(Q);	/* 队头结点出队 */
			visit(p);
			if(p->lchild)
				EnQueue(p->lchild);
			if(p->rchild)
				EnQueue(p->rchild);
		}
	}
}

/* 一个完全二叉树按顺序存储结构存储在数组中，结点个数为 n。求出离
* 下标分别为 i 和 j 的两个结点最近的公共祖先结点。
*/
int theSharedAncestor(int tree[], int i, int j){
	int p = i, q = j;
	while(p != q){
		if(p > q)
			p /= 2;		/* p 向上走 */
		if(p < q)
			q /= 2;		/* q 向上走 */
	}
	return tree[data];
}

/* 计算一棵给定二叉树的结点数 */
static int n;
void count(BinTreeNode *root){
	if(root != NULL){
		++n;
		count(root->lchild);
		count(root->rchild);
	}
}

/* 计算一棵二叉树的所有叶结点数 */
static int n;
void count(BinTreeNode *root){
	if(root != NULL){
		if(root->lchild == NULL && root->rchild == NULL)
			++n;
		count(root->lchild);
		count(root->rchild);
	}
}

/* 求二叉树中数值为 x 的结点所在层号 */
static int level = 1;
void levelNum(BinTreeNode *root, int x){
	if(root != NULL){
		if(root->data == x)
			printf("%d", level);
	}
	++level;
	
	levelNum(root->lchild, x);
	levelNum(root->rchild, x);		
	/* 
	   这两句执行完后，要是还没找到 x, 指针得返回到上一层，
	   去其他结点继续寻找，所以 level 要减 1 了 
	*/
	--level;
}

/* 由先序序列和中序序列构造二叉树 */
BinTreeNode *creatBT(int preOrder[], int inOrder[], int left_pre, int right_pre, int left_in, int right_in){
	BinTreeNode *root;
	int i;
	
	root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	root -> lchild = r -> rchild = NULL;
	
	/* 查找当前子树根节点在 inOrder 中的位置 */
	for(i = left_in; i <= right_in; ++i)
		if(inOrder[i] == preOrder[left_pre])
			break;
	root -> data = inOrder[i];
	
	/* 
	   通过在 inOrder 中找到分界点 i, 确定在 preOrder[] 和 inOrder[] 中当前子树的左子树范围，
	   再仿照之前的方法建立左子树，将左子树的根连接在 root 的左指针域上 
	*/
	root -> lchild = creatBT(preOrder, inOrder, left_pre+1, left_pre+(i-left_in), left_in, i-1);
	root -> rchild = creatBT(preOrder, inOrder, left_pre+1, left_pre+(i-left_in), i+1, right_in);
}