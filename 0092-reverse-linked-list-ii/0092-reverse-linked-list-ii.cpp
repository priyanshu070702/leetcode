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
   ListNode* reverse(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode*l2=head->next;
        ListNode*ans=reverse(l2);
        l2->next=head;
        l2->next->next=NULL;
        return ans;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*runner=head;
        int count=1;
        ListNode*prev1=NULL;
        while(count!=left && runner!=NULL){
            prev1=runner;
            runner=runner->next;
            count++;
        }
        ListNode*rec=runner;
        ListNode*prev2=NULL;

        while(count!=right && runner!=NULL){
            prev2=runner;
            runner=runner->next;
            count++;
        }
        prev2=runner;
        runner=runner->next;
        prev2->next=NULL;
        if(prev1!=NULL){
            prev1->next=NULL;
        }
        

        ListNode*l3=reverse(rec);
        if(prev1!=NULL){
            prev1->next=l3;
        }
        
        else{
            head=l3;
        }
        rec->next=runner;

        return head;

        
    }
};