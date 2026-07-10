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
ListNode* findMid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
    }
    return slow;
}
ListNode* merge(ListNode* left,ListNode* right){
       if(!left)return right;
        if(!right)return left;
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(left && right){
            if(left->val<=right->val){
                tail->next=left;
                left=left->next;
            }else{
                tail->next=right;
                right=right->next;
            }
            tail=tail->next;
        }
        //copy renmaining 
        while(left){
            tail->next=left;
            tail=tail->next;
            left=left->next;
        }
         while(right){
            tail->next=right;
            tail=tail->next;
            right=right->next;
        }
        return dummy->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        //Merge Sort 
        ListNode* mid=findMid(head);
        ListNode* nextmid=mid->next;
        //divide into two parts 
        mid->next=NULL;
        //divide both untill single unit 
        ListNode* left= sortList(head);
        ListNode* right= sortList(nextmid);
        //merge both 
        return merge(left,right);
    }
};