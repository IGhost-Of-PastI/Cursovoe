#include <iostream>
#include <list>
#include <Windows.h>

using namespace std;

//void SearchAndInput(list<Point>& points, Point newPoint)
//{
//    bool result = false;
//    //*** Проверка не существует ли точки с такой же координатой x в списке   
//    bool IsExist = false;
//    for (auto bIter = points.begin(); bIter != points.end(); bIter++)
//    {
//        if ((*bIter).x == newPoint.x)
//        {
//            IsExist = true;
//            cout << "Точка с такой координатой x существует";
//            break;
//        }
//    }
//    //***
//    //*** Если такой точки не существут то доабвить точку
//    if (IsExist == false)
//    {
//        //*** Чтобы проще искать сосдение точки, список заполняется в определённом порядке
//        for (auto bIter = points.begin(); bIter != points.end(); bIter++)
//        {
//            //*** Поиск точки чья координата x больше координаты новой точки
//            if ((*bIter).x > newPoint.x)
//            {
//                //*** Если такая точка найдена то передней вставляется новая точка
//                if (bIter == points.begin())
//                {
//                    points.push_front(newPoint);
//                    result = true;
//                    break;
//                }
//                else
//                {
//                    points.insert(--bIter, newPoint);
//                    result = true;
//                    break;
//                }
//                //***
//            }
//            //***
//        }
//        //*** Если такая точка не найдена то просто добавить новую точку в конец списка.
//        if (result != true)
//        {
//            points.push_back(newPoint);
//        }
//        //***
//    }
//    //***
//}
//void OutPutPoints(list<Point>& points)
//{
//    for (auto bIter = points.begin(); bIter != points.end(); bIter++)
//    {
//        cout << "Точка " << "x: " << (*bIter).x << " y: " << (*bIter).y << endl;
//    }
//}
struct Point
{
    double x;
    double y;
};




void DataInput(list<Point>& points)
{
    int count;
    cout << "Введите колличество точке, которыми вы зададите функцию" << endl;
    cin >> count;

    for (int i=0;i<count;i++)
    {
        //*** Ввод новой точки
        Point temp;
        cout << "Введите X:" << endl;
        cin >> temp.x;
        cout << "Введите Y:" << endl;
        cin >> temp.y;
        //***

        //*** Попытка добавить точку в список
        bool result = false;
        //*** Проверка не существует ли точки с такой же координатой x в списке   
        bool IsExist = false;
        for (auto bIter = points.begin(); bIter != points.end(); bIter++)
        {
            if ((*bIter).x == temp.x)
            {
                IsExist = true;
                cout << "Точка с такой координатой x существует";
                break;
            }
        }
        //***
        //*** Если такой точки не существут то доабвить точку
        if (IsExist == false)
        {
            //*** Чтобы проще искать сосдение точки, список заполняется в определённом порядке
            for (auto bIter = points.begin(); bIter != points.end(); bIter++)
            {
                //*** Поиск точки чья координата x больше координаты новой точки
                if ((*bIter).x > temp.x)
                {
                    //*** Если такая точка найдена то передней вставляется новая точка
                    if (bIter == points.begin())
                    {
                        points.push_front(temp);
                        result = true;
                        break;
                    }
                    else
                    {
                        points.insert(--bIter, temp);
                        result = true;
                        break;
                    }
                    //***
                }
                //***
            }
            //*** Если такая точка не найдена то просто добавить новую точку в конец списка.
            if (result != true)
            {
                points.push_back(temp);
            }
            //***
        }
        //***
        //***
    }
    for (auto bIter = points.begin(); bIter != points.end(); bIter++)
    {
        cout << "Точка " << "x: " << (*bIter).x << " y: " << (*bIter).y << endl;
    }
}

void LinearInterpolation(list<Point>& points) {
    int count;
    cout << "Введите колличество аргументов функции(x), для получения при помощи интепроляции, соответствующих им значений" << endl;
    cin >> count;
    
    for (int i=0;i<count;i++)
    {
        double interpolX;
        cout << "Введите значение x точки, чтобы получить приближенное значение y при помощи линейной интерполяции. В пределах "<< (*points.begin()).x << " и "<< (*--points.end()).x << endl;
        cin >> interpolX;

        if ((*points.begin()).x < interpolX && interpolX < (*--points.end()).x)
        {
            for (auto bIter = points.begin(); bIter != points.end(); bIter++)
            {
                if ((*bIter).x > interpolX)
                {
                   cout<< "y: " << (*(prev(bIter))).y + ((*bIter).y - (*(prev(bIter))).y) * ((interpolX - (*(prev(bIter))).x) / ((*bIter).x - (*(prev(bIter))).x)) << endl;
                    break;
                }

            }
        }
        else
        {
            cout << "Введенный x за пределами зоны определения функции"<<endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    list<Point> points;
    DataInput(points);
    LinearInterpolation(points);
    return 0;
}