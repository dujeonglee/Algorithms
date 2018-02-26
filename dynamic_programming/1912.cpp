#include <cstdint>
#include <iostream>
#include <vector>

int main()
{
    uint32_t N;
    int32_t input;
    int32_t solution;

    std::cin >> N;

    std::vector<int32_t> result(N, 0);

    std::cin >> result[0];
    solution = result[0];
    for (uint32_t i = 1; i < N; i++)
    {
        std::cin >> input;
        if (result[i - 1] + input > input)
        {
            result[i] = result[i - 1] + input;
        }
        else
        {
            result[i] = input;
        }
        if(solution < result[i])
        {
            solution = result[i];
        }
    }
    std::cout<<solution<<std::endl;
    return 0;
}