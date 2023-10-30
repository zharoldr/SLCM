#pragma once

#include "Gate.hpp"

namespace SLCM {

    // TODO: Use templates to create N-bit Adders
    // template<size_t N>
    // struct Adder : public Unit<1+2*N,1+N> { ... }
    struct Adder1B : public Unit<3,2> {
        GETSET(A  , 0);
        GETSET(B  , 1);
        GETSET(Cin, 2);

        Output tick() override;
    private:
        Xor m_xor1;
        Xor m_xor2;

        And m_and1;
        And m_and2;

        Or m_or;
    };

    struct Adder2B : public Unit<5,3> {
        GETSET(A0, 0);
        GETSET(B0, 1);
        GETSET(A1, 2);
        GETSET(B1, 3);
        GETSET(Cin, 4);

        Output tick() override;
    private:
        Adder1B m_adder1;
        Adder1B m_adder2;
    };

    struct Adder4B : public Unit<9,5> {
        GETSET(A0, 0);
        GETSET(B0, 1);
        GETSET(A1, 2);
        GETSET(B1, 3);
        GETSET(A2, 4);
        GETSET(B2, 5);
        GETSET(A3, 6);
        GETSET(B3, 7);
        GETSET(Cin, 8);

        Output tick() override;
    private:
        Adder2B m_adder1;
        Adder2B m_adder2;
    };

    struct Adder8B : public Unit<17,9> {
        GETSET(A0,   0);
        GETSET(B0,   1);
        GETSET(A1,   2);
        GETSET(B1,   3);
        GETSET(A2,   4);
        GETSET(B2,   5);
        GETSET(A3,   6);
        GETSET(B3,   7);
        GETSET(A4,   8);
        GETSET(B4,   9);
        GETSET(A5,  10);
        GETSET(B5,  11);
        GETSET(A6,  12);
        GETSET(B6,  13);
        GETSET(A7,  14);
        GETSET(B7,  15);
        GETSET(Cin, 16);

        Output tick() override;
    private:
        Adder4B m_adder1;
        Adder4B m_adder2;
    };
}

