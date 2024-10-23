


set(CMAKE_CXX_STANDART 20)
#set(CMAKE_CXX_STANDART_REQUIRED ON)
add_executable(tests)
target_sources(tests PRIVATE 
  test_main.cpp
  test_cash.cpp
  )
target_compile_features(tests PRIVATE cxx_std_17)


target_link_libraries(tests PRIVATE gtest_main gmock_main logic utils)
target_include_directories(tests PUBLIC 
  ../googletest/googletest/include/
  ../googletest/googlemock/include/
  ../src/units/
  ../src/maps/
  ../src/text_work/
  ../src/utils/
)




