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



    return 0;

}
