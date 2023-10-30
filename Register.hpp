#pragma once

#include "Latch.hpp"

namespace SLCM {
    
    // TODO: Use templates to create N-bit Registers
    // template<size_t N>
    // struct Register : public Unit<3+N,N> { ... }
    struct Register1B : public Unit<4, 1> {

        GETSET(Ld, 0);
        GETSET(En, 1);
        GETSET(Cl, 2);
        GETSET(D, 3);

        Output tick() override;
    private:
        Nand m_nand;

        And m_and1;
        And m_and2;

        Or m_or;

        LatchD m_latch;

        Tristate m_tri;
    };

    struct Register2B : public Unit<5, 2> {

        GETSET(Ld, 0);
        GETSET(En, 1);
        GETSET(Cl, 2);

        GETSET(D0, 3);
        GETSET(D1, 4);

        Output tick() override;
    private:
        Register1B m_reg1;
        Register1B m_reg2;
    };

    struct Register4B : public Unit<7, 4> {

        GETSET(Ld, 0);
        GETSET(En, 1);
        GETSET(Cl, 2);

        GETSET(D0, 3);
        GETSET(D1, 4);
        GETSET(D2, 5);
        GETSET(D3, 6);

        Output tick() override;
    private:
        Register2B m_reg1;
        Register2B m_reg2;
    };

    struct Register8B : public Unit<11, 8> {

        GETSET(Ld,  0);
        GETSET(En,  1);
        GETSET(Cl,  2);

        GETSET(D0,  3);
        GETSET(D1,  4);
        GETSET(D2,  5);
        GETSET(D3,  6);
        GETSET(D4,  7);
        GETSET(D5,  8);
        GETSET(D6,  9);
        GETSET(D7, 10);

        Output tick() override;
    private:
        Register4B m_reg1;
        Register4B m_reg2;
    };
}
