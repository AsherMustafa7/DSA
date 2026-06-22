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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp=headA;
        int c1=0;
        while(temp!=NULL)
        {
            c1++;
            temp=temp->next;
        }
        temp=headB;
        int c2=0;
        while(temp!=NULL)
        {
            c2++;
            temp=temp->next;
        }
        int d=abs(c1-c2);
        if(c2>c1)
        {
            for(int i =0; i<d;i++ )
            {
                headB=headB->next;
            }
        }
        else
        {
            for(int i =0; i<d;i++ )
            {
                headA=headA->next;
            }
        }
        int f=0;
        while(headA!=NULL)
        {
            if(headA==headB)
            {
                f=1;
                break;

            }
            headA=headA->next;
            headB=headB->next;
        }
        if(f==1)
        return headA;
        return nullptr;
    }
};