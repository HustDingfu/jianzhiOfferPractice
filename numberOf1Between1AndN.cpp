/*
题目:求出1~13的整数中1出现的次数,并算出100~1300的整数中1出
现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、
12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你
们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中
1出现的次数。
*/
/*
思路: 递归. 以25346为例分析，1-25436出现1的数字 = 5347~25346出现的数字
加上1~5346的数字。1~5346是一个比原问题规模更小的子问题，所以可以递归解决。
5347~25346出现1的数实际上等于1~20000出现的数字。这个利用排列组合解决即可。
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        // 负数情况
        if(n < 0) n = -n;
    	if(n == 0) return 0;
        if(n < 10) return 1;
        
        string s = to_string(n);
        int size = s.size();
        int numOfFirstDigit;// 第一位出现1的数目
        int numOfOtherDigits;//其他位出现的1的数目
        n = stoi(s.substr(1));
        if(s[0]-'0' > 1){
            numOfFirstDigit = pow(10,size - 1);
        }else {
            numOfFirstDigit = n + 1;
        } 
        
        numOfOtherDigits = (s[0] - '0')*(size - 1)*pow(10,size-2);
        return numOfFirstDigit + numOfOtherDigits 
            + NumberOf1Between1AndN_Solution(n);
    }
};