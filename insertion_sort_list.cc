/*
 * =====================================================================================
 *
 *       Filename:  insertion_sort_list.cc
 *
 *    Description:  Sort a linked list using insertion sort.
 *
 *        Version:  1.0
 *        Created:  04/25/2014 08:50:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution {
    public:
        ListNode *insertionSortList(ListNode *head){
            if(head == NULL)
                return head;

            ListNode *node = new ListNode(0); 
            node->next = head;
			ListNode *end = NULL;
            while(node->next != end)
            {
                ListNode *p = node;
				head = p->next;
                while(head->next != end)
                {
                    if(head->val > head->next->val)
                    {
                       p->next = head->next;
                       head->next = p->next->next;
                       p->next->next = head;
                    }
                   p = p->next;
                   head = p->next;
                }
                end = head;
            }
            head = node->next;
            delete(node);
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

    ListNode *list=sol.insertionSortList(&a);
    while(list)
    {
        std::cout<<list->val<<' '<<std::endl;
        list = list->next;
    }
    return 0;
}

