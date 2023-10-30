#pragma once

#include "Unit.hpp"

namespace SLCM {

    struct Gate : public Unit<2, 1> {
        GETSET(A, 0)
        GETSET(B, 1)
    };

    struct      And : public Gate { Output tick() override { return {   m_i[0] && m_i[1]  }; } };
    struct     Nand : public Gate { Output tick() override { return { !(m_i[0] && m_i[1]) }; } };
    struct       Or : public Gate { Output tick() override { return {   m_i[0] || m_i[1]  }; } };
    struct      Nor : public Gate { Output tick() override { return { !(m_i[0] || m_i[1]) }; } };
    struct      Xor : public Gate { Output tick() override { return {   m_i[0]  ^ m_i[1]  }; } };
    
    // A = In
    // B = Enable
    struct Tristate : public Gate { Output tick() override { return {   m_i[0]  * m_i[1]  }; } };

}

