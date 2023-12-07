/*
题目来源：
https://leetcode.cn/problems/zero-matrix-lcci/description/
解答：
https://www.bilibili.com/video/BV1nt4y1b7pw/?vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/


/*
暴力解法 
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
            vector<vector<int>> tmp = matrix;
            int m = matrix.size();
            int n = matrix[0].size();
            for(int i = 0; i < m ; i ++){
                for(int j = 0 ; j < n; j ++){
                    if(tmp[i][j] == 0){
                        for(int k = 0; k < n; k ++){
                            matrix[i][k] = 0;
                        }
                        for(int k = 0; k < m; k ++){
                            matrix[k][j] = 0;
                        }
                    }
                }
            }
    }
};

/*
稍微简化了时间复杂度 
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      vector<int> col(n),row(m);
      for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
          if(matrix[i][j] == 0){
            row[i] = 1;
            col[j] = 1;
          }
        }
      }
      for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
          if(row[i] == 1 || col[j] == 1){
            matrix[i][j] = 0;
          }
        }
      }

    }
};
/*
常数空间 
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      int row0_flag = 0, col0_flag = 0;
      for(int i = 0; i < m; i ++){
        if(matrix[i][0] == 0){
          col0_flag = 1;
          break;
        }
      }
      for(int j = 0; j < n; j ++){
        if(matrix[0][j] == 0){
          row0_flag = 1;
          break;
        }
      }
      for(int i = 1; i < m; ++ i){
        for(int j = 1; j < n;  ++ j){
          if(matrix[i][j] == 0){
            matrix[i][0] = matrix[0][j] = 0;
          }
        }
      }
      for(int i = 1; i < m;  ++ i){
        for(int j = 1; j < n;  ++ j){
          if(matrix[i][0] == 0 || matrix[0][j] == 0){
            matrix[i][j] = 0;
          }
        }
      }
      if(row0_flag == 1){
        for(int j = 0; j < n; j ++){
          matrix[0][j] = 0;
        }
      }
      if(col0_flag == 1){
        for(int i = 0; i < m; i ++){
          matrix[i][0] = 0;
        }
      }
    }
};
