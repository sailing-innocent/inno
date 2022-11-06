set(ENGINE_ROOT_DIR "${INNO_ROOT_DIR}/engine")
set(THIRD_PARTY_DIR "${ENGINE_ROOT_DIR}/3rdparty")
set(ENGINE_ASSET_DIR "/asset")
set(LIBSAIL_DIR "D:/repos/sail/build/Debug/")
set(LIBSAIL_INCLUDE "D:/repos/sail/include/")
set(LIBING_DIR "D:/repos/ing/build/Debug/")
set(LIBING_INCLUDE "D:/repos/ing/include/")

set(DEPLOY_CONFIG_DIR "configs/deployment")
set(DEVELOP_CONFIG_DIR "configs/development")

option(ENABLE_PHYSICS_DEBUG_RENDER "Enable Physics Debug Renderer" OFF)

#only suport physics debug render at window platform
if (NOT WIN32)
endif()


if (ENABLE_PHYSICS_DEBUG_RENDER)
    set(JOLT_ASSET_DIR "/jolt-asset")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/MP")
    set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT InnoEditor)
endif()

set(vulakn_include "E:/sdk/Vulkan/Include/")

if (WIN32)
    set(vulkan_lib "E:/sdk/Vulkan/Lib/vulkan-1.lib")
    set(glslangValidator_executable "E:/sdk/Vulkan/Bin/glslangValidator.exe")
    add_compile_definitions("E:/sdk/Vulkan/Bin/")
endif()

set(SHADER_COMPILE_TARGET InnoShaderCompile)
add_subdirectory(shader)
# add_subdirectory(3rdparty)
add_subdirectory(source/runtime)
add_subdirectory(source/editor)
# add_subdirectory(source/meta_parser)
# add_subdirectory(source/test)

# set(CODEGEN_TARGET "InnoPreCompile")
# include(source/precompile/precompile.cmake)
# set_target_properties("${CODEGEN_TARGET}" PROPERTIES FOLDER "Engine")

# add_dependencies(InnoRuntime "${CODEGEN_TARGET}")
# add_dependencies("${CODEGEN_TARGET}" "InnoParser")
