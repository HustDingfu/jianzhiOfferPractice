/*
题目:输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，
输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
/*
思路:分三步走。
1)为每个节点产生对应的新节点，插入原链表节点的后面；
2)为复制的节点为random指针赋值
3)将链表拆分成两个链表
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
     	RandomListNode* cur = pHead;
        //复制链表节点N的M,将节点M插入到N的后面；
        while(cur) {
     		RandomListNode* newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
         	cur = newNode->next;
        }
        
        //将复制节点M的random指向节点N的random指针的下一位
       	cur = pHead;
        while(cur) {
            if(cur->random)
                cur->next->random = cur->random->next;
            else 
                cur->next->random = nullptr;
            cur = cur->next->next;
        }
        
        //将链表拆分成两个链表
        if(!pHead) return pHead;
        RandomListNode* clonedHead = pHead->next;
        
        cur = pHead;
        while(cur){
			RandomListNode* tmpNode = cur->next;
            cur->next = tmpNode->next;
            if(tmpNode->next) 
                tmpNode->next = tmpNode->next->next;
           cur = cur->next;
        }
        
        return clonedHead;
        
    }
};