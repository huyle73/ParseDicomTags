#include "vega/manipulators/code_string_manipulator.h"

namespace vega {
  namespace vr {
    template <>
    bool manipulator_is_valid_for<manipulators::CodeStringManipulator>(VR::value_type value) {
      return value == vr::CS_VALUE;
    }
  }
}
