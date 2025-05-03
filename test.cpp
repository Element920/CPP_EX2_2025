//israelmor555@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.h"
#include <iostream>
namespace mat {
    TEST_CASE("Matrix Construction and Access") {
        mat::SquareMat mat(3);

        CHECK(mat.at(0, 0) == 0);
        CHECK(mat.at(1, 1) == 0);

        mat.at(0, 0) = 7;
        mat.at(2, 2) = 9;

        CHECK(mat.at(0, 0) == 7);
        CHECK(mat.at(2, 2) == 9);

        std::cout << "Construction and Access:\n" << mat << "\n";
    }

    TEST_CASE("Matrix Addition") {
        mat::SquareMat a(2), b(2);
        a.at(0, 0) = 1; a.at(1, 1) = 2;
        b.at(0, 0) = 3; b.at(1, 1) = 4;

        mat::SquareMat c = a + b;

        CHECK(c.at(0, 0) == 4);
        CHECK(c.at(1, 1) == 6);
        CHECK(c.at(0, 1) == 0);

        SUBCASE("Addition size mismatch throws") {
            mat::SquareMat d(3);
            CHECK_THROWS_AS(a + d, std::invalid_argument);
        }
        std::cout << "Matrix Addition:\n" << c << "\n";
    }

    TEST_CASE("Matrix Subtraction") {
        mat::SquareMat a(2), b(2);
        a.at(0, 0) = 5; a.at(1, 1) = 7;
        b.at(0, 0) = 2; b.at(1, 1) = 3;

        mat::SquareMat c = a - b;

        CHECK(c.at(0, 0) == 3);
        CHECK(c.at(1, 1) == 4);

        SUBCASE("Subtraction size mismatch throws") {
            mat::SquareMat d(3);
            CHECK_THROWS_AS(a - d, std::invalid_argument);
        }
        std::cout << "Matrix Subtraction:\n" << c << "\n";
    }

    TEST_CASE("Matrix Unary Minus") {
        mat::SquareMat a(2);
        a.at(0, 0) = 1;
        a.at(1, 1) = -2;

        mat::SquareMat b = -a;

        CHECK(b.at(0, 0) == -1);
        CHECK(b.at(1, 1) == 2);

    }

    TEST_CASE("Matrix Multiplication") {
        mat::SquareMat a(2), b(2);
        a.at(0, 0) = 1; a.at(0, 1) = 2;
        a.at(1, 0) = 3; a.at(1, 1) = 4;
        b.at(0, 0) = 5; b.at(0, 1) = 6;
        b.at(1, 0) = 7; b.at(1, 1) = 8;

        mat::SquareMat c = a * b;

        CHECK(c.at(0, 0) == 19);
        CHECK(c.at(0, 1) == 22);
        CHECK(c.at(1, 0) == 43);
        CHECK(c.at(1, 1) == 50);

        SUBCASE("Multiplication size mismatch throws") {
            mat::SquareMat d(3);
            CHECK_THROWS_AS(a * d, std::invalid_argument);
        }
    }

    TEST_CASE("Matrix Scalar Multiplication") {
        mat::SquareMat a(2);
        a.at(0, 0) = 1;
        a.at(1, 1) = 2;

        mat::SquareMat b = a * 3;

        CHECK(b.at(0, 0) == 3);
        CHECK(b.at(1, 1) == 6);
    }

    TEST_CASE("Matrix Element-wise Multiplication (Hadamard Product)") {
        mat::SquareMat a(2), b(2);
        a.at(0, 0) = 2; a.at(1, 1) = 3;
        b.at(0, 0) = 4; b.at(1, 1) = 5;

        mat::SquareMat c = a % b;

        CHECK(c.at(0, 0) == 8);
        CHECK(c.at(1, 1) == 15);
    }

    TEST_CASE("Matrix Modulo Scalar") {
        mat::SquareMat a(2);
        a.at(0, 0) = 5;
        a.at(1, 1) = 9;

        mat::SquareMat b = a % 4;

        CHECK(b.at(0, 0) == 1);
        CHECK(b.at(1, 1) == 1);

        SUBCASE("Modulo by zero throws") {
            CHECK_THROWS_AS(a % 0, std::invalid_argument);
        }
    }

    TEST_CASE("Matrix Division by Scalar") {
        mat::SquareMat a(2);
        a.at(0, 0) = 6;
        a.at(1, 1) = 8;

        mat::SquareMat b = a / 2;

        CHECK(b.at(0, 0) == 3);
        CHECK(b.at(1, 1) == 4);

        SUBCASE("Division by zero throws") {
            CHECK_THROWS_AS(a / 0, std::invalid_argument);
        }
    }

    TEST_CASE("Matrix Exponentiation") {
        mat::SquareMat a(2);
        a.at(0, 0) = 2; a.at(0, 1) = 0;
        a.at(1, 0) = 0; a.at(1, 1) = 2;

        mat::SquareMat b = a ^ 3;

        CHECK(b.at(0, 0) == 8);
        CHECK(b.at(1, 1) == 8);

        SUBCASE("Negative exponent throws") {
            CHECK_THROWS_AS(a ^ -1, std::invalid_argument);
        }
    }

    TEST_CASE("Matrix Pre/Post Increment and Decrement") {
        mat::SquareMat a(2);

        ++a;
        CHECK(a.at(0, 0) == 1);
        CHECK(a.at(1, 1) == 1);

        a++;
        CHECK(a.at(0, 0) == 2);
        CHECK(a.at(1, 1) == 2);

        --a;
        CHECK(a.at(0, 0) == 1);
        CHECK(a.at(1, 1) == 1);

        a--;
        CHECK(a.at(0, 0) == 0);
        CHECK(a.at(1, 1) == 0);
    }

    TEST_CASE("Matrix Transpose") {
        mat::SquareMat a(2);
        a.at(0, 1) = 5;
        a.at(1, 0) = 3;

        mat::SquareMat b = ~a;

        CHECK(b.at(0, 1) == 3);
        CHECK(b.at(1, 0) == 5);
    }

    TEST_CASE("Matrix Determinant") {
        mat::SquareMat a(1);
        a.at(0, 0) = 7;
        CHECK((!a) == 7);

        mat::SquareMat b(2);
        b.at(0, 0) = 1; b.at(0, 1) = 2;
        b.at(1, 0) = 3; b.at(1, 1) = 4;
        CHECK((!b) == -2);

        mat::SquareMat c(3);
        c.at(0,0) = 6; c.at(0,1) = 1; c.at(0,2) = 1;
        c.at(1,0) = 4; c.at(1,1) = -2; c.at(1,2) = 5;
        c.at(2,0) = 2; c.at(2,1) = 8; c.at(2,2) = 7;
        CHECK((!c) == -306);

        mat::SquareMat d(4);
        d.at(0,0) = 7;  d.at(0,1) = 2;  d.at(0,2) = 9;  d.at(0,3) = 4;
        d.at(1,0) = 5;  d.at(1,1) = 1;  d.at(1,2) = 6;  d.at(1,3) = 8;
        d.at(2,0) = 3;  d.at(2,1) = 0;  d.at(2,2) = 2;  d.at(2,3) = 7;
        d.at(3,0) = 9;  d.at(3,1) = 4;  d.at(3,2) = 1;  d.at(3,3) = 6;
        CHECK((!d) == 234);
        std::cout << "Determinant:\n" << a << "\n";
        std::cout << "Determinant:\n" << b << "\n";
        std::cout << "Determinant:\n" << c << "\n";
        std::cout << "Determinant:\n" << d << "\n";

    }

    TEST_CASE("Matrix Comparisons") {
        mat::SquareMat a(2), b(2);
        a.at(0, 0) = 1;
        b.at(0, 0) = 1;

        CHECK(a == b);
        b.at(1, 1) = 1;
        CHECK(a != b);

        CHECK(a < b);
        CHECK(b > a);
        CHECK(a <= b);
        CHECK(!(b <= a));
        CHECK(b >= a);
    }

    TEST_CASE("Compound Assignment Operators") {
        mat::SquareMat a(2), b(2);
        a.at(0, 0) = 2;
        a.at(1, 1) = 3;
        b.at(0, 0) = 1;
        b.at(1, 1) = 1;

        // חיבור מטריצות
        a += b;
        CHECK(a.at(0, 0) == 3);
        CHECK(a.at(1, 1) == 4);

        //  חיסור מטריצות
        a -= b;
        CHECK(a.at(0, 0) == 2);
        CHECK(a.at(1, 1) == 3);

        //  כפל מטריצות
        a *= b;
        CHECK(a.at(0, 0) == 2);
        CHECK(a.at(1, 1) == 3);

        // כפל בסקלר
        a *= 2;
        CHECK(a.at(0, 0) == 4);
        CHECK(a.at(1, 1) == 6);

        // חילוק בסקלר
        a /= 2;
        CHECK(a.at(0, 0) == 2);
        CHECK(a.at(1, 1) == 3);

        // ניסיון לעשות מודולו לפי מטריצה — אמור לזרוק חריגה בגלל אפס
        CHECK_THROWS_AS(a %= b, std::invalid_argument);

        // כעת נוסיף ל-a את b ואז נעשה מודולו לפי סקלר (ללא אפס)
        a += b;  // a (0,0)=3, (1,1)=4
        a %= 2;  // כל איבר mod 2

        CHECK(a.at(0, 0) == 1);
        CHECK(a.at(1, 1) == 0);
    }

}
