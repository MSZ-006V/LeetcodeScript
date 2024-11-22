#include<iostream>
#include<vector>
#include<string>
#include<ranges>
#include<algorithm>
#include<numeric>
#include<sstream>
#include<memory>
#include<unordered_map>

using namespace std;

int bs(vector<int>& nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return left;
}

int quicksort(vector<int>& nums, int l, int r, int k){
    if(l == r) return nums[k];
    int partition = nums[l], i = l - 1, j = r + 1;
    while(i < j){
        do i++; while(nums[i] < partition);
        do j--; while(nums[j] > partition);
        if(i < j) swap(nums[i], nums[j]);
    }
    // 此时的数组以partition分成两个部分，左边部分是[l, j], 右边是[j + 1, r]
    // 左边部分的所有元素都小于右边的所有元素，如果k<=j的话，那就说明是要找数组中第k小的元素，所以就往左边遍历
    // 如果k>j的话，那就说明是要找数组中第k大的元素，那就往右边遍历
    if(k <= j) return quicksort(nums, l, j, k); 
    else return quicksort(nums, j + 1, r, k);
}


int main(){
    // vector<int> a = {2,4,3,3,2,4,5,7,8,8,9,5,3,1};
    // unordered_map<int, int> ht;
    // for(auto num : a){
    //     ht[num]++;
    // }
    // vector<pair<int, int>> f(ht.begin(), ht.end());
    // sort(f.begin(), f.end());
    // for(auto p : f){
    //     cout << p.first << ' ' << p.second << endl;
    // }
    // std::string sentence = "Hello my name is Jane";
    // std::vector<std::string> words;
    // size_t start = 0, end;

    // while ((end = sentence.find(' ', start)) != std::string::npos) {
    //     words.push_back(sentence.substr(start, end - start));
    //     start = end + 1; // 移动到下一个单词的起始位置
    // }

    // // 最后一个单词
    // words.push_back(sentence.substr(start));

    // for (const auto& w : words) {
    //     std::cout << w << std::endl;
    // }
    vector<int> nums = {42, 31,5,2,3,85};
    int n = nums.size();
    int res = quicksort(nums, 0, n - 1, n - 1);
    cout << res;

    return 0;
    
}