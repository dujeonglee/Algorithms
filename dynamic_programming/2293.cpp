#include <cstdint>
#include <iostream>

int main()
{
    uint32_t n;
    uint32_t k;
    uint32_t tokens[100];
    uint32_t DP[10001] = {0};

    std::cin >> n;
    std::cin >> k;

    for (uint32_t i = 0; i < n; i++)
    {
        std::cin >> tokens[i];
    }

    DP[0] = 1;
    for (uint32_t t = 0; t < n; t++)
    {
        for (uint32_t i = tokens[t]; i <= k; i++)
        {
            if (i >= tokens[t])
            {
                DP[i] += DP[i - tokens[t]];
            }
        }
    }
    std::cout << DP[k] << std::endl;
    return 0;
}
