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
    ListNode* deleteMiddle(ListNode* head) {
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if(count==1)return NULL;
        int delnode=count/2;
        count=1;
        temp=head;
        while(temp!=NULL && count<delnode){
            temp=temp->next;
            count++;
        }
        ListNode* deleteNode=temp->next;
        temp->next=deleteNode->next;
        return head;
    }
};