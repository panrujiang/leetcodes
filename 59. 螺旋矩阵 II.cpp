/*
解答详见：
https://programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE 

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int i ,j;
        int startx = 0,starty = 0;
        int offset = 1;
        int count = 1;
        int loop = n/2;
        while(loop --){
            for(j = starty; j < n - offset; j ++){
                    res[startx][j] = count++;
            }
            for(i = startx; i < n - offset; i ++ ){
                    res[i][j] = count ++;
            }
            for(; j > starty; j --){
                    res[i][j] = count ++;
            }
            for(i ; i > startx; i --){
                    res[i][j] = count ++;
            }
            offset ++;
            startx ++;
            starty ++;
        }
    if(n%2 == 1){
        res[n/2][n/2] = n*n;
    }
    return res;
    }  
};
/*
根据力扣的官方解答，写出的代码 
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n,vector<int>(n,0));
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int count = 1;
    while(left <= right && top <= bottom){
        for(int i = left; i <= right; i ++){
            matrix[top][i]=count;
            count ++;
        }
        for(int i = top + 1; i <= bottom; i ++){
            matrix[i][right]=count;
            count ++;
        }
        for(int i = right - 1; i >= left; i -- ){
                    matrix[bottom][i]=count;
                    count ++;
        }
        for(int i = bottom - 1; i >= top + 1; i -- ){
                   matrix[i][left]=count;
                    count ++;
        }
        left ++;
        right --;
        top ++;
        bottom --;
    }
    return matrix;

    }
};
/*
比较屌的解法 ，想法是压缩上下左右的横线 
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int left = 0,right = n-1,top = 0,bottom = n-1;
        int x = 1; // 待加入的数字
        while(x <= n*n) {
            // 上
            for(int i = left; i <= right;i++){
                ans[top][i] = x++;
            }
            top++;
            // 右
            for(int i = top; i <= bottom; i++) {
                ans[i][right] = x++;
            }
            right--;
            // 下
            for(int i = right;i >= left;i--){
                ans[bottom][i] = x++;
            }
            bottom--;
            // 左
            for(int i = bottom; i >= top; i--) {
                ans[i][left] = x++;
            }
            left++;
        }

        return ans;
    }
};
