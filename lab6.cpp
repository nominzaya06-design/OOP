#include <iostream>
#include <iomanip>   
#include <cmath>     
#include <cstring>  
using namespace std;


// SHAPE: Дүрсийн нэр болон суурь координатыг хадгалах эх класс
class Shape {
protected:
    char name[30];
    float x, y;

public:
    // Дүрсний нэр болон суурь координатыг оноох байгуулагч функц
    Shape(const char* n = "Shape", float x = 0, float y = 0) {
        strcpy(name, n);
        this->x = x;
        this->y = y;
    }

    // Дүрсний нэрийг хэвлэх функц
    void showName() {
        cout << left << setw(15) << "Ner:" << name << endl;
    }
};



// 2DSHAPE: талбай, периметртэй
class TwoDShape : public Shape {
protected:
    float areaValue;
    float perimeterValue;

public:
    // Нэр болон суурь координатыг Shape рүү дамжуулна
    TwoDShape(const char* n = "2DShape", float x = 0, float y = 0) : Shape(n, x, y) {
        areaValue = 0;
        perimeterValue = 0;
    }

    // Талбай, периметрийг хэвлэдэг функц
    void showBasicInfo() {
        cout << left << setw(15) << "Talbai:"   << areaValue << endl;
        cout << left << setw(15) << "Perimetr:" << perimeterValue << endl;
    }
};


