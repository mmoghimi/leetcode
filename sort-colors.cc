class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0, 0, 0};
        for(int x: nums)
            ++count[x];
        
        int i = 0;
        for(i = 0; i < count[0]; ++i)
            nums[i] = 0;
        
        for(; i< count[0] + count[1]; ++i)
            nums[i] = 1;
        
        for(; i<nums.size(); ++i)
            nums[i] = 2;
    }
};