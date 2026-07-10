add_executable(otmatrix main_app.cpp)

target_compile_features(otmatrix PUBLIC cxx_std_20)

target_link_libraries(otmatrix PRIVATE
                        matrix::matrix
)

if (MSVC)
    target_compile_options(otmatrix PRIVATE /W4)
else()
    target_compile_options(otmatrix PRIVATE -Wall -Wextra -pedantic -Werror)
endif()


# Installation

install(TARGETS otmatrix RUNTIME DESTINATION bin)