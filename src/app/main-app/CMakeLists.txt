add_executable(main-app main_app.cpp)

target_compile_features(main-app PUBLIC cxx_std_20)

target_link_libraries(main-app PRIVATE
                        matrix::matrix
)

if (MSVC)
    target_compile_options(main-app PRIVATE /W4)
else()
    target_compile_options(main-app PRIVATE -Wall -Wextra -pedantic -Werror)
endif()


# Installation

install(TARGETS main-app RUNTIME DESTINATION bin)