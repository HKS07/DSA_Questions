class Solution {
public:
    int threeSumClosest(vector<int>& n, int tar) {
        int closest = 1e9, sz = n.size(), sum = 0;
        sort(n.begin(),n.end());
        for( int i = 0; i <= sz-3; ++i )
        {
            int t = tar - n[i];
            int l = i+1, r = sz-1;
            
            while( l < r )
            {
                if( abs( t - n[l]-n[r]) < closest )
                {
                    closest = abs( t - n[l]-n[r]);
                    sum = n[i]+n[l]+n[r];
                }
                
                if( n[i]+n[l]+n[r] < tar ) ++l;
                else --r;
            }
        }
        return sum;
    }
};