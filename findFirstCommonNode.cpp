/*
题目:输入两个链表，找出它们的第一个公共结点。
*/
/*
思路:两个指针，一个指针走完pHead1接着走pHead2,
另一个指针走完pHead2接着走pHead1;
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2) return nullptr; //空链表的情况
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        while(cur1 != cur2) {
            if(cur1) cur1 = cur1->next;
            else cur1 = pHead2;
            
            if(cur2) cur2 = cur2->next;
            else cur2 = pHead1;
        }
        return cur1;
    }
};