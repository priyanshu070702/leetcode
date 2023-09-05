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
        unordered_map<Node*,Node*>mp;
        Node* temp=new Node(0);
        Node* tmp=head;
        Node* sol=temp;
        while(tmp)
        {
            if(tmp && !mp[tmp])
            {
                temp->next=new Node(tmp->val);
                mp[tmp]=temp->next;
            }
            else temp->next=mp[tmp];
            if(tmp->random && !mp[tmp->random])
            {
                temp->next->random=new Node(tmp->random->val);
                mp[tmp->random]=temp->next->random;
            }
            else temp->next->random=mp[tmp->random];
            temp=temp->next;
            tmp=tmp->next;
        }
        return sol->next;
    }
};