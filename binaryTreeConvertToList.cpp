/*
题目:输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向
链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/
/*
思路:递归实现；
分解成两个问题，左子树变成双向链表，右子树变成双向链表；
左子树和root节点之间的两个指针关系，右子树和root之间的链表关系
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* pLastNode = nullptr;
        return convertCore(pRootOfTree, &pLastNode);
    }
    
    //返回的是双向链表的首节点
    // pLastNode保存着双向链表的最后一个节点
    TreeNode* convertCore(TreeNode* root, TreeNode** pLastNode){
        if(root == nullptr) return root;
        if(!root->left && !root->right ) {
            *pLastNode = root;
            return root;
        }
        
        TreeNode* head = root;
        if(root->left){
            head = convertCore(root->left, pLastNode);
            head->left = nullptr;
        }
        if(*pLastNode != nullptr) {
        	(*pLastNode)->right = root;
        	root->left = *pLastNode;
        }
        *pLastNode = root;
        if(root->right){
            TreeNode* pHead = convertCore(root->right,pLastNode);  
            root->right = pHead;
            pHead->left = root;
        }
        if(*pLastNode)
        	(*pLastNode)->right = nullptr;
        return head;
    }
};