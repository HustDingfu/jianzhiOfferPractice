/*
题目:一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/
/*
思路:找出一个出现一次的数字比较容易,直接异或即可获得;
这里可以将按照某种策略将数字分为两组,让这两个数分别处于不同
的分组里，然后分别异或即可；
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int>& data,int* num1,int *num2) {
        
        int res = 0;
        for(auto num : data)
            res ^= num;
		
        // 分组策略；
        int i = 0;
        while(((res >> i) & 1) == 0) i++;
        
        *num1 = *num2 = 0;
        
        for(auto num : data)
            if((num >> i) & 1) *num1 ^= num;
        	else *num2 ^= num;
    }
};