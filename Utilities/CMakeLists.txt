add_library(utilities utilities.cpp utilities.h)
target_include_directories(utilities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
find_package( OpenCV REQUIRED )
target_link_libraries(utilities ${OpenCV_LIBS} )