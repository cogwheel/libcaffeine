########################################################################
# CMake module for finding Asio
#
# The following variables will be defined:
#
#  ASIO_FOUND
#  ASIO_INCLUDE_DIRS

# Set required variables
if (NOT "$ENV{ASIO_ROOT_DIR}" STREQUAL "")
    set(ASIO_ROOT_DIR "$ENV{ASIO_ROOT_DIR}" CACHE INTERNAL "Copied from environment")
else()
    set(ASIO_ROOT_DIR "" CACHE PATH "Where is the ASIO root directory located?")
endif()

find_path(ASIO_INCLUDE_DIRS
	NAMES asio.hpp
	HINTS ${ASIO_ROOT_DIR}/asio/include
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Asio DEFAULT_MSG ASIO_INCLUDE_DIRS)