class Solution {
public:
    int trap(vector<int>& height) {
        // monotonic stack, decreasing stack from top to bottom
        // store the index of element in this stack
        int res = 0;
        stack<int> st;
        st.push(0);

        for(int i = 1; i < height.size(); ++i){
            if(height[st.top()] >= height[i]){
                st.push(i);
            }
            else{
                while(!st.empty() && height[st.top()] < height[i]){
                    int mid = st.top(); st.pop();

                    if(!st.empty()){
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        res += h * w;
                    }
                }
                st.push(i);
            }
        }

        return res;
    }
};
