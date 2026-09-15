/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode*recursion(ListNode*fnode,ListNode*lnode){
        if(fnode==nullptr) return nullptr;
       if(lnode==nullptr) return fnode;
       
        if(lnode->next==nullptr){
            lnode->next=fnode;
            fnode->next=nullptr;
            return lnode;
        }
        ListNode*newhead=recursion(lnode->next,lnode->next->next);
        lnode->next=fnode;
        fnode->next=newhead;
        return lnode;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr) return nullptr;
       return recursion(head,head->next);
    }
};