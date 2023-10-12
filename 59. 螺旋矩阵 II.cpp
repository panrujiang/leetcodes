/*
½â´ðÏê¼û£º
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
