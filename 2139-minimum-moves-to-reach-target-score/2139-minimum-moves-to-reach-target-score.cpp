class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0,t = target, d = maxDoubles;
        
        while( t > 1 )
        {
            if( t%2 == 0  )
            {
                if( d != 0 )
                {
                    t/=2;
                    count++;
                     d--;
                }
                else
                {
                    count += t-1;
                    break;
                }
            }
            else 
            {
                t--;
                count++;
            }
        }
        return count;
    }
};