/*
题目:操作给定的二叉树，将其变换为源
二叉树的镜像
*/
/*
思路: 典型递归实现,左子树右子树实现之后
再交换根节点的左右指针即可
*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
	if(nullptr == pRoot)
            return;
        TreeNode* pNode = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pNode;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
