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
    void deleteNode(ListNode* node) 
    {
        if(node==NULL)
        return;
        ListNode* next=node->next;
        ListNode* prev=node;
        while(next!=NULL)
        {
            node->val=next->val;
            prev=node;
            node=node->next;
            next=next->next;
        }
        prev->next=NULL;
        delete(node);
    }
};