/*
题目来源：
https://leetcode.cn/problems/1fGaJU/description/
解答：
https://leetcode.cn/problems/1fGaJU/solutions/1262660/hui-su-jie-fa-by-wan-gong-jie-zi-8-14f1/
https://leetcode.cn/problems/1fGaJU/solutions/941911/jian-dan-yi-dong-javac-pythonjs-san-shu-nu6el/
*/

/*
回溯算法 
但超出了时间限制 
*/
class Solution {
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    int[] nums;
    int[] visited;
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        this.visited = new int[nums.length];
        this.nums = nums;
        List<Integer> list = new ArrayList<Integer>();
        dfs(list, 0, 0);
        return result;

    }
    public void dfs(List<Integer> list, int sum, int index){
        if(list.size() > 3){
            return;
        }
        if(list.size() == 3 && sum == 0){
            result.add(new ArrayList<Integer>(list));
        }
        for(int i = index; i < nums.length; i ++){
            if(i > 0 && nums[i] == nums[i -1] && visited[i - 1] == 0){
                continue;
            }
            list.add(nums[i]);
            visited[i] = 1;
            dfs(list, sum + nums[i], i + 1);
            list.remove(list.size() - 1);
            visited[i] = 0;
        }
    }
}


/*
学的老汤 
三指针加去重加排序 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3){
            return {};
        }
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i ++){
        	//去重 
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1, right = nums.size() -1;
            while(left < right){
                if(nums[left] + nums[right] == -nums[i]){
                    ret.push_back({nums[i], nums[left], nums[right]});
                    //去重 
                    while(left < right && nums[left] == nums[++left]);
                    while(left < right && nums[right] == nums[--right]);
                }else if(nums[left] + nums[right] < -nums[i]){
                    left ++;
                }else{
                    right --;
                }
            }
        }
    
        return ret;
    }
};
