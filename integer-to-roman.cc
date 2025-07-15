class Solution {
public:
    string intToRoman(int num) {
        string res;

        // thousands
        string v1000[] = {"", "M", "MM", "MMM"};
        res += v1000[num/1000];

        // hundreds
        string v100[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        res += v100[(num%1000) / 100];

        // tens
        string v10[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        res += v10[(num%100)/10];

        // ones
        string v1[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        res += v1[num%10];

        return res;
    }
};