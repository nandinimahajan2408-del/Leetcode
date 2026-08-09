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
    ListNode*findmiddle(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode*merge2ll(ListNode*head1,ListNode*head2){
        ListNode*t1=head1;
        ListNode*t2=head2;
        
        ListNode*dnode=new ListNode(-1);
        ListNode*temp=dnode;
        while(t1!=nullptr&&t2!=nullptr){
            if(t1->val<=t2->val){
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }else{
                temp->next=t2;
                t2=t2->next;
                temp=temp->next;
            }
        }
       if(t1!=nullptr) temp->next=t1;
       else temp->next=t2;

       return dnode->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode*middle=findmiddle(head);
        ListNode*lefthead=head;
        ListNode*righthead=middle->next;
        middle->next=nullptr;

        lefthead=sortList(lefthead);
        righthead=sortList(righthead);

        head=merge2ll(lefthead,righthead);
        return head; 
    }
};