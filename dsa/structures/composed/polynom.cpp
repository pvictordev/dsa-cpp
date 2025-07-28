#include <iostream>
#include <vector>
using namespace std;

class Polynomial {
private:
    vector<int> coefficients;  // Coeficientii polinomului

public:
    // Constructor care primește coeficientii pentru polinom
    Polynomial(int degree) {
        coefficients.resize(degree + 1, 0);  // Alocăm coeficienți pentru fiecare grad
    }

    // Setează coeficientul pentru un anumit grad
    void setCoefficient(int degree, int coeff) {
        if (degree >= 0 && degree < coefficients.size()) {
            coefficients[degree] = coeff;
        }
    }

    // Adaugă un alt polinom
    Polynomial add(const Polynomial& other) {
        int maxDegree = max(coefficients.size(), other.coefficients.size());
        Polynomial result(maxDegree - 1);

        for (int i = 0; i < maxDegree; i++) {
            int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result.setCoefficient(i, coeff1 + coeff2);
        }

        return result;
    }

    // Înmulțește două polinoame
    Polynomial multiply(const Polynomial& other) {
        int newDegree = coefficients.size() + other.coefficients.size() - 2;
        Polynomial result(newDegree);

        for (int i = 0; i < coefficients.size(); i++) {
            for (int j = 0; j < other.coefficients.size(); j++) {
                result.setCoefficient(i + j, result.getCoefficient(i + j) + coefficients[i] * other.coefficients[j]);
            }
        }

        return result;
    }

    // Returnează coeficientul unui anumit grad
    int getCoefficient(int degree) const {
        if (degree >= 0 && degree < coefficients.size()) {
            return coefficients[degree];
        }
        return 0;  // Dacă gradul este mai mare decât dimensiunea vectorului, coeficientul este 0
    }

    // Afișează polinomul
    void print() {
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            if (coefficients[i] != 0) {
                cout << coefficients[i] << "x^" << i;
                if (i > 0) cout << " + ";
            }
        }
        cout << endl;
    }
};

void run_polynom() {
    cout << "\nPolynom \n";

    Polynomial p1(2);  // Polinom de gradul 2: 2x^2 + 3x + 5
    p1.setCoefficient(2, 2);
    p1.setCoefficient(1, 3);
    p1.setCoefficient(0, 5);
    
    cout << "Polinom 1: ";
    p1.print();

    Polynomial p2(1);  // Polinom de gradul 1: 3x + 2
    p2.setCoefficient(1, 3);
    p2.setCoefficient(0, 2);

    cout << "Polinom 2: ";
    p2.print();

    Polynomial p3 = p1.add(p2);
    cout << "Adunarea celor doua polinoame: ";
    p3.print();

    Polynomial p4 = p1.multiply(p2);
    cout << "Inmultirea celor doua polinoame: ";
    p4.print();
}
