#pragma once

#include <iosfwd>

namespace SLCM {

    enum class State {
        LOW,
        HIG,
        NON
    };

    void validate(const State ste);

    const State operator&&(const State lhs, const State rhs);
    const State operator||(const State lhs, const State rhs);
    const State operator^(const State lhs, const State rhs);
    const State operator!(const State ste);

    const State operator*(const State lhs, const State rhs); // Tristate

    std::ostream& operator<<(std::ostream& os, const State& ste);
}
