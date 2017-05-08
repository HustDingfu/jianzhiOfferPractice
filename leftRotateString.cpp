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




/*
题目:牛客最近来了一个新员工Fish，每天早晨总是会拿着
一本英文杂志，写些句子在本子上。同事Cat对Fish写的内
容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意
思。例如，“student. a am I”。后来才意识到，这家伙
原来把句子单词的顺序翻转了，正确的句子应该是
“I am a student.”。Cat对一一的翻转这些单词顺序可
不在行，你能帮助他么？
*/
/*
思路1:反转整个字符串，再反转每个单词；
思路2:可以用stringstream试着去处理//这种方法可能会有些问题
但依旧在牛客网上通过了测试
*/

class Solution {
public:
    string ReverseSentence(string str) {
        istringstream is(str);
        ostringstream os;
        string tmp;
        vector<string> s;
        while(is >> tmp){
            s.push_back(tmp);
        }
        if(s.empty()) return str;
        reverse(s.begin(),s.end());
        for(int i = 0; i < s.size();i++){
            if(i!=0) os << " ";
            os << s[i];
        }
            
        return os.str();
    }
};