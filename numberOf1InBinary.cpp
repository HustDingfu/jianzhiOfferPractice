/*
题目: 输入一个整数，输出该数二进制表示中1的个数。
其中负数用补码表示。
*/
/*
思路: n&(n-1)会将二进制中的最后一个1消除
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int res = 0;
         while(n) {
             res++;
             n = n&(n-1);
         }
         return res;
     }
};