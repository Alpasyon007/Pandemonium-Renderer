# CMake Bulid File
#
# CMake Version
# cmake_minimum_required(VERSION 3.10)

# # Compiler Settings
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# # Set Variables
# set(SOURCE_DIR src)
set(VULKAN_PATH C:/VulkanSDK/1.3.231.1)
set(GLFW_PATH glfw)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${GLFW_PATH})

# Set the project name
# project(PandemoniumRenderer)

# Add the executable
# add_executable(
# 	PandemoniumRenderer
# 	${SOURCE_DIR}/main.cpp
# )

target_sources(
    PandemoniumRenderer
    PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(
    PandemoniumRenderer 
    PRIVATE 
    ${SOURCE_DIR}
    ${VULKAN_PATH}/Include
    ${GLFW_PATH}/include
)

# target_link_libraries(
#     PandemoniumRenderer
#     PRIVATE
#     ${VULKAN_PATH}/Lib/vulkan-1.lib
#     glfw
# )