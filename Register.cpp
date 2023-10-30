#include "Register.hpp"

namespace SLCM {

    Unit<3,1>::Output Register1B::tick() {
        m_nand.setA(getLd());
        m_nand.setB(getLd());

        m_and1.setA(m_latch.tick()[0]);
        m_and1.setB(m_nand.tick()[0]);

        m_and2.setA(getLd());
        m_and2.setB(getD());

        m_or.setA(m_and1.tick()[0]);
        m_or.setB(m_and2.tick()[0]);

        m_latch.setD(m_or.tick()[0]);
        m_latch.setEn(getCl());

        m_tri.setA(m_latch.tick()[0]);
        m_tri.setB(getEn());

        return m_tri.tick();
    }

    Unit<5,2>::Output Register2B::tick() {
        m_reg1.setLd(getLd());
        m_reg1.setEn(getEn());
        m_reg1.setCl(getCl());
        m_reg1.setD(getD0());

        m_reg2.setLd(getLd());
        m_reg2.setEn(getEn());
        m_reg2.setCl(getCl());
        m_reg2.setD(getD1());

        auto reg1_tick = m_reg1.tick();
        auto reg2_tick = m_reg2.tick();

        Unit<5,2>::Output ret{};
        std::copy(reg1_tick.begin(), reg1_tick.end(), ret.begin());
        std::copy(reg2_tick.begin(), reg2_tick.end(), 1+ret.begin());

        return ret;
    }

    Unit<7,4>::Output Register4B::tick() {
        m_reg1.setLd(getLd());
        m_reg1.setEn(getEn());
        m_reg1.setCl(getCl());
        m_reg1.setD0(getD0());
        m_reg1.setD1(getD1());

        m_reg2.setLd(getLd());
        m_reg2.setEn(getEn());
        m_reg2.setCl(getCl());
        m_reg2.setD0(getD2());
        m_reg2.setD1(getD3());

        auto reg1_tick = m_reg1.tick();
        auto reg2_tick = m_reg2.tick();

        Unit<7,4>::Output ret{};
        std::copy(reg1_tick.begin(), reg1_tick.end(), ret.begin());
        std::copy(reg2_tick.begin(), reg2_tick.end(), 2+ret.begin());

        return ret;
    }

    Unit<11,8>::Output Register8B::tick() {
        m_reg1.setLd(getLd());
        m_reg1.setEn(getEn());
        m_reg1.setCl(getCl());
        m_reg1.setD0(getD0());
        m_reg1.setD1(getD1());
        m_reg1.setD2(getD2());
        m_reg1.setD3(getD3());

        m_reg2.setLd(getLd());
        m_reg2.setEn(getEn());
        m_reg2.setCl(getCl());
        m_reg2.setD0(getD4());
        m_reg2.setD1(getD5());
        m_reg2.setD2(getD6());
        m_reg2.setD3(getD7());

        auto reg1_tick = m_reg1.tick();
        auto reg2_tick = m_reg2.tick();

        Unit<11,8>::Output ret{};
        std::copy(reg1_tick.begin(), reg1_tick.end(), ret.begin());
        std::copy(reg2_tick.begin(), reg2_tick.end(), 4+ret.begin());

        return ret;
    }
}
