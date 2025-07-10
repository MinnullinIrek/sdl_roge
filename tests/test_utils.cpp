#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::_;
using ::testing::ExpectationSet;
#include "random.h"



TEST(_TEST_utils, random_test) {
   EXPECT_TRUE(random(0, 10) < 11);
}
