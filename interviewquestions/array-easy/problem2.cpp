//https://leetcode.com/explore/featured/card/top-interview-questions-easy/92/array/564/

#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    /** Initial Solution:
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
    }**/
    // Second Solution:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            // Every time it slopes upwards we accumulate the total change in slope
            // i.e everytime it goes up in value we add that change to profit
            if(prices[i + 1] > prices[i])
            {
                profit += (prices[i + 1] - prices[i]);
            }
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