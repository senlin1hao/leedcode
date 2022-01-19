#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

//迭代法
struct ListNode *reverseList(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    
    struct ListNode headNode;
    headNode.next = head;
    struct ListNode *pNode1 = head;
    struct ListNode *pNode2 = head;
    struct ListNode *pNode3 = &headNode;
    while (pNode1 != NULL)
    {
        pNode1 = pNode1->next;
        pNode2->next = pNode3;
        pNode3 = pNode2;
        pNode2 = pNode1;
    }
    head->next = NULL;
    head = pNode3;
    return head;
}