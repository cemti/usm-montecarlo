#include <iostream>
#include <random>
static constexpr size_t N = 100;

int main()
{
    std::mt19937 rd(std::random_device{}());
    std::uniform_int_distribution<> di(0, N);

    size_t A = 0, xi = 0, n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        uint8_t arr[N + 1]{};
        auto even = 1 + (N >> 1);
        auto odd = N - (N >> 1);

        while (even != 0)
        {
            auto j = di(rd);

            if (arr[j] == 0)
                --(j & 1 ? odd : even);
            else if (j == 1 && arr[j] == 1)
                ++A;
            else
                continue;

            ++arr[j];
        }

        xi += odd;
    }
    
    std::cout << "P(A) = " << static_cast<double>(A) / n
        << "\nMxi = " << static_cast<double>(xi) / n;
}