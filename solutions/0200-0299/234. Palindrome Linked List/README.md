<p><strong>Problem: [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/description/) <br>
<strong>Category:</strong> Linked List<br>
<strong>Difficulty:</strong> Easy<br>
<strong>Language:</strong> C++</p>

TC / SC = O(n) / O(1) 

<br>

<h3>Thought Process</h3>

<p>The code can be divided into 3 parts, and this problem is related to 3 previous LeetCode problems (problem 141, 876, 206) on <a href="https://www.techinterviewhandbook.org/grind75">Grind75</a> <br>

```cpp
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        // (1) Find the middle of the linked list
        /*
        cf. 141. Linked List Cycle
        cf. 876. Middle of the Linked List: 3 for 1~5; 4 for 1~6
        */
        ListNode* slow = head;
        ListNode* fast = head->next; // For edge cases

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // (2) Reverse the second half
        /*
        cf. 206. Reverse Linked List
        */
        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        ListNode* temp_next = nullptr;

        while (cur) {
            // Note the relationshop here
            temp_next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp_next;
        }
        // At this moment, cur is a nullptr

        // (3) Compare the first half and the second half
        /*
        Use pre as the condition here since cur is a nullptr now
        */
        while (pre) {
            if (pre->val != head->val) {
                return false;
            }
            pre = pre->next;
            head = head->next;
        }

        return true;
    }
};
```