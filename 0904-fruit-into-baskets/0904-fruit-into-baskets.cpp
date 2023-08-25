class Solution {
public:
    int totalFruit(vector<int>& f) {
         map<int,int> freq;
        int type = 0;
        int l = 0, r = 0, len = 0;
        
        while( r < f.size() )
        {
            freq[f[r]]++;
            if( freq[f[r]] == 1) 
                type++;
            
            if( type <= 2 )
            {
                len = max( len, r - l + 1);
                ++r;
            }
            else
            {
                while( type > 2 )
                {
                    freq[f[l]]--;
                    if( freq[f[l]] == 0 ) type--;
                    ++l;
                }
                ++r;
            }
        }
        return len;
    }
};