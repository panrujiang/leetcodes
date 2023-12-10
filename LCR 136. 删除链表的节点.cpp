/*
题目来源：
https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/description/
解答：
https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/solutions/167212/mian-shi-ti-18-shan-chu-lian-biao-de-jie-dian-sh-2/
*/

/*
双指针 
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head -> val == val){
            return head -> next;
        }
        ListNode* pre = head，*cur = pre -> next; 
        while(cur && cur -> val != val){
            pre = cur;
            cur = cur -> next;
        }
        if(cur) {
            pre -> next = cur -> next;
        }
        return head;
    }
};
