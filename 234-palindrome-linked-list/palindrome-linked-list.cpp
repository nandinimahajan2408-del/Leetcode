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
    ListNode*reversetheLL(ListNode*head){
        ListNode*temp=head;
        ListNode*prev=nullptr;
        while(temp!=nullptr){
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return true;
        ListNode *slow=head;
        ListNode *fast=head;
      while(fast->next!=nullptr&&fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
      } 
      ListNode *newhead=reversetheLL(slow->next); 
      ListNode *first=head;
      ListNode*  second=newhead;
      while(second!=nullptr){
        if(first->val!=second->val){
            return false;
        }
        second=second->next;
        first=first->next;
      }
      reversetheLL(newhead);
      return true;

    }
};