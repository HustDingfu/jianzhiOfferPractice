/*
题目:输入一个链表，输出该链表中倒数第k个结点。
*/
/*
思路:两个指针，一个先走K步;
注意:k过大,或者pListHead为NULL
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	ListNode* cur = pListHead;
        int cnt = k;
        while(cur && cnt > 0){
            cur = cur->next;
            cnt--;
        }
		//k值过大的情况
        if(cnt != 0) return nullptr;
        ListNode* prev = pListHead;
        while(cur){
            cur = cur->next;
            prev = prev->next;
        }
        return prev;
    }
};