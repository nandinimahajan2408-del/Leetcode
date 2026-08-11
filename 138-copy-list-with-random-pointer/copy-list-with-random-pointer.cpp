/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* temp=head;
        while(temp!=nullptr){
            Node*newnode=new Node (temp->val);
            newnode->next=temp->next;
           temp->next=newnode;
           temp=temp->next->next;
        }

       Node*temp1=head;
        while(temp1!=nullptr){
           Node*copynode=temp1->next;
           if(temp1->random!=nullptr) copynode->random=temp1->random->next;
            temp1=temp1->next->next;
        }
        Node*dnode=new Node(-1);
        Node*res=dnode;
        Node*temp2=head;
        while(temp2!=nullptr){
            res->next=temp2->next;
            temp2->next=temp2->next->next;
            
            res=res->next;
            temp2=temp2->next;
        }
        return dnode->next;
        
    }
};