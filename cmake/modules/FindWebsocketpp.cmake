########################################################################
# CMake module for finding Websocketpp
#
# The following variables will be defined:
#
#  WEBSOCKETPP_FOUND
#  WEBSOCKETPP_INCLUDE_DIRS

# Set required variables
if (NOT "$ENV{WEBSOCKETPP_ROOT_DIR}" STREQUAL "")
    set(WEBSOCKETPP_INCLUDE_DIRS "$ENV{WEBSOCKETPP_ROOT_DIR}" CACHE INTERNAL "Copied from environment")
else()
    set(WEBSOCKETPP_INCLUDE_DIRS "" CACHE PATH "Where is the WEBSOCKETPP root directory located?")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Websocketpp DEFAULT_MSG WEBSOCKETPP_INCLUDE_DIRS)