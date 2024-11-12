#include "coords.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "map.h"
#include "cell_holder.h"
#include "subscriber.h"
#include "cell.h"

using ::testing::_;
using ::testing::ExpectationSet;


class MockSubscriber : public Subscriber {
 public:
  MOCK_METHOD1(notify, void(std::weak_ptr<Publisher>));
};

TEST(_TEST_MAP, null_term_str_sort) {
  std::shared_ptr<Map> map = std::make_shared<Map>(CoordPair<int>{40, 40});

  {
    EXPECT_FALSE(map->getCell({10, 10}));
    auto id = map->getIdentifier({10, 10});
    EXPECT_EQ(id.adress, "");
    EXPECT_EQ(id.charId, ' ');
    EXPECT_EQ(id.color, Color::black);
    EXPECT_EQ(id.bgColor, Color::black);
  }

  {
    map->setSeen({10, 10});
    auto id = map->getIdentifier({10, 10});
    EXPECT_EQ(id.adress, "");
    EXPECT_EQ(id.charId, '.');
    EXPECT_EQ(id.color, Color::white);
    EXPECT_EQ(id.bgColor, Color::black);
  }

  { 
      EXPECT_FALSE(map->isWall({10, 10}));
  }
  std::shared_ptr<MockSubscriber> sub = std::make_shared<MockSubscriber>();

  {
    auto holder = std::make_shared<CellHolder>();
    map->addSubscriber(sub);
    EXPECT_CALL(((*sub)), notify(_)).Times(1);
    map->setCellHolder({10, 10}, holder);
    auto cell = map->getCell({10, 10});
    EXPECT_TRUE(cell);
    EXPECT_EQ(cell->getHolder(), holder);
    //EXPECT_FALSE(holder->hasIdentifier());
  }

  {
     EXPECT_CALL(((*sub)), notify(_)).Times(1);
     map->moveUnitFromTo({10, 10}, {10, 20});
     {
       auto cell = map->getCell({10, 10});
       EXPECT_TRUE(cell);
       EXPECT_FALSE(cell->getHolder());
     }
     {
       auto cell = map->getCell({10, 20});
       EXPECT_TRUE(cell);
       EXPECT_TRUE(cell->getHolder());
       //EXPECT_TRUE(cell->getHolder()->hasIdentifier());
     }
  }

  {
    map->removeSubscriber(sub);
    EXPECT_CALL(((*sub)), notify(_)).Times(0);
    
    map->moveUnitFromTo({10, 20}, {20, 30});
    {
      auto cell = map->getCell({10, 20});
      EXPECT_TRUE(cell);
      EXPECT_FALSE(cell->getHolder());
    }
    {
      auto cell = map->getCell({20, 30});
      EXPECT_TRUE(cell);
      EXPECT_TRUE(cell->getHolder());
      //EXPECT_TRUE(cell->getHolder()->hasIdentifier());
    }
  }

  {
    int cnt = 0;
    for (const auto& cell : *map) {
      ++cnt;
    }
    EXPECT_EQ(cnt, 3);
  }

}
