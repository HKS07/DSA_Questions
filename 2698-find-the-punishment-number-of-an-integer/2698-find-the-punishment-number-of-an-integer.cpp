class Solution {
public:
    bool helpPart( string s, int targ, int idx, int curSum )
    {
        if( idx >= s.length() ) {return curSum == targ;}
        
        int num = 0;
        for( int i = idx; i < s.length(); ++i )
        {
            num = num*10 + (s[i] - '0');
            
            if( helpPart(s, targ, i+1, curSum + num)){ return true;}
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sol = 0;
        for(int i = 1; i <= n; ++i )
        {
            int num = i*i;
            
            if( helpPart(to_string(num),i,0,0) ) sol += num;
        }
        return sol;
    }
};