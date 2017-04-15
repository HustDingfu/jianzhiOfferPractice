/*
题目: 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/
/*
思路: 深度优先搜索。搜索的路径值都保存在tmpPath中，如果路径值能满足条件
即将该tmpPath保存在最后结果中，如果不行，就进行回溯；
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>> res;
        vector<int> tmpPath;
     	FindPath(root,res,tmpPath,expectNumber);
        return res;
    }
    
    void FindPath(TreeNode* root, vector<vector<int>> &res,
                 vector<int>& tmpPath, int expectNumber) {
        if(root == nullptr ) return ;
        tmpPath.push_back(root->val);
        if(root->val == expectNumber && root->left==nullptr && root->right==nullptr) {
            res.push_back(tmpPath);
        }else {	
        	if(root->left) 
            	FindPath(root->left,res,tmpPath,expectNumber - root->val);
        	if(root->right)
          		FindPath(root->right,res,tmpPath,expectNumber - root->val);
        }
       	tmpPath.pop_back();
        
    }
};