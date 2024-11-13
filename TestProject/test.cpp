#include<iostream>
#include<vector>
#include<string>
#include<ranges>
#include<algorithm>
#include<numeric>
#include<unordered_map>

using namespace std;



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
    vector<string> words = {"hello", "how", "are", "you"};
    string s = words[0];
    s = accumulate(words.begin() + 1, words.end(), s, [](auto a, auto b){
        return a + " " + b;
    });
    cout << s;

    map<int, int> tt;
    for(auto interval : intervals){
        tt[intervals[0]]++;
        tt[intervals[1]]--;
    }
    for(auto t : tt){
        cout << t.first << ' ' << t.second << endl;
    }
}