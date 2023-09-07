class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
    
        for( int num = low; num <= high; ++num )
        {
            string curNum = to_string(num);
            int n = curNum.length();
            int sum = 0;
            for( int i = 0; i < n/2; ++i )
            {
                sum += curNum[i] - curNum[n-1-i];
            }
            if( n%2 == 0 && sum == 0 ) count++;
        }
        return count;
    }
};