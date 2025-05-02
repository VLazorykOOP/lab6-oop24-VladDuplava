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
    friend istream& operator>>(istream& is, Person& p) {
        cout << "Введіть ім'я: ";
        is >> p.name;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Ім'я: " << p.name;
        return os;
    }
};

// Похідний клас Батько
class Father : public Person {
protected:
    string job;
public:
    Father(const string& n = "Невідомо", const string& j = "Невідомо") : Person(n), job(j) {}
    virtual ~Father() {}
    friend istream& operator>>(istream& is, Father& f) {
        is >> (Person&)f;
        cout << "Введіть професію: ";
        is >> f.job;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Father& f) {
        os << (Person&)f << ", Професія: " << f.job;
        return os;
    }
};

// Похідний клас Мати
class Mother : public Person {
protected:
    string hobby;
public:
    Mother(const string& n = "Невідомо", const string& h = "Невідомо") : Person(n), hobby(h) {}
    virtual ~Mother() {}
    friend istream& operator>>(istream& is, Mother& m) {
        is >> (Person&)m;
        cout << "Введіть хобі: ";
        is >> m.hobby;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Mother& m) {
        os << (Person&)m << ", Хобі: " << m.hobby;
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
        : Father(n, j), Mother(n, h), school(s) {}
    virtual ~Daughter() {}
    friend istream& operator>>(istream& is, Daughter& d) {
        cout << "Для Батька:\n";
        is >> (Father&)d;
        cout << "Для Матері:\n";
        is >> (Mother&)d;
        cout << "Введіть школу: ";
        is >> d.school;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Daughter& d) {
        os << "Дочка (з боку Батька): " << (Father&)d << ", (з боку Матері): " << (Mother&)d
           << ", Школа: " << d.school;
        return os;
    }
    void showInfo() const {
        cout << "Інформація про Дочку: Ім'я: " << Father::name << ", Професія: " << job
             << ", Хобі: " << hobby << ", Школа: " << school << endl;
    }
};

int main() {
    Daughter d;
    cout << "Введіть дані про дочку:\n";
    cin >> d;
    cout << d << endl;
    d.showInfo();
    return 0;
}
