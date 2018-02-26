#include <cstdint>
#include <iostream>

int main()
{
    int32_t N;
    int32_t M;
    int32_t MAT[301][301] = {{0}};
    int32_t tmp;
    int32_t K;

    std::cin >> N;
    std::cin >> M;
    for (int32_t n = 0; n <= N; n++)
    {
        for (int32_t m = 0; m <= M; m++)
        {
            if (n == 0 || m == 0)
            {
                MAT[n][m] = 0;
            }
            else
            {
                std::cin >> tmp;
                MAT[n][m] = MAT[n][m-1] + tmp;
            }
        }
    }

    std::cin >> K;
    for (int32_t k = 0; k < K; k++)
    {
        int32_t i, j;
        int32_t x, y;
        int32_t result;
        std::cin >> i;
        std::cin >> j;
        std::cin >> x;
        std::cin >> y;
        result = 0;
        for (i; i <= x; i++)
        {
            result += (MAT[i][y] - MAT[i][j-1]);
        }
        std::cout << result << std::endl;
    }
    return 0;
}