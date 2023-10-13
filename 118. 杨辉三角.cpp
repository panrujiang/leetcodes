/*
原题：
https://leetcode.cn/problems/pascals-triangle/description/ 
解答：
https://leetcode.cn/problems/pascals-triangle/solutions/510638/yang-hui-san-jiao-by-leetcode-solution-lew9/ 
*/

/*
找递归公式，该解答中涉及到了resize()函数，因为杨辉三角的行数是定的，列数是变化的，所以列数要用resize()函数来确定。 
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for(int i =0; i < numRows; i ++){
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for(int j = 1; j < i; j ++){
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
            return ret;
    }
}; 
