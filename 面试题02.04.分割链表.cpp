/*
题目来源：
https://leetcode.cn/problems/partition-list-lcci/description/
解答：
https://leetcode.cn/problems/partition-list-lcci/solutions/1214749/mian-shi-ti-0204-fen-ge-lian-biao-shuang-46vz/
*/

/*
分别形成两个链表 
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyNode1 = new ListNode(0);
        ListNode* dummyNode2 = new ListNode(0);
        ListNode* cur = head, *cur1 = dummyNode1, *cur2 = dummyNode2;
        while(cur){
            if(cur -> val < x){
                cur1 -> next = cur;
                cur1 = cur;
            }else{
                cur2 -> next = cur;
                cur2 = cur;
            }
            cur = cur -> next;
        }
        cur1 -> next = dummyNode2 -> next;
        cur2 -> next = NULL;
        ListNode* ans = dummyNode1 -> next;
        delete dummyNode1;
        delete dummyNode2;
        return ans;
    }
};

/*
K佬的优化版 
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smlDummy = new ListNode(0), *bigDummy = new ListNode(0);
        ListNode *sml = smlDummy, *big = bigDummy;
        while (head != nullptr) {
            if (head->val < x) {
                sml->next = head;
                sml = sml->next;
            } else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        sml->next = bigDummy->next;
        big->next = nullptr;
        return smlDummy->next;
    }
};

/*
快慢指针 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* slow = head, * fast = head;
        while(fast){
            if(fast -> val < x){
                int temp = slow -> val;
                slow -> val = fast -> val;
                fast -> val = temp;
                slow = slow -> next;
                fast = fast -> next;
            }else{
                fast = fast -> next;
            }
        }
        return head;
    }
};
