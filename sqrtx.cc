class Solution {
public:
    int mySqrt(int x) {
      int start = 1;
      int end = 46340;
      while(end > start) {
        int mid = (start+end)/2;
        if(mid*mid == x)
          return mid;
        else if (mid*mid > x)
          end = mid-1;
        else
          start = mid+1;
      }
      if(start * start <= x)
        return start;
      else
        return start-1;
    }
};
