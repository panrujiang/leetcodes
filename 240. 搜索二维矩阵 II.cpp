/*
题目来源：
https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
解答：
https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solutions/95306/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/
https://leetcode.cn/problems/search-a-2d-matrix/solutions/688573/gong-shui-san-xie-yi-ti-shuang-jie-er-fe-l0pq/
*/

/*
类似树，找到一个顶点，左边小于这个顶点，右边大于这个节点 
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m - 1, j = 0;
        while(i >= 0 && j < n){
            int flag = matrix[i][j];
            if(flag == target){
                return true;
            }else if(flag > target){
                i --;
            }else{
                j ++;
            }
        }
        return false;
    }
};
