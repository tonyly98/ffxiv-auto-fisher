add_executable(main main.cpp)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
find_package( OpenCV REQUIRED )
target_link_libraries(main utilities ${OpenCV_LIBS} )