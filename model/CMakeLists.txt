set(NAME model)
set(COMPONENT_NAME ${PROJECT_NAME}_${NAME})

add_library(${COMPONENT_NAME}
    "db/mongocommand.cpp"
    "db/mongofactory.cpp"
    "db/mongoquery.cpp"
    "entity.cpp"
    "field.cpp"
)
add_library(${PROJECT_NAME}::${NAME} ALIAS ${COMPONENT_NAME})
target_compile_features(${COMPONENT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${COMPONENT_NAME}
    CONAN_PKG::gsl_microsoft
    CONAN_PKG::mongo-cxx-driver
)
target_include_directories(${COMPONENT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)

set(UNIT_TEST ${COMPONENT_NAME}_unittest)
add_executable(${UNIT_TEST}
    "entity_test.cpp"
)
target_compile_features(${UNIT_TEST} PRIVATE cxx_std_17)
target_include_directories(${UNIT_TEST} PRIVATE
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(${UNIT_TEST}
    ${COMPONENT_NAME}
    CONAN_PKG::gtest
)
add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})

set(AUTO_TEST ${COMPONENT_NAME}_autotest)
add_executable(${AUTO_TEST}
    "db/mongocommand_test.cpp"
    "db/mongoquery_test.cpp"
)
target_compile_features(${AUTO_TEST} PRIVATE cxx_std_17)
target_include_directories(${AUTO_TEST} PRIVATE
    ${CMAKE_SOURCE_DIR}
)
target_link_libraries(${AUTO_TEST}
    ${COMPONENT_NAME}
    CONAN_PKG::gtest
    CONAN_PKG::mongo-cxx-driver
)
add_test(NAME ${AUTO_TEST} COMMAND ${AUTO_TEST})
