#include <iostream>
#include <cmath>
using namespace std;

const double Epsilon_0 = 8.854e-12;   // Permittivity of free space
const double Mu_0 = 4 * M_PI * 1e-7;  // Permeability of free space

class Field {
protected:
    double value;

public:
    Field() : value(0.0) {}
    Field(double v) : value(v) {}

    virtual ~Field() {}

    virtual void printMagnitude() const {
        cout << "Field magnitude: " << value << endl;
    }

    friend ostream& operator<<(ostream& os, const Field& f) {
        os << "Field magnitude: " << f.value;
        return os;
    }
};

class Electric_Field : public Field {
private:
    double Q;
    double R;

public:
    Electric_Field() : Field(), Q(0.0), R(1.0) {}
    Electric_Field(double charge, double radius) : Field(), Q(charge), R(radius) {
        value = Q / (4 * M_PI * Epsilon_0 * R * R);
    }

    void printMagnitude() const override {
        cout << "Electric Field magnitude: " << value << " N/C" << endl;
    }

    Electric_Field operator+(const Electric_Field& other) const {
        Electric_Field result;
        result.value = this->value + other.value;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Electric_Field& ef) {
        os << "Electric Field magnitude: " << ef.value << " N/C";
        return os;
    }
};

class Magnetic_Field : public Field {
private:
    double I;
    double R;

public:
    Magnetic_Field() : Field(), I(0.0), R(1.0) {}
    Magnetic_Field(double current, double radius) : Field(), I(current), R(radius) {
        value = (Mu_0 * I) / (2 * M_PI * R);
    }

    void printMagnitude() const override {
        cout << "Magnetic Field magnitude: " << value << " T" << endl;
    }

    Magnetic_Field operator+(const Magnetic_Field& other) const {
        Magnetic_Field result;
        result.value = this->value + other.value;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Magnetic_Field& mf) {
        os << "Magnetic Field magnitude: " << mf.value << " T";
        return os;
    }
};

int main() {
    Electric_Field ef1(5.0, 0.1);
    Electric_Field ef2(10.0, 0.1);
    Electric_Field ef3 = ef1 + ef2;

    ef1.printMagnitude();
    ef2.printMagnitude();
    ef3.printMagnitude();

    cout << ef1 << endl;
    cout << ef2 << endl;
    cout << ef3 << endl;

    Magnetic_Field mf1(2.0, 0.1);
    Magnetic_Field mf2(3.0, 0.1);
    Magnetic_Field mf3 = mf1 + mf2;

    mf1.printMagnitude();
    mf2.printMagnitude();
    mf3.printMagnitude();

    cout << mf1 << endl;
    cout << mf2 << endl;
    cout << mf3 << endl;

    return 0;
}
