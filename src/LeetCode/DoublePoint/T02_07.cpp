/**
* 链表相交
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 双指针
 * @param headA
 * @param headB
 * @return
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA;
    ListNode *pB = headB;
    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    while (pA != pB) {
        pA = pA == nullptr ? headB : pA->next;
        pB = pB == nullptr ? headA : pB->next;
    }
    return pA;
}

/**
 * 哈希表法
 * @return
 */




int main() {

}