/*
������Դ��
https://leetcode.cn/problems/container-with-most-water/description/
���
Hello�㷨 
*/
/*
��̬�滮 
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int Max = 0;
        while(i < j){
            Max = max(Max, (j - i) * min(height[i], height[j]));
            if(height[i] < height[j]){
                i ++;
            }else{
                j --;
            }
        }
        return Max;
    }
};
