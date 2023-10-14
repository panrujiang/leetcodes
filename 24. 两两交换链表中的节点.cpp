/*
��Ŀ��Դ��
https://leetcode.cn/problems/swap-nodes-in-pairs/description/
���
https://www.programmercarl.com/0024.%E4%B8%A4%E4%B8%A4%E4%BA%A4%E6%8D%A2%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9.html#%E6%80%9D%E8%B7%AF
https://leetcode.cn/problems/swap-nodes-in-pairs/solutions/7058/hua-jie-suan-fa-24-liang-liang-jiao-huan-lian-biao/
https://leetcode.cn/problems/swap-nodes-in-pairs/solutions/444474/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-91/
*/

/*
��������Щ��Ŀ��һ���û�ͼ 
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode* cur = dummyNode;
        while(cur -> next && cur->next->next){
            ListNode* tmp = cur ->next;
            ListNode* tmp1 = cur -> next -> next ->next;
            cur -> next = cur ->next ->next;
            cur -> next -> next = tmp;
            tmp -> next = tmp1;
            cur = cur ->next->next;
        }
        return dummyNode -> next;
    }
};

/*
���ʵĵݹ顣�ݹ���뷨�Ǽ��������Ѿ������˹�ģ��С������Ľ������������֮һЩ�������裬�Ӷ������ģ��������⣬ͬʱע��Ҫ�ҵ����� 
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* next =  head ->next;
        head -> next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
