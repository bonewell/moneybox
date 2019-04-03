cmake_minimum_required(VERSION 3.2)

project(moneybox)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(${PROJECT_NAME}
    "main.cpp"
    "model/db/mongocommand.cpp"
    "model/db/mongofactory.cpp"
    "model/db/mongoquery.cpp"
    "model/field.cpp"
    "model/item.cpp"
    "model/table.cpp"
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
