class Solution {
public:
  
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> p(n+1,true);
        vector<vector<int>> sol;
        p[0]=false;
        p[1]=false;
        
        for( int i = 2; i*i <= n; ++i )
        {
            if(!p[i]) continue;
            for( int j = i*i; j <= n  ; j+=i)
            {  
                p[j]=false;
            }
        }
        for( int i = 2; i <= n-1; ++i )
        {
            int j = n-i;
            if( p[i] && p[j] && i <=j )
            {
                sol.push_back({i,j});
            }
        }
        
        
        return sol;
    }
};