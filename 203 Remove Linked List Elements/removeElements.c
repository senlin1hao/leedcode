#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
    int val;
    struct ListNode *next;
};

//新建一个虚拟头结点，其在栈中
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode Head;
    Head.next = head;

    struct ListNode *pListNode1 = Head.next;
    struct ListNode *pListNode2 = &Head;
    while (pListNode1 != NULL)
    {
        if (pListNode1->val == val)
        {
            pListNode1 = pListNode1->next;
            free(pListNode2->next);
            pListNode2->next = pListNode1;
            continue;
        }
        pListNode1 = pListNode1->next;
        pListNode2 = pListNode2->next;
    }
    return Head.next;
}