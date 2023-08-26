class Solution {
public:
    int threeSumClosest(vector<int>& n, int t) {
        int closest = 1e9, sz = n.size(), sum = 0;
        sort(n.begin(),n.end());
        for( int i = 0; i <= sz-3; ++i )
        {
            
            int l = i+1, r = sz-1;
            
            while( l < r )
            {
                int val = n[i]+n[l]+n[r];
                if( abs( t - val) < closest )
                {
                    closest = abs( t - val);
                    sum = val;
                }
                
                if( n[i]+n[l]+n[r] < t ) ++l;
                else --r;
            }
        }
        return sum;
    }
};