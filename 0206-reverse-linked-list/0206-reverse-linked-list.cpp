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
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
        return NULL;
        stack<int> st;
        ListNode* copy=head;
        while(copy!=NULL)
        {
            st.push(copy->val);
            copy=copy->next;
        }
        ListNode* curr=new ListNode(st.top());
        st.pop();
        ListNode* newhead=curr;
        while(!st.empty())
        {
            ListNode* newnode=new ListNode(st.top());
            
            st.pop();
            curr->next=newnode;
            curr=newnode;
        }

        return newhead;
    }
};