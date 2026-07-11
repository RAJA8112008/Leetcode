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
ListNode* reverse(ListNode* head,int &count,int k){
    ListNode* next=NULL;
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int count=1;
        while(temp && count<k){
            temp=temp->next;
            count++;
        }
        //if count<k
        if (temp == NULL)
         return head;

        ListNode* nextnode=temp->next;
        temp->next=NULL;
        //reverse k nodes 
        int c=0;
       ListNode* node= reverse(head,c,k);
       
       head->next=reverseKGroup(nextnode,k);
      return node;
    }
};