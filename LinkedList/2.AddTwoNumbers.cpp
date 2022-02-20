#include <cstddef>
#include <iostream>

struct ListNode 
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode dummy(0);
      ListNode *l3 = &dummy;
      int carry = 0;

      while (l1!=nullptr && l2 !=nullptr)
      {
        int total = (l1 == nullptr ? l1->val : 0) + (l2 == nullptr ? l2->val : 0) + carry;
        if (total > 9)
        {
          carry = total / 10;
          total = total % 10;
        }
        else
        {
          carry = 0;
        }
        l3->next = new ListNode(total);
        l3 = l3->next;
        std::cout << total << std::endl;

        l1 = l1->next;
        l2=l2->next;
      }
      return dummy.next;
    }
};
