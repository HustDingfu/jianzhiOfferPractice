/*
题目:输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,
*/
/*
思路1: 借用快排的partition方法
思路2: 借用推排序
思路3: 直接调用STL中的nth_element函数
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k <= 0 || input.empty() || k > input.size()) 
            return vector<int>();
        
        nth_element(input.begin(),input.begin() + k-1,input.end());
        vector<int> res(input.begin(), input.begin()+k);
    	return res;
            
    }
};