//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/564/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int i = 0;
        int j = 1;
        int stock;
        bool holding = false;
        int profit = 0;
        while(j < (int)prices.size())
        {
            if(prices[i] < prices[j])
            {
                if(!holding)
                {
                    stock = prices[i]; // buy the stock
                    holding = true;
                }
            }
            else
            {
                if(holding)
                {
                    // sell the stock
                    profit += prices[i] - stock;
                    holding = false;
                }
            }
            i++;
            j++;
        }
        // sell off remaining stock using last day value
        if(holding)
        {
            profit += prices[i] - stock;
            holding = false;
        }
        return profit;
    }
};

int main()
{
    Solution s;
    std::vector<int> prices = {7,6,4,3,1};
    int profit = s.maxProfit(prices);
    std::cout << "Profit: " << profit << std::endl;
    return 0;
}