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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        vector<int>v;
        ListNode* copy=head->next;
        int p=1;
        ListNode* prev=head;
        while(copy!=NULL)
        {   
            if(copy!=head && copy->next!=NULL)
            {
                if(copy->val>prev->val && copy->val > copy->next->val)
                {
                    v.push_back(p);
                }
                if(copy->val<prev->val && copy->val < copy->next->val)
                {
                    v.push_back(p);
                }
            }
            prev=copy;
            copy=copy->next;
            p++;
        }
        if(v.size()<2)
        {
            return {-1,-1};
        }
        int maxd=v[v.size()-1]-v[0];
        int mind=INT_MAX;
        for(int i=0; i <v.size();i++)
        {
            if(i!=v.size()-1)
            mind=min(v[i+1]-v[i],mind);
        }
        return {mind,maxd};
    }
};