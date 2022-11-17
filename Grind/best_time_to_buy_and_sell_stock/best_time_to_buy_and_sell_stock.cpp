class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum = 0;
        int lowest_price = std::numeric_limits<int>::max();
        
        // This solution is too slow
        // for (int i = 0; i < prices.size() - 1; i++) {
        //     int max = *std::max_element(prices.begin() + i + 1, prices.end());
        //     int new_maximum = max - prices[i];
        //     maximum = std::max(new_maximum, maximum);
        // }
        
        for (int i = 0; i < prices.size(); i++) {
            lowest_price = std::min(prices[i], lowest_price);
            maximum = std::max(prices[i] - lowest_price, maximum);
        }
        
        return maximum;
        
    }
};