/* 二叉树结点定义 */
struct BinTreeNode{
	ElemType data;
	BinTreeNode *lchild, *rchild;
}*BinTree;


/* 计算二叉树的高度 */
int Height(BinTreeNode *BinTree){
	if(BinTree == NULL)
		return 0;
	else{
		int i = Height(BinTree -> lchild);
		int j = Height(BinTree -> rchild);
		return (i < j) ? j+1 : i+1;
	}
}

