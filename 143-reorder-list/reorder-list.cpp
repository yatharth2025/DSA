
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *cur = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;

        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode *a = head, *b = prev;
        while (b) {
            ListNode* x = a->next;
            ListNode* y = b->next;
            a->next = b;
            b->next = x;
            a = x;
            b = y;
        }
    }
};
