#include <cstdint>
#include <iostream>

uint32_t result[501][501] = {0};

int main()
{
    uint32_t NUMBERS = 0;
    std::cin >> NUMBERS;
    uint32_t solution = 0;

    for (uint32_t level = 1; level <= NUMBERS; level++)
    {
        for (uint32_t i = 1; i <= level; i++)
        {
            uint32_t score = 0;
            std::cin >> score;
            if (level == 1)
            {
                result[level][i] = score;
                break;
            }
            else
            {
                if ((i - 1 >= 1) && (result[level - 1][i - 1] + score > result[level][i]))
                {
                    result[level][i] = result[level - 1][i - 1] + score;
                }
                if ((i <= level - 1) && (result[level - 1][i] + score > result[level][i]))
                {
                    result[level][i] = result[level - 1][i] + score;
                }
                if ((level == NUMBERS) && (solution < result[level][i]))
                {
                    solution = result[level][i];
                }
            }
        }
    }
    if (NUMBERS == 1)
    {
        std::cout << result[1][1] << std::endl;
    }
    else
    {
        std::cout << solution << std::endl;
    }
    return 0;
}