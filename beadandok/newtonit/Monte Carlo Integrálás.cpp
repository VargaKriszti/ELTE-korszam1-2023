using namespace std;
#include <iostream>
#include <functional>
#include <random>




//Monte Carlo Integrálás
template<typename F, typename P>
double MonteCarlo(F integrand, P inDomain, double xmin, double xmax, double ymin, double ymax, double zmin, double zmax) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> xDist(xmin, xmax);
    std::uniform_real_distribution<double> yDist(ymin, ymax);
    std::uniform_real_distribution<double> zDist(zmin, zmax);

    int numSamples = 1000000; // Number of samples for the Monte Carlo integration
    int count = 0;
    for (int i = 0; i < numSamples; ++i) {
        double x = xDist(gen);
        double y = yDist(gen);
        double z = zDist(gen);
        if (inDomain(x, y, z)) {
            count++;
        }
    }

    double volume = (xmax - xmin) * (ymax - ymin) * (zmax - zmin);
    double result = volume * (count / static_cast<double>(numSamples));
    return result;
}


int main()
{
    double result = MonteCarlo(
    [](auto x, auto y, auto z) { return exp(-x * x - y * y - z * z); },
    [](auto x, auto y, auto z) -> bool { return x * x + y * y + z * z < 16.0; },
    -4.0, 4.0, -4.0, 4.0, -4.0, 4.0
    );

    std::cout << "Közelítő érték: " << result << std::endl;

    return 0;
}