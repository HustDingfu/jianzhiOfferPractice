/*
题目:在一个字符串(1<=字符串长度<=10000，全部由字母
组成)中找到第一个只出现一次的字符,并返回它的位置。如
果字符串为空,返回-1
*/
/*
思路:扫描一次，记录每个字符出现的次数;再次扫描,找到第
一个出现位置为1的位置；
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
     	if(str.empty()) return -1; // 字符串为空的情况
        unordered_map<char, int> hash;
        
        for(auto ch : str)
            hash[ch]++;
        
       	for(int i = 0; i < str.size(); i++){
            if(hash[str[i]] == 1) return i;
        }
        
        return -1;
    }
};