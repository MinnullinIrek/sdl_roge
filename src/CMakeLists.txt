


set(CMAKE_CXX_STANDART 20)
# set(CMAKE_CXX_STANDART_REQUIRED ON)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE 
  main.cpp 
  game.h 
  game.cpp
  renderer.h
  renderer.cpp
  keyboard.h
  keyboard.cpp
  
  )
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
  utils/console.cpp
  utils/console.h
  
)
target_compile_features(utils PUBLIC cxx_std_20)


add_library(logic 
  units/cell_holder.h
  units/cell_holder.cpp
  units/unit.h
  units/unit.cpp
  maps/cell.h
  maps/cell.cpp
)

target_compile_features(logic PUBLIC cxx_std_20)

add_library(components 
  game_components/component.h
  game_components/constants.h
  game_components/entity.h
  game_components/entity.cpp
  game_components/entity.cpp
  game_components/entityManager.h
  game_components/entityManager.cpp
  game_components/components/transform_component.h
)

target_compile_features(components PUBLIC cxx_std_20)



add_library(visualiser 
  # visualiser/chars_window.h
  # visualiser/chars_window.cpp
  # visualiser/game_log_window.h
  # visualiser/game_log_window.cpp
  # visualiser/inventory_window.h
  # visualiser/inventory_window.cpp
  visualiser/iwindow.h
  # visualiser/log_window.h
  # visualiser/log_window.cpp
  visualiser/main_window.h
  visualiser/main_window.cpp
  # visualiser/map_window.h
  # visualiser/map_window.cpp
  # visualiser/shower.h
  # visualiser/shower.cpp
  # visualiser/tab.h
  # visualiser/tab.cpp
  # visualiser/visualiser.h
  # visualiser/visualiser.cpp
  visualiser/window.h
  visualiser/window.cpp
  )
  target_compile_features(visualiser PUBLIC cxx_std_20)

target_include_directories(logic PUBLIC 
  utils/
  units/
  maps/
  game_components/
)
target_include_directories(components PUBLIC 
  utils/
)

target_include_directories(visualiser PUBLIC 
  utils/
)

target_link_libraries(components PRIVATE utils PUBLIC  ${BOOST_LIB})


target_link_libraries(${PROJECT_NAME} PRIVATE vendor utils visualiser components logic PUBLIC  ${BOOST_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC 
  ../vendor/SDL/include/SDL3
  utils/
  ../vendor/CppConsoleGameLibrary
  visualiser/
)



