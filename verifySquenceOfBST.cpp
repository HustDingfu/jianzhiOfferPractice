/*
题目:输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
/*
思路:可以使用递归。后序遍历，序列的最后一个元素就是根节点； 前面比根节点
小的就是左子树，接着后面就应该是右子树，如果右子树存在元素小于根节点，那么
就返回错误； 然后依次对左子树和右子树进行递归操作；
*/
class Solution {
public:
    bool VerifySquenceOfBST(const vector<int>& sequence) {
        if(sequence.empty()) return false;
		return VerifySquenceOfBST(sequence,0,sequence.size() - 1);
    }
    bool VerifySquenceOfBST(const vector<int>& sequence, int low, int high){
	if(low >= high) return true;
        int mid;
       
       	for(mid = low; sequence[mid] < sequence[high];mid++);
            
        for(int i = mid; i < high; i++){
            if(sequence[i] < sequence[high]) return false;
        }
        return VerifySquenceOfBST(sequence,low,mid-1) &&
             	VerifySquenceOfBST(sequence,mid,high-1);
    }
};
