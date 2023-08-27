class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        set<int> num;
        long long sum = 0;
        for( int i = 1; num.size() < n; ++i )
        {
            if( num.find(target-i) == num.end() )
            {
                sum += i;
                num.insert(i);
            }
        }
        return sum;
    }
};