/*
题目:从上到下打印出二叉树的每个节点，同层节点从左至右打印。
*/
/*
思路：用队列做辅助数据结构打印即可
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
	if(nullptr == root) return vector<int>();
        vector<int> res;
        queue<TreeNode*> data;
		data.push(root);
        while(!data.empty()) {
            TreeNode* curNode = data.front();
           	if(curNode->left) 
                data.push(curNode->left);
            if(curNode->right)
                data.push(curNode->right);
            res.push_back(curNode->val);
            data.pop();
        }
        return res;
    }
};
