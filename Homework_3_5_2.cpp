#include <iostream>
#include <string>

class Figure {
public:
    Figure() {};
    virtual std::string getSides() {
        return "";
    };
    virtual std::string getAngles() {
        return "";
    };    
    std::string getName() {
        return name;
    };

protected:
    std::string name;
};

class Triangle : public Figure {
public:
    Triangle( int a, int b, int c, int A, int B ) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = 180 - A - B;
        name = "Треугольник";
    };
    std::string getSides() override{  
        return "a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c);
    };
    std::string getAngles() override{
        return "A = " + std::to_string(A) + ", B = " + std::to_string(B) + ", C = " + std::to_string(C);
    };
protected:
    int A, B, C;
    double a, b, c;
};

class Quadrangle : public Figure {
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C ) { 
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = 360 - A - B - C;
        name = "Четырехугольник";
    };
    std::string getSides() override {
        return "a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", c = " + std::to_string(c) + ", d = " + std::to_string(d);
    };
    std::string getAngles() override {
        return "A = " + std::to_string(A) + ", B = " + std::to_string(B) + ", C = " + std::to_string(C) + ", D = " + std::to_string(D);
    };
protected:
    int A, B, C, D;
    double a, b, c, d;
};

class RightTriangle : public Triangle {
public: 
    RightTriangle( int a, int b, int c, int A) : Triangle( a, b, c, A, 90) { 
        name = "Прямоугольный треугольник";
    };
};

class IsoscelesTriangle : public Triangle {
public: 
    IsoscelesTriangle( int a, int c, int A ) : Triangle( a, a, c, A, A) {
        name = "Равнобедренный треугольник"; 
    };
};    

class EquilateralTriangle : public IsoscelesTriangle {
public: 
    EquilateralTriangle( int a ) : IsoscelesTriangle( a, a, 60 ) { 
        name = "Равносторонний треугольник";
    };
};    

class Parallelogram : public Quadrangle {
public: 
    Parallelogram( int a, int b, int A ) : Quadrangle( a, b, a , b, A, 180 - A, A) {
        name = "Параллелограм";
    };
};    

class Rectangle : public Parallelogram {
public: 
    Rectangle( int a, int b ) : Parallelogram( a, b, 90 ) {
        name = "Прямоугольник";
    };
};   

class Rhomb : public Parallelogram {
public: 
    Rhomb( int a, int A ) : Parallelogram( a, a, A ) {
        name = "Ромб";
    };
};   

class Square : public Rhomb {
public: 
    Square( int a ) : Rhomb( a, 90 ) {
        name = "Квадрат";
    };
};   

void printFigureInfo(Figure* fig) {
    std::cout << fig->getName() << " : " << std::endl;
    std::cout << "Стороны : " << fig->getSides() << std::endl;
    std::cout << "Углы : " << fig->getAngles() << std::endl << std::endl;     
};

int main()
{

    setlocale(LC_ALL, "Russian");

    Triangle triangle(10, 20, 30, 50, 60);
    printFigureInfo(&triangle);

    RightTriangle rightTriangle(10,20,30,50);
    printFigureInfo(&rightTriangle);

    IsoscelesTriangle isoscelesTriangle(10,20,50);
    printFigureInfo(&isoscelesTriangle);

    EquilateralTriangle equilateralTriangle(30);
    printFigureInfo(&equilateralTriangle);

    Quadrangle quadrangle(10,20,30,40,80,110,70);
    printFigureInfo(&quadrangle);

    Parallelogram parallelogram(20, 30, 120);
    printFigureInfo(&parallelogram);

    Rectangle rectangle(10,20);
    printFigureInfo(&rectangle);

    Rhomb rhomb(10,40);
    printFigureInfo(&rhomb);

    Square square(30);
    printFigureInfo(&square);

}
