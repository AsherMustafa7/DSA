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
        ListNode* temp=head;
        ListNode* before=head;
        
        int c=0;
        while(c<n)
        {
            temp=temp-> next;
            c++;
        }
        if(temp==nullptr)
        {
            return head->next;
        }
        while(temp->next!=nullptr)
        {
            temp=temp->next;
            before=before->next;
        }
        before->next=before->next->next;
        return head;
    }
   
};