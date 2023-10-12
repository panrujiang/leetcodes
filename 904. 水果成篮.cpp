/*
我们可以使用滑动窗口解决本题，left 和 right 分别表示满足要求的窗口的左右边界，同时我们使用哈希表存储这个窗口内的数以及出现的次数。

我们每次将 right 移动一个位置，并将 fruits[right]加入哈希表。如果此时哈希表不满足要求（即哈希表中出现超过两个键值对），那么我们需要不断移动 left，并将 fruits[left] 从哈希表中移除，直到哈希表满足要求为止。

需要注意的是，将 fruits[left]从哈希表中移除后，如果 fruits[left]哈希表中的出现次数减少为 0，需要将对应的键值对从哈希表中移除。

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
