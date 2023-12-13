/*
��Ŀ��Դ��
https://leetcode.cn/problems/defanging-an-ip-address/description/
���
https://www.bilibili.com/video/BV1da411M798?p=31&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/


/*
Python
*/
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace(".","[.]")
         
         
/*
C++,���� 
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
C++ ����������C++�Լ�����ɫ 
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
