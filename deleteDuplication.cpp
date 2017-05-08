/*
题目:在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 
处理后为 1->2->5
*/
/*
思路:保留一个指向当前结点的前指针，然后判断当前元素是否存在相等，
存在相等，就找到与当前元素不相等的第一个元素，构成新的链表即可；
按照这样思路循环下去即可
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if(pHead == nullptr)
            return pHead;
        
        ListNode* cur = pHead;
        ListNode* prev = nullptr;
        while(cur){
           	//判断是否存在相等元素
            if(cur->next && cur->next->val == cur->val){
               	int tmpVal = cur->val;
                //找到与当前结点元素不相等的第一个结点
                while(cur && cur->val==tmpVal)
                    cur = cur->next;
                if(prev == nullptr) pHead = cur;
            	else prev->next = cur;
            }else{
                prev = cur;
                cur = cur->next;
            }
            
          
        }
        return pHead;
    }
};