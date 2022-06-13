int findMinimumCoins(int amount) 
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    
    int num_coins = 0;
    int i = coins.size() - 1;
    while (amount) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            ++num_coins;
        }
        --i;
    }
    
    return num_coins;
}
