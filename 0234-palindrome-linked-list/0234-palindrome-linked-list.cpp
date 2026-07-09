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
    ListNode* prev=NULL;
    ListNode* next=NULL;
    ListNode* curr=head;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
 }
    bool isPalindrome(ListNode* head) {
        //find middle of LL 
        if(head==NULL || head->next==NULL)return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow is pointing middle of LL
        ListNode* newHead=reverse(slow->next);
        ListNode* h1=newHead;
        ListNode* h2=head;
        while(h1){
            if(h1->val != h2->val)return false;
            h1=h1->next;
            h2=h2->next;
        }
        return true;
    }
};