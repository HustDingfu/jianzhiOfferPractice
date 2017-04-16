/*
题目:把只包含素因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们
把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。 
*/
/*
思路: 丑数u=2^x*3^y*5^z;关键是如何确定x,y,z的值使其有序
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index < 0) return 0; // invalid input;
        
        vector<int> ugly(index);
        ugly[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i = 1; i < index; i++){
            ugly[i] = min(ugly[t2]*2, min(ugly[t3]*3, ugly[t5]*5));
         	
            if(ugly[i] == ugly[t2]*2) t2++;
            if(ugly[i] == ugly[t3]*3) t3++;
            if(ugly[i] == ugly[t5]*5) t5++;
        }
        
        return ugly[index-1];
    }
};