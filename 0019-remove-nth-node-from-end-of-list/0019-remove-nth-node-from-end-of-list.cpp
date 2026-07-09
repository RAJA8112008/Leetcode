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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int Totalnode=0;
        ListNode* temp=head;
        while(temp!=NULL){
            Totalnode++;
            temp=temp->next;
        }
        int delnode=Totalnode-n;
        if(delnode==0){
            return head->next;
        }
        temp=head;
        int count=1;
        while(temp!=NULL && count<delnode){
            temp=temp->next;
            count++;
        }
        ListNode* deleteNode=temp->next;
        temp->next=deleteNode->next;
        return head;
    }
};