#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

//一趟扫描实现
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode Head;
    Head.next = head;
    struct ListNode *pNode1 = &Head;
    struct ListNode *pNode2 = head;
    for (int i = 1; i < n; i++)
    {
        pNode2 = pNode2->next;
    }
    
    while (pNode2->next != NULL)
    {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }

    pNode2 = pNode1->next;
    pNode1->next = pNode2->next;
    free(pNode2);
    
    return Head.next;
}