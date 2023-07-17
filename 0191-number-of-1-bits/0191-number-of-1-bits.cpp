class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sol = 0;
        while(n>0)
        {
            if( n & 1 ) sol++;
            n >>= 1;
        }
        return sol;
    }
};