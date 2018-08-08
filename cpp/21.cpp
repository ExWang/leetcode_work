//21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* pl1, ListNode* pl2) {
        ListNode *head, *tmp, *h1;
        // pl1 = l1;
        // pl2 = l2;
        if((pl1!=NULL) && (pl2==NULL))
        {
            head = pl1;
            pl1 = pl1->next;
        }
        else if((pl2!=NULL) && (pl1==NULL))
        {
            head = pl2;
            pl2 = pl2->next;
        }
        else if((pl1!=NULL) && (pl2!=NULL))
        {
            if(pl1->val <= pl2->val)
            {
                head = pl1;
                pl1 = pl1->next;
            }
            else
            {
                head = pl2;
                pl2 = pl2->next;
            }
        }
        else
        {
            head = NULL;
            return head;
        }
        // tmp = head;
        h1 = head;
        while((pl1!=NULL) || (pl2!=NULL))
        {
            if((pl1!=NULL) && (pl2!=NULL))
            {
                if(pl1->val <= pl2->val)
                {
                    tmp = pl1;
                    pl1 = pl1->next;
                    head->next = tmp;
                }
                else if(pl1->val >= pl2->val)
                {
                    tmp = pl2;
                    pl2 = pl2->next;
                    head->next = tmp;
                }
            }
            else if((pl1!=NULL) && (pl2==NULL))
            {
                head->next = pl1;
                pl1 = pl1->next;
            }
            else if((pl1==NULL) && (pl2!=NULL))
            {
                head->next = pl2;
                pl2 = pl2->next;
            }
            head=head->next; 
        }
        head->next = NULL;
        return h1;
    }
};
