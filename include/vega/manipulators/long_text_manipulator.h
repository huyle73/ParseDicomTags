#pragma once

#include "vega/manipulators/single_string_manipulator.h"

namespace vega {
  namespace manipulators {
    class LongTextManipulator : public SingleStringManipulator {
      using SingleStringManipulator::SingleStringManipulator;

      public:
        virtual bool is_valid_for(const VR& vr) const override {
          return vr == vr::LT;
        }
    };
  }

  namespace vr {
    template <>
    bool manipulator_is_valid_for<manipulators::LongTextManipulator>(VR::value_type value);
  }
}
