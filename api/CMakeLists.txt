set(NAME api)
set(COMPONENT_NAME ${PROJECT_NAME}_${NAME})

add_library(${COMPONENT_NAME}
    "moneybox.cpp"
)
add_library(${PROJECT_NAME}::${NAME} ALIAS ${COMPONENT_NAME})
target_compile_features(${COMPONENT_NAME} PRIVATE cxx_std_17)
target_compile_options(${COMPONENT_NAME} PRIVATE -fprofile-arcs -ftest-coverage)
target_link_libraries(${COMPONENT_NAME}
    ${PROJECT_NAME}::controller
    CONAN_PKG::jsonformoderncpp
    -fprofile-arcs
    -ftest-coverage
)
target_include_directories(${COMPONENT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)
