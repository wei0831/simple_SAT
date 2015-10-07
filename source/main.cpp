#include "Collision.h"
#include <iostream>

void printSATResult(bool b);

int main(void)
{
    std::cout << "[0]==============" << std::endl;
    SAT_POLY test0_A;
    test0_A.AddPoints(5.0f, 5.0f);
    test0_A.AddPoints(5.0f, -5.0f);
    test0_A.AddPoints(-5.0f, -5.0f);
    test0_A.AddPoints(-5.0f, 5.0f);
    test0_A.RecomputeFaces();
    std::cout << "Poly [A]: " << test0_A;

    SAT_POLY test0_B;
    test0_B.AddPoints(10.0f, 5.0f);
    test0_B.AddPoints(10.0f, -5.0f);
    test0_B.AddPoints(7.0f, -5.0f);
    test0_B.AddPoints(7.0f, 5.0f);
    test0_B.RecomputeFaces();
    std::cout << "Poly [B]: " << test0_B;
    
    printSATResult(SAT(test0_A, test0_B));
    std::cout << "[0]==============" << std::endl;

    std::cout << "[1]==============" << std::endl;
    SAT_POLY test1_A;
    test1_A.AddPoints(5.0f, 5.0f);
    test1_A.AddPoints(5.0f, -5.0f);
    test1_A.AddPoints(-5.0f, -5.0f);
    test1_A.AddPoints(-5.0f, 5.0f);
    test1_A.RecomputeFaces();
    std::cout << "Poly [A]: " << test1_A;

    SAT_POLY test1_B;
    test1_B.AddPoints(7.0f, 5.0f);
    test1_B.AddPoints(7.0f, -5.0f);
    test1_B.AddPoints(4.0f, -5.0f);
    test1_B.AddPoints(4.0f, 5.0f);
    test1_B.RecomputeFaces();
    std::cout << "Poly [B]: " << test1_B;

    printSATResult(SAT(test1_A, test1_B));
    std::cout << "[1]==============" << std::endl;

    std::cout << "[2]==============" << std::endl;
    SAT_POLY test2_A;
    test2_A.AddPoints(0.0f, 5.0f);
    test2_A.AddPoints(5.0f, 0.0f);
    test2_A.AddPoints(0.0f, -5.0f);
    test2_A.AddPoints(-5.0f, 0.0f);
    test2_A.RecomputeFaces();
    std::cout << "Poly [A]: " << test2_A;

    SAT_POLY test2_B;
    test2_B.AddPoints(10.0f, 10.0f);
    test2_B.AddPoints(10.0f, 1.0f);
    test2_B.AddPoints(1.0f, 1.0f);
    test2_B.AddPoints(1.0f, 10.0f);
    test2_B.RecomputeFaces();
    std::cout << "Poly [B]: " << test2_B;

    printSATResult(SAT(test2_A, test2_B));
    std::cout << "[2]==============" << std::endl;


    std::cout << "[3]==============" << std::endl;
    SAT_POLY test3_A;
    test3_A.AddPoints(0.0f, 5.0f);
    test3_A.AddPoints(5.0f, 0.0f);
    test3_A.AddPoints(0.0f, -5.0f);
    test3_A.AddPoints(-5.0f, 0.0f);
    test3_A.RecomputeFaces();
    std::cout << "Poly [A]: " << test3_A;

    SAT_POLY test3_B;
    test3_B.AddPoints(10.0f, 10.0f);
    test3_B.AddPoints(10.0f, 3.0f);
    test3_B.AddPoints(3.0f, 3.0f);
    test3_B.AddPoints(3.0f, 10.0f);
    test3_B.RecomputeFaces();
    std::cout << "Poly [B]: " << test3_B;

    printSATResult(SAT(test3_A, test3_B));
    std::cout << "[3]==============" << std::endl;

    std::cout << "[4]==============" << std::endl;
    SAT_POLY test4_A;
    test4_A.AddPoints(0.0f, 7.0f);
    test4_A.AddPoints(5.0f, 5.0f);
    test4_A.AddPoints(0.0f, 0.0f);
    test4_A.RecomputeFaces();
    std::cout << "Poly [A]: " << test4_A;

    SAT_POLY test4_B;
    test4_B.AddPoints(2.0f, 10.0f);
    test4_B.AddPoints(7.0f, 10.0f);
    test4_B.AddPoints(2.0f, 5.0f);
    test4_B.RecomputeFaces();
    std::cout << "Poly [B]: " << test4_B;

    printSATResult(SAT(test4_A, test4_B));
    std::cout << "[4]==============" << std::endl;

    std::cout << "[5]==============" << std::endl;
    SAT_POLY test5_A;
    test5_A.AddPoints(-2.0f, 4.0f);
    test5_A.AddPoints(2.0f, 4.0f);
    test5_A.AddPoints(0.0f, 2.0f);
    test5_A.RecomputeFaces();
    std::cout << "Poly [A]: " << test5_A;

    SAT_POLY test5_B;
    test5_B.AddPoints(0.0f, 2.0f);
    test5_B.AddPoints(2.0f, 0.0f);
    test5_B.AddPoints(-2.0f, 0.0f);
    test5_B.RecomputeFaces();
    std::cout << "Poly [B]: " << test5_B;

    printSATResult(SAT(test5_A, test5_B));
    std::cout << "[5]==============" << std::endl;
}

void printSATResult(bool b)
{
    if (b)
        std::cout << "[Result] -- Collision!" << std::endl;
    else
        std::cout << "[Result] -- NO Collision!" << std::endl;
}
