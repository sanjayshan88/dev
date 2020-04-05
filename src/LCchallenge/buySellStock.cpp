#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int sum = 0;
    if (prices.size() <=1 ) {
        return 0;
    }

    for (int i=1; i<prices.size(); i++) {
        int last_sell = 0;
        if (prices[i] < prices[i-1]) {
            last_sell = prices[i];
        } else {
            sum += prices[i] - prices[i-1];
        }
    }

    return sum;
}

int main()
{
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(1);
    //prices.push_back(4);

    cout << maxProfit(prices) << endl;

    return 0;
}