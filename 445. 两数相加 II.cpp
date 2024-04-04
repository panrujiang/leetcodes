/*
题目来源：
https://leetcode.cn/problems/add-two-numbers-ii/description/
解答：
https://leetcode.cn/problems/add-two-numbers-ii/solutions/2328330/fan-zhuan-lian-biao-liang-shu-xiang-jia-okw6q/
*/

/*
我自己的解法：
栈加队列 
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;
        ListNode* l11 = l1, *l22 = l2;
        while(l1 || l2){
            if(l1){
                stk1.push(l1 -> val);
                l1 = l1 -> next;
            }
             if(l2){
                stk2.push(l2 -> val);
                l2 = l2 -> next;
            }
        }
        ListNode* cur = stk1.size() > stk2.size() ? l11 : l22;
        ListNode* ret = cur;
        queue<int> que;
        int add = 0;
        while(!stk1.empty() || !stk2.empty()){
            int tmp1, tmp2;
            if(!stk1.empty()){
                tmp1 = stk1.top();
                stk1.pop();
            }else{
                tmp1 = 0;
            }
            if(!stk2.empty()){
                tmp2 = stk2.top();
                stk2.pop();
            }else{
                tmp2 = 0;
            }
            int ans = tmp1 + tmp2 + add;
            if(ans >= 10){
                ans -= 10;
                add = 1;
            }else{
                add = 0;
            }
            que.push(ans);
        }
        //这是为了应对5 + 5 的情况 
        if(add == 1){
            que.push(1);
        }
        ListNode* DummyNode = new ListNode(0, NULL);
       while(!que.empty()){
            ListNode* Node = new ListNode(que.front(),DummyNode -> next);
            DummyNode -> next = Node;
           que.pop();
       }
       return DummyNode -> next;
    }
};


/*
灵神的解法之递归解法
先对链表进行反转
最后在反转回来 
*/
class Solution {
ListNode* reverseList(ListNode * head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    auto new_head = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return new_head;
}
ListNode *addTwo(ListNode* l1, ListNode* l2, int carry = 0){
    if(!l1 && !l2){
        return carry? new ListNode(carry) : NULL;
    }
    if(l1 == NULL){
        swap(l1, l2);
    }
    carry += l1 -> val + (l2 ? l2 -> val : 0);
    l1 -> val = carry % 10;
    l1 -> next = addTwo(l1 -> next, (l2 ? l2 -> next : NULL), carry / 10);
    return l1;
}
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        auto l3 = addTwo(l1, l2);
        return reverseList(l3);

    }
};

/*
栈的简化版本 
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        while(l1 != null){
            stack1.push(l1.val);
            l1 = l1.next;
        }
        while(l2 != null){
            stack2.push(l2.val);
            l2 = l2.next;
        }
        int carry = 0;
        ListNode head = null;
        while(!stack1.isEmpty() || !stack2.isEmpty() || carry > 0){
            int sum = carry;
            sum += stack1.isEmpty() ? 0 : stack1.pop();
            sum += stack2.isEmpty() ? 0 : stack2.pop();
            ListNode node = new ListNode(sum % 10);
            node.next = head;
            head = node;
            carry = sum / 10;

        }
        return head;
    }

}
