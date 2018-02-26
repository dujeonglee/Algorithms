#include <cstdint>
#include <iostream>

int main()
{
    uint32_t N;
    uint32_t M;
    uint32_t candy[1000][1000];

    std::cin >> N;
    std::cin >> M;

    for (uint32_t i = 0; i < N; i++)
    {
        for (uint32_t j = 0; j < M; j++)
        {
            candy[i][j] = 0;
            uint32_t tmp;
            std::cin >> tmp;
            if (i < 1 && j < 1)
            {
                candy[i][j] = tmp;
            }
            if(i > 0)
            {
                if(candy[i][j] < candy[i-1][j] + tmp)
                {
                    candy[i][j] = candy[i-1][j] + tmp;
                }
            }
            if(j > 0)
            {
                if(candy[i][j] < candy[i][j-1] + tmp)
                {
                    candy[i][j] = candy[i][j-1] + tmp;
                }
            }
            if(i > 0 && j > 0)
            {
                if(candy[i][j] < candy[i-1][j-1] + tmp)
                {
                    candy[i][j] = candy[i-1][j-1] + tmp;
                }
            }
        }
    }
    std::cout<<candy[N-1][M-1]<<std::endl;
    return 0;
}