/*
常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥
补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从
第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
*/
/*
思路:动态规划
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	if(array.empty()) return -1;
        
        int maxSum = array[0];
        int tmpSum = 0;
        
        for(auto num : array) {
            if(tmpSum + num > 0)
                tmpSum += num;
            else tmpSum = 0;
            
            if(tmpSum == 0)
            	maxSum = max(num, maxSum);
            else
                maxSum = max(tmpSum, maxSum);
        }
        return maxSum;
    }
};