/*
题目:小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就
写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列
的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:
18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正
数序列
*/
/*
思路:连续子序列和的变化是有规律可寻的.当小于sum序列可以在后面再添加一位；
当大于sum,首先要减少最前面的序列值
*/
class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> res;
    	
        int low = 1, high = 2;
        int curSum = 3;
        while( low <= sum/2){
            if(curSum == sum) {
                vector<int> tmp(high - low + 1);
                int cnt = 0;
                for(auto& num : tmp)
                    num = low + cnt++;
                res.push_back(tmp);
                curSum += (++high);
            }else if(curSum < sum) {
                curSum += ++high;
            }else{
                curSum -= low++;
            }      
        }
        return res;
    }
};