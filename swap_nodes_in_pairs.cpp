class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *temp=new ListNode();
        ListNode *prev=temp;
        ListNode *curr=head;
        while(curr!=NULL && curr->next!=NULL){
            prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return temp->next;
    }
};
