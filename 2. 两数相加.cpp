/*
问题来源：
https://leetcode.cn/problems/add-two-numbers/description/
解答：
https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/add-two-numbers/solutions/2327008/dong-hua-jian-ji-xie-fa-cong-di-gui-dao-oe0di/
*/

/*
借用队列 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        vector<int> ans;
        while(l1 || l2 || add){
            int sum = 0;
            if(l1) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += add;
            add = sum / 10;
            ans.push_back(sum % 10);
        }
        ListNode* DummyNode = new ListNode(0, NULL), * cur = DummyNode;
        for(auto num : ans){
            cur -> next = new ListNode(num, NULL);
            cur = cur -> next;
        }
        return DummyNode -> next;
    }
};

/*
不用队列 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode* DummyNode = new ListNode(0, NULL), * cur = DummyNode;
        while(l1 || l2 || add){
            int sum = 0;
            if(l1) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += add;
            add = sum / 10;
            cur -> next = new ListNode(sum % 10, NULL);
            cur = cur -> next;
        }
        
        return DummyNode -> next;
    }
};
/*
递归 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if(!l1 && !l2){
            return carry ? new ListNode(carry) : nullptr;
        }
        if(!l1){
            swap(l1, l2);
        }
        carry += l1 -> val + (l2? l2 -> val : 0);
        l1 -> val = carry % 10;
        l1->next = addTwoNumbers(l1->next, (l2 ? l2->next : nullptr), carry / 10); // 进位
        return l1;
    }
};
