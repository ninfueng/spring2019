#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cstring>

// same idea as typedef
using uint = unsigned int;


// TODO: template this class with a type T.
// What do we need to change in the method signature or members?
template<typename T>
class DenseMatrix
{
public:
    DenseMatrix(uint rows, uint cols) {
        this->n_rows = rows;
        this->n_cols = cols;
        this->elements = new T[this->n_rows * this->n_cols];
    }

    ~DenseMatrix() {
        if (this->elements) {
            delete[] this->elements;
            this->elements = nullptr;
        }
    }

    DenseMatrix(const DenseMatrix<T>& dm)
    {
        this->n_rows = dm.n_rows;
        this->n_cols = dm.n_cols;
        this->elements = new T[this->n_rows * this->n_cols];
        std::memcpy(this->elements, dm.elements, this->n_rows * this->n_cols * sizeof(T));
    }

    DenseMatrix operator +(const DenseMatrix& dm) {
        // TODO: check if n_rows and n_cols match dm.n_rows and dm.n_cols. 
        // if not same, throw std::invalid_argument
        if(this->n_rows == dm.n_rows && this->n_cols == dm.n_cols) {
            ;
        } else {
            throw std::invalid_argument("Must match between n_rows and n_cols");
        }
        // TODO: create a new DenseMatrix<T> with same dimensions
        // implement the addition with a loop.
        DenseMatrix<T>* res = new DenseMatrix<T> (dm.n_rows, dm.n_cols);
        for(int i = 0; i < dm.n_rows; ++i) {
            for(int j = 0; j < dm.n_cols; ++j) {
                res->elements[i + j*dm.n_rows] = this->elements[i + j*this->n_rows] + dm.elements[i + j*dm.n_rows];
            }
        }
        return *res;
    }

    const T& operator ()(uint row, uint col) const {
        // TODO: check if row < n_rows and cols < n_cols
        // if not throw std::out_of_range

        // TODO: return const reference to element
        // hint: you do not have to do anything special
        
        if(row > this->n_rows &&  col > this->n_cols) {
            throw std::out_of_range("");
        }
        return this->elements[row + this->n_rows*col];
    }

    T& operator ()(uint row, uint col) {
        // TODO: check if row < n_rows and cols < n_cols
        // if not throw std::out_of_range
        if(row > this->n_rows &&  col > this->n_cols) {
            throw std::out_of_range("");
        }

        // TODO: return mutable reference to element
        // hint: you do not have to do anything special
        return this->elements[row + this->n_rows*col];
    }

    /**
     * TODO: Implement the output stream operator.
     * Note that it is declared a "friend" function. 
     * This allows us to call private methods if necessary. 
     * Is there a private method that could be helpful?
     */
    //template <typename U>
    friend std::ostream& operator <<(std::ostream& stream, DenseMatrix dm) {
        //std::cout << dm.elements[] << std::endl;
        for(int i = 0; i < dm.n_rows; ++i) {
            for(int j = 0; j < dm.n_cols; ++j) {
                std::cout  << i << "|" << j << "|" << "=" <<  dm.elements[i + j*dm.n_rows] << std::endl;
            }
        }
        return stream;
    }

private:
    uint n_rows;
    uint n_cols;
    int *elements;

    void print(std::ostream& stream)
    {
        for (uint i = 0; i < this->n_rows; i++) {
            for (uint j = 0; j < this->n_cols; j++) {
                // TODO: print out element (i, j). 
                stream << "[placeholder]" << "";
            }
            stream << std::endl;
        }   
    }
};


int main()
{
    DenseMatrix<int> a(2, 3);
    DenseMatrix<int> b(2, 3);

    // set some numbers
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            a(i, j) = i + j;
            b(i, j) = 1;
        }
    }
         
    // add them
    DenseMatrix<int> c = a + b;
    std::cout << "A: " << std::endl;
    std::cout << a << std::endl;
    std::cout << "B: " << std::endl << b << std::endl;
    std::cout << "C = A + B:" << std::endl << c << std::endl;
    return 0;
}
