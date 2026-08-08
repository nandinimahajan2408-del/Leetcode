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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode*temp=head;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        if(temp==nullptr) return head->next;
        ListNode*nth=head;
        while(temp->next!=nullptr){
            temp=temp->next;
            nth=nth->next;
        }
        
      ListNode* del=nth->next;
      nth->next=nth->next->next;
      delete(del);
      return head;
    }
};