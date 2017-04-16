/*
题目:汇编语言中有一种移位指令叫做循环左移（ROL），现在有个
简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给
定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符
序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即
“XYZdefabc”。是不是很简单？OK，搞定它！
*/
/*
思路:三次reverse即可。注意边界条件
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //字符串为空,或者只有一个字符
        if(str.empty() || str.size() == 1) 
            return str; 
        
        //处理n为负，n大于str.size()的情况
        n = (n%(str.size())+str.size())%str.size();
        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        reverse(str.begin(),str.end());
        return str;
    }
};