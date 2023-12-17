/*
��Ŀ��Դ��
https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/description/
���
https://leetcode.cn/problems/convert-binary-number-in-a-linked-list-to-integer/solutions/464257/4chong-fang-fa-zhi-jie-bian-li-di-gui-zhan-arrayli/
*/

/*
�ҵ����� ���ϵĳ���2 
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode * node;
        int ans = 0;
        while(node){
            ans = ans * 2 + node -> val;
            node = node -> next; 
        }
        return ans;
    }
};

/*
ջ�ķ��� 
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        stack<int> st;
        ListNode * node = head;
        while(node){
            st.push(node -> val);
            node = node -> next;
        }
        int n = 0;
        int res = 0; 
        while(!st.empty()){
            res += st.top() * pow(2,n);
            st.pop();
            n ++;
        }
        return res;
    }
};
/*
Java�ĵݹ鷨
����Ҫ�뵽�ݹ� 
*/
class Solution {
    int count = 0;
    int res = 0;
    public int getDecimalValue(ListNode head) {
        if(head == null) return 0;
        res += getDecimalValue(head.next) + head.val * Math.pow(2, count);
        count++;
        return (int)res;
    }
}
