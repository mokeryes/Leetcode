/*
 *  两数相加
 */

#include <iostream>

using namespace std;

struct ListNode {
    int value; 
    ListNode *next;
    ListNode() : value(0), next(nullptr) {}
    ListNode(int x) : value(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : value(x), next(next) {}
};

class Solution {
    public:
        // 充分遍历两个链表
        ListNode* addTwoNumbersFirstway(ListNode *l1, ListNode *l2) {
            ListNode *numList = new ListNode();
            ListNode *head = numList;

            while (l1 && l2) {
                int tmp = l1 -> value + l2 -> value + numList -> value;
                if (tmp >= 10) {
                    numList -> value = tmp - 10;
                    numList -> next = new ListNode(1);
                } else {
                    numList -> value += l1 -> value + l2 -> value;
                    if (l1 -> next || l2 -> next)
                        numList -> next = new ListNode();
                }

                l1 = l1 -> next;
                l2 = l2 -> next;
                numList = numList -> next;
            }

            while (l1 && !l2) {
                int tmp = l1 -> value + numList -> value;
                if (tmp >= 10) {
                    numList -> value = tmp - 10;
                    numList -> next = new ListNode(1);
                } else {
                    numList -> value += l1 -> value;
                    if (l1 -> next)
                        numList -> next = new ListNode();
                }

                l1 = l1 -> next;
                numList = numList -> next;
            }

            while (l2 && !l1) {
                int tmp = l2 -> value + numList -> value;
                if (tmp >= 10) {
                    numList -> value = tmp - 10;
                    numList -> next = new ListNode(1);
                } else {
                    numList -> value += l2 -> value;
                    if (l2 -> next)
                        numList -> next = new ListNode();
                }

                l2 = l2 -> next;
                numList = numList -> next;
            }
            
            return head;
        }

        // 充分遍历一个链表之后，将一个链表加到另一个链表后面
        ListNode* addTwoNumbersSecondway(ListNode *l1, ListNode *l2) {
            ListNode *head1 = l1;
            ListNode *head = l1;

            while (l1) {
                l1 -> value += l2 -> value;
                if (l1 -> next == NULL && l2 -> next != NULL) {
                    l1 -> next = l2 -> next;
                    break;
                }
                if (l2 -> next == NULL && l1 -> next != NULL)
                    break;

                l1 = l1 -> next;
                l2 = l2 -> next;
            }


            while (head1) {
                if (head1 -> value >= 10) {
                    if (head1 -> next == NULL && head1 -> value >= 10)
                        head1 -> next = new ListNode(0);
                    head1 -> next -> value += 1;
                    head1 -> value -= 10;
                }

                head1 = head1 -> next;
            }

            return head;
        }
};

// 数字转换为链表（倒序）
ListNode* creatNode(int num) {
    ListNode *numList = new ListNode();
    ListNode *head = numList;

    for (int count = 0; num > 0; count++) {
        count = num % 10;
        numList -> value = count;
        if (num >= 10)
            numList -> next = new ListNode();

        num /= 10;
        numList = numList -> next;
    }

    return head;
}

int main()
{
    int numA = 10;
    int numB = 90;
//    cin >> numA >> numB;
    ListNode *numListA = creatNode(numA);
    ListNode *numListB = creatNode(numB);

    Solution so;
//    ListNode *numList = so.addTwoNumbersFirstway(numListA, numListB);
    ListNode *numList = so.addTwoNumbersSecondway(numListA, numListB);
    while (numList) {
        cout << numList -> value;
        numList = numList -> next;
    }
    cout << endl;

    return 0;
}
