/*
问题来源：
https://leetcode.cn/problems/happy-number/description/
解答：
https://www.programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/happy-number/solutions/21454/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/
https://leetcode.cn/problems/happy-number/solutions/224894/kuai-le-shu-by-leetcode-solution/
*/

/*
问题关键在于当数字出现重复的时候，就说明不会是快乐数了，这里用到了set，注意set的插入是insert(),vector的插入是
push_back() 
*/
class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> count;
        int sum = 0;
        while(1){
            sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(count.find(sum) != count.end()){
                return false;
            }else{
                count.insert(sum);
            }
            n = sum;
        }

    }
};
/*
双指针法，本质思想还是会不会循环，会不会形成圈，如果有圈，一快一慢的双指针一定会相遇，有点类似之前的带环链表找入口的题
*/
class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        }while(slow != fast);

        return slow == 1;
    }
};
