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
    vector<int> nums = {42};
    vector<int> num1 = std::move(nums);
    cout << nums.size() << ' ' << num1.size();

    return 0;
    
}