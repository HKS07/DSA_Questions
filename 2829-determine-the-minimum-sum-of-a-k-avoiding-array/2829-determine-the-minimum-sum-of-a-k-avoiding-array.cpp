class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> s;
        int sol = 0;
        
        for( int i = 1; s.size() < n; ++i )
        {
            if( s.find(k-i) == s.end()  ) {
                sol += i;
                s.insert(i);
            } 
        }
        return sol;
    }
};