# - Main CMake buildscript for mpags-cipher
# Comments in a CMake Script are lines begining with a '#'

# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler command/flags
#   are used. This can also be done by removing the 'set' command and
#   running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Don't allow C++ Compiler Vendor Extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Use our standard set of flags for the GNU/Clang compilers
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")
endif()

# - Add MPAGSCipher subdirectory to the build
add_subdirectory(MPAGSCipher)

# - Add Documentation subdirectory
add_subdirectory(Documentation)

# - Enable testing and add Testing subdirectory to the build
enable_testing()
add_subdirectory(Testing)

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher mpags-cipher.cpp)
target_link_libraries(mpags-cipher PRIVATE MPAGSCipher)

# - Install mpags-cipher using UNIX/GNU directory structure
include(GNUInstallDirs)
install(TARGETS mpags-cipher DESTINATION ${CMAKE_INSTALL_BINDIR})
