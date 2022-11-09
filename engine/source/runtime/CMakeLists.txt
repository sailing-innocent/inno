set(TARGET_NAME InnoRuntime)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add library json11
file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${SOURCE_FILES})

add_library(${TARGET_NAME} ${HEADER_FILES} ${SOURCE_FILES})

list(APPEND RUNTIME_LIBS_DIR
    ${LIBSAIL_DIR}
    ${LIBING_DIR}
    "E:/libs/glfw"
    "E:/sdk/Vulkan/Lib"
    "E:/libs/spdlog/"
)

list(APPEND RUNTIME_INCLUDE
    ${LIBSAIL_INCLUDE}
    ${LIBING_INCLUDE}
    "E:/libs/eigen/"
    "E:/sdk/Vulkan/Include"
    "E:/includes"
    "include"
)

list(APPEND RUNTIME_LIBS
    "glfw3"
    "vulkan-1"
    "libsail" 
    "libing"
    "spdlogd"
)

target_link_directories(${TARGET_NAME} PUBLIC ${RUNTIME_LIBS_DIR})
target_link_libraries(${TARGET_NAME} PUBLIC ${RUNTIME_LIBS})
target_include_directories(${TARGET_NAME} PUBLIC ${RUNTIME_INCLUDE})

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/source/>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
)


# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

# link libraries

string(TOLOWER ${TARGET_NAME}/version.h VERSION_HEADER_LOCATION)

set(INNO_RUNTIME_HEADS "${HEADER_FILES}" PARENT_SCOPE)
