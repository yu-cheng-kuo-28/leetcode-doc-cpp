/*
[Easy]
234. Palindrome Linked List
https://leetcode.com/problems/palindrome-linked-list/
*/

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
[Overview]
1. Finding the middle -> 2. Reversal -> 3. Comparison
*/
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
