class Solution {
public:
    int lastRemainingR(int n) {
        if(n == 1)
            return 1;
        if(n % 2 == 0) {
            return lastRemaining(n/2) * 2 - 1;
        } else {
            return lastRemaining(n/2) * 2;
        }
    }
    
    int lastRemaining(int n) {
        if(n == 1)
            return 1;
        
        return lastRemainingR(n/2) * 2;
    }
};

