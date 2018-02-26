#include <cstdint>
#include <iostream>

int main()
{
    int32_t n;
    int32_t k;
    int32_t values[100];
    int32_t dp[10001];

    std::cin >> n;
    std::cin >> k;
    for (int32_t i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }
    for (int32_t i = 1; i <= k; i++)
    {
        dp[i] = -1;
        for (int32_t j = 0; j < n; j++)
        {
            if (i == values[j])
            {
                dp[i] = 1;
            }
            else if (i > values[j])
            {
                if (dp[i - values[j]] == -1)
                {
                    continue;
                }
                else if ((dp[i] == -1) || (dp[i] > dp[i - values[j]] + 1))
                {
                    dp[i] = dp[i - values[j]] + 1;
                }
            }
        }
    }
    std::cout << dp[k] << std::endl;
    return 0;
}