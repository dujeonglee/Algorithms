#include <cstdint>
#include <iostream>
#include <queue>
#include <tuple>

#define MAX_QUEUE_LENGTH (10000)

int main()
{
    uint32_t N;
    uint32_t M;
    uint32_t front = 0;
    uint32_t rear = 0;

    char matrix[101][101];
    std::queue<std::tuple<uint8_t, uint8_t, uint32_t>> q;

    std::cin >> N;
    std::cin >> M;
    for (uint8_t i = 0; i <= N; i++)
    {
        for (uint8_t j = 0; j <= M; j++)
        {
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            }
            else
            {
                std::cin >> matrix[i][j];
                matrix[i][j] -= '0';
            }
        }
    }

    // push
    q.push(std::make_tuple(1, 1, 1));
    matrix[1][1] |= 0x2;
    while (q.size())
    {
        // pop
        uint8_t n = std::get<0>(q.front());
        uint8_t m = std::get<1>(q.front());
        uint32_t length = std::get<2>(q.front());
        q.pop();

        if (n == N && m == M)
        {
            std::cout << length << std::endl;
            return 0;
        }
        else
        {
            if (n + 1 <= N && ((matrix[n + 1][m] & 0x2) == 0) && matrix[n + 1][m])
            {
                matrix[n + 1][m] |= 0x2;
                q.push(std::make_tuple(n + 1, m, length + 1));
            }
            if (m + 1 <= M && ((matrix[n][m + 1] & 0x2) == 0) && matrix[n][m + 1])
            {
                matrix[n][m + 1] |= 0x2;
                q.push(std::make_tuple(n, m + 1, length + 1));
            }
            if (n - 1 > 0 && ((matrix[n - 1][m] & 0x2) == 0) && matrix[n - 1][m])
            {
                matrix[n - 1][m] |= 0x2;
                q.push(std::make_tuple(n - 1, m, length + 1));
            }
            if (m - 1 > 0 && ((matrix[n][m - 1] & 0x2) == 0) && matrix[n][m - 1])
            {
                matrix[n][m - 1] |= 0x2;
                q.push(std::make_tuple(n, m - 1, length + 1));
            }
        }
    }
    return 0;
}