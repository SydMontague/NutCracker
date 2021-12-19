cmake_minimum_required (VERSION 3.10)

project("NutCracker")

SET(SOURCE_FILES
    src/BinaryReader.h
    src/BlockState.h
    src/Errors.cpp
    src/Errors.h
    src/Expressions.h
    src/Formatters.h
    src/main.cpp
    src/NutDecompiler.cpp
    src/NutScript.cpp
    src/NutScript.h
    src/SqObject.cpp
    src/SqObject.h
    src/Statements.cpp
    src/Statements.h)

add_executable(NutCracker ${SOURCE_FILES})
add_subdirectory("src/bindings")
