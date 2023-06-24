
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // int ch1 = INT_MAX, ch2 = INT_MAX -1;
        sort(prices.begin(),prices.end());
        return (prices[0]+prices[1]) > money ? money: money - (prices[0]+prices[1]);
        
    }
};