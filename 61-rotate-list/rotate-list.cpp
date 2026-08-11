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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||k==0) return head;
        ListNode*tail=head;
        int len=1;
        while(tail->next!=nullptr){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
        k=k%len;
        //k=k-1;
        int cnt=len-k-1;
        ListNode*slow=head;
        while(slow!=nullptr&&cnt>0){
            cnt--;
            slow=slow->next;
        }

        tail->next=head;
        head=slow->next;
        slow->next=nullptr;
        return head;
    }
};