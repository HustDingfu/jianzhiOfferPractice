/*
题目:一个链表中包含环，请找出该链表的环的入口结点。
*/

/*
思路:两个指针，快指针每次走两步，慢指针走一步，当他们第一次相遇的
时候，快指针比慢指针多的步数是环的长度的整数倍（不妨假设相等且为L）

此时把一个指针重置链表的头指针和另外一个指针同时往前走一步，当他们进入环中
之后，指针时时刻刻都会相等，那么什么时候会第一次相等呢？那里就是环的入口
结点出。
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if(pHead == nullptr) return pHead;
        ListNode* back = pHead;
        ListNode* front = pHead;
        
        while(front)
        {
            if(front->next == nullptr)
                return nullptr;
            front = front->next->next;
            back = back->next;
            if(front == back) break;
        }
        
        back = pHead;
        while(back != front)
        {
            back = back->next;
            front = front->next;
        }
        return back;
        
    }
};