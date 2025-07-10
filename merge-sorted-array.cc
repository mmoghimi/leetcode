class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = 0; i < m; ++i)
      nums1[m+n-1-i] = nums1[m-1-i];
    // for(auto i: nums1)
    //   cout << i << endl;
    int index1 = n;
    int index2 = 0;
    int write_index = 0;
    while(write_index<m+n) {
      // cout << index1 << index2 << write_index << endl;
      if(index2 == n) {
        nums1[write_index++] = nums1[index1++];
        break;
      } else if (index1 == m+n) {
        nums1[write_index++] = nums2[index2++];
      } else if(nums1[index1] < nums2[index2]) {
        nums1[write_index++] = nums1[index1++];
      } else {
        nums1[write_index++] = nums2[index2++];
      }
    }
  }
};
