add_executable(pulso main.cpp)

target_compile_features(pulso PRIVATE cxx_std_17)

target_include_directories(pulso PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_options(pulso PRIVATE -Wall -Wextra -Wpedantic -O2)