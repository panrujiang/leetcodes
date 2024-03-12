/*
题目来源：
https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/description/
解答：
https://blog.csdn.net/weixin_64904163/article/details/126804101
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* slow = head, *fast = head;
        k-=1;
        while(k --){
            fast = fast -> next;
        }
        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow -> val;
    }
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* slow = head, *fast = head;
        while(k --){
            fast = fast -> next;
        }
        while(fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow -> val;
    }
};



