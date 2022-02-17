#include <cstdlib>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
      this->val=val;
      next=NULL;
    };
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *slow = head, *fast = head;
      for (int i=0; i<n; i++) fast = fast->next;
      if (!fast) return head->next;
      while (fast->next) fast = fast->next, slow=slow->next;
      slow->next = slow->next->next;
      return head;
    }
};