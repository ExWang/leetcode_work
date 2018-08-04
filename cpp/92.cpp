//92. Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int index = 1;
        ListNode *startNode, *endNode, *mtmpNode, *mstartNode, *i = head;
        if(m==n)
            return head;
        while(i!=NULL)
        {
            if(index == m) //start
            {
                endNode = i;
                startNode = endNode->next;
                mstartNode = i;
            }
            else if(index >m && index <n)
            {
                
                i=startNode->next;
                startNode->next = mstartNode;
                mstartNode = startNode;
                startNode = i;
                index++;
                continue;
            }
            else if(index==n && m!=1)
            {
                i=startNode->next;
                startNode->next = mstartNode;
                mstartNode = startNode;
                mtmpNode->next = startNode;
                endNode->next = i;
                return head;
            }
             else if(index==n && m==1)
            {
                i=startNode->next;
                startNode->next = mstartNode;
                mstartNode = startNode;
                head = startNode;
                endNode->next = i;
                return startNode;
            }
            else if(index == m-1 && m!=1)
            {
                mtmpNode = i;
            }
            index++;
            i=i->next;
        }
    }
};