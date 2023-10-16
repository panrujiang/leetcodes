/*
������Դ��
https://leetcode.cn/problems/happy-number/description/
���
https://www.programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/happy-number/solutions/21454/shi-yong-kuai-man-zhi-zhen-si-xiang-zhao-chu-xun-h/
https://leetcode.cn/problems/happy-number/solutions/224894/kuai-le-shu-by-leetcode-solution/
*/

/*
����ؼ����ڵ����ֳ����ظ���ʱ�򣬾�˵�������ǿ������ˣ������õ���set��ע��set�Ĳ�����insert(),vector�Ĳ�����
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
˫ָ�뷨������˼�뻹�ǻ᲻��ѭ�����᲻���γ�Ȧ�������Ȧ��һ��һ����˫ָ��һ�����������е�����֮ǰ�Ĵ�����������ڵ���
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
