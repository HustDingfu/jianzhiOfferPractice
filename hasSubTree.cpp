/*
题目:输入两棵二叉树A，B，判断B是不是A的子结构。
ps：我们约定空树不是任意一个树的子结构
*/
/*
思路:首先在pRoot1中找到与pRoot2值相等的节点，
然后进行匹配判断是否存在同样的结构
*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if(nullptr == pRoot1 || nullptr == pRoot2)
            return false;
        
        if(pRoot1->val == pRoot2->val) {
            if(compareTwoTree(pRoot1, pRoot2))
                return true;
        }
          
        return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    
	//两个树根节点相同，判断是否具有相同的结构
    bool compareTwoTree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if(nullptr == pRoot2) 	return true;
        if(nullptr == pRoot1 || pRoot1->val != pRoot2->val)
            return false;
        return compareTwoTree(pRoot1->left,pRoot2->left) && 
            compareTwoTree(pRoot1->right,pRoot2->right);
    }
};
