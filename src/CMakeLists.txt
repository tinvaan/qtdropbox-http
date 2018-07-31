add_executable(http dropboxhttp.cpp main.cpp)
target_link_libraries(http Qt5::Core Qt5::Network)
