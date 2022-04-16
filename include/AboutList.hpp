#pragma once
#include "Util.h"

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
            return nullptr;
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;

        bool p1_p2 = true;
        bool p2_p1 = true;
        while (p1 || p2)
        {
            if (p1->val == p2->val)
                return p1;
            if (!p1->next)
            {
                if (!p1_p2)
                    return nullptr;
                p1 = pHead2;
                p1_p2 = false;
            }
            else
            {
                p1 = p1->next;
            }
            if (!p2->next)
            {
                if (!p2_p1)
                    return nullptr;
                p2 = pHead1;
                p2_p1 = false;
            }
            else
            {
                p2 = p2->next;
            }
        }
        return nullptr;
    }
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (!pHead->next || !pHead->next->next)
            return nullptr;
        ListNode *slow = pHead->next;
        ListNode *fast = pHead->next->next;

        while (fast)
        {
            if (fast->next && fast->next->next)
            {
                if (fast == slow)
                {
                    fast = pHead;
                    while (fast != slow)
                    {
                        fast = fast->next;
                        slow = slow->next;
                    }
                    return fast;
                }
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return nullptr;
    }
};
struct RandomListNode
{

    int label;

    struct RandomListNode *next, *random;

    RandomListNode(int x): label(x), next(NULL), random(NULL)
    {
    }
};
class SolutionJZ35
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (!pHead)
            return pHead; // 为空则返回
        RandomListNode *cur = pHead;
        while (cur)
        {
            RandomListNode *tmp = new RandomListNode(cur->label); // 拷贝节点
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        RandomListNode *old = pHead, *clone = pHead->next, *ret = pHead->next;
        while (old)
        {
            clone->random = old->random == NULL ? NULL : old->random->next; // 处理拷贝节点的随机指针
            if (old->next)
                old = old->next->next; // 注意特判空指针
            if (clone->next)
                clone = clone->next->next;
        }

        old = pHead, clone = pHead->next;
        while (old)
        { // 拆分链表
            if (old->next)
                old->next = old->next->next;
            if (clone->next)
                clone->next = clone->next->next;
            old = old->next;
            clone = clone->next;
        }

        return ret;
    }
};
void printList(ListNode *head)
{
    ListNode *p = head;
    cout << "List:";
    while (p)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
void test(){
    Solution t;
    ListNode a1(1);
    ListNode a2(2);
    ListNode a3(3);
    ListNode a4(4);
    ListNode a5(5);

    ListNode b1(4);
    ListNode b2(5);

    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    a5.next = &a3;

    b1.next = &b2;
    b2.next = &a4;

    printList(&a1);
    printList(&b1);

    // ListNode *c = t.FindFirstCommonNode(&a1, &b1);
    // printList(c);
    ListNode *c = t.EntryNodeOfLoop(&a1);
    printList(c);
}