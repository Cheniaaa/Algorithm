/**
 * 删除链表中倒数第n个节点
 */
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 双指针（前后指针）：使两个指针保持n的距离
 * @param head
 * @param n
 * @return
 */
ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *sentinel = new ListNode(-1, head);
    ListNode *firstP = head;
    ListNode *secondP = sentinel;
    for (int i = 0; i < n; ++i) {
        firstP = firstP->next;
    }
    while (firstP) {
        firstP = firstP->next;
        secondP = secondP->next;
    }
    secondP->next = secondP->next->next;
    head = sentinel->next;//考虑到删除第一个元素的情况
    delete sentinel;
    return head;
}

int main() {
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    for (int i = 0; i < 5; ++i) {
        ListNode *node = new ListNode(i + 1);
        temp->next = node;
        temp = temp->next;
    }

    ListNode *res = removeNthFromEnd(head, 3);
    while (res) {
        cout << res->val << '\t';
        res = res->next;
    }
}