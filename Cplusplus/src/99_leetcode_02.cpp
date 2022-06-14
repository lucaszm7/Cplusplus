#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "lzm.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>


/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#include <string>
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* r = new ListNode(-1);
        ListNode* p = r;

        int il1 = 0, il2 = 0, carry = 0;

        while (l1 || l2 || carry != 0)
        {
            if (l1)
            {
                il1 = l1->val;
                l1 = l1->next;
            }
            else
            {
                il1 = 0;
            }

            if (l2)
            {
                il2 = l2->val;
                l2 = l2->next;
            }
            else
            {
                il2 = 0;
            }

            int temp = il1 + il2 + carry;

            p->next = new ListNode(temp % 10);
            carry = temp / 10;
            p = p->next;
        }

        if (carry != 0)
            p->next = new ListNode(carry);

        return r->next;

    }
};

int leetcode_02()
{
    // [2,4,9]
    // [5, 6, 4, 9]
    /*ListNode l3(3), l2(4, &l3), l1(2, &l2);
    ListNode ll3(4), ll2(6, &ll3), ll1(5, &ll2);*/

    {
        ListNode l3(3), l2(4, &l3), l1(2, &l2);
        ListNode ll3(4), ll2(6, &ll3), ll1(5, &ll2);

        ListNode* r1;

        Solution sol;
        r1 = sol.addTwoNumbers(&l1, &ll1);

        while (r1 != nullptr)
        {
            std::cout << r1->val << " - ";
            r1 = r1->next;
        }
        std::cout << "\n";
    }

    {
        ListNode l3(9), l2(4, &l3), l1(2, &l2);
        ListNode ll4(9), ll3(4, &ll4), ll2(6, &ll3), ll1(5, &ll2);

        ListNode* r1;

        Solution sol;
        r1 = sol.addTwoNumbers(&l1, &ll1);

        while (r1 != nullptr)
        {
            std::cout << r1->val << " - ";
            r1 = r1->next;
        }


    }

    std::cout << "\n";

    {
        /*[9]
          [1, 9, 9, 9, 9, 9, 9, 9, 9, 9]*/
        ListNode l1(9);
        ListNode ll10(9), ll9(9, &ll10), ll8(9, &ll9), ll7(9, &ll8), ll6(9, &ll7),
            ll5(9, &ll6), ll4(9, &ll5), ll3(9, &ll4), ll2(9, &ll3), ll1(1, &ll2);

        ListNode* r1;

        Solution sol;
        r1 = sol.addTwoNumbers(&l1, &ll1);

        while (r1 != nullptr)
        {
            std::cout << r1->val << " - ";
            r1 = r1->next;
        }
    }

    std::cin.get();
    return 0;
}