/*
题目来源：
https://leetcode.cn/problems/defanging-an-ip-address/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=31&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/


/*
Python
*/
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace(".","[.]")
         
         
/*
C++,遍历 
*/

class Solution {
public:
    string defangIPaddr(string address) {
        int n = address.size();
        string ans = "";
        for(int i = 0; i < n; i ++){
            if(address[i] == '.'){
                ans += "[.]";
            }else{
                ans += address[i];
            }
        }
        return ans;
    }
};

/*
C++ 遍历，但有C++自己的特色 
*/
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (auto & c : address) {
            if (c == '.') {
                ans.append("[.]");
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
