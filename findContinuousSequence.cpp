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


/*
题目:输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和
正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/
/*
思路:有序数组，一个指针在前，一个指针在后，进行移动，如果遇到两者和为Sum
此时就是乘积最小的 返回即可
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(const vector<int>& array,int sum) {
		if(array.size() < 2) return vector<int>();// invalid input
        vector<int> res;
        int low  = 0;
        int high = array.size() - 1;
            
        while(low < high){
            int curSum = array[low] + array[high];
            if(curSum < sum) low++;
            else if(curSum > sum) high--;
            else {// 满足条件        
                res.push_back(array[low++]);
                res.push_back(array[high--]);
                break;
            }
        }   
        return res;
    }
};