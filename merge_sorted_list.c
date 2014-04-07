/*
 * =====================================================================================
 *
 *       Filename:  merge_sorted_list.cc
 *
 *    Description:  合并有序链表，给定两个升序的链表，返回一个合并之后的升序链表
 *
 *        Version:  1.0
 *        Created:  04/04/2014 08:22:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  billowkiller (), billowkiller@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <assert.h>

struct node{
    int val;
    struct node *next;
};
typedef struct node Node;

Node* mergeList(Node *list_a, Node* list_b)
{
    assert(list_a || list_b);
    if(list_a == NULL) return list_b;
    if(list_b == NULL) return list_a;
    Node *list = (Node *)malloc(sizeof(Node));
    Node *t = list;
    while(list_a && list_b){
        if(list_a->val < list_b->val){
            t->next = list_a;
            list_a = list_a->next;
        }else{
            t->next = list_b;
            list_b = list_b->next;
        }
        t = t->next;
    }
    while(list_a){
        t->next = list_a;
        list_a = list_a->next;
        t = t->next;
    }
    while(list_b){
        t->next = list_b;
        list_b = list_b->next;
        t = t->next;
    }
    t = list->next;
    free(list);
    return t;
}

void printList(Node* list)
{
    printf("hello\n");
    while(list)
    {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

int main(){
    Node *list_a = (Node*)malloc(sizeof(Node));
    Node *list_b = (Node*)malloc(sizeof(Node));
    list_a->val = 1;
    list_b->val = 9;
    int i;
    Node *l1 = list_a, *l2=list_b;
    for(i=0; i<6; i++)
    {
        Node *a = (Node*)malloc(sizeof(Node));
        Node *b = (Node*)malloc(sizeof(Node));
        a->val = i+2; a->next = NULL;
        b->val = i+9; b->next = NULL;
        l1->next = a;
        l2->next = b;
        l1 = a;
        l2 = b;
    }

    printList(list_a);
    printList(list_b);
    Node * list = mergeList(NULL, NULL);
    printList(list);
    return 0;
}
