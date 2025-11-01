#include <unordered_set>
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 双指针法
 * @param head
 * @return
 */
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (!fast->next) {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }

    }
    return nullptr;
}

/**
 * 哈希表法
 * @param head
 * @return
 */
ListNode *detectCycle1(ListNode *head) {
    unordered_set<ListNode *> node;//底层为哈希表
    while (head != nullptr) {
        if (node.count(head)) {
            return head;
        }
        node.insert(head);
        head = head->next;
    }
    return nullptr;
}

int main() {

};