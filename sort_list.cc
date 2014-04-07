/*
 * =====================================================================================
 *
 *       Filename:  sort_list.cc
 *
 *    Description:  Sort a linked list in O(n log n) time using constant space complexity.
 *
 *        Version:  1.0
 *        Created:  04/03/2014 04:02:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Definition for singly-linked list.
 */
#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
private:
    /*  Split the nodes of the given list into front and back halves,
     *  and return the two lists using the reference parameters.
     *  If the length is odd, the extra node should go in the front list.
     *  Uses the fast/slow pointer strategy.  */
    void FrontBackSplit(ListNode *source, ListNode** front, ListNode** back)
    {
        ListNode *fast, *slow;
        if(source == NULL || source->next == NULL)
        {
            *front = source;
            *back = NULL;
        }
        else
        {
           slow = source;
           fast = source->next;

           while(fast)
           {
               fast = fast->next;
               if(fast)
               {
                   slow = slow->next;
                   fast = fast->next;
               }
           }
        }

        *front = source;
        *back = slow->next;
        slow->next = NULL;
    }

    ListNode *merge_sort(ListNode *a, ListNode *b)
    {
         ListNode *result = NULL;
         if(!a)
             return b;
         else if(!b)
             return a;

         if(a->val <= b->val)
         {
             result = a;
             result->next = merge_sort(a->next, b);
         }
         else
         {
             result = b;
             result->next = merge_sort(a, b->next);
         }
         return result;
    }

    void merge(ListNode **node) {
        ListNode *head = *node;
        ListNode *a;        
        ListNode *b;        

        if(head==NULL || head->next==NULL)
            return;

        FrontBackSplit(head, &a, &b);

        merge(&a);
        merge(&b);

        *node = merge_sort(a, b); 
    }


public:

    ListNode *sortList(ListNode *head) {
        merge(&head);
        return head;
    }
};

int main()
{
    Solution sol;

    ListNode a(4);
    ListNode b(3); a.next=&b;
    ListNode c(2); b.next=&c;
    ListNode d(1); c.next=&d;
    ListNode e(0); d.next=&e;

    ListNode *list=sol.sortList(&a);
    while(list)
    {
        std::cout<<list->val<<' '<<std::endl;
        list = list->next;
    }
    return 0;
}
