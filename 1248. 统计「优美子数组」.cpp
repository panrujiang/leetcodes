/*
��Ŀ��Դ��
https://leetcode.cn/problems/count-number-of-nice-subarrays/description/
���
https://leetcode.cn/problems/binary-subarrays-with-sum/solutions/562198/de-liao-yi-wen-ba-qian-zhui-he-miao-sha-mqngx/
https://leetcode.cn/problems/count-number-of-nice-subarrays/solutions/213352/hua-dong-chuang-kou-qian-zhui-he-bi-xu-miao-dong-b/
*/

/*
ǰ׺�� + ��ϣ�� 
map[0] = 1����˼����ʼ����ʱ����������Ϊ0��ʱ����һ�����������Ӧ�þ��Ǵ�0��ʼ����ǰ��û�нض� 
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int ans = 0;
        unordered_map <int, int> map;
        map[0] = 1;
        for(auto num : nums){
            count += num % 2;
            ans += map[count - k];
            map[count] ++;
        }
        return ans;
    }
};

/*
�������ڣ������ֽṹ������ 
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0, oddCnt = 0, res = 0;
        while(right < nums.size()){
            if(nums[right ++] % 2){
                oddCnt ++;
            }
            if(oddCnt == k){
                int tmp = right;
                while(right < nums.size() && (nums[right] & 1) == 0){
                    right ++;
                }
                int rightEvenCnt = right - tmp;
                int leftEvenCnt = 0;
                while((nums[left] & 1) == 0){
                    leftEvenCnt ++;
                    left ++;
                }
                res += (leftEvenCnt + 1) * (rightEvenCnt + 1);
                left ++;
                oddCnt --;
            }
        }
        return res;
    }
};
