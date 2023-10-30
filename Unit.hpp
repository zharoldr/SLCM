#pragma once

#include <array>

#include "State.hpp"


#define GETSET(name, pin) void set##name(const State ste) { this->m_i[pin] = ste; }\
    const State get##name() const { return this->m_i[pin]; }

namespace SLCM {

    template<size_t iN, size_t oN>
    class Unit {
    public:
        using Input  = std::array<State, iN>;
        using Output = std::array<State, oN>;

        Unit() = default;
        Unit(const Unit&) = delete;
        Unit(Unit&&) noexcept = delete;
        Unit& operator=(const Unit&) = delete;
        Unit& operator=(Unit&&) noexcept = delete;
        virtual ~Unit() = default;

        virtual Output tick() = 0;
    protected:

        State&       operator[](const size_t idx)       { return m_i[idx]; }
        const State& operator[](const size_t idx) const { return m_i[idx]; }

        Input m_i{};
    };

}

