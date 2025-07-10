class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0;
        string res;
        int carryover = 0;
        while(i < a.length() || i < b.length()) {
            int aa = (i < a.length()) ? a[i]-'0' : 0;
            int bb = (i < b.length()) ? b[i]-'0' : 0;
            int s = aa + bb + carryover;
            res += '0' + s % 2;
            carryover = s / 2;
            ++i;
        }
        if (carryover)
            res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};