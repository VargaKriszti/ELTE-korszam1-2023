#include "newtonit.h"
using namespace std;
#include <iostream>
#include <functional>
#include <random>

template <typename F, typename T, typename dF>
T Newtonit(F f, dF df, T x0)
{
    T a = x0;
    for (int i = 1; i < 100; i++) //csak 100 iteráció
    {
        T h = f(x0) / df(x0);
        a = x0 - h;
		x0 = a;
    }
    return a;
}






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
    //megadott paraméterek
    double x0 = 10.0;
    auto f = [](double x) {return x * x - 612.0; };
    auto df = [](double x) {return 2 * x; };

    double eredmeny = Newtonit(f, df, x0);
    std::cout << eredmeny << std:: endl;


    //második házi kipróbálása
    Vector2d v = {1.0, 2.0};
    Vector2d u = {4.0, -2.0};
    auto s = 2.0;
    std::cout << "Öszeadás után az x=" << v.x+u.x << " és az y=" << v.y+u.y << " koordináták.\n";
    std::cout << "Kivonás után az x=" << v.x-u.x << " és az y=" << v.y-u.y << " koordináták.\n";
    std::cout << "Osztás után az x=" << v.x/s << " és az y=" << v.y/s << " koordináták.\n";
    std::cout << "Szorzás után az x=" << v.x*s << " és az y=" << v.y*s << " koordináták.\n";


     v += u;
    std::cout << "+= után az x=" << v.x << " és az y=" << v.y<< " koordináták.\n";
     v -= u;
    std::cout << "-= után az x=" << v.x << " és az y=" << v.y << " koordináták.\n";
     v *= s;
    std::cout << "*= után az x=" << v.x << " és az y=" << v.y << " koordináták.\n";
     v /= s; 
    std::cout << "/= után az x=" << v.x << " és az y=" << v.y << " koordináták.\n";


    std::cout << "Vektorszorzás után az eredmény: " << v.dot(u) <<"\n";
    auto a = v.length();
    std::cout << "A vektor hossza: " << a << "\n";
    auto b = v.sqlength();
    std::cout << "A vektor hosszának négyzete: " << b << "\n";
    std::cout << "A vektor normált hossza: " << v.normalize() << "\n";




    //nagybeadandó Monte Carlo Integrálás
    double result = MonteCarlo(
        [](auto x, auto y, auto z) { return exp(-x * x - y * y - z * z); },
        [](auto x, auto y, auto z) -> bool { return x * x + y * y + z * z < 16.0; },
        -4.0, 4.0, -4.0, 4.0, -4.0, 4.0
    );

    std::cout << "Approximate result: " << result << std::endl;




    return 0;

}
