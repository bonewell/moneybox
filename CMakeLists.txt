cmake_minimum_required(VERSION 3.2)

project(moneybox VERSION 0.1 LANGUAGES CXX
  DESCRIPTION "Give me your money"
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(${PROJECT_NAME}
    "main.cpp"
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME}
    ${PROJECT_NAME}::model
    ${PROJECT_NAME}::view
    ${PROJECT_NAME}::controller
    ${PROJECT_NAME}::api
    CONAN_PKG::jsonformoderncpp
    CONAN_PKG::boost
    CONAN_PKG::gsl_microsoft
    CONAN_PKG::mongo-cxx-driver
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}
)

enable_testing()
add_subdirectory(model)
add_subdirectory(view)
add_subdirectory(controller)
add_subdirectory(api)

