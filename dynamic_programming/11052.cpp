#include <cstdint>
#include <iostream>

#if 0
1
10

2
10 5

3
10 5 15
#endif
int main()
{
    uint32_t n;
    uint32_t price[1001];
    uint32_t DP[1001] = {0};
    DP[0] = 0;

    std::cin >> n;
    for (uint32_t i = 1; i <= n; i++)
    {
        std::cin >> price[i];
        DP[i] = 0;
        for (uint32_t j = 0; j < i; j++)
        {
            if (DP[i] < DP[j] + price[i - j])
            {
                DP[i] = DP[j] + price[i - j];
            }
        }
    }
    std::cout<<DP[n]<<std::endl;
    return 0;
}