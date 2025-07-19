


set(CMAKE_CXX_STANDART 20)
# set(CMAKE_CXX_STANDART_REQUIRED ON)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE 
  main.cpp 
  game.h 
  game.cpp
  renderer.h
  renderer.cpp
  game_struct.h
  sdl_port.h
  sdl_port.cpp
  event_sdl_port.h
  event_sdl_port.cpp
  abstract_port.h
  abstract_event_port.h
  
  )
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

add_library(utils 
  utils/log.h
  utils/log.cpp
  utils/headers.h
  utils/headers.cpp  
  utils/coords.h
  utils/coords.cpp
  utils/random.h
  utils/subscriber.h
  utils/subscriber.cpp
  utils/game_drawer.cpp
  utils/game_drawer.h
  utils/templateCash.hpp
  utils/keyboard.h
  utils/keyboard.cpp
  utils/console_windows.h
  utils/console_windows.cpp
  utils/command.h
  utils/command.cpp
  utils/gamefsm.h
  utils/invoker.h
  utils/invoker.cpp
  utils/interactor.h
  utils/interactor.cpp
  utils/lua_class.h
  utils/lua_class.cpp
  

  utils/actor/actor.h
  utils/actor/actor.cpp
  utils/actor/actor_strategy.h
  utils/actor/actor_strategy.cpp
  utils/actor/actor_strategy_char.h
  utils/actor/actor_strategy_char.cpp
  utils/actor/actor_strategy_fsm.h
  utils/actor/actor_strategy_fsm.cpp
  utils/actor/actor_strategy_inventory.h
  utils/actor/actor_strategy_inventory.cpp
  utils/actor/actor_strategy_map.h
  utils/actor/actor_strategy_map.cpp

  

)
target_compile_features(utils PUBLIC cxx_std_20)


add_library(logic 
  units/cell_holder.h
  units/cell_holder.cpp
  units/unit.h
  units/unit.cpp
  units/watching.h
  units/watching.cpp
  units/visualization_unit.h
  units/visualization_unit.cpp
  units/interactor.h
  units/interactor.cpp
  units/group.cpp
  units/group.h 
  units/char_component.h
  units/char_component.cpp
  maps/cell.h
  maps/cell.cpp
  maps/map.h
  maps/map.cpp
  maps/mover.h
  maps/mover.cpp  
  maps/map_generator.h
  maps/map_generator.cpp
  )



target_compile_features(logic PUBLIC cxx_std_20)

add_library(chars
  chars/base_char.h
  chars/base_char.cpp  
)
target_compile_features(chars PUBLIC cxx_std_20)

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
  visualiser/log_window.h
  visualiser/log_window.cpp
  visualiser/main_window.h
  visualiser/main_window.cpp
  visualiser/map_window.h
  visualiser/map_window.cpp
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

target_include_directories(visualiser PUBLIC 
  utils/
  maps/
  game_components/
)

target_include_directories(logic PUBLIC 
  utils/
  units/
  maps/
  game_components/
  chars/
  ../lua-5.4.7/src
)


target_include_directories(components PUBLIC 
  utils/
)

target_include_directories(chars PUBLIC 
  utils/
)

target_include_directories(utils PUBLIC 
 ../lua-5.4.7/src
)


# add_subdirectory(../lua-5.4.7)

target_link_libraries(components PRIVATE utils PUBLIC  ${BOOST_LIB})
target_link_libraries(visualiser PRIVATE logic PUBLIC  ${BOOST_LIB})
target_link_libraries(chars PRIVATE utils PUBLIC  ${BOOST_LIB})
target_link_libraries(utils PRIVATE LuaLib PUBLIC  ${BOOST_LIB})


target_link_libraries(${PROJECT_NAME} PRIVATE vendor utils visualiser components logic LuaLib chars PUBLIC  ${BOOST_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC 
  ../vendor/SDL/include/SDL3
  ../SDL_ttf/include/SDL3_ttf
  utils/
  ../vendor/CppConsoleGameLibrary
  visualiser/
  chars/
)



