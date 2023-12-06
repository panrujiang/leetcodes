/*
问题来源：
https://leetcode.cn/problems/convert-1d-array-into-2d-array/description/
解答：
https://leetcode.cn/problems/convert-1d-array-into-2d-array/solutions/1186383/gong-shui-san-xie-jiang-2021-de-1-gai-ch-qc1a/ 
https://leetcode.cn/problems/convert-1d-array-into-2d-array/solutions/1185411/jiang-yi-wei-shu-zu-zhuan-bian-cheng-er-zt47o/
*/

/*
Java
*/
class Solution {
    public int[][] construct2DArray(int[] year2021, int m, int n) {
        if (year2021.length != m * n) return new int[0][0];
        int[][] year2022 = new int[m][n];
        for (int i = 0, idx = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                year2022[i][j] = year2021[idx++];
            }
        }
        return year2022;
    }
}

/*
c++,emplace_back()函数 
*/
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(original.size() != m * n) return ans;
        
        for(auto it = original.begin(); it != original.end(); it += n){
            ans.emplace_back(it, it + n);
        }
        return ans;
    }
};
