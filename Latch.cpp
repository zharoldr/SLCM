#include "Latch.hpp"

namespace SLCM {

    Unit<2,2>::Output LatchSR::tick() {

        m_nor1.setA(getR());
        m_nor2.setB(getS());

        m_nor2.setA(m_nor1.tick()[0]);
        m_nor1.setB(m_nor2.tick()[0]);

        return { m_nor1.tick()[0], m_nor2.tick()[0] };
    }
    Unit<3,2>::Output LatchSRE::tick() {

        m_and1.setA(getR());
        m_and1.setB(getEn());

        m_and2.setA(getEn());
        m_and2.setB(getS());

        m_latch.setR(m_and1.tick()[0]);
        m_latch.setS(m_and2.tick()[0]);

        return m_latch.tick();
    }
    Unit<2,2>::Output LatchD::tick() {
        m_nand.setA(getD());
        m_nand.setB(getD());

        m_latch.setR(m_nand.tick()[0]);
        m_latch.setEn(getEn());
        m_latch.setS(getD());

        return m_latch.tick();
    }
}

