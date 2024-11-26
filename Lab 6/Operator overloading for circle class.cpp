#include <iostream>
using namespace std;

class Circle{
    double radius;
    public:
        void setRadius(double);
        double getRadius() const;

        Circle operator +(Circle);
        Circle operator +(double);
        friend Circle operator +(double, Circle);

};

double Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(double r)
{
    if(r > 0)
        radius = r;
    else
        radius = 1;
}

Circle Circle::operator +(Circle rhs)
{
    Circle temp;
    temp.radius = radius + rhs.radius;
    return temp;
}

Circle Circle::operator +(double n)
{
    Circle temp;
    temp.radius = radius + n;
    return temp;;
}

Circle operator+(double n, Circle rhs)
{
    Circle temp;
    temp.radius = n + rhs.radius;
    return temp;
}

int main()
{

    Circle circle1, circle2, circle3, circle4,circle5, circle6;

    circle1.setRadius(6.3);
    circle2.setRadius(4.2);
    circle3.setRadius(12.5);

    circle4 = circle1 + circle2;
    circle5 = circle2 + 8.23;
    circle6 = 7.4 + circle2;

    cout << "Radius of Circle 4 : " << circle4.getRadius() << endl;
    cout << "Radius of Circle 5 : " << circle5.getRadius() << endl;
    cout << "Radius of Circle 6 : " << circle6.getRadius() << endl;

    circle4 = circle1 + circle2 + circle3; // cascading
    cout << "Radius of Circle 4 : " << circle4.getRadius() << endl;

    return 0;
}