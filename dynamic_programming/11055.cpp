#include <cstdint>
#include <iostream>

int main()
{
    uint32_t n;
    uint32_t array[1001];
    uint32_t sum[1001];
    uint32_t result = 0;
    std::cin >> n;

    for (uint32_t i = 1; i <= n; i++)
    {
        std::cin >> array[i];
        sum[i] = array[i];
        if(result < sum[i])
        {
            result = sum[i];
        }
    }
    for (uint32_t i = 1; i <= n; i++)
    {
        for (uint32_t ii = 1; ii <= i - 1; ii++)
        {
            if (array[ii] < array[i])
            {
                if (sum[i] < sum[ii] + array[i])
                {
                    sum[i] = sum[ii] + array[i];
                    if (result < sum[i])
                    {
                        result = sum[i];
                    }
                }
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}