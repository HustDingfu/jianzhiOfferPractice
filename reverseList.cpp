/*
题目:反转链表
*/
/*
思路1: 声明三个指针prev->cur->next;每次循环记录next节点
针对cur节点进行操作,循环直到cur==null位置,此时prev为
最后一个节点，返回他作为反转链表的头节点；
思路2: 利用递归实现
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        
        ListNode* cur = pHead;
        ListNode* prev = nullptr;
        ListNode* next;
        
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;

    }
};