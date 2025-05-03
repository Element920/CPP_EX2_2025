//israelmor555@gmail.com
//
// Created by israel on 4/21/25.
//
#include "SquareMat.h"
#include "iostream"

    int main() {

        mat:: SquareMat A(3), B(3);
        mat::SquareMat C = A + B;
        mat::SquareMat D = A * B;

        std::cout << "Matrix A:\n" << A;
        std::cout << "Matrix B:\n" << B;
        std::cout << "A + B:\n" << C;
        std::cout << "A * B:\n" << D;



        return 0;
    }
