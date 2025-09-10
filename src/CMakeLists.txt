add_library(app
	app.h
	app_impl.h
	app_impl.cxx
)

include_directories(${CMAKE_SOURCE_DIR}/lru)

target_link_libraries(app
	lru
)

add_executable(bach-algo-implementaion
	main.cxx
)

target_link_libraries(bach-algo-implementaion
	app
)

