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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1;
        stack<int>s2;
        ListNode* h1=l1;
        while(h1!=NULL){
            s1.push(h1->val);
            h1=h1->next;
        }
        ListNode* h2=l2;
        while(h2!=NULL){
            s2.push(h2->val);
            h2=h2->next;
        }
        int carry=0;
        ListNode* temp=new ListNode();
        ListNode* head=temp;
        while(!s1.empty()||!s2.empty()||carry!=0){
            int sum=carry;
            if(!s1.empty()){
                sum+=s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum+=s2.top();
                s2.pop();
            }
            carry=sum/10;
            ListNode *add=new ListNode(sum%10);
            head->next=add;
            head=add;
        }

        ListNode *st=temp->next;
        ListNode *p=NULL;
        ListNode *q=NULL;
        ListNode *r=st;
        while(r!=NULL){
            p=q;
            q=r;
            r=r->next;
            q->next=p;
        }
        temp=q;
        return temp;
    }
};