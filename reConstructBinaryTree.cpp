/*
题目: 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入
前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6},
则重建二叉树并返回。
*/
/*
思路: 关于树的问题一般都可以考虑递归解决;针对根节点，分别找到根节点
的左子树和右子树即可，而找左子树和右子树则是一个递归过程，递归思路就
出来了，转换成代码即可
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
	if(pre.size()!= vin.size()) throw new exception;
    if(pre.empty() || vin.empty()) return nullptr;
         
    TreeNode* root = new TreeNode(pre[0]);
    //中序遍历中找到根节点的迭代器位置
    auto iter = find(vin.begin(), vin.end(),pre[0]);
  
    //用以递归寻找左子树的根节点的前序遍历和中序遍历数组   
    vector<int> preOfLeft(pre.begin()+1, pre.begin()+(iter-vin.begin())+1);
    vector<int> vinOfLeft(vin.begin(), iter);
    //用以递归寻找右子树的根节点的前序遍历和中序遍历数组 
    vector<int> preOfRight(pre.begin()+(iter-vin.begin())+1, pre.end());
    vector<int> vinOfRight(iter+1, vin.end());
    root->left = reConstructBinaryTree(preOfLeft,vinOfLeft);
    root->right = reConstructBinaryTree(preOfRight,vinOfRight);
    return root;
}

    
