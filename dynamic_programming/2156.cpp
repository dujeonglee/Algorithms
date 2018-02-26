#include <cstdint>
#include <iostream>

int main()
{
    uint32_t WINES = 0;

    /*N N-1 N-3*/
    uint32_t A;
    uint32_t A_1;
    uint32_t A_2;

    /*N N-2 N-3*/
    uint32_t B;
    uint32_t B_1;
    uint32_t B_2;

    /*N N-2 N-4*/
    uint32_t C;
    uint32_t C_1;
    uint32_t C_2;

    std::cin >> WINES;

    if (WINES == 1)
    {
        uint32_t result = 0;
        std::cin >> result;
        std::cout << result << std::endl;
        return 0;
    }
    else if (WINES == 2)
    {
        uint32_t result = 0;
        uint32_t tmp = 0;
        std::cin >> tmp;
        result += tmp;
        std::cin >> tmp;
        result += tmp;
        std::cout << result << std::endl;
        return 0;
    }
    else
    {
        uint32_t result = 0;
        uint32_t SCORES[3] = {0};
        uint32_t tmp = 0;
        for (uint32_t i = 1; i <= 2; i++)
        {
            std::cin >> SCORES[i];
        }
        // For WINES == 2
        A = SCORES[2] + SCORES[1]; /*2, 1, -1*/
        A_1 = SCORES[1];           /*1, 0, -2*/
        A_2 = 0;                   /*0, -1, -3*/
        B = SCORES[2];             /*2, 0, -1*/
        B_1 = SCORES[1];           /*1, -1, -2*/
        B_2 = 0;
        C = SCORES[2];   /*2, 0, -2*/
        C_1 = SCORES[1]; /*1, -1, -3*/
        C_2 = 0;         /*0, -2, -4*/
        for (uint32_t i = 3; i <= WINES; i++)
        {
            std::cin >> tmp;
            A_2 = A_1;
            A_1 = A;
            B_2 = B_1;
            B_1 = B;
            C_2 = C_1;
            C_1 = C;
            if (A < B_1 + tmp)
            {
                A = B_1 + tmp;
            }
            if (A < C_1 + tmp)
            {
                A = C_1 + tmp;
            }

            if (B < A_2 + tmp)
            {
                B = A_2 + tmp;
            }

            if (C < B_2 + tmp)
            {
                C = B_2 + tmp;
            }
            if (C < C_2 + tmp)
            {
                C = C_2 + tmp;
            }
        }
        if (result < A)
        {
            result = A;
        }
        if (result < B)
        {
            result = B;
        }
        if (result < C)
        {
            result = C;
        }
        std::cout << result << std::endl;
        return 0;
    }
    return 0;
}