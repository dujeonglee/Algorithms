#include <cstdint>
#include <iostream>
#include <queue>

int main()
{
    int32_t N;
    int32_t K;
    uint32_t V[3125];
    std::queue<std::pair<int32_t, int32_t>> q;

    for(uint32_t i = 0 ; i < 3125 ; i++)
    {
        V[i] = 0;
    }

    std::cin >> N;
    std::cin >> K;
    q.push(std::make_pair(N, 0));


    while (q.size() > 0)
    {
        int32_t position = q.front().first;
        int32_t time = q.front().second;
        q.pop();
        V[position / 32] |= (0x1 << position % 32);

        if (position == K)
        {
            std::cout << time << std::endl;
            return 0;
        }

        if ((position - 1 >= 0) && (V[(position - 1) / 32] & (0x1 << (position - 1) % 32)) == 0)
        {
            q.push(std::make_pair(position - 1, time + 1));
        }
        if ((position + 1 <= 100000) && (V[(position + 1) / 32] & (0x1 << (position + 1) % 32)) == 0)
        {
            q.push(std::make_pair(position + 1, time + 1));
        }
        if ((position * 2 <= 100000) && (V[(position * 2) / 32] & (0x1 << (position * 2) % 32)) == 0)
        {
            q.push(std::make_pair(position * 2, time + 1));
        }
    }
    return 0;
}