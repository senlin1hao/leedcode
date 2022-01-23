#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    struct ListNode Head;
    Head.next = head;
    struct ListNode* pNode1 = &Head;
    struct ListNode* pNode2;
    struct ListNode* pNode3;
    while ((pNode1->next != NULL) && (pNode1->next->next != NULL))
    {
        pNode2 = pNode1->next;
        pNode3 = pNode2->next;
        pNode2->next = pNode3->next;
        pNode1->next = pNode3;
        pNode3->next = pNode2;
        pNode1 = pNode2;
    }
    return Head.next;
}