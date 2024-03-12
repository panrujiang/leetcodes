/*
题目来源：
https://leetcode.cn/problems/SLwz0R/description/
解答：
https://leetcode.cn/problems/SLwz0R/solutions/1417848/shan-chu-lian-biao-de-dao-shu-di-n-ge-ji-ydte/
*/

/*
我的想法是要删除一个节点，必须找到该节点的前面一个节点 
*/

/*
双指针 ，题目变成了找倒数第n+1个节点 
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0,head);//这种写法学一学 
        ListNode * slow = dummyNode, *fast = dummyNode;
        n += 1;
        while(n --){
            fast = fast -> next;
        }
        while(fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        ListNode* ans = dummyNode -> next;
        delete(dummyNode);
        return ans;
    }
};

/*
堆栈的做法也不错 
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummyNode;
        while(cur){
            stk.push(cur);
            cur = cur -> next;
        }
        for(int i = 0 ; i < n; i ++){
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev -> next = prev -> next -> next;
        ListNode* ans = dummyNode -> next;
        delete dummyNode;
        return ans;
    }
};
