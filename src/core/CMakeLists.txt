cmake_minimum_required (VERSION 3.10)

project("NutCrackerCLI")

SET(SOURCE_FILES
    "Actions.cpp" 
    "Actions.h"
    "BinaryReader.h"
    "BlockState.h"
    "Errors.cpp"
    "Errors.h"
    "Expressions.h"
    "Formatters.h"
    "main.cpp"
    "NutDecompiler.cpp"
    "NutScript.cpp"
    "NutScript.h"
    "SqObject.cpp"
    "SqObject.h"
    "Statements.cpp"
    "Statements.h")

add_executable(NutCracker ${SOURCE_FILES})
