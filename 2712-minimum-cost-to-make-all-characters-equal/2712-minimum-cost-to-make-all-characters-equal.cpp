class Solution {
public:
    long long minimumCost(string s) {
       
        long long cost = 0;
        int len = s.length();
        int inv = 0;
        for( int i = 1; i < len; ++i )
        {
            char temp = inv == 0? s[i]: s[i] == '0'? '1':'0';
            if( s[i] != s[i-1] )
            {
                //left
                int lCost = i;
                    //right
                int rCost = len - i;
                
                //inverting left
                if( lCost < rCost )
                cost += i;
                else{
                //inverting right
                inv = (inv + 1)%2;
                cost += (len - i);
                }
            }
        }
        return cost;
    }
};