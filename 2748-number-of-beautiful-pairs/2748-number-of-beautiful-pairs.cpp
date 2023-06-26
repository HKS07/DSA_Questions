class Solution {
public:
    int countBeautifulPairs(vector<int>& nums)
    {
        int count = 0;
        for( int i = 0; i < nums.size() - 1; ++i )
        {
            for( int j = i + 1; j < nums.size(); ++j )
            {
                int firstDig , secondDig = nums[j]%10;
                if( nums[i] <= 9 ) firstDig = nums[i];
                else if( nums[i] <= 99 ) firstDig = nums[i]/10;
                else if( nums[i] <= 999 ) firstDig = nums[i]/100;
                else firstDig = nums[i]/1000;
                // cout<<firstDig<<" "<<secondDig<<endl;
                if( std::gcd(firstDig, secondDig) == 1) count++;
            }
        }
        return count;
    }
};