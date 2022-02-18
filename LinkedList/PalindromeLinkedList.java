
class Solution {
  public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
   }
   public boolean isPalindrome(ListNode head) {
    ListNode fast=head, slow=head;
    while (fast != null && fast.next != null) 
    {
      fast = fast.next.next;
      slow = slow.next;
    }
    if (fast !=null) { // odd nodes: let right half smaller
      slow = slow.next;
    }
    slow = reverse(slow);
    fast = head;

    while (slow != null && fast != null)
    {
      if (slow.val != fast.val) return false;
      fast = fast.next;
      slow = slow.next;
    }
    return true;
   }

   public ListNode reverse(ListNode head) 
   {
     ListNode prev = null;

     while (head != null)
     {
       ListNode temp = head.next;
       head.next = prev;
       prev=head;
       head=temp;
     }
     return prev;
   }
}