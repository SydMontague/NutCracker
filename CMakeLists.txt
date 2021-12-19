cmake_minimum_required (VERSION 3.10)

project("NutCracker")

set(CMAKE_CXX_STANDARD 14)

if (MSVC)
	add_definitions("-D_CRT_SECURE_NO_WARNINGS -D_WIN32_WINNT=0x0601") # Windows 7
else()
	set(CMAKE_CXX_FLAGS -pthread)
endif()

# --- Libraries ---
# python
FIND_PACKAGE(Python3)
FIND_PACKAGE(PythonLibs REQUIRED)

# boost
if(WIN32)
    set(Boost_USE_STATIC_LIBS ON) 
elseif(BUILD_SHARED)
    set(Boost_USE_STATIC_LIBS OFF) 
endif()

FIND_PACKAGE(Boost COMPONENTS python${Python3_VERSION_MAJOR}${Python3_VERSION_MINOR} REQUIRED)

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS} )
add_subdirectory("src/core")
add_subdirectory("src/bindings")
