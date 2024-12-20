class Solution {
public:
    int maxArea(vector<int>& heights) {
        // tc O(n), sc O(1)
        // 一个简单的双指针，每次检查完后，移动较小那一边的指针，期望得到一个更高的边
        int left = 0, right = heights.size() - 1;
        int max_v = 0;
        while(left < right){
            int area = (right - left) * min(heights[left], heights[right]);
            //cout << left << ' ' << right << ' ' << area << endl;
            max_v = max(max_v, area);

            if(heights[left] < heights[right]){
                left++;
            }  
            else{
                right--;
            }
        }

        return max_v;
    }
};
