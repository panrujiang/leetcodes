/*
题目来源：
https://leetcode.cn/problems/maximum-69-number/description/
解答：
https://leetcode.cn/problems/maximum-69-number/solutions/79090/c-zhao-chu-di-yi-ge-6zai-na-li-ji-ke-by-logan-31/
*/

/*
我的做法，转换成字符串 
stoi(s)将字符串转换为整形 
*/
class Solution {
public:
    int maximum69Number (int num) {
        string s  = "";
        while(num){
            s = (char)(num % 10 + '0') + s;
            num /= 10;
        }
        for(char& ch : s){
            if(ch == '6'){
                ch = '9';
                break;
            }
        }
        return stoi(s);
    }
};

/*
找到最高位的6 ，加上 3 * pow(10,th - 1)即可 
*/
class Solution {
public:
    int maximum69Number (int num) {
        int count = 0, th = 0;
        int re = num;
        while(re){
            count ++;
            if(re % 10 == 6){
                th = count;
            }
            re /= 10;
        }
        return th == 0 ? num : num + 3 * pow(10,th - 1);
    }
};

/*
原解题者的思路 ，如果找不到，th = 0, 3 * pow(10,th - 1) = 3 * 10 ^(-1) 是个小数，返回值又是个int型，会自动去尾 
*/
class Solution {
public:
    int maximum69Number (int num) {
        int count = 0, th = 0;
        int re = num;
        while(re){
            count ++;
            if(re % 10 == 6){
                th = count;
            }
            re /= 10;
        }
        return  num + 3 * pow(10,th - 1);
    }
};
