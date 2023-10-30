#include "Adder.hpp"

namespace SLCM {

    Unit<3,2>::Output Adder1B::tick() {
        m_xor1.setA(getA());
        m_xor1.setB(getB());

        auto xor1_tick = m_xor1.tick();

        m_xor2.setA(xor1_tick[0]);
        m_xor2.setB(getCin());

        m_and1.setA(getCin());
        m_and1.setB(xor1_tick[0]);

        m_and2.setA(getA());
        m_and2.setB(getB());

        m_or.setA(m_and1.tick()[0]);
        m_or.setB(m_and2.tick()[0]);

        return { m_xor2.tick()[0], m_or.tick()[0] };
    }

    Unit<5,3>::Output Adder2B::tick() {
        m_adder1.setA(getA0());
        m_adder1.setB(getB0());

        m_adder1.setCin(getCin());

        m_adder2.setA(getA1());
        m_adder2.setB(getB1());

        auto adder1_tick = m_adder1.tick();

        m_adder2.setCin(adder1_tick[1]);

        auto adder2_tick = m_adder2.tick();

        Unit<5,3>::Output ret{};
        ret[0] = adder1_tick[0];
        ret[1] = adder2_tick[0];
        ret[2] = adder2_tick[1];

        return ret;
    }

    Unit<9,5>::Output Adder4B::tick() {
        m_adder1.setA0(getA0());
        m_adder1.setB0(getB0());
        m_adder1.setA1(getA1());
        m_adder1.setB1(getB1());

        m_adder1.setCin(getCin());

        m_adder2.setA0(getA2());
        m_adder2.setB0(getB2());
        m_adder2.setA1(getA3());
        m_adder2.setB1(getB3());

        auto adder1_tick = m_adder1.tick();

        m_adder2.setCin(adder1_tick[2]);

        auto adder2_tick = m_adder2.tick();

        Unit<9,5>::Output ret{};
        ret[0] = adder1_tick[0];
        ret[1] = adder1_tick[1];

        ret[2] = adder2_tick[0];
        ret[3] = adder2_tick[1];

        ret[4] = adder2_tick[2];

        return ret;
    }

    Unit<17,9>::Output Adder8B::tick() {
        m_adder1.setA0(getA0());
        m_adder1.setB0(getB0());
        m_adder1.setA1(getA1());
        m_adder1.setB1(getB1());
        m_adder1.setA2(getA2());
        m_adder1.setB2(getB2());
        m_adder1.setA3(getA3());
        m_adder1.setB3(getB3());

        m_adder1.setCin(getCin());

        m_adder2.setA0(getA3());
        m_adder2.setB0(getB3());
        m_adder2.setA1(getA4());
        m_adder2.setB1(getB4());
        m_adder2.setA2(getA5());
        m_adder2.setB2(getB5());
        m_adder2.setA3(getA6());
        m_adder2.setB3(getB6());

        auto adder1_tick = m_adder1.tick();

        m_adder2.setCin(adder1_tick[4]);

        auto adder2_tick = m_adder2.tick();

        Unit<17,9>::Output ret{};
        ret[0] = adder1_tick[0];
        ret[1] = adder1_tick[1];
        ret[2] = adder1_tick[2];
        ret[3] = adder1_tick[3];

        ret[4] = adder2_tick[0];
        ret[5] = adder2_tick[1];
        ret[6] = adder2_tick[2];
        ret[7] = adder2_tick[3];

        ret[8] = adder2_tick[4];

        return ret;
    }

}
