/*
问题来源：
https://leetcode.cn/problems/sliding-window-maximum/description/
解答：
 https://programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html#%E6%80%9D%E8%B7%AF
*/


class Solution {
private:
    class MyQueue{
        public:
            deque<int> que;
            void pop(int value){
                if(!que.empty() && value == que.front()){
                    que.pop_front();
                }
            }
            void push(int value){
                while(!que.empty() && value > que.back()){
                    que.pop_back();
                }
                que.push_back(value);
            }
            int front(){
                return que.front();
            }
    };


public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for(int i = 0; i < k;i ++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k; i < nums.size(); i ++){
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
