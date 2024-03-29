/*
������Դ��
https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/
���
https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solutions/104565/csan-chong-jie-fa-reversefan-zhuan-fa-dui-zhan-fa-/
*/

/*
˫ָ�� 
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
    vector<int> reverseBookList(ListNode* head) {
        vector<int> ans;
        while(head){
            ans.push_back(head -> val);
            head = head -> next;
        }
        int left = 0, right = ans.size() - 1;
        while(left < right){
            swap(ans[left], ans[right]);
            left ++;
            right --;
        }
        return ans;
    }
};

/*
ֱ��reverse()���� 
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
    vector<int> reverseBookList(ListNode* head) {
        vector<int> ans;
        while(head){
            ans.push_back(head -> val);
            head = head -> next;
        }
        //reverse������������ 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
��ջ�� 
*/
class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        while(head){
            stk.push(head -> val);
            head = head -> next;
        }
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};
/*
ֱ�ӷ�ת���� 
*/
class Solution {
public:
    vector<int> reverseBookList(ListNode* head) {
       ListNode* pre = NULL;
       vector<int> ans;
       ListNode* cur = head;
       while(cur){
            ListNode* tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
       }
       while(pre){
            ans.push_back(pre -> val);
            pre = pre -> next;
       }
    return ans;
    }
};

/*
�ݹ�ķ��� 
*/
class Solution {
public:
    vector<int> res;
    vector<int> reverseBookList(ListNode* head) {
            if(!head){
                return res;
            }
            reverseBookList(head -> next);
            res.push_back(head -> val);
            return res;
    }
};
