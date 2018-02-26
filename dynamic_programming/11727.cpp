#include <cstdint>
#include <iostream>

int main()
{
    uint32_t n;
    uint32_t dp[1001] = {0};

    std::cin >> n;

    dp[1] = 1; // |,
    dp[2] = 3; // ||, =, ㅁ
    for (uint32_t i = 3; i <= n; i++)
    {
        dp[i] = 0;
        dp[i] = (dp[i] + dp[i - 1]) % 10007; // |
        dp[i] = (dp[i] + dp[i - 2]) % 10007; // ㅁ
        dp[i] = (dp[i] + dp[i - 2]) % 10007; // =
    }
    std::cout << dp[n] << std::endl;
    return 0;
}