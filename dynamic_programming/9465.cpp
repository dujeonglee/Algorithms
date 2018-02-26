#include <cstdint>
#include <iostream>

int main()
{
    uint32_t T;

    std::cin >> T;
    for (uint32_t t = 0; t < T; t++)
    {
        uint32_t n;
        uint16_t S_T[100001];
        uint16_t S_B[100001];

        uint32_t N_T;
        uint32_t N_1_T;
        uint32_t N_2_T;
        uint32_t N_B;
        uint32_t N_1_B;
        uint32_t N_2_B;

        std::cin >> n;
        for (uint32_t i = 1; i <= n; i++)
        {
            std::cin >> S_T[i];
        }
        for (uint32_t i = 1; i <= n; i++)
        {
            std::cin >> S_B[i];
        }

        N_T = S_T[1];
        N_1_T = 0;
        N_2_T = 0;
        N_B = S_B[1];
        N_1_B = 0;
        N_2_B = 0;

        for (uint32_t i = 2; i <= n; i++)
        {
            N_2_T = N_1_T;
            N_1_T = N_T;
            N_T = 0;

            N_2_B = N_1_B;
            N_1_B = N_B;
            N_B = 0;

            if (N_T < N_2_T + S_T[i])
            {
                N_T = N_2_T + S_T[i];
            }
            if (N_T < N_2_B + S_T[i])
            {
                N_T = N_2_B + S_T[i];
            }
            if (N_T < N_1_B + S_T[i])
            {
                N_T = N_1_B + S_T[i];
            }

            if (N_B < N_2_B + S_B[i])
            {
                N_B = N_2_B + S_B[i];
            }
            if (N_B < N_2_T + S_B[i])
            {
                N_B = N_2_T + S_B[i];
            }
            if (N_B < N_1_T + S_B[i])
            {
                N_B = N_1_T + S_B[i];
            }
        }
        std::cout << (N_T > N_B ? N_T : N_B) << std::endl;
    }
    return 0;
}