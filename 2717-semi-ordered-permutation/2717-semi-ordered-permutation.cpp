class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int onePos = -1, nPos = -1,size = nums.size();

        for( int i = 0; i < size; ++i )
        {
            if( nums[i] == 1 ) onePos = i;
            if( nums[i] == size ) nPos = i;
        }

        if( onePos < nPos ) return onePos + size - nPos - 1;
        else return onePos + size - nPos - 2;

    }
};