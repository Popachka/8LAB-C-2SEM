#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Perimeter
{
public:
    static int Count;
    virtual double Calc() = 0;
    Perimeter()
    {
        Count++;
    }
    ~Perimeter(){
        Count--;
    }

protected:
    const double pi = 3.14;
};
int Perimeter::Count = 0;
class Circle : public Perimeter
{
public:
    Circle()
    {
        R = 1;
    }
    Circle(double R)
    {
        this->R = R;
    }
    double Calc() override
    {
        return 2 * pi * R;
    }
    ~Circle(){};

private:
    double R;
};
class Square : public Perimeter
{
public:
    Square()
    {
        a = 1;
    };
    Square(double a)
    {
        this->a = a;
    };
    ~Square(){};
    double Calc() override
    {
        return a + a;
    }

private:
    double a;
};
class Rectangle : public Perimeter
{
public:
    Rectangle()
    {
        a = 1;
        b = 1;
    }
    Rectangle(double a, double b)
    {
        this->a = a;
        this->b = b;
    }
    ~Rectangle() {}
    double Calc() override
    {
        return (a + b) * 2;
    }

private:
    double a;
    double b;
};

class Figure
{
public:
    double Calc(Perimeter *perimeter)
    {
        return perimeter->Calc();
    }

private:
};
int main()
{
    Circle ball;
    Square box;
    Rectangle wardrobe;
    Figure anyFigure;
    vector<Perimeter *> figures = {&ball, &box, &wardrobe};
    for (int i = 0; i < figures.size(); i++)
    {
        if (i == 0)
        {
            cout << "P.Ball = ";
        }
        if (i == 1)
        {
            cout << "P.Box = ";
        }
        if (i == 2)
        {
            cout << "P.Wardrobe = ";
        }
        cout << anyFigure.Calc(figures[i]) << endl;
    }

    return 0;
}