#include <iostream>
using namespace std;

template <typename T>
class Matrix {

private:
    T** mat;
    int rows;    
    int cols;    

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;

        mat = new T*[rows];
        
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];  

            for (int j = 0; j < cols; j++) {
                mat[i][j] = 0;
            }       
        }
    }

    void set(const T& row, const T& col, const T& value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            mat[row][col] = value;
        }
    }

    T get(const T& row, const T& col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return mat[row][col];
        }
        return -1; 
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] mat[i]; 
        delete[] mat;         
    }
};

void run_matrix() {
    cout << "Matrix\n";

    Matrix<int> m(3, 3); 

    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(0, 2, 3);
    m.set(1, 0, 4);
    m.set(1, 1, 5);
    m.set(1, 2, 6);
    m.set(2, 0, 7);
    m.set(2, 1, 8);
    m.set(2, 2, 9);

    m.display();
}
