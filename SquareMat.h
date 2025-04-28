#ifndef SQUARE_MAT_H
#define SQUARE_MAT_H

#include <iostream>

namespace mat {

    class SquareMat {
    private:
        int* data;
        int size;

    public:

        SquareMat(int size);
        SquareMat(const SquareMat& other);
        SquareMat& operator=(const SquareMat& other);
        ~SquareMat();
        int& at(int row, int col);
        const int& at(int row, int col) const;
        int getSize() const;
        SquareMat operator+(const SquareMat& other) const;
        SquareMat operator-(const SquareMat& other) const;
        SquareMat operator-() const;
        SquareMat operator*(const SquareMat& other) const;
        SquareMat operator*( int scalar) const;
        SquareMat operator%(const SquareMat& other) const;
        SquareMat operator%(int scalar) const;
        SquareMat operator/(int scalar) const;
        SquareMat operator^(int exponent) const;
        SquareMat& operator++(); // prefix ++
        SquareMat operator++(int); // postfix ++
        SquareMat& operator--(); // prefix --
        SquareMat operator--(int); // postfix --
        SquareMat operator~() const;
        int* operator[](int row);
        const int* operator[](int row) const;
        bool operator==(const SquareMat& other) const;
        bool operator!=(const SquareMat& other) const;
        bool operator<(const SquareMat& other) const;
        bool operator>(const SquareMat& other) const;
        bool operator<=(const SquareMat& other) const;
        bool operator>=(const SquareMat& other) const;
        int operator!() const;
        SquareMat& operator+=(const SquareMat& other);
        SquareMat& operator-=(const SquareMat& other);

        SquareMat& operator*=(const SquareMat& other);
        SquareMat& operator*=(int scalar);
        SquareMat& operator/=(int scalar);
        SquareMat& operator%=(const SquareMat& other);
        SquareMat& operator%=(int scalar);
        void print(std::ostream& os = std::cout) const;


    };
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
} // namespace mat

#endif // SQUARE_MAT_H
