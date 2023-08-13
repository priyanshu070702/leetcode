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
    ListNode* reverse(ListNode* head){
        ListNode* p=head;
        ListNode* q=NULL;
        ListNode* r=NULL;
        while(p!=NULL){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    int cnt(int n){
        int cnt=0;
        while(n>0){
            cnt++;
            n=n/10;
        }
        return cnt;
    }
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);
        ListNode *temp=head;
        int carry=0;
        while(temp->next!=NULL){
            int mul=((temp->val)*2)+carry;
            int dig=mul%10;
            temp->val=dig;
            carry=mul/10;
            
            temp=temp->next;
        }
       // temp=temp->next;
        if(cnt((2*temp->val)+carry)>1){
            int sum=(2*(temp->val))+carry;
            temp->val=sum%10;
            ListNode *st=new ListNode(sum/10);
            temp->next=st;
        }
        else{
            temp->val=(2*(temp->val))+carry;
        }
        head=reverse(head);
        return head;
    }
};