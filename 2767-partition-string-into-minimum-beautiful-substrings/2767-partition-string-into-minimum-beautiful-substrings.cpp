class Solution {
public:
    bool checkPowerOf5(int val){
        if(val == 0) return false;
        while(val % 5 == 0)
            val /= 5; 
        return (val == 1);
    }
    int helpPart( int idx, string &s )
    {
        if( idx == s.length() ) return 0;
        if( s[idx] == '0' ) return 20;
        
        int sol = 20, val = 0;// sol for storing partition which is preinitiallized as max then comes val
        //used for converting binary to decimal 
        for( int i = idx; i < s.length(); ++i )
        {
            val = val*2 + s[i] - '0';
            if( (checkPowerOf5(val)) ) 
                sol = min ( sol,1 + helpPart(i+1,s));
        }
        return sol;
    }
    int minimumBeautifulSubstrings(string &s) {
        int ans = helpPart(0,s);
        return ans>s.length()?-1:ans;
    }
};