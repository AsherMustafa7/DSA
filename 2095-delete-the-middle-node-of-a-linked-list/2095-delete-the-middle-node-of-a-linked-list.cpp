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
        if(head->next==NULL)
        {
            return NULL;
        }
        ListNode* first=head;
        ListNode* prev=NULL;
        ListNode* second=head;
        while(second!=NULL && second->next!=NULL)
        {
            second=second->next->next;
            prev=first;
            first=first->next;
        }
        prev->next=first->next;
        first->next=NULL;
        delete(first);
        return head;
    }
};