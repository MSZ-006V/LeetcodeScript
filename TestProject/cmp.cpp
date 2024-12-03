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

int main(){
    
    sort(arr.begin(), arr.end());
    for(auto n : arr){
        cout << n << ' ';
    }
    cout << endl;
    vector<int> arr = {1,2,34,2,3,5,3,7,743,4};
    sort(arr.begin(), arr.end(), [](auto& a, auto& b){
        return a > b;
    });
    for(auto n : arr){
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}