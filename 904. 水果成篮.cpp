/*
���ǿ���ʹ�û������ڽ�����⣬left �� right �ֱ��ʾ����Ҫ��Ĵ��ڵ����ұ߽磬ͬʱ����ʹ�ù�ϣ��洢��������ڵ����Լ����ֵĴ�����

����ÿ�ν� right �ƶ�һ��λ�ã����� fruits[right]�����ϣ�������ʱ��ϣ������Ҫ�󣨼���ϣ���г��ֳ���������ֵ�ԣ�����ô������Ҫ�����ƶ� left������ fruits[left] �ӹ�ϣ�����Ƴ���ֱ����ϣ������Ҫ��Ϊֹ��

��Ҫע����ǣ��� fruits[left]�ӹ�ϣ�����Ƴ������ fruits[left]��ϣ���еĳ��ִ�������Ϊ 0����Ҫ����Ӧ�ļ�ֵ�Դӹ�ϣ�����Ƴ���

*/
class Solution{
public: totalFruit(vector<int> &fruits){
	int length = fruits.size();
	unordered_map<int,int> cnt;
	
	int left = 0,ans = 0;
	for(int right = 0; right < fruits.size(); right ++){
		cnt[fruits[right]] ++;
		while(cnt.size() > 2){
			auto it = cnt.find(fruits[left]);
			it -> second --;
			if(it -> second == 0){
				cnt.erase(it)
			}
			left ++;
		}
		ans = max(ans,right - left + 1);
	}
	return ans;
}
};
