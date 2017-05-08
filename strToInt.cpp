/*
题目:将一个字符串转换成一个整数，要求不能使
用字符串转换整数的库函数。 数值为0或者字符串
不是一个合法的数值则返回0 
*/
/*
思路: 注意特殊情况就好
*/
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())//字符串为空 
            return 0; 
        bool isPositive = true;
        int pos = 0;
        //前面的字符可能为空
        while(str[pos] == ' ') pos++;
        if(str[pos] == '+') pos++;
        if(str[pos] == '-'){
            pos++;
            isPositive = false;
        }
        long long sum = 0;
        while(pos < str.size()){
            if(isdigit(str[pos])){
                sum = 10*sum + str[pos]-'0';
                pos++;
            }else{
               	return 0;
            }
        }
        sum = isPositive? sum : -sum;
        if(sum > INT_MAX) return INT_MAX;//上溢
        if(sum < INT_MIN) return INT_MIN;//下溢
        return sum;
        
        
    }
};