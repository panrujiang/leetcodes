/*
题目来源：
https://leetcode.cn/problems/merge-two-sorted-lists/description/
解答：
https://blog.csdn.net/weixin_64904163/article/details/126804101
https://leetcode.cn/problems/merge-two-sorted-lists/solutions/103891/yi-kan-jiu-hui-yi-xie-jiu-fei-xiang-jie-di-gui-by-/
*/

/*
模拟 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(0);
        ListNode* cur1 = list1, *cur2 = list2,*cur = dummyNode;
        while(cur1 && cur2){
            if(cur1 -> val < cur2 -> val){
                cur -> next = cur1;
                cur1 = cur1 -> next;
                cur = cur -> next;
            }else{
                cur -> next = cur2;
                cur2 = cur2 -> next;
                cur = cur -> next;
            }
        }
        //这里用if即可，不必用while，因为这里后面本来就是连着的 
        if(cur1){
            cur -> next = cur1;
        }else{
            cur -> next = cur2;
        }
        ListNode* ans = dummyNode -> next;
        delete dummyNode;
        return ans;
    }
};

/*
递归的方法 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        if(list1 -> val <= list2 -> val){
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }
        list2 -> next = mergeTwoLists(list1, list2 -> next);
        return list2;
    }
};
