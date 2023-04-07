#include <iostream>
#include <math.h>

using namespace std;

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

int main()
{
    //megadott paraméterek
    double x0 = 10.0;
    auto f = [](double x) {return x * x - 612.0; };
    auto df = [](double x) {return 2 * x; };

    double eredmeny = Newtonit(f, df, x0);
    std::cout << eredmeny << std:: endl;
    return 0;
}
