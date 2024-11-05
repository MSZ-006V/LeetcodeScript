#include<iostream>
#include<vector>
#include<ranges>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){
    vector<int> a = {2,4,3,3,2,4,5,7,8,8,9,5,3,1};
    unordered_map<int, int> ht;
    for(auto num : a){
        ht[num]++;
    }
    vector<pair<int, int>> f(ht.begin(), ht.end());
    sort(f.begin(), f.end());
    for(auto p : f){
        cout << p.first << ' ' << p.second << endl;
    }
}