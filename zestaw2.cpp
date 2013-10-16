#include <iostream>
#include <cmath>

using namespace std;

class wektor
{
    private:
        double * xy;
    public:

        void ustaw_x(double a) {xy[0] = a;}

        void ustaw_y(double a) {xy[1] = a;}

        wektor()
        {
            xy = new double[2];
            xy[0] = 0;
            xy[1] = 0;
        }

        wektor(double x, double y)
        {
            xy = new double[2];
            ustaw_x(x);
            ustaw_y(y);
        }

        ~wektor()
        {
            delete[] xy;
        }

        double X() {return xy[0];}

        double Y() {return xy[1];}

        double dlugosc() {return sqrt((xy[0]*xy[0])+(xy[1]*xy[1]));}

        wektor operator+ (wektor g)
        {
            wektor temp;
            temp.xy[0] = g.xy[0] + xy[0];
            temp.xy[1] = g.xy[1] + xy[1];
            return temp;
        }

        wektor operator* (double g)
        {
            wektor temp;
            temp.xy[0] = g * xy[0];
            temp.xy[1] = g * xy[1];
            return temp;
        }

        bool rownosc(double a, double b)
        {
            return abs(a-b)<0.001;
        }

        bool operator== (wektor g)
        {
            return rownosc(X(), g.X()) && rownosc(Y(), g.Y());
        }

        bool operator!= (wektor g)
        {
            return !(*this==g);
        }
};

int main(void)
{
    wektor a(2,4);
    wektor b(3,5);
    wektor c;
    c = a + b;
    cout << c.X() << "," << c.Y() << endl;
}
