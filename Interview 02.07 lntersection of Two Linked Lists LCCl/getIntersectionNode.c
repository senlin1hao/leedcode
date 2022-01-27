#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

//交点不是数值相等，而是指针相等
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int countA = 0;
    int countB = 0;
    struct ListNode *nodeLong = headA;
    struct ListNode *nodeShort = headB;

    while (nodeLong != NULL)
    {
        ++countA;
        nodeLong = nodeLong->next;
    }
    while (nodeShort != NULL)
    {
        ++countB;
        nodeShort = nodeShort->next;
    }
    
    int difference;
    if (countA < countB)
    {
        nodeLong = headB;
        nodeShort = headA;
        difference = countB - countA;
    }
    else
    {
        nodeLong = headA;
        nodeShort = headB;
        difference = countA - countB;
    }
    
    while (difference--)
    {
        nodeLong = nodeLong->next;
    }
    
    while (nodeLong != NULL)
    {
        if (nodeLong == nodeShort)
        {
            return nodeLong;
        }
        nodeLong = nodeLong->next;
        nodeShort = nodeShort->next;
    }
    
    return NULL;
}