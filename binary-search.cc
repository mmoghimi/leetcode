class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0; int e = nums.size()-1;

        while(e > s + 1) {
            int mid = (s+e) / 2;
            if(nums[mid] > target)
                e = mid-1;
            else if (nums[mid] < target)
                s = mid+1;
            else
                return mid;
        }
        if(target == nums[s])
            return s;
        else if (target == nums[e])
            return e;
        
        return -1;
        

    }
};