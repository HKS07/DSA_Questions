class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& n, int k) {
        int prod = 1, sol = 0;
        
        for( int r = 0, l = 0; r < n.size(); ++r )
        {
            prod *= n[r];
            
            while( prod >= k && l <= r )
            {
                prod /= n[l];
                l++;
            }
            sol += r-l+1;
        }
        return sol;
    }
};