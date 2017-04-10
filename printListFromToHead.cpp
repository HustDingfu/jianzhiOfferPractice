/*
题目:输入一个链表，从尾到头打印链表每个节点的值。
*/
/*
思路1: 用栈;
思路2: 递归实现
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
vector<int> printListFromTailToHead(ListNode* head) {
    stack<int> st;
    ListNode* cur = head;
    while(cur){
        st.push(cur->val);
        cur = cur->next;
    }
    vector<int> res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
         
    return res;
}
