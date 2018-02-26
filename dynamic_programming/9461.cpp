#include <cstdint>
#include <iostream>

int main()
{
    uint32_t T;
    uint32_t DP[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
    for (uint32_t i = 11; i <= 100; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 5];
    }

    std::cin >> T;
    for (uint32_t t = 0; t < T; t++)
    {
        uint32_t N;
        std::cin >> N;

        std::cout << DP[N] << std::endl;
        std::cout << DP[10] << std::endl;
    }
}
