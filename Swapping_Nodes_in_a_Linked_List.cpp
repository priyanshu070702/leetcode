class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p=head;
        while(--k){
            p=p->next;
        }
        ListNode* backmove=head;
        ListNode* frontmove=p;
        while(frontmove->next!=NULL){
            frontmove=frontmove->next;
            backmove=backmove->next;
        }
        swap(p->val,backmove->val);
        return head;
    }
};
