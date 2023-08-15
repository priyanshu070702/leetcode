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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small=new ListNode();
        ListNode* large=new ListNode();
        ListNode* temp=head;
        head=small;
        ListNode* large_head=large;
        while(temp!=NULL){
            if(temp->val<x){
                ListNode *st=new ListNode(temp->val);
                small->next=st;
                small=small->next;
            }
            else if(temp->val>=x){
                ListNode *st=new ListNode(temp->val);
                large->next=st;
                large=large->next;
            }
            temp=temp->next;
        }
        small->next=large_head->next;
        head=head->next;
        return head;
    }
};