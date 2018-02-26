#include <cstdint>
#include <iostream>

enum type_t
{
    T1 = 0, /*
            * 1
            * 1
            * 1
            */
    T2,     /*
            * 0
            * 0
            * 1
            */
    T3,     /*
            * 0
            * 1
            * 1
            */
    T4,     /*
            * 1
            * 0
            * 0
            */
    T5,     /*
            * 1
            * 1
            * 0
            */
    T6      /*
            * 0
            * 0
            * 0
            */
};

int main()
{
    uint32_t N;
    uint32_t DP[32][5];

    DP[0][T1] = 1;
    DP[0][T2] = 0;
    DP[0][T3] = 0;
    DP[0][T4] = 0;
    DP[0][T5] = 0;
    DP[0][T6] = 0;

    std::cin >> N;
    for (uint32_t i = 1; i <= N; i++)
    {
        DP[i][T1] = DP[i - 1][T3] + DP[i - 1][T5] + DP[i - 1][T6];
        DP[i][T2] = DP[i - 1][T5];
        DP[i][T3] = DP[i - 1][T4] + DP[i - 1][T1];
        DP[i][T4] = DP[i - 1][T3];
        DP[i][T5] = DP[i - 1][T2] + DP[i - 1][T1];
        DP[i][T6] = DP[i - 1][T1];
    }

    std::cout << DP[N][T1] << std::endl;
    return 0;
}