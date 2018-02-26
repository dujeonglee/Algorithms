#include <cstdint>
#include <iostream>

int main()
{
    int32_t STAIRS = 0;
    int32_t SCORES[301];

    std::cin >> STAIRS;
    for (uint32_t s = 1; s <= STAIRS; s++)
    {
        std::cin >> SCORES[s];
    }
    // [N][N-1][N-3]
    int32_t A = 0;
    // [N-1][N-2][N-4]
    int32_t A_1 = 0;
    // [N-2][N-3][N-5]
    int32_t A_2 = 0;

    // [N][N-2][N-3]
    int32_t B = 0;
    // [N-1][N-3][N-4]
    int32_t B_1 = 0;
    // [N-2][N-4][N-5]
    int32_t B_2 = 0;

    // [N][N-2][N-4] 
    int32_t C = 0;
    // [N-1][N-3][N-5] 
    int32_t C_1 = 0;
    // [N-2][N-4][N-6] 
    int32_t C_2 = 0;

    for (int32_t last_step = 1; last_step <= STAIRS; last_step++)
    {
        A_2 = A_1;
        A_1 = A;
        A = 0;
        B_2 = B_1;
        B_1 = B;
        B = 0;
        C_2 = C_1;
        C_1 = C;
        C = 0;
        if(A < B_1 + SCORES[last_step])
        {
            A = B_1 + SCORES[last_step];
        }
        if(A < C_1 + SCORES[last_step])
        {
            A = C_1 + SCORES[last_step];
        }

        if(B < A_2 + SCORES[last_step])
        {
            B = A_2 + SCORES[last_step];
        }

        if(C < B_2 + SCORES[last_step])
        {
            C = B_2 + SCORES[last_step];
        }
        if(C < C_2 + SCORES[last_step])
        {
            C = C_2 + SCORES[last_step];
        }
    }
    int32_t result = 0;
    if(result < A)
    {
        result = A;
    }
    if(result < B)
    {
        result = B;
    }
    if(result < C)
    {
        result = C;
    }
    std::cout << result << std::endl;
    return 0;
}