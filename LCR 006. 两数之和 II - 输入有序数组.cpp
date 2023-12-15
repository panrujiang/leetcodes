/*
��Ŀ��Դ��
https://leetcode.cn/problems/kLl5u1/description/
���
https://www.bilibili.com/video/BV1da411M798?p=51&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
˫ָ�� 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] == target){
                return {left, right};
            }else if(numbers[left] + numbers[right] > target){
                right --;
            }else{
                left ++;
            }
        } 
        return {};
    }
};

/*
��ϣ�����۵�һ�� 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        for(int i = 0 ; i < numbers.size(); i ++){
            auto iter = map.find(target - numbers[i]);
            if(iter != map.end()){
                return {iter -> second, i};
            }
            map.insert(pair<int, int>(numbers[i],i));
        }
        return {};
    }
};
