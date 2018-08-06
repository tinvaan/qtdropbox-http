add_executable(http
    endpoints.cpp
    dropboxrequest.cpp
    dropboxauth.cpp
    main.cpp)
target_link_libraries(http Qt5::Core Qt5::Network)
