/*
��Ŀ��Դ��
https://leetcode.cn/problems/qIsx9U/description/
���
https://leetcode.cn/problems/qIsx9U/solutions/1673310/by-ac_oier-g5ha/
*/

/*
��Ҷ�Ķ��У�ά�����еĳ��� 
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
