#include <cstdint>
#include <iostream>

int main()
{
    uint32_t N;
    uint32_t DP[100001];

    std::cin >> N;

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    DP[4] = 1;

    for (uint32_t i = 5; i <= N; i++)
    {
        DP[i] = 0xffffffff;
        uint32_t ii = 1;
        while (i >= ii * ii)
        {
            if (DP[i] > DP[i - ii * ii] + 1)
            {
                DP[i] = DP[i - ii * ii] + 1;
            }
            ii++;
        }
    }
    std::cout << DP[N] << std::endl;
    return 0;
}