/*
��Ŀ��Դ��
https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
���
https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/9749/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/ 
https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/1125936/gong-shui-san-xie-shuang-zhi-zhen-shi-xi-t5hc/
https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/1123971/zhao-dao-zi-fu-chuan-zhong-suo-you-zi-mu-xzin/
*/
/*
�ⷨ���ǻ������ڷ�������������������¼ָ�����ڵ�Ԫ�ظ������������������ȣ�C++����ֱ����˲�����sCount == pCount�������򷵻��±�
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            int sLen = s.size(), pLen = p.size();

            if(sLen < pLen){
                return vector<int>();
            }
            vector<int> ans;
            vector<int> sCount(26);
            vector<int> pCount(26);
            for(int i =0; i < pLen; i ++){
                sCount[s[i] - 'a'] ++;
                pCount[p[i] - 'a'] ++;
            }

            if(sCount == pCount){
                ans.emplace_back(0);//׷��Ԫ�� 
            }

            for(int i = 0;i < sLen - pLen; i ++){
                sCount[s[i] - 'a'] --;
                sCount[s[i + pLen] - 'a'] ++;
                if(sCount == pCount){
                    ans.emplace_back(i + 1);
                }
            }
            return ans;
    }
};
/*
�Ż����Ż���ֻ��һ�����飬ͬʱ�� differ����¼��ͬԪ�ظ�����ֻ��differ == 0������������ 
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(),pLen = p.size();

        if(sLen < pLen){
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);//count��������¼�����ִ�Ԫ�ظ����� 
        for(int i = 0; i < pLen; i ++){
            count[s[i] - 'a'] ++;
            count[p[i] - 'a'] --;
        }
        int differ= 0;//��¼��ͬԪ�ظ��� 
        for(int j =0; j < 26; j ++){
            if(count[j] != 0){
                differ++;
            }
        } 
        if(!differ){
            ans.emplace_back(0);
        }
        for(int i =0; i < sLen - pLen; i ++){
        	//���˴���Ԫ�����ִ��еĸ���Ϊ1ʱ���Ƴ���Ԫ�زŻ�����differ�ı仯������֮ǰ�պ���p�е���ĸƥ�䣬Ϊ0���Ƴ����Ļ��������Ӳ�ͬԪ�ظ��� 
            if(count[s[i] - 'a'] == 1){
                differ --;
            }else if(count[s[i] - 'a'] == 0){
                differ ++;
            }
            count[s[i] - 'a'] --;
            if(count[s[i + pLen] - 'a'] == -1){
                differ --;
            }else if(count[s[i + pLen] - 'a'] == 0){
                differ ++;
            }
            count[s[i + pLen] - 'a'] ++;
            if(!differ){
                ans.emplace_back(i + 1);
            }
        }
            return ans;
    }
};
