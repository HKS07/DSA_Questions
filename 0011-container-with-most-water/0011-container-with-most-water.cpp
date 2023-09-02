class Solution {
public:
    int maxArea(vector<int>& h) {
        int sol = 0, l = 0, r = h.size()-1;
        // cout<<r;
        while( l < r )
        {
            int w = r-l;
            int curH = min(h[l],h[r]);
            cout<<h[l]<<" "<<h[r];
            sol = max( sol, w * curH);
            if( h[l] < h[r] ) l++;
            else if( h[l] > h[r] ) r--;
            else
            {
                ++l;--r;
            }
        }
        return sol;
    }
};