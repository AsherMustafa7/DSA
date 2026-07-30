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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        vector<int>v;
        ListNode* copy1=list1;
        ListNode* copy2=list2;
        while(copy1!=NULL)
        {
            v.push_back(copy1->val);
            copy1=copy1->next;
        }
        while(copy2!=NULL)
        {
            v.push_back(copy2->val);
            copy2=copy2->next;
        }
        sort(v.begin(),v.end());
        ListNode* head=NULL;
        ListNode* temp=NULL;
        for(int i=0; i <v.size();i++)
        {
            ListNode* newnode=new ListNode(v[i]);
            if(i==0)
            {
                head=newnode;
                temp=head;
            }
            else
            {
                temp->next=newnode;
                temp=newnode;
            }
        }
        return head;
    }
};