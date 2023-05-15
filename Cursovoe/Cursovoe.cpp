#include <iostream>
#include <list>

using namespace std;

struct Point
{
    double x;
    double y;
};

void DataInput(list<Point>& points)
{
    for (;;)
    {
        unsigned int count;
        cout << "Введите колличество точке, которыми вы зададите функцию" << endl;
        cin >> count;
        cout << endl;
        if (count >= 2)
        {
            for (int i = 0; i < count; i++)
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
                        cout << "Точка с такой координатой x существует" << endl;
                        i--;
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
            cout << endl;
            for (auto bIter = points.begin(); bIter != points.end(); bIter++)
            {
                cout << "Точка " << "x: " << (*bIter).x << " y: " << (*bIter).y << endl;
            }
            break;
        }
        else
        {
            cout << "Нужно хотябы 2 опорные точки" << endl;
        }
    }
}

void LinearInterpolation(list<Point>& points) {
    unsigned int count;
    cout << "Введите колличество аргументов функции(x), для получения при помощи интепроляции, соответствующих им значений" << endl;
    cin >> count;
    cout << endl;
    if (count >= 1)
    {
        for (int i = 0; i < count; i++)
        {
            double interpolX;
            cout << "Введите значение x точки, чтобы получить приближенное значение y при помощи линейной интерполяции. В пределах " << (*points.begin()).x << " и " << (*--points.end()).x << endl;
            cin >> interpolX;
            cout << endl;
            //*** Проверка входит ли аргумент в область определения
            if ((*points.begin()).x <= interpolX && interpolX <= (*--points.end()).x)
            {
                //*** Перебор списка для поиска опрных точке
                for (auto bIter = points.begin(); bIter != points.end(); bIter++)
                {
                    //*** Если ограничивающие точки найдены, то вычислить значение по средством интерполяции
                    if ((*bIter).x > interpolX)
                    {
                        cout << "y: " << (*(prev(bIter))).y + ((*bIter).y - (*(prev(bIter))).y) * ((interpolX - (*(prev(bIter))).x) / ((*bIter).x - (*(prev(bIter))).x)) << endl;
                        break;
                    }
                    //***
                }
                //*** 
            }
            else
            {
                cout << "Введенный x за пределами зоны определения функции" << endl;
                i--;
            }
            //***
        }
    }
    else
    {
        cout << "Нужен хотя бы 1 аргумент." << endl;
    }
}

int main() {
    try {
        setlocale(LC_ALL, "Rus");
        list<Point> points;
        DataInput(points);
        LinearInterpolation(points);
        return 0;
    }
    catch (exception a)
    {
        cout << "Во время выполнения программы произошла ошибка, вероятно она связана с тем, что некоторые данные не соотстветстовали необходимому формату" << endl;
        return 1;
    }
}