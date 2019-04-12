set(NAME view)
set(COMPONENT_NAME ${PROJECT_NAME}_${NAME})

add_library(${COMPONENT_NAME}
    "amount.cpp"
    "transfer.cpp"
    "transfersend.cpp"
)
add_library(${PROJECT_NAME}::${NAME} ALIAS ${COMPONENT_NAME})
target_compile_features(${COMPONENT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${COMPONENT_NAME}
    CONAN_PKG::jsonformoderncpp
    CONAN_PKG::gsl_microsoft
)
target_include_directories(${COMPONENT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)

set(UNIT_TEST ${COMPONENT_NAME}_unittest)
add_executable(${UNIT_TEST}
    "amount_test.cpp"
    "transfer_test.cpp"
    "transfersend_test.cpp"
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

