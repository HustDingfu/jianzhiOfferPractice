/*
题目:输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列
是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,
4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长
度是相等的）
*/
/*
思路:用一个数据栈模拟进栈出栈的过程。i,j分别自相vector里面当前操作元素
1)如果栈为空，必须要进栈;
2)如果栈顶元素不等于j指向的元素，就再次进栈一个元素
  相等，则元素出栈，j++
如果正常结束，就应该i和j指针同时为数组的大小，否则就不正常
*/
class Solution {
public:
    bool IsPopOrder(const vector<int>& pushV,const vector<int>& popV) {
  		int i = 0, j = 0;
        stack<int> data;
        while(i <= pushV.size() && j < popV.size()) {
       		if(data.empty() && i < pushV.size()) {
                data.push(pushV[i++]);
                continue;
            }
            
            if(data.top() != popV[j]) {
               if(i < pushV.size()) data.push(pushV[i++]);  
               else return false;
            } else {
                data.pop();
                j++;
            }
        }
        if(i == pushV.size() && j == popV.size()) return true;
        return false;
        
    }
};