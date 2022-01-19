#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

//递归法
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    struct ListNode *pNode1 = head->next;
    if (pNode1 == NULL)
    {
        return head;
    }
    struct ListNode *pNode2 = reverseList(pNode1);
    pNode1->next = head;
    head->next = NULL; //防止链表起环！！！
    return pNode2;
}