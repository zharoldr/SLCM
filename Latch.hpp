#pragma once

#include "Gate.hpp"

namespace SLCM {

    struct LatchSR : public Unit<2,2> {

        GETSET(R, 0);
        GETSET(S, 1);

        Output tick() override;
    private:
        Nor m_nor1;
        Nor m_nor2;
    };

    struct LatchSRE : public Unit<3,2> {
        
        GETSET(R , 0);
        GETSET(En, 1);
        GETSET(S , 2);

        Output tick() override;
    private:
        And m_and1;
        And m_and2;

        LatchSR m_latch;
    };

    struct LatchD : public Unit<2,2> {
        GETSET(D , 0);
        GETSET(En, 1);

        Output tick() override;
    private:
        Nand m_nand;
        LatchSRE m_latch;
    };
}
