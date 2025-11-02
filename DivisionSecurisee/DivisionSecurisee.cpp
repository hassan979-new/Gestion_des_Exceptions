#include <iostream>
using namespace std;

double diviser(double a, double b)
{
    if (b == 0)
    {
        throw "impossible de diviser sur 0";
    }
    return a / b;
}

int main(int argc, char const *argv[])
{
    try
    {
        cout << "10 / 2 = " << diviser(10, 2) << endl;
        cout << "15.5 / 3.5 = " << diviser(15.5, 3.5) << endl;
        cout << "10 / 0 = " << diviser(10, 0) << endl;
    }
    catch (const char *e)
    {
        std::cerr << "Erreur : " << e << '\n';
    }

    return 0;
}
