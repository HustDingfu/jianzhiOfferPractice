/*
题目:用两个栈来实现一个队列，完成队列的Push和Pop操作。 
队列中的元素为int类型。
*/
/*
思路: 一个栈用用来保存进队的序列,另一个栈用来保存出队的
队列;当需要进队的时候就向第一个栈push元素即可,当需要出队
的时候,如果第二个栈不为空,直接出栈即可;如果为空,则将第一
个栈的元素全部出栈同时进栈到第二个栈。
*/

class Solution
{
public:
    const int NoNodeReturn = -1;
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        if(stack2.empty() && stack1.empty())
            return NoNodeReturn;
         
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int head = stack2.top();
        stack2.pop();
        return head;       
    }
 
private:
    stack<int> stack1;//用来保存进队的
    stack<int> stack2;//用来保存出队的
};