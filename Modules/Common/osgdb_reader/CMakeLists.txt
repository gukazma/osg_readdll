set(TARGET_NAME "osgdb_reader")

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE HPP_FILES "*.hpp")
file(GLOB_RECURSE CPP_FILES "*.cpp")

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${HPP_FILES} ${CPP_FILES})

add_library(${TARGET_NAME} SHARED ${HEADER_FILES} ${CPP_FILES} ${HEADER_FILES} ${HPP_FILES})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER Modules)

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

target_compile_definitions(${TARGET_NAME} PRIVATE DLL_EXPORTS)


find_package(OpenSceneGraph REQUIRED)
# Link dependencies    
target_link_libraries(${TARGET_NAME} 
    PUBLIC
    CONAN_PKG::openscenegraph
          )

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
add_compile_definitions(${OPENSCENEGRAPH_COMPILE_DEFINITIONS})
set_target_properties(${TARGET_NAME}
    PROPERTIES
        FOLDER Modules
)