#include<bits/stdc++.h>
class Solution {
public:
    int isVal( vector<int> &n, int divisor, int th )
    {
        int sum = 0;
        
        for( auto i: n)
        {
            sum += ceil((double)i/(double)divisor);
        }
        return sum <= th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        
        long long low = 1, high = *max_element(nums.begin(),nums.end()), sol = 1e9;
        
        while( low <= high )
        {
            long long mid = (low+high)/2;
            
            if( isVal(nums,mid,threshold) )
            {
                sol = min(mid,sol);
                high = mid-1;
            }
            else 
            {
                low = mid+1;
            }
        }
        return sol;
    }
};