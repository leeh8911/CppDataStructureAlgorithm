cmake_minimum_required(VERSION 3.11.3)

# Set the C++ standard we will use
set(CMAKE_CXX_STANDARD 17)

# Add the path of the cmake files to the CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

project(CPP_DATA_STRUCTURE_ALGORITHM)

# Set library output path to /lib
set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib")

# Add the pugixml and GoogleTest library subdirectories
add_subdirectory(thirdparty/googletest)

# Add project executable
add_executable(CPP_DATA_STRUCTURE_ALGORITHM src/TestCode.cpp)

target_link_libraries(CPP_DATA_STRUCTURE_ALGORITHM 
    gtest_main 
)

# Set options for Linux or Microsoft Visual C++
# if( ${CMAKE_SYSTEM_NAME} MATCHES "Linux" )
#     target_link_libraries(CPP_DATA_STRUCTURE_ALGORITHM PUBLIC pthread)
# endif()

if(MSVC)
	target_compile_options(CPP_DATA_STRUCTURE_ALGORITHM PUBLIC /D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING /wd4459)
endif()
