cmake_minimum_required(VERSION 3.5)
project(wordParser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/common_parser.h
    include/factory.h
    include/float_parser.h
    include/int_parser.h
    include/parser_driver.h
    include/person.h
    include/person_parser.h
    include/string_parser.h
    include/utility.h
    include/word_table.h
    src/common_parser.cpp
    src/factory.cpp
    src/float_parser.cpp
    src/int_parser.cpp
    src/main.cpp
    src/parser_driver.cpp
    src/person.cpp
    src/person_parser.cpp
    src/string_parser.cpp
    src/word_table.cpp
#    test/test_common_parser.cpp
#    test/test_factory.cpp
    test/test_float_parser.cpp
#    test/test_int_parser.cpp
#    test/test_parser_driver.cpp
#    test/test_person.cpp
#    test/test_person_parser.cpp
#    test/test_string_parser.cpp
#    test/test_word_table.cpp
    test.txt)

include_directories ("${PROJECT_SOURCE_DIR}/include")

add_executable(wordParser ${SOURCE_FILES})