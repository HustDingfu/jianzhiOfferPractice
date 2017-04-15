/*
题目:输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串
abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/
/*
思路:递归思路；分解成两个子问题，前面一个字符和后面的n-1个字符的问题；
然后依次将第一个字符和后面的n-1个字符进行交换，即可得到全部的排列
*/
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        permutation(res,str,0);
        sort(res.begin(), res.end());
        return res;
    }
    /*
    @res 保存返回结果的字符串数组
    @str 传入的字符串变量
    @index 当前的递归的深度（正在处理字符的下标）
    */
    void permutation(vector<string>& res, string& str, int index) {
        
        if(index + 1 == str.size())
            res.push_back(str);
        else {
            
            unordered_set<char> st;//用来保存字符使用过的情况
            for(int i = index; i < str.size();i++){
                if(st.find(str[i]) == st.end()) {
                    st.insert(str[i]);//记录使用过的字符
               		swap(str[i],str[index]);  
                	permutation(res,str,index+1);//处理剩下的n-1个字符
                	swap(str[i],str[index]); 
                } 
            }
        }
    }
};