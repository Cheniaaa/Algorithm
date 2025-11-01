/**
* 两两交换链表中的节点
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
 * 递归
 * @param head
 * @return
 */
ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

/**
 * 迭代（需要增加一个头节点）
 * @return
 */

int main() {

}