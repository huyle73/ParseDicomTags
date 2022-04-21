#pragma once

#include "vega/manipulators/single_string_manipulator.h"

namespace vega {
  namespace manipulators {
    class URIManipulator : public SingleStringManipulator {
      using SingleStringManipulator::SingleStringManipulator;

      public:
        virtual bool is_valid_for(const VR& vr) const override {
          return vr == vr::UR;
        }
    };
  }

  namespace vr {
    template <>
    bool manipulator_is_valid_for<manipulators::URIManipulator>(VR::value_type value);
  }
}
