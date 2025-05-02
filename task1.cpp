#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;


class Base {
protected:
    int baseData;
public:
    Base(int data = 0) : baseData(data) {}
    virtual ~Base() {}
};


class D1 : virtual public Base {
protected:
    int derived1Data;
public:
    D1(int bData = 0, int d1Data = 0) : Base(bData), derived1Data(d1Data) {}
};

class D2 : virtual public Base {
protected:
    int derived2Data;
public:
    D2(int bData = 0, int d2Data = 0) : Base(bData), derived2Data(d2Data) {}
};

class D3 : virtual public Base {
protected:
    int derived3Data;
public:
    D3(int bData = 0, int d3Data = 0) : Base(bData), derived3Data(d3Data) {}
};

class D4 : virtual public Base {
protected:
    int derived4Data;
public:
    D4(int bData = 0, int d4Data = 0) : Base(bData), derived4Data(d4Data) {}
};


class NonVirtualDerived1 : public Base {
protected:
    int derived1Data;
public:
    NonVirtualDerived1(int bData = 0, int d1Data = 0) : Base(bData), derived1Data(d1Data) {}
};

class NonVirtualDerived2 : public Base {
protected:
    int derived2Data;
public:
    NonVirtualDerived2(int bData = 0, int d2Data = 0) : Base(bData), derived2Data(d2Data) {}
};

class NonVirtualDerived3 : public Base {
protected:
    int derived3Data;
public:
    NonVirtualDerived3(int bData = 0, int d3Data = 0) : Base(bData), derived3Data(d3Data) {}
};

class NonVirtualDerived4 : public Base {
protected:
    int derived4Data;
public:
    NonVirtualDerived4(int bData = 0, int d4Data = 0) : Base(bData), derived4Data(d4Data) {}
};


int getKeyboardInput() {
    int data;
    cout << "Enter data: ";
    cin >> data;
    return data;
}

// получення з файлу
int getFileInput() {
    ifstream file("input.txt");
    int data;
    if (file >> data) {
        return data;
    }
    return 0;
}

//рандомне введеня
int getRandomInput() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    return dis(gen);
}

int main() {
    // Віртуальні обєкти
    D1 d1v(getKeyboardInput(), getKeyboardInput());
    D2 d2v(getFileInput(), getFileInput());
    D3 d3v(getRandomInput(), getRandomInput());
    D4 d4v(getRandomInput(), getRandomInput());

    // Невіртуальні обєкти
    NonVirtualDerived1 d1nv(getKeyboardInput(), getKeyboardInput());
    NonVirtualDerived2 d2nv(getFileInput(), getFileInput());
    NonVirtualDerived3 d3nv(getRandomInput(), getRandomInput());
    NonVirtualDerived4 d4nv(getRandomInput(), getRandomInput());

    cout << "Size of Derived1 (virtual): " << sizeof(d1v) << " bytes\n";
    cout << "Size of Derived2 (virtual): " << sizeof(d2v) << " bytes\n";
    cout << "Size of Derived3 (virtual): " << sizeof(d3v) << " bytes\n";
    cout << "Size of Derived4 (virtual): " << sizeof(d4v) << " bytes\n";
    cout << "Size of NonVirtualDerived1: " << sizeof(d1nv) << " bytes\n";
    cout << "Size of NonVirtualDerived2: " << sizeof(d2nv) << " bytes\n";
    cout << "Size of NonVirtualDerived3: " << sizeof(d3nv) << " bytes\n";
    cout << "Size of NonVirtualDerived4: " << sizeof(d4nv) << " bytes\n";

    return 0;
}
