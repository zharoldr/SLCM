#include "State.hpp"

#include <iostream>
#include <cassert>

namespace SLCM {

    void validate(const State ste) { assert(ste != State::NON &&
        "Cannot perform operation with NON!!"); }

    const State operator&&(const State lhs, const State rhs) {
        validate(lhs);
        validate(rhs);

        if (lhs == State::LOW || rhs == State::LOW)
            return State::LOW;
        return State::HIG;
    }
    const State operator||(const State lhs, const State rhs) {
        validate(lhs);
        validate(rhs);

        if (lhs == State::HIG || rhs == State::HIG)
            return State::HIG;
        return State::LOW;
    }
    const State operator^(const State lhs, const State rhs) {
        validate(lhs);
        validate(rhs);

        if (lhs == rhs)
            return State::LOW;
        return State::HIG;
    }
    const State operator!(const State ste) {
        validate(ste);

        if (ste == State::LOW)
            return State::HIG;
        return State::LOW;
    }
    // Used by Tristate
    const State operator*(const State lhs, const State rhs) {
        validate(lhs); validate(rhs);

        if (rhs == State::LOW)
            return State::NON;
        return lhs;
    }
    std::ostream& operator<<(std::ostream& os, const State& ste) {
        switch (ste) {
        case State::LOW: {
            os << "LOW ";
            break;
        }
        case State::HIG: {
            os << "HIG ";
            break;
        }
        case State::NON: {
            os << "NON ";
            break;
        }
        default:
            assert(false && "Something terrible happened! Unknown State!!");
        }

        return os;
    }
}
