project(BitManip VERSION 1.0.0)

add_library(BitManip INTERFACE)
target_include_directories(BitManip
	INTERFACE
		"${CMAKE_CURRENT_SOURCE_DIR}"
)
add_library(BitManip::BitManip ALIAS BitManip)
