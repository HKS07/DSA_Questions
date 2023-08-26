class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        int once = p%10;
        
        if( once >= 5)
        {
            p += (10-once);
        }
        else 
        {
            p -= once;
        }
        
        return 100-p;
    }
};