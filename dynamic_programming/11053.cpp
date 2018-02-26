#include <iostream>
#include <cstdint>

#if 0
10, 20, 10, 30, 20, 50
99, 20, 10, 30, 20, 50
#endif
int main()
{
    uint32_t n;
    uint32_t input[1001] = {0};
    input[0] = 0;
    uint32_t result[1001] = {0};
    result[0] = 0;

    uint32_t answer = 0;

    std::cin >> n;
    for (uint32_t i = 1; i <= n; i++)
    {
        std::cin >> input[i];
        for (uint32_t j = 0; j < i; j++)
        {
            if (input[j] < input[i])
            {
                if (result[i] < result[j] + 1)
                {
                    result[i] = result[j] + 1;
                    if(answer < result[i])
                    {
                        answer = result[i];
                    }
                }
            }
        }
    }
    std::cout<<answer<<std::endl;
    return 0;
}