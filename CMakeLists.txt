cmake_minimum_required(VERSION 3.5)
project(mypymod)
set(BUILD_SHARED_LIBS "ON")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES myNativeModule.c)
set(CMAKE_SHARED_LINKER_FLAGS "-L/usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/lib/python2.7/config -lpython2.7 -ldl -framework CoreFoundation")
find_package(PythonLibs REQUIRED)
add_library(mypymod SHARED ${SOURCE_FILES})

# Note that python would not load module with dylib extension, this should not be a problem on Linux
set_target_properties(mypymod PROPERTIES
        PREFIX ""
        OUTPUT_NAME "myNativeModule"
        SUFFIX ".so")

include_directories("/usr/local/Cellar/python/2.7.11/Frameworks/Python.framework/Versions/2.7/include/python2.7")
target_link_libraries(mypymod ${PYTHON_LIBRARIES})
