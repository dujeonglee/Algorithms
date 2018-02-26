#include <cstdint>
#include <iostream>

int main()
{
    int32_t TEST_CASE;
    int32_t NUMBER;

    int32_t ones;
    int32_t twos;
    int32_t threes;
    int32_t factorial[12];

    factorial[0] = 1;
    for (uint32_t i = 1; i <= 11; i++)
    {
        if (i == 1)
        {
            factorial[i] = 1;
        }
        else
        {
            factorial[i] = factorial[i - 1] * i;
        }
    }

    std::cin >> TEST_CASE;
    for (int32_t t = 0; t < TEST_CASE; t++)
    {
        std::cin >> NUMBER;

        int32_t result = 0;

        for (threes = NUMBER / 3; threes > -1; threes--)
        {
            for (twos = (NUMBER - (threes * 3)) / 2; twos > -1; twos--)
            {
                result += factorial[threes + twos + NUMBER - (threes * 3) - (twos * 2)] / (factorial[threes] * factorial[twos] * factorial[NUMBER - (threes * 3) - (twos * 2)]);
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}