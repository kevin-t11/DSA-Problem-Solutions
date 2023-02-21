/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  private:
  
  ListNode* getMiddle(ListNode* head)
  {
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast != NULL && fast->next != NULL)
    {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
  
  ListNode* reverse(ListNode* head)
  {
    if(head->next == NULL)
    {
      return head;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* forward = NULL;
    
    while(curr != NULL)
    {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
    }
    return prev;
  }
public:
    bool isPalindrome(ListNode* head) {
      // only one Node in list
      if(head->next == NULL)
      {
        return head;
      } 
      
      //step 1: find middle Node
      ListNode* middle = getMiddle(head);
      
      //step 2: reverse list after middle
      ListNode* temp = middle->next;
      
      temp = reverse(temp);
      
      //step 3: check two halves are equal or not ?
      ListNode* head1 = head;
      ListNode* head2 = temp;
      
      while(head2 != NULL)
      {
        if(head1->val != head2->val)
        {
          return false;
        }
        
        head1 = head1->next;
        head2 = head2->next;
      }
      
      //strp 4: repeat step 2 (optional)
      temp = middle->next;
      temp = reverse(temp);
      
      return true;
    }
};