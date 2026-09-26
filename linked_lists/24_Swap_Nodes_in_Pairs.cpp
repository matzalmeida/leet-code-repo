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
public:
    ListNode* swapPairs(ListNode* head) {
        int i = 0;
        ListNode *prev = NULL, *it = head;
        while (it != NULL) {
            if (it->next == NULL) {
                return head;
            } else if (it == head) {
                head = it->next;
                it->next = head->next;
                head->next = it;
                prev = it;
            } else {
                prev->next = it->next;
                it->next = prev->next->next;
                prev->next->next = it;
                prev = it;
            }
            it = it->next;
        }
        return head;
    }
};
