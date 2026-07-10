/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* s1=headA;
        ListNode* s2=headB;
       while(s1 != s2){
        if(s1==NULL){
            s1=headB;
        }else{
             s1=s1->next;
        }
       
        if(s2==NULL){
            s2=headA;
        }else{
            s2=s2->next;
        }
        
       }
       return s1;
    }
};