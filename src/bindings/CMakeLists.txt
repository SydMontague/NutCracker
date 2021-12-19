cmake_minimum_required (VERSION 3.10)

project("NutCrackerPythonBindings")

SET(SOURCE_FILES
    "../core/Actions.cpp" 
    "../core/Actions.h"
    "../core/BinaryReader.h"
    "../core/BlockState.h"
    "../core/Errors.cpp"
    "../core/Errors.h"
    "../core/Expressions.h"
    "../core/Formatters.h"
    "../core/NutDecompiler.cpp"
    "../core/NutScript.cpp"
    "../core/NutScript.h"
    "../core/SqObject.cpp"
    "../core/SqObject.h"
    "../core/Statements.cpp"
    "../core/Statements.h"
    "python.cpp")
    
add_library (NutCrackerPythonBindings SHARED ${SOURCE_FILES})

set_target_properties(NutCrackerPythonBindings
        PROPERTIES OUTPUT_NAME NutCracker)