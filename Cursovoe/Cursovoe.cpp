#include <iostream>
#include <list>

using namespace std;

struct Point
{
    double x;
    double y;
};

bool SearchAndInput(list<Point>& points,Point newPoint)
{
    bool result=false;
    for (auto bIter = points.begin(); bIter != points.end(); bIter++)
    {
        if ((*bIter).x > newPoint.x)
        {
            points.insert(--bIter, newPoint);
            result = true;
            break;
        }
    }
    if(result != true)
    {

    }
}

void DataInput(list<Point>& points)
{
    for (;;)
    {
        Point temp;
        cout << "Введите X:" << endl;
        cin >> temp.x;
        cout << "Введите Y:" << endl;
        cin >> temp.y;

        if(points.empty() == true)
        {
            points.push_front(temp);
        }
        else
        {
           
        }
    }
}

double linear_interpolation(double x1, double y1, double x2, double y2, double x) {
    return y1 + (y2 - y1) * ((x - x1) / (x2 - x1));
}

int main() {
    list<Point> points;

    double x[] = { 0, 1, 2, 3, 4 };
    double y[] = { 0, 1, 4, 9, 16 };
    double x_new = 2.5;
    double y_new = linear_interpolation(x[2], y[2], x[3], y[3], x_new);
    cout << "The value of f(" << x_new << ") is approximately " << y_new << endl;
    return 0;
}