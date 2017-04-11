/*
题目:定义栈的数据结构，请在该类型中实现一个
能够得到栈最小元素的min函数。
*/
/*
思路:两个栈，一个为数据栈，一个为存储最小值的
辅助栈。元素入数据栈的时候，如果元素小于辅助栈的
top元素就要压入辅助栈；元素出栈的时候，要判断出栈
是不是等于辅助栈的top元素，如果等于，辅助栈topo元素
也要出栈。
注意:关于非正常操作，该如何处理，值得商量，这里是抛出
异常。
*/
class Solution {
public:
    void push(int value) {
        data.push(value);
        if(minValue.empty() || min() >= value)
            minValue.push(value);
    }
    void pop() {
        if(data.empty())
            throw new exception;
        
        if(min() == data.top())
            minValue.pop();
        
        data.pop();
    }
    
    int top() {
       if(data.empty())
        	throw new exception;
        
        return data.top();
    }
    int min() {
        if(minValue.empty())
            throw new exception;
        return minValue.top();
    }
private:
	stack<int> data;
    stack<int> minValue;
};
