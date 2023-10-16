/*
��Ŀ��Դ��
https://leetcode.cn/problems/linked-list-cycle-ii/description/
���
https://www.programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
https://leetcode.cn/problems/linked-list-cycle-ii/solutions/441131/huan-xing-lian-biao-ii-by-leetcode-solution/
https://leetcode.cn/problems/linked-list-cycle-ii/solutions/12616/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
*/
/*
�������뷨���漰���˱Ƚ϶����ѧ˼�� 
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1 -> next;
                    index2 = index2 -> next;
                }
                return index2;
            }
        }
            return NULL;
    }
};
/*
�ұ��˵��뷨����ϣ�� �����۹ٷ���һ�ֽⷨ 
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        ListNode * cur = head;
        while(cur){
            if(visited.count(cur)){
                return cur;
            }
            visited.insert(cur);
            cur = cur -> next;
        }
        return NULL;
    }
};
/*
K��Ľⷨ���뿨��������ͬ 
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (true) {
            if (fast == nullptr || fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

