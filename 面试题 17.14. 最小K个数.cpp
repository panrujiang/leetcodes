/*
问题来源：
https://leetcode.cn/problems/smallest-k-lcci/description/
解答：
https://leetcode.cn/problems/smallest-k-lcci/solutions/590916/zui-xiao-kge-shu-by-leetcode-solution-o5eg/
https://leetcode.cn/problems/smallest-k-lcci/solutions/975338/gong-shui-san-xie-yi-ti-si-jie-you-xian-yy5k5/
*/

/*
这种TOP-k的问题经常使用堆来实现，最小k个使用大顶堆，最大k个使用小顶堆。C++的默认优先队列是大顶堆 
*/
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> vec(k,0);
        if(k == 0){
            return vec;
        }
        priority_queue<int> Q;
        for(int i = 0; i < k; i ++){
            Q.push(arr[i]);
        }
        for(int i = k; i < arr.size(); i ++){
            if(arr[i] < Q.top()){
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i ++){
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};

/*
宫水三叶的快速排序
想法来自于快速排序 
*/
class Solution {
private:
    void qsort(vector<int>& arr, int l, int r, int k){
        if(l >= r) return;
        int i = l, j = r;
        int ridx = rand() % (r - l + 1) + l;
        swap(arr[l],arr[ridx]);
        int x = arr[l];
        while(i < j){
            while(i < j && arr[j] >= x) j --;
            while(i < j && arr[i] <= x) i ++;
            swap(arr[i],arr[j]);
        }
        swap(arr[i], arr[l]);
        if(i > k) qsort(arr, l, i - 1,k);
        if(i < k) qsort(arr, i + 1, r,k);
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans(k);
        if(k == 0) return {};
        qsort(arr, 0, n - 1,k);
        for(int i = 0; i < k; i ++){
            ans[i] = arr[i];
        }
        return ans;
    }
};

/*
官方的快速排序 
*/
class Solution {
    int partition(vector<int>& nums, int l, int r){
        int i = l, pivot = nums[r];
        for(int j = l; j < r ; j ++){
            if(nums[j] < pivot){
                swap(nums[i ++], nums[j]);
            }
        }
            swap(nums[i], nums[r]);
            return i;
    }

    int randomized_partition(vector<int>& nums, int l, int r){
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    void randomized_selected(vector<int>& arr, int l, int r, int k){
        if(l >= r) return;
        int pos = randomized_partition(arr, l, r);
        int num = pos - l + 1;
        if(k == num){
            return;
        }else if(k < num){
            randomized_selected(arr, l, pos - 1, k);
        }else{
            randomized_selected(arr, pos + 1, r, k - num);
        }
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, arr.size() - 1,k);
        vector<int> vec;
        for(int i = 0; i < k; i ++){
            vec.push_back(arr[i]);
        }
        return vec;
    }
};
