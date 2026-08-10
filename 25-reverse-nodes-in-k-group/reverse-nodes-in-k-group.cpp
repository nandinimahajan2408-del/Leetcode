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

    ListNode*getthkthnode(ListNode*temp,int k){
        k=k-1;
        while(temp!=nullptr&&k>0){
            k--;
            temp=temp->next;
        }
        return temp;

    }

    ListNode*reversell(ListNode*head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }

        ListNode*newhead=reversell(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
        
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*prev=nullptr;
        ListNode*temp=head;
        while(temp!=nullptr){
        ListNode*kthnode=getthkthnode(temp,k);
        if(kthnode==nullptr){
            if(prev) prev->next=temp;
            break;
        }

        ListNode* nxtnode=kthnode->next;
        kthnode->next=nullptr;
        reversell(temp);
        if(temp==head){
            head=kthnode;
        }else{
            prev->next=kthnode;
        }
        prev=temp;
        temp=nxtnode;
        }
        return head;

    }
};