#include <cstdint>
#include <iostream>

int main()
{
    uint32_t N;
    uint32_t RED_COST[1000];
    uint32_t GREEN_COST[1000];
    uint32_t BLUE_COST[1000];

    uint32_t END_WITH_RED[1000];
    uint32_t END_WITH_GREEN[1000];
    uint32_t END_WITH_BLUE[1000];
    std::cin >> N;
    for (uint32_t i = 0; i < N; i++)
    {
        std::cin >> RED_COST[i];
        std::cin >> GREEN_COST[i];
        std::cin >> BLUE_COST[i];
    }
    END_WITH_RED[0] = RED_COST[0];
    END_WITH_GREEN[0] = GREEN_COST[0];
    END_WITH_BLUE[0] = BLUE_COST[0];
    if (N == 1)
    {
    }
    else
    {
        for (uint32_t i = 1; i < N; i++)
        {
            if (END_WITH_BLUE[i - 1] < END_WITH_GREEN[i - 1])
            {
                END_WITH_RED[i] = END_WITH_BLUE[i - 1] + RED_COST[i];
            }
            else
            {
                END_WITH_RED[i] = END_WITH_GREEN[i - 1] + RED_COST[i];
            }

            if (END_WITH_RED[i - 1] < END_WITH_BLUE[i - 1])
            {
                END_WITH_GREEN[i] = END_WITH_RED[i - 1] + GREEN_COST[i];
            }
            else
            {
                END_WITH_GREEN[i] = END_WITH_BLUE[i - 1] + GREEN_COST[i];
            }

            if (END_WITH_RED[i - 1] < END_WITH_GREEN[i - 1])
            {
                END_WITH_BLUE[i] = END_WITH_RED[i - 1] + BLUE_COST[i];
            }
            else
            {
                END_WITH_BLUE[i] = END_WITH_GREEN[i - 1] + BLUE_COST[i];
            }
        }
    }
    if (END_WITH_RED[N - 1] <= END_WITH_GREEN[N - 1] && END_WITH_RED[N - 1] <= END_WITH_BLUE[N - 1])
    {
        std::cout << END_WITH_RED[N - 1] << std::endl;
    }
    else if (END_WITH_GREEN[N - 1] <= END_WITH_RED[N - 1] && END_WITH_GREEN[N - 1] <= END_WITH_BLUE[N - 1])
    {
        std::cout << END_WITH_GREEN[N - 1] << std::endl;
    }
    else if (END_WITH_BLUE[N - 1] <= END_WITH_GREEN[N - 1] && END_WITH_BLUE[N - 1] <= END_WITH_RED[N - 1])
    {
        std::cout << END_WITH_BLUE[N - 1] << std::endl;
    }
    return 0;
}