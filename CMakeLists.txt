cmake_minimum_required(VERSION 3.2)

project(moneybox)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "model/db/mongocommand.cpp"
    "model/db/mongofactory.cpp"
    "model/db/mongoquery.cpp"
    "model/entity.cpp"
    "model/field.cpp"
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME}
    CONAN_PKG::boost
    CONAN_PKG::gsl_microsoft
    CONAN_PKG::mongo-cxx-driver
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)

enable_testing()
set(UNIT_TEST ${PROJECT_NAME}_unittest)
add_executable(${UNIT_TEST}
    "model/field.cpp"
    "model/db/mongocommand.cpp"
    "model/db/mongofactory.cpp"
    "model/db/mongoquery.cpp"
    "model/entity.cpp"
    "model/entity_test.cpp"
)
target_compile_features(${UNIT_TEST} PRIVATE cxx_std_17)
target_include_directories(${UNIT_TEST} PRIVATE
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(${UNIT_TEST}
    CONAN_PKG::gtest
    CONAN_PKG::mongo-cxx-driver
)
add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})

set(AUTO_TEST ${PROJECT_NAME}_autotest)
add_executable(${AUTO_TEST}
    "model/db/mongocommand.cpp"
    "model/db/mongocommand_test.cpp"
    "model/db/mongoquery.cpp"
    "model/db/mongoquery_test.cpp"
)
target_compile_features(${AUTO_TEST} PRIVATE cxx_std_17)
target_include_directories(${AUTO_TEST} PRIVATE
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(${AUTO_TEST}
    CONAN_PKG::gtest
    CONAN_PKG::mongo-cxx-driver
)
add_test(NAME ${AUTO_TEST} COMMAND ${AUTO_TEST})
