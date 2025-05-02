#include <iostream>
#include <string>

using namespace std;

// Базовий клас Людина
class Person {
protected:
    string name;
public:
    Person(const string& n = "Невідомо") : name(n) {}
    virtual ~Person() {}

    virtual istream& input(istream& is) {
        cout << "Введіть ім'я: ";
        is >> name;
        return is;
    }

    virtual ostream& output(ostream& os) const {
        os << "Ім'я: " << name;
        return os;
    }
};

// Похідний клас Батько
class Father : virtual public Person {
protected:
    string job;
public:
    Father(const string& n = "Невідомо", const string& j = "Невідомо") : Person(n), job(j) {}
    virtual ~Father() {}

    istream& input(istream& is) override {
        Person::input(is);
        cout << "Введіть професію: ";
        is >> job;
        return is;
    }

    ostream& output(ostream& os) const override {
        Person::output(os);
        os << ", Професія: " << job;
        return os;
    }
};

// Похідний клас Мати
class Mother : virtual public Person {
protected:
    string hobby;
public:
    Mother(const string& n = "Невідомо", const string& h = "Невідомо") : Person(n), hobby(h) {}
    virtual ~Mother() {}

    istream& input(istream& is) override {
        Person::input(is);
        cout << "Введіть хобі: ";
        is >> hobby;
        return is;
    }

    ostream& output(ostream& os) const override {
        Person::output(os);
        os << ", Хобі: " << hobby;
        return os;
    }
};

// Похідний клас Дочка з множинним успадкуванням
class Daughter : public Father, public Mother {
private:
    string school;
public:
    Daughter(const string& n = "Невідомо", const string& j = "Невідомо",
             const string& h = "Невідомо", const string& s = "Невідомо")
        : Person(n), Father(n, j), Mother(n, h), school(s) {}
    virtual ~Daughter() {}

    istream& input(istream& is) override {
        cout << "Для Батька:\n";
        Father::input(is);
        cout << "Для Матері:\n";
        Mother::input(is);
        cout << "Введіть школу: ";
        is >> school;
        return is;
    }

    ostream& output(ostream& os) const override {
        os << "Дочка (з боку Батька): ";
        Father::output(os);
        os << ", (з боку Матері): ";
        Mother::output(os);
        os << ", Школа: " << school;
        return os;
    }

    void showInfo() const {
        cout << "Інформація про Дочку: Ім'я: " << name << ", Професія: " << job
             << ", Хобі: " << hobby << ", Школа: " << school << endl;
    }
};

// Перевантаження операторів для зручності
istream& operator>>(istream& is, Person& p) {
    return p.input(is);
}

ostream& operator<<(ostream& os, const Person& p) {
    return p.output(os);
}

int main() {
    Daughter d;
    cout << "Введіть дані про дочку:\n";
    cin >> d;
    cout << d << endl;
    d.showInfo();
    return 0;
}
