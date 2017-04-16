/*
题目:输入一棵二叉树，求该树的深度。从根结点
到叶结点依次经过的结点（含根、叶结点）形成树
的一条路径，最长路径的长度为树的深度。
*/
/*
思路:递归
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(nullptr == pRoot) return 0;
        
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
};

/*
题目:输入一棵二叉树，判断该二叉树是否是平衡二叉树
*/
/*
思路: 递归(自顶向下)
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(nullptr == pRoot)	return true;
        int diffDepth = TreeDepth(pRoot->left) -  
            TreeDepth(pRoot->right);
        if(diffDepth > 1 || diffDepth < -1)
            return false;
        return IsBalanced_Solution(pRoot->left)
            && IsBalanced_Solution(pRoot->right);
    }
    
    int TreeDepth(TreeNode* pRoot)
    {
    	if(nullptr == pRoot) return 0;
        
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
};