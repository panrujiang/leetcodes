/*
题目来源：
https://leetcode.cn/problems/min-stack/description/
解答：
https://www.bilibili.com/video/BV1tC4y1M72q/?spm_id_from=333.1296.top_right_bar_window_custom_collection.content.click&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/min-stack/solutions/242861/zui-yi-dong-yi-ge-zhan-tong-shi-bao-cun-dang-qian-/
*/

/*
老汤的解法 
*/
class MinStack {
    stack<int> datastack;
    stack<int> minstack;
public:
    MinStack() {

    }
    
    void push(int val) {
        datastack.push(val);
        if(minstack.empty() || minstack.top() >= val){
            minstack.push(val);
        }
    }
    
    void pop() {
        if(!minstack.empty() && minstack.top() == datastack.top()){
            minstack.pop();
        }
        datastack.pop();
    }
    
    int top() {
        return datastack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/*
单栈的做法 
*/
class MinStack {
    stack<pair<int,int>> stack;
public:
    MinStack() {
    }
    
    void push(int x) {
        if(stack.size() == 0){
            stack.push({x,x});
        }else{
            stack.push({x,min(x, stack.top().second)});
        }
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
    }
};


