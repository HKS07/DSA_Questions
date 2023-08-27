class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, s = 0;
        for( auto i: moves) 
        {
            if( i == 'L' ) l++;
            else if( i == 'R' ) r++;
            else s++;
        }
        return abs(l-r) + s;
    }
};