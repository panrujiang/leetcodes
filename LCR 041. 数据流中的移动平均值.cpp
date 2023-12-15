/*
题目来源：
https://leetcode.cn/problems/qIsx9U/description/
解答：
https://leetcode.cn/problems/qIsx9U/solutions/1673310/by-ac_oier-g5ha/
*/

/*
三叶的队列，维护队列的长度 
*/
class MovingAverage {
    int n, sum = 0;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size; 
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size() > n){
            sum -= q.front();
            q.pop();
        }
        return sum * 1.0 / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
