project(CurlIntro)

find_package(CURL REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/EasyHandle.cpp
    src/EasyHandleBuilder.cpp
    src/MultiHandle.cpp
    )

target_compile_options(${PROJECT_NAME}
    PRIVATE -fexceptions -Wall -Wextra -Wshadow -Wnon-virtual-dtor
    PRIVATE -pedantic
    PRIVATE -Wall
    PRIVATE -Wshadow
    PRIVATE -Wnon-virtual-dtor
    PRIVATE -Wold-style-cast
    PRIVATE -Wcast-align
    PRIVATE -Wunused
    PRIVATE -Woverloaded-virtual
    PRIVATE -Wpedantic
    PRIVATE -Wconversion
    PRIVATE -Wsign-conversion
    PRIVATE -Wmisleading-indentation
    PRIVATE -Wduplicated-cond
    PRIVATE -Wduplicated-branches
    PRIVATE -Wlogical-op
    PRIVATE -Wnull-dereference
    PRIVATE -Wuseless-cast
    PRIVATE -Wdouble-promotion
    PRIVATE -Wformat=2
    #PRIVATE -Wlifetime
    PRIVATE -Wimplicit-fallthrough
    )

target_link_libraries(${PROJECT_NAME}
    ${CURL_LIBRARIES}
    )

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CURL_INCLUDE_DIR}
    )

