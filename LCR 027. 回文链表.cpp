/*
题目来源：
https://leetcode.cn/problems/aMhZSa/description/
解答：
https://www.bilibili.com/video/BV1F34y1V7Y3/?spm_id_from=333.788&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/aMhZSa/solutions/1052602/jian-zhi-offer-ii-027-hui-wen-lian-biao-sbwvc/
*/

/*
双指针找中间节点；反转链表 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next){
            return true;
        }
        ListNode *slow = head, *fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode * newHead = slow -> next;
        slow -> next = NULL;

        ListNode * left = head;
        ListNode * right = reverseList(newHead);
        while(right){
            if(left -> val != right -> val){
                return false;
            }
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
    ListNode * reverseList(ListNode * head){
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr){
            ListNode * next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};


/*
数组的方法 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while(head){
            vals.push_back(head -> val);
            head = head -> next;
        }
        for(int i = 0, j = vals.size() - 1; i <= j;i ++, j --){
            if(vals[i] != vals[j]){
                return false;
            }
        }
        return true;
    }
};

