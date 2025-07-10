class Solution {
private:
  vector<int> nums;
public:
  Solution(vector<int>& nums) {
    this->nums = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return nums;
  }

  void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
  }
  
  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> shuffled_nums = nums;
    for(int i = 0; i < nums.size(); ++i) {
      swap(shuffled_nums[i], shuffled_nums[i+rand()%(nums.size()-i)]); 
    }
    return shuffled_nums;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
