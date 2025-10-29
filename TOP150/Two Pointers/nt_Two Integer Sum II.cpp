// tc O(n^2), outer loop is O(n), inner loop is O(n), sc O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        for(int right = 0; right < numbers.size(); ++right){
            if(target - numbers[right] > numbers[right]) continue;
            int left = 0;
            while(left < right){
                if(numbers[left] + numbers[right] == target) return {left + 1, right + 1};
                left++;
            }
        }

        return {};
    }
};

// two points, can use the feature about this array, increasing 
// tc O(n), sc O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            if(numbers[left] + numbers[right] > target){
                right--;
            }else if(numbers[left] + numbers[right] < target){
                left++;
            }else{
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};
