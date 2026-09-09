cmake_minimum_required(VERSION 3.16)
project(fcs_model C)

# Common_lib must be added first — Controller and VMS_model depend on it
add_subdirectory(Common_lib)
add_subdirectory(src/Controller)
add_subdirectory(src/VMS_model)

# Expose the liberliber-generated interface headers to consumers.
# These are NOT compiled — they are the public contract headers only.
add_library(fcs_model_interface INTERFACE)
target_include_directories(fcs_model_interface INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)