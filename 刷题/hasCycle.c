/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
    if (head == NULL) return false;
    struct ListNode* slow_p = head;
    struct ListNode* quick_p = head;
    while (quick_p && quick_p->next)
    {
        slow_p = slow_p->next;
        quick_p = quick_p->next->next;
        if (slow_p == quick_p)
            return true;
    }
    return false;
}