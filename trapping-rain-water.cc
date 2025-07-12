class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_until(n);
        vector<int> max_from(n);

        max_until[0] = height[0];
        for(int i = 1; i < n; ++i) {
            max_until[i] = max(max_until[i-1], height[i]);
        }
        max_from[n-1] = height[n-1];
        for(int i = n-2; i >= 0; --i) {
            max_from[i] = max(max_from[i+1], height[i]);
        }

        int trapped = 0;
        for(int i = 1; i < n-1; ++i) {
            if(max_from[i] > height[i] && max_until[i] > height[i])
                trapped += min(max_from[i], max_until[i]) - height[i];
        }

        return trapped;
    }
};