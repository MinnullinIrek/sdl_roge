


set(CMAKE_CXX_STANDART 20)
# set(CMAKE_CXX_STANDART_REQUIRED ON)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

add_library(utils 
  utils/log.h
  utils/log.cpp
  utils/headers.h
  utils/coords.h
  utils/coords.cpp
  utils/random.h
  utils/subscriber.h
  utils/subscriber.cpp
  utils/random.h
  utils/console.cpp
  utils/console.h
  utils/templateCash.hpp
)


add_library(logic 
  units/cell_holder.h
  units/cell_holder.cpp
  units/unit.h
  units/unit.cpp
  maps/cell.h
  maps/cell.cpp
)

target_include_directories(logic PUBLIC 
  utils/
  units/
  maps/
)



target_link_libraries(${PROJECT_NAME} PRIVATE vendor utils PUBLIC  ${BOOST_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC 
  ../vendor/SDL/include/SDL3
  utils/
  ../vendor/CppConsoleGameLibrary
)



