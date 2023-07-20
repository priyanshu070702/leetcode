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
    ListNode* mid(ListNode* head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* p=NULL;
        ListNode* q=NULL;
        while(curr!=NULL){
            q=p;
            p=curr;
            curr=curr->next;
            p->next=q;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL){
            return true;
        }
        
        //finding middle
        ListNode* middle=mid(head);
        
        //reversing half linkedlist
        ListNode *temp=middle->next;
        middle->next=reverse(temp);
        
        //comparing 
        ListNode* head1=head;
        ListNode* head2=middle->next;
        while(head2!=NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        
        temp=middle->next;
        middle->next=reverse(temp);
        
        return true;
    }
};