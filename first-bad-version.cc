// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        uint32_t a = 1;
        uint32_t b = n;

        while(a+1<b) {
            uint32_t m = (a+b)/2;

            if(isBadVersion(m))
                b = m;
            else
                a = m;
        }
        if(isBadVersion(a))
            return a;
        else
            return b;
    }
};
