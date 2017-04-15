/*
题目: 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
*/
/*
思路:比较num1+num2和num2+num1大小排序即可
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
  		auto lmda = [](int num1, int num2) {
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            return s1 + s2 < s2 + s1;
        };
        
        sort(numbers.begin(), numbers.end(), lmda);
        
        ostringstream os;
        for(auto num : numbers)
            os << num;
        return os.str();
    }
};