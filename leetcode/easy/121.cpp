class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    int min_price = prices[0];
    int max_w = 0;

    for (int i = 0; i < prices.size(); ++i) {
        max_w = max(prices[i] - min_price, max_w);
        min_price = min(min_price, prices[i]);
        }

        return max_w;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min_num = prices[0];
        int max_w = 0;

        for (int price: prices) {
            max_w = max(max_w, price - min_num);
            min_num = min(min_num, price);
        }

        return max_w;
    }
};