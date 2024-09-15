// #include "gmock/gmock.h"
// #include "coords.h"

#include "coords.h"
#include "subscriber.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

// using ::testing::_;
// using ::testing::ExpectationSet;

// #include "../googletest/googletest/include/gtest/gtest.h"
TEST(_test, null_term_str_sort) { EXPECT_EQ(true, true); }

TEST(utils_test, coord) {
  // initGameStruct();
  {
    Coord cd1 = {5, 6};
    Coord cd2 = {2, 8};
    Coord cdResult = cd1 + cd2;
    Coord cdExpected = {7, 14};
    EXPECT_EQ(cdResult, cdExpected);
  }
  {
    Coord cd1 = {5, 6};
    Coord cd2 = {2, 8};
    Coord cdResult = cd1 - cd2;
    Coord cdExpected = {3, -2};
    EXPECT_EQ(cdResult, cdExpected);
  }

  {
    Coord cd1 = {5, 6};
    Coord cd2 = {2, 8};
    Coord cdResult = cd1 - cd2;
    Coord cdExpected = {3, -2};
    EXPECT_EQ(cd1 < cd2, false);
  }

  {
    Coord cd1 = {8, 6};
    Coord cd2 = {2, 8};
    Coord cdResult = cd1 - cd2;
    Coord cdExpected = {3, -2};
    EXPECT_FALSE(cd1 == cd2);
    cd1 = {8, 2};
    EXPECT_FALSE(cd1 == cd2);
    cd1 = {2, 8};
    EXPECT_TRUE(cd1 == cd2);
  }

  {
    Coord cd1 = {3, 6};

    Coord cdResult = cd1 / 3;
    Coord cdExpected = {1, 2};
    EXPECT_EQ(cdResult, cdExpected);
  }
  {
    Coord cd1 = {2, 2};

    int result = static_cast<int>(cd1.length());
    int expected = 2;
    EXPECT_EQ(result, expected);
  }
}

using ::testing::_;
using ::testing::ExpectationSet;

class SubscriberMock : public Subscriber {
 public:
  MOCK_METHOD1(notify, void(std::weak_ptr<Publisher>));
};


TEST(header_test, subscriber) {
  std::shared_ptr<Publisher> pb = std::make_shared<Publisher>();
  // SubscriberMock
  auto sb1 = std::make_shared<SubscriberMock>();
  auto sb2 = std::make_shared<SubscriberMock>();
  pb->addSubscriber(sb1);
  pb->addSubscriber(sb2);


  {
    EXPECT_CALL(((*sb1)), notify(_)).Times(1);
    EXPECT_CALL(((*sb2)), notify(_)).Times(1);
    pb->emit();
  }
  {
    pb->removeSubscriber(sb2);
    EXPECT_CALL(((*sb1)), notify(_)).Times(1);
    EXPECT_CALL(((*sb2)), notify(_)).Times(0);
    pb->emit();
  }
  {
    pb->removeSubscriber(sb1);
    EXPECT_CALL(((*sb1)), notify(_)).Times(0);
    EXPECT_CALL(((*sb2)), notify(_)).Times(0);
    pb->emit();
  }
}
