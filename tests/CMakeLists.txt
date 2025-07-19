


set(CMAKE_CXX_STANDART 20)
#set(CMAKE_CXX_STANDART_REQUIRED ON)
enable_testing()


add_executable(test_runner
  src/test_main.cpp
)


find_package(GTest REQUIRED)

target_link_libraries(test_runner PRIVATE GTest::GTest)

add_test(first test_runner_exec COMMAND test_runner)


target_include_directories(tests PUBLIC 
  ../googletest/googletest/include/
  ../googletest/googlemock/include/
  ../src/units/
  ../src/maps/
  ../src/text_w
  ork/
  ../src/utils/
)




