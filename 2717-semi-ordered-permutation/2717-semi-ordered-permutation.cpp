class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int onePos = -1, nPos = -1,size = nums.size();

        // //left
        // for( int i = 0; i < size; ++i )
        // {
        //     if( nums[i] == 1 )
        //     {
        //         onePos = i; break;
        //     }
        // }
        // //right 
        // for( int i = size-1; i >= 0; --i )
        // {
        //     if( nums[i] == size )
        //     {
        //         nPos = i; break;
        //     }
        // }
        
        for( int i = 0, j = size - 1; j >=0; ++i, --j )
        {
            if( nums[i] == 1 && onePos == -1 ) onePos = i;
            if( nums[j] == size && nPos == -1 ) nPos = j;
        }

        if( onePos < nPos ) return onePos + size - nPos - 1;
        else return onePos + size - nPos - 2;

    }
};