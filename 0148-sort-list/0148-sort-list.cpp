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
    ListNode* sortList(ListNode* head) 
    {
        vector<int>v;
        ListNode*copy=head;
        while(copy!=NULL)
        {
            v.push_back(copy->val);
            copy=copy->next;
        }
        sort(v.begin(),v.end());
        
        for(int i =0; i <v.size();i++)
        {
            ListNode* newnode=new ListNode(v[i]);
            if(i==0)
            {
                head=newnode;
                copy=head;
            }
            else
            {
                copy->next=newnode;
                copy=copy->next;
            }
        }
        return head;
    }
};