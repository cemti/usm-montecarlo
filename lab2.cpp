#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>

auto f(double x, double y) { return 1 / std::sqrt(24 + x * x + y * y); }
auto G(double x, double y) { return x * x + y * y <= 25; }

int main()
{
    size_t n;
    std::cin >> n;

    std::uniform_real_distribution<> di(-5, 5);
    std::mt19937 rnd(std::random_device{}());
    auto S = 0.;

    for (size_t i = 0; i < n; ++i)
        if (auto x = di(rnd), y = di(rnd); G(x, y))
            S += f(x, y);

    constexpr auto A = (5. * 2) * (5 * 2);
    std::cout << std::fixed << std::setprecision(8) << A * S / n;
}