#pragma once

#include "../test_helper.h"

#include <sstream>
#include "vega/manipulators/age_string_manipulator.h"
#include "vega/dicom/data_element.h"

using namespace vega;
using namespace vega::manipulators;

TEST(AgeStringManipulatorTest, constructor_test) {
  AgeStringManipulator manipulator{};

  manipulator.emplace_back(20, Age::Unit::YEAR);
  manipulator.emplace_back(365, Age::Unit::DAY);

  EXPECT_EQ(manipulator.str(), "020Y\\365D ");

  AgeStringManipulator manipulator2(manipulator.raw_value());

  EXPECT_EQ(manipulator[0], manipulator2[0]);
  EXPECT_EQ(manipulator[1], manipulator2[1]);
}

TEST(AgeStringManipulatorTest, data_element_test) {
  vega::dicom::DataElement data_element{Tag {0x0010, 0x1010}, vr::AS};
  auto manipulator = data_element.get_manipulator<AgeStringManipulator>();

  manipulator->emplace_back(5, Age::Unit::WEEK);
  manipulator->emplace_back(100, Age::Unit::MONTH);

  EXPECT_EQ(data_element.str(), "005W\\100M ");
}
