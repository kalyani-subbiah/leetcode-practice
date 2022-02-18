#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      ListNode *odd = head;
      ListNode *evenhead = head->next, *even=evenhead;
      while (even && even->next) 
      {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd=odd->next;
        even=even->next;
      }
      odd->next=evenhead;
      return head;
    }
};