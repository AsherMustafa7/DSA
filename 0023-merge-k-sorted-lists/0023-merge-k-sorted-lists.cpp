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
    struct compare
    {
        bool operator()(ListNode* A, ListNode* B)
        {
            return A->val>B->val;
        }
        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>,compare>pq;
        for(int i=0;i<lists.size();i++)
        {   if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        if(pq.empty())
        {
            return nullptr;
        }
        
        ListNode* head=nullptr;
        ListNode* temp=nullptr;
         if(head==nullptr)
            {
                head=pq.top();
                temp=head;
                pq.pop();
                if(temp->next!=NULL)
                pq.push(temp->next);
            }
        while(!pq.empty())
        {
           
                ListNode* newnode=nullptr;
                newnode=pq.top();
                pq.pop();
                if(newnode->next!=NULL)
                pq.push(newnode->next);
                temp->next=newnode;
                temp=newnode;
        }
        return head;
    }
};