/*
��Ŀ��Դ��
https://leetcode.cn/problems/search-a-2d-matrix-ii/description/
���
https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solutions/95306/mian-shi-ti-04-er-wei-shu-zu-zhong-de-cha-zhao-zuo/
https://leetcode.cn/problems/search-a-2d-matrix/solutions/688573/gong-shui-san-xie-yi-ti-shuang-jie-er-fe-l0pq/
*/

/*
���������ҵ�һ�����㣬���С��������㣬�ұߴ�������ڵ� 
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
