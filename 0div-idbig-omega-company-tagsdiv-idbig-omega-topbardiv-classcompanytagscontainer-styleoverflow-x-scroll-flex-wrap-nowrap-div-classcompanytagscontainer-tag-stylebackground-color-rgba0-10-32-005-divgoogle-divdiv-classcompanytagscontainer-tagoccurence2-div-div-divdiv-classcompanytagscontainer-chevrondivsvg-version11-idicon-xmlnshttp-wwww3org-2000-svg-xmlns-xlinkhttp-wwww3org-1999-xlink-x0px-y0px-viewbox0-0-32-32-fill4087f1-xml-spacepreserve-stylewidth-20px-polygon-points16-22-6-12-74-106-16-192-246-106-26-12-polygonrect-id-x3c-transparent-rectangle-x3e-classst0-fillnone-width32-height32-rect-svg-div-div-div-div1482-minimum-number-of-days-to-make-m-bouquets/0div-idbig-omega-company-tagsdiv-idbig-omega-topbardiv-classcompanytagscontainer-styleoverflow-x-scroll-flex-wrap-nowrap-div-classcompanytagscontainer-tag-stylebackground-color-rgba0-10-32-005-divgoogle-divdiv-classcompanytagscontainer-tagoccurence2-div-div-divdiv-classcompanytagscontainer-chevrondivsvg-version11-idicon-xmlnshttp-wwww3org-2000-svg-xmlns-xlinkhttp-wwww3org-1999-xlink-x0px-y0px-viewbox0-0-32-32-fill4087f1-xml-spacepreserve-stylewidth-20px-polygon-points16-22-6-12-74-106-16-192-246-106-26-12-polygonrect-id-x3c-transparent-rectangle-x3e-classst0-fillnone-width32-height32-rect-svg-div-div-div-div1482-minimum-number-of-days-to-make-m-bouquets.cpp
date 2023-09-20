class Solution {
public:
    bool valid(vector<int>& bD, int m, int k, int day )
    {
        //noOfB     cnt
        int bqt = 0, bSize = 0;

        for( int i = 0; i < bD.size(); ++i )
        {
            // if( bSize >= k )
            // {
            //     bSize = 0;
            //     bqt++;
            // }
            // if( bD[i] > day )
            // {
            //     bSize = 0;
            // }
            // else
            // {
            //     ++bSize;
            // }
            if( bD[i] <= day ) bSize++;
            else
            {
                bqt += bSize/k;
                bSize=0;
            }
        }
        // if( bSize >= k ) bqt++;
        bqt += bSize/k;
        
        return bqt >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if( (long long)m*k > bloomDay.size() ) return -1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int low = 1, sol = -1;
        // valid(bloomDay,m,k,8);
        while( low <= high )
        {
            int mid = (low+high)/2;
            
            if( valid(bloomDay,m,k,mid) )
            {
                
                high = mid-1;
                sol = mid;
                cout<<"Day:  "<<sol<<" " ;
            }
            else
            {
                low = mid+1;
            }
        }
        return sol;
    }
};