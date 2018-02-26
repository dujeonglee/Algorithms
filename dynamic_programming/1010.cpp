#include <cstdint>
#include <iostream>

#if 0
N! / N-C! / C! 
N! / C+1! / C-1!
#endif
int main()
{
    uint32_t choose[31][31];
    uint32_t T;
    uint32_t N;
    uint32_t M;
    uint32_t RESULT;

    for (uint32_t i = 1; i <= 30; i++)
    {
        for (uint32_t j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                choose[i][j] = i;
            }
            else
            {
                choose[i][j] = choose[i][j - 1] * (i - j + 1) / j;
            }
        }
    }
    
    std::cin >> T;
    for (uint32_t i = 0; i < T; i++)
    {
        std::cin >> N;
        std::cin >> M;
        std::cout << choose[M][N] << std::endl;
    }
    return 0;
}