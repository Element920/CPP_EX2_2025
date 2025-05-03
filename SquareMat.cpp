//israelmor555@gmail.com
#include "SquareMat.h"
#include <stdexcept>

namespace mat {
    SquareMat::SquareMat(int size) : size(size) {
        data = new int[size * size]{0};
    }

    SquareMat::SquareMat(const SquareMat& other) : size(other.size) {
        data = new int[size * size];
        for (int i = 0; i < size * size; ++i)
            data[i] = other.data[i];
    }

    SquareMat& SquareMat::operator=(const SquareMat& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size * size];
            for (int i = 0; i < size * size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    SquareMat::~SquareMat() {
        delete[] data;
    }

    int& SquareMat::at(int row, int col) {
        if (row < 0 || row >= size || col < 0 || col >= size)
            throw std::out_of_range("Index out of range");
        return data[row * size + col];
    }

    const int& SquareMat::at(int row, int col) const {
        if (row < 0 || row >= size || col < 0 || col >= size)
            throw std::out_of_range("Index out of range");
        return data[row * size + col];
    }

    int SquareMat::getSize() const {
        return size;
    }

    SquareMat SquareMat::operator+(const SquareMat& other) const {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match");
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
            result.data[i] = this->data[i] + other.data[i];
        return result;
    }



    SquareMat SquareMat::operator*(const SquareMat& other) const {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match");
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k)
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
        return result;
    }


    void SquareMat::print(std::ostream& os) const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                os << at(i, j) << " ";
            os << "\n";
        }
    }


    SquareMat SquareMat::operator-(const SquareMat& other) const {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match");
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
            result.data[i] = this->data[i] - other.data[i];
        return result;
    }

    SquareMat SquareMat::operator-() const {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i)
            result.data[i] = this->data[i]*(-1);
        return result;
    }

    SquareMat SquareMat::operator*(const int scalar) const {
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i) {
            result.data[i] = this->data[i] * scalar;
        }
        return result;
    }


    SquareMat SquareMat::operator%(const SquareMat& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Matrix sizes do not match for element-wise multiplication");
        }
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i) {
            result.data[i] = this->data[i] * other.data[i];
        }
        return result;
    }

    SquareMat SquareMat::operator%(int scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Modulo by zero");
        }
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i) {
            result.data[i] = this->data[i] % scalar;
        }
        return result;
    }
    SquareMat SquareMat::operator/(int scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }
        SquareMat result(size);
        for (int i = 0; i < size * size; ++i) {
            result.data[i] = this->data[i] / scalar;
        }
        return result;
    }
    SquareMat SquareMat::operator^(int exponent) const {
        if (size == 0) {
            throw std::invalid_argument("Empty matrix");
        }
        if (exponent < 0) {
            throw std::invalid_argument("Negative exponent not supported");
        }
        SquareMat result(size);


        for (int i = 0; i < size; ++i) {
            result.at(i, i) = 1;
        }

        SquareMat base = *this;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            exponent /= 2;
        }
        return result;
    }
    SquareMat& SquareMat::operator++() {
        for (int i = 0; i < size * size; ++i) {
            ++data[i];
        }
        return *this;
    }
    SquareMat SquareMat::operator++(int) {
        SquareMat temp = *this;
        ++(*this);
        return temp;
    }
    SquareMat& SquareMat::operator--() {
        for (int i = 0; i < size * size; ++i) {
            --data[i];
        }
        return *this;
    }
    SquareMat SquareMat::operator--(int) {
        SquareMat temp = *this;
        --(*this);
        return temp;
    }
    // טרנספוזיציה
    SquareMat SquareMat::operator~() const {
        SquareMat result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.at(i, j) = this->at(j, i);
            }
        }
        return result;
    }

    // גישה בסוגריים מרובעים
    int* SquareMat::operator[](int row) {
        return &data[row * size];
    }
    const int* SquareMat::operator[](int row) const {
        return &data[row * size];
    }


    bool SquareMat::operator==(const SquareMat& other) const {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size * size; ++i) {
            sum1 += data[i];
            sum2 += other.data[i];
        }
        return sum1 == sum2;
    }
    bool SquareMat::operator!=(const SquareMat& other) const {
        return !(*this == other);
    }

    // השוואות סדר
    bool SquareMat::operator<(const SquareMat& other) const {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size * size; ++i) {
            sum1 += data[i];
            sum2 += other.data[i];
        }
        return sum1 < sum2;
    }
    bool SquareMat::operator>(const SquareMat& other) const {
        return other < *this;
    }
    bool SquareMat::operator<=(const SquareMat& other) const {
        return !(other < *this);
    }
    bool SquareMat::operator>=(const SquareMat& other) const {
        return !(*this < other);
    }


    int SquareMat::operator!() const {
        if (size == 1)
            return data[0];

        if (size == 2)
            return data[0] * data[3] - data[1] * data[2];

        int determinant = 0;
        for (int col = 0; col < size; ++col) {
            SquareMat sub(size - 1);
            for (int i = 1; i < size; ++i) {
                int sub_col = 0;
                for (int j = 0; j < size; ++j) {
                    if (j == col) continue;
                    sub.at(i - 1, sub_col) = at(i, j);
                    sub_col++;
                }
            }
            int sign = (col % 2 == 0) ? 1 : -1;
            determinant += sign * at(0, col) * !sub;
        }
        return determinant;
    }


    SquareMat& SquareMat::operator+=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match");
        for (int i = 0; i < size * size; ++i) {
            data[i] += other.data[i];
        }
        return *this;
    }

    SquareMat& SquareMat::operator-=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match");
        for (int i = 0; i < size * size; ++i) {
            data[i] -= other.data[i];
        }
        return *this;
    }

    SquareMat& SquareMat::operator*=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match");

        int* newData = new int[size * size](); // אפס את המטריצה החדשה

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    newData[i * size + j] += at(i, k) * other.at(k, j);
                }
            }
        }

        delete[] data;
        data = newData;
        return *this;
    }

    SquareMat& SquareMat::operator*=(int scalar) {
        for (int i = 0; i < size * size; ++i) {
            data[i] *= scalar;
        }
        return *this;
    }

    SquareMat& SquareMat::operator/=(int scalar) {
        if (scalar == 0)
            throw std::invalid_argument("Division by zero");

        for (int i = 0; i < size * size; ++i) {
            data[i] /= scalar;
        }
        return *this;
    }

    SquareMat& SquareMat::operator%=(int scalar) {
        if (scalar == 0)
            throw std::invalid_argument("Modulo by zero");

        for (int i = 0; i < size * size; ++i) {
            data[i] %= scalar;
        }
        return *this;
    }

    SquareMat& SquareMat::operator%=(const SquareMat& other) {
        if (size != other.size)
            throw std::invalid_argument("Matrix sizes do not match");

        for (int i = 0; i < size * size; ++i) {
            if (other.data[i] == 0)
                throw std::invalid_argument("Modulo by zero element");
            data[i] %= other.data[i];
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        mat.print(os);
        return os;
}

}
