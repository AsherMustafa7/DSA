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
    ListNode *detectCycle(ListNode *head) 
    {
        unordered_map<ListNode*,int>mp;
        ListNode* newnode=head;
        while(newnode!=NULL)
        {
            mp[newnode]++;
            if(mp[newnode]>1)
            {
                return newnode;
            }
            newnode=newnode->next;
        }
        return NULL;
    }
};