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

// SQUARE: Квадратын зүүн дээд оройг Shape дээрх x, y-д хадгална
// Бусад 3 оройг энд тооцоолж хадгална
class Square : public TwoDShape {
private:
    float x2, y2, x3, y3, x4, y4;
    float side;

    void calcArea() {
        areaValue = side * side;
    }

    void calcPerimeter() {
        perimeterValue = 4 * side;
    }

public:
    // Зүүн дээд орой болон талын уртаас бусад оройг тооцоолж объект үүсгэнэ
    Square(float leftTopX, float leftTopY, float s)
        : TwoDShape("Kvadrat", leftTopX, leftTopY) {
        side = s;

        x2 = x + s;  y2 = y;      // баруун дээд орой
        x3 = x + s;  y3 = y - s;  // баруун доод орой
        x4 = x;      y4 = y - s;  // зүүн доод орой

        calcArea();
        calcPerimeter();
    }
    void show() {
        showName();
        cout << left << setw(15) << "Side:" << side << endl;
        cout << left << setw(15) << "TopLeft:" << "(" << x  << ", " << y  << ")" << endl;
        cout << left << setw(15) << "TopRight:" << "(" << x2 << ", " << y2 << ")" << endl;
        cout << left << setw(15) << "BottomRight:" << "(" << x3 << ", " << y3 << ")" << endl;
        cout << left << setw(15) << "BottomLeft:" << "(" << x4 << ", " << y4 << ")" << endl;
        showBasicInfo();
    }
};

// CIRCLE: Тойргийн төвийн координат нь Shape дээрх x, y-д хадгалагдана
class Circle : public TwoDShape {
private:
    float radius;

    void calcArea() {
        areaValue = 3.14159f * radius * radius;
    }

    void calcPerimeter() {
        perimeterValue = 2 * 3.14159f * radius;
    }
public:
    // Төвийн координат, радиус авч тойрог объект үүсгэнэ
    Circle(float cx, float cy, float r)
        : TwoDShape("Toirog", cx, cy) {
        radius = r;
        calcArea();
        calcPerimeter();
    }
    void show() {
        showName();
        cout << left << setw(15) << "Tuv:" << "(" << x << ", " << y << ")" << endl;
        cout << left << setw(15) << "Radius:" << radius << endl;
        showBasicInfo();
    }
};

// TRIANGLE: Зөв гурвалжны дээд оройг Shape дээрх x, y-д хадгална
// Бусад 2 оройг энд тооцоолж хадгална
class Triangle : public TwoDShape {
private:
    float x2, y2, x3, y3;
    float side;

    void calcArea() {
        areaValue = (sqrt(3.0f) / 4.0f) * side * side;
    }

    void calcPerimeter() {
        perimeterValue = 3 * side;
    }

public:
    // Дээд орой болон талын уртаас бусад 2 оройг тооцоолж объект үүсгэнэ
    Triangle(float topX, float topY, float s)
        : TwoDShape("Zuv gurvaljin", topX, topY) {
        side = s;

        // Зөв гурвалжны өндрийг олж байна
        float h = (sqrt(3.0f) / 2.0f) * s;

        // (x, y) нь дээд орой
        x2 = x - s / 2;  y2 = y - h;   // зүүн доод орой
        x3 = x + s / 2;  y3 = y - h;  // баруун доод орой
        calcArea();
        calcPerimeter();
    }
    void show() {
        showName();
        cout << left << setw(15) << "Side:" << side << endl;
        cout << left << setw(15) << "Top:" << "(" << x  << ", " << y  << ")" << endl;
        cout << left << setw(15) << "Left:" << "(" << x2 << ", " << y2 << ")" << endl;
        cout << left << setw(15) << "Right:" << "(" << x3 << ", " << y3 << ")" << endl;
        showBasicInfo();
    }
};
  

int main() {
    Circle c(2, 3, 5);
    Square s(0, 4, 4);
    Triangle t(0, 6, 6);
    

    cout <<"Circle"<< endl;
    c.show();
    cout <<"Square"<< endl;
    s.show();
    cout <<"Triangle"<< endl;
    t.show();

    return 0;
}

