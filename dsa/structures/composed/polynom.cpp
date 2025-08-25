#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

class Polynomial {
private:
    vector<int> coefficients;  

    void normalize() {
        while (!coefficients.empty() && coefficients.back() == 0)
            coefficients.pop_back();
    }

public:
    Polynomial(int degree = -1) {
        if (degree >= 0) coefficients.resize(degree + 1, 0);
    }

    int degree() const {
        for (int i = (int)coefficients.size() - 1; i >= 0; --i)
            if (coefficients[i] != 0) return i;
        return -1;
    }

    void setCoefficient(int degree, int coeff) {
        if (degree < 0) return;
        if (degree >= (int)coefficients.size())
            coefficients.resize(degree + 1, 0);   
        coefficients[degree] = coeff;
        normalize();
    }

    int getCoefficient(int degree) const {
        if (degree >= 0 && degree < (int)coefficients.size())
            return coefficients[degree];
        return 0;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = (int)max(coefficients.size(), other.coefficients.size());
        Polynomial result(maxDegree - 1);

        for (int i = 0; i < maxDegree; i++) {
            int coeff1 = (i < (int)coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < (int)other.coefficients.size()) ? other.coefficients[i] : 0;
            result.setCoefficient(i, coeff1 + coeff2);
        }
        result.normalize();
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        if (degree() == -1 || other.degree() == -1) return Polynomial(); // 0
        int newDegree = degree() + other.degree();
        Polynomial result(newDegree);

        for (int i = 0; i <= degree(); i++) {
            for (int j = 0; j <= other.degree(); j++) {
                int cur = result.getCoefficient(i + j);
                result.setCoefficient(i + j, cur + getCoefficient(i) * other.getCoefficient(j));
            }
        }
        result.normalize();
        return result;
    }


    pair<Polynomial, Polynomial> divide(const Polynomial& divisor) const {
        int dQ = divisor.degree();
        if (dQ == -1) throw runtime_error("Impartire la polinomul zero!");

        Polynomial R = *this;           
        Polynomial Q;                   

        int lcQ = divisor.getCoefficient(dQ); 
        if (lcQ == 0) throw runtime_error("Divizor invalid.");

        // câtul are cel mult gradul difference
        int maxQdeg = max(0, R.degree() - dQ);
        Q.coefficients.assign(maxQdeg + 1, 0);

        while (R.degree() >= dQ && R.degree() != -1) {
            int dR  = R.degree();
            int lcR = R.getCoefficient(dR);

            int c = lcR / lcQ;
            int k = dR - dQ; 

            // Q += c * x^k
            int qOld = Q.getCoefficient(k);
            Q.setCoefficient(k, qOld + c);

            // R -= (c * x^k) * divisor
            for (int i = 0; i <= dQ; ++i) {
                int pos = i + k;
                int newVal = R.getCoefficient(pos) - c * divisor.getCoefficient(i);
                R.setCoefficient(pos, newVal);
            }
            R.normalize();
        }

        Q.normalize();
        return {Q, R};
    }

    static Polynomial getDiv(const Polynomial& P, const Polynomial& q) {
        auto res = P.divide(q);
        return res.first; // câtul
    }


    void print() const {
        if (degree() == -1) { cout << "0\n"; return; }

        bool first = true;
        for (int i = degree(); i >= 0; --i) {
            int c = getCoefficient(i);
            if (c == 0) continue;

            if (!first) cout << (c >= 0 ? " + " : " - ");
            else if (c < 0) cout << "-";

            int absC = std::abs(c);
            if (!(i > 0 && absC == 1)) cout << absC; 
            if (i >= 1) {
                cout << "x";
                if (i >= 2) cout << "^" << i;
            }
            first = false;
        }
        cout << "\n";
    }
};

void run_polynom() {
    cout << "\nPolynom \n";

    Polynomial p1(2);  // 2x^2 + 3x + 5
    p1.setCoefficient(2, 2);
    p1.setCoefficient(1, 3);
    p1.setCoefficient(0, 5);

    cout << "Polynom 1: ";
    p1.print();

    Polynomial p2(1);  // 3x + 2
    p2.setCoefficient(1, 3);
    p2.setCoefficient(0, 2);

    cout << "Polynom 2: ";
    p2.print();

    Polynomial p3 = p1.add(p2);
    cout << "Sum 2 polynoms: ";
    p3.print();

    Polynomial p4 = p1.multiply(p2);
    cout << "Multiply 2 polynoms: ";
    p4.print();

    auto [cat, rest] = p4.divide(p2);
    cout << "Divide (p1 * p2) by p2: cat = ";
    cat.print();
    cout << "Rest = ";
    rest.print();

    Polynomial qOnly = Polynomial::getDiv(p4, p2);
    cout << "getDiv(p4, p2) = ";
    qOnly.print();
}
