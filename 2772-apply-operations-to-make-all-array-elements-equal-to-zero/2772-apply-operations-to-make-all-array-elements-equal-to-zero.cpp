class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int reductionTillNow = 0, sz = nums.size();
        
        for( int i = 0; i < sz; ++i )
        {
            if( reductionTillNow > nums[i] ) return false;   
            nums[i] -= reductionTillNow;
            reductionTillNow += nums[i];
            // when we reach to window size and after word
            // do reduce the first element from the reductionTillNow
            if( i >= k - 1 ) 
                reductionTillNow -= nums[i-k+1];
        }
        return reductionTillNow == 0;
    }
};