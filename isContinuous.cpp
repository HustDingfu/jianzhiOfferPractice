/*
题目: 判断输入序列是否是顺子
*/
/*
思路: 判断数组长度，最大值最小值是否满足条件；
用bit位判断是否出现过重复数字；
然后判断最大值最小值是否小于4；
思路2： 排序后判断即可
扩展： 如果1,10,11，12,13,14是顺子呢？ 该如何做呢？
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        // input invalid
        if(numbers.size() != 5)
            return false;
        
        int min = 14;
        int max = -1;
        int flag = 0;
        int countOfZero = 0;
        for(auto num : numbers) {
            if(num == 0) {
                countOfZero++;
                continue;
            }else if(num > 13 || num < 0){
                return false;
            }else{
                if(((flag >> num) & 1) == 1)
                    return false;
                flag = flag | (1<<num);
            }
            
            max = (max > num) ? max : num;
            min = (min < num) ? min : num;
        }
        
        if(countOfZero > 4 || max - min > 4)
            return false;
        return true;
    }
};