class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if( sx == fx && sy == fy && t == 0 ) return true;
        if( sx == fx && sy == fy && t <= 1 ) return false;
        // if( sx == fx && sy == fy && t >= 2 ) return true;
        
        //less than equal to acceptable
        int xD = abs(sx-fx), yD = abs(sy-fy);

        return (min(xD,yD) + abs(xD-yD)) <= t ;
    }
};