########################################################################
# CMake module for finding Libwebsockets
#
# The following variables will be defined:
#
#  LIBWEBSOCKETS_FOUND
#  LIBWEBSOCKETS_INCLUDE_DIRS
#  LIBWEBSOCKETS_LIBRARIES

# Set required variables
if (NOT "$ENV{LIBWEBSOCKETS_ROOT_DIR}" STREQUAL "")
    set(LIBWEBSOCKETS_ROOT_DIR "$ENV{LIBWEBSOCKETS_ROOT_DIR}" CACHE INTERNAL "Copied from environment")
else()
    set(LIBWEBSOCKETS_ROOT_DIR "" CACHE PATH "Where is the LIBWEBSOCKETS root directory located?")
endif()

find_path(LIBWEBSOCKETS_INCLUDE_DIRS
	NAMES libwebsockets.h
	HINTS ${LIBWEBSOCKETS_ROOT_DIR}/build/include
)

find_library(LIBWEBSOCKETS_LIBRARIES
	NAMES libwebsockets.a libwebsockets.lib
	HINTS ${LIBWEBSOCKETS_ROOT_DIR}/build/lib/Release
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Libwebsockets DEFAULT_MSG LIBWEBSOCKETS_LIBRARIES LIBWEBSOCKETS_INCLUDE_DIRS)