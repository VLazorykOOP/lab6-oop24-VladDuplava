#include <iostream>
#include <cmath>

using namespace std;

// Абстрактний базовий клас
class DataSet {
public:
    virtual double norm() const = 0; // Чисто віртуальна функція
    virtual ~DataSet() {}
};

// Комплексне число
class ComplexNumber : public DataSet {
private:
    double real, imag;
public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    double norm() const override {
        return real * real + imag * imag; // Квадрат модуля
    }
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

// Вектор з 3 елементів
class Vector : public DataSet {
private:
    double elements[3];
public:
    Vector(double e1 = 0.0, double e2 = 0.0, double e3 = 0.0) {
        elements[0] = e1;
        elements[1] = e2;
        elements[2] = e3;
    }
    double norm() const override {
        double sum = 0.0;
        for (int i = 0; i < 3; i++) {
            sum += elements[i] * elements[i];
        }
        return sqrt(sum); // Корінь із суми квадратів
    }
    double getElement(int i) const { return elements[i]; }
};

// Матриця 2x2
class Matrix : public DataSet {
private:
    double elements[2][2];
public:
    Matrix(double e11 = 0.0, double e12 = 0.0, double e21 = 0.0, double e22 = 0.0) {
        elements[0][0] = e11; elements[0][1] = e12;
        elements[1][0] = e21; elements[1][1] = e22;
    }
    double norm() const override {
        double sum = 0.0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                sum += elements[i][j] * elements[i][j];
            }
        }
        return sqrt(sum); // Корінь із суми квадратів елементів
    }
    double getElement(int i, int j) const { return elements[i][j]; }
};

int main2() {
    ComplexNumber c(3.0, 4.0); // 3 + 4i
    Vector v(1.0, 2.0, 2.0); // [1, 2, 2]
    Matrix m(1.0, 2.0, 3.0, 4.0); // [[1, 2], [3, 4]]

    cout << "Complex Number: " << c.getReal() << " + " << c.getImag() << "i, Norm: " << c.norm() << endl;
    cout << "Vector: [" << v.getElement(0) << ", " << v.getElement(1) << ", " << v.getElement(2) << "], Norm: " << v.norm() << endl;
    cout << "Matrix: [[" << m.getElement(0, 0) << ", " << m.getElement(0, 1) << "], ["
         << m.getElement(1, 0) << ", " << m.getElement(1, 1) << "]], Norm: " << m.norm() << endl;

    return 0;
}
