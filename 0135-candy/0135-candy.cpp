class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> d(n,1);
        for( int i = 1; i < n; ++i )
        {
            if( r[i] > r[i-1] )
            {
                d[i] = d[i-1]+1;
            }
        }
        int sol = 0;
        for( int i = n-2; i >= 0; --i )
        {
            if( r[i] > r[i+1] )
            d[i] = max( d[i], d[i+1]+1);
        }
        for( auto i: d) sol+= i;
        return sol;
    }
};