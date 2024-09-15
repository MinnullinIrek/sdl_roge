cmake_minimum_required(VERSION 3.20)
project(SDLTutorial)
set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)
# target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)


#find_package(Boost 1.78.0 REQUIRED)
#if(Boost_FOUND)
#  include_directories(${Boost_INCLUDE_DIRS})
#endif()
#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

add_subdirectory(vendor)
add_subdirectory(src)
add_subdirectory(googletest)
add_subdirectory(tests)



#add_compile_definitions(BOOST_BEAST_USE_STD_STRING_VIEW)
#add_compile_definitions(BOOST_THREAD_PROVIDES_FUTURE)
