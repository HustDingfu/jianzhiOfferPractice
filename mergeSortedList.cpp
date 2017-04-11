/*
题目:合并两个有序的链表
*/
/*
思路1: 循环实现,注意边界条件
思路2: 递归实现,逻辑稍微简单
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(nullptr == pHead1) return pHead2;
        if(nullptr == pHead2) return pHead1;
        ListNode* root;
        if(pHead1->val < pHead2->val) {
            root = pHead1;
            pHead1 = pHead1->next;
        }else {
            root = pHead2;
            pHead2 = pHead2->next;
        }
        ListNode* cur = root;
        while(pHead1 && pHead2) {
            if(pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        
        if(pHead1) {
            cur->next = pHead1;
        }else 
            cur->next = pHead2;
        return root;
            
    }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(nullptr == pHead1) return pHead2;
        if(nullptr == pHead2) return pHead1;
        ListNode* root;
        if(pHead1->val < pHead2->val) {
            root = pHead1;
            root->next = Merge(pHead1->next, pHead2);
        }else {
            root = pHead2;
            root->next = Merge(pHead1, pHead2->next);
        }
        
        return root; 
    }
};