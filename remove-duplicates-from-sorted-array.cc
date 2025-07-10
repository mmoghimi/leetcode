class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write_index = 0;
        int read_index = 0;
        int n = nums.size();

        while(read_index < n) {
            while(read_index < n && nums[write_index] == nums[read_index])
                ++read_index;
            if(read_index < n)
                nums[++write_index] = nums[read_index];
        }
        return write_index+1;
    }
};