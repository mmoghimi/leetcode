class Solution {
public:
int getKth(vector<int>& nums1, vector<int>& nums2, int a, int b, int c, int d, int k) {
  while(a<b && c<d) {
    cout << a << " " << b << " " << c << " " << d << " " << k << endl;
    cout << "(";
    for (int i = a; i < b; ++i)
      cout << nums1[i] << " ";
    cout << "|||";
    for (int i = c; i < d; ++i)
      cout << nums2[i] << " ";
    cout << ")\n";
    // if((a+b)/2 + (c+d)/2 == k) {
    //     cout << "here" << endl;
    //     return max(nums1[(a+b)/2], nums2[(c+d)/2]);
    // } else 
    
    cout << "x" << (b-a)/2 + (d-c)/2 << " " <<  k << endl;   
    if((b-a)/2 + (d-c)/2 < k) {
      if(nums1[(a+b)/2] < nums2[(c+d)/2]) {
        cout << "case1" << endl;
        k -= (b-a)/2;
        a = (a+b)/2;
      } else {
        cout << "case2" << endl;
        k -= (d-c)/2;
        c = (c+d)/2;
      }
    } else {
      if(nums1[(a+b)/2] < nums2[(c+d)/2]) {
        cout << "case3" << endl;
        b = (a+b)/2;
      } else {
        cout << "case4" << endl;
        d = (c+d)/2;
      }
    }
  }
  cout << a << " " << b << " " << c << " " << d << " " << k << endl;
    
  if(a==b)
    return nums2[k];
  else
    return nums1[k];
}
    
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if ((nums1.size()+nums2.size())%2 == 0) {
        return (getKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), (nums1.size()+nums2.size())/2) 
             + getKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), (nums1.size()+nums2.size())/2-1))/2;
    } else 
        return getKth(nums1, nums2, 0, nums1.size(), 0, nums2.size(), (nums1.size()+nums2.size())/2);
}
};
