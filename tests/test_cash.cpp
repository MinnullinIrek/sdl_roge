
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "templateCash.hpp"

using ::testing::_;
using ::testing::ExpectationSet;

static const int cashCapacity = 10;

struct CashValueChecker {
  static int counter;
  static int total;
  int num = 0;
  CashValueChecker() : num(counter) {
    ++counter;
    ++total;
  }
  CashValueChecker(const CashValueChecker& old) : num(old.num) { ++total; };
  CashValueChecker(CashValueChecker&& old) noexcept : num(old.num) {
    ++total;
    old.num = -1;
  }

  CashValueChecker& operator=(const CashValueChecker& old) = delete;
  CashValueChecker& operator=(CashValueChecker&& old) {
    num = old.num;
    old.num = -1;
  };

  ~CashValueChecker() { --total; }
};

int CashValueChecker::counter = 0;
int CashValueChecker::total = 0;

TEST(CASH, test_cash_0) {
  {
    TemplateCash<int, CashValueChecker> cash(cashCapacity);

    EXPECT_FALSE(cash.exists(0));
    EXPECT_FALSE(cash.exists(1));
    for (int i = 0; i < cashCapacity; ++i) {
      auto c = CashValueChecker();
      cash.put(i, c);
    }

    for (int i = 0; i < cashCapacity; ++i) {
      ASSERT_TRUE(cash.exists(i));
      auto c = cash.get(i);
      ASSERT_TRUE(cash.get(i).num == i + 2);
    }

    ASSERT_EQ(CashValueChecker::counter, cashCapacity + 2);

    cash.put(cashCapacity + 1, CashValueChecker());

    ASSERT_EQ(CashValueChecker::total, 12);
    ASSERT_FALSE(cash.exists(0));
    ASSERT_FALSE(cash.exists(cashCapacity + 3));
    ASSERT_EQ(cash.get(cashCapacity + 1).num, cashCapacity + 2);
  }
  ASSERT_EQ(CashValueChecker::total, 0);
}
