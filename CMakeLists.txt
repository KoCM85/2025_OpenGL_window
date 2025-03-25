cmake_minimum_required(VERSION 3.28)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 1)
set(VERSION_PATCH 10)

project(OpenGL_window LANGUAGES C CXX VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

find_package(OpenGL REQUIRED)

if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
	set(PROJ_PLATFORM x64)
else()
	set(PROJ_PLATFORM x86)
endif()

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
	set(PROJ_GRAPHIC D:/Sources/Graphic/OpenGL)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
	set(PROJ_GRAPHIC /Users/user/Documents/Sources/Graphic/OpenGL)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
	set(PROJ_GRAPHIC /home/serg/Documents/Sources/Graphic/OpenGL)
endif()

set(PROJ_TEMP ${CMAKE_SOURCE_DIR}/build)
set(PROJ_SOURCES
	${CMAKE_SOURCE_DIR}/sources/main.cpp
	${PROJ_TEMP}/version.h
	${PROJ_TEMP}/version.cpp
	${PROJ_GRAPHIC}/GLAD2/src/glad.c
)
set(PROJ_INCLUDE_DIR
	${PROJ_GRAPHIC}/GLAD2/include
	${PROJ_GRAPHIC}/GLFW/include
)
set(PROJ_BINARY_DIR ${CMAKE_SOURCE_DIR}/binary/${PROJ_PLATFORM}/$<CONFIG>)
set(PROJ_LINK_DIR ${PROJ_GRAPHIC}/GLFW/lib/${PROJ_PLATFORM}/$<CONFIG>)
set(PROJ_CONFIGURE_FILE_1 ${CMAKE_SOURCE_DIR}/sources/version.cpp_cmake_in)
set(PROJ_RESULTING_FILE_1 ${PROJ_TEMP}/version.cpp)
set(PROJ_CONFIGURE_FILE_2 ${CMAKE_SOURCE_DIR}/sources/version.h_cmake_in)
set(PROJ_RESULTING_FILE_2 ${PROJ_TEMP}/version.h)
set(PROJ_LINK_LIB
	glfw3
	OpenGL::GL
)

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
	set(PROJ_LINK_LIB ${PROJ_LINK_LIB}
			"-framework Cocoa"
			"-framework IOKit"
			"-framework QuartzCore")
endif()

option(PROJ_VERSION_PRINT "If selected, project version will be printed, otherwise nope" ON)
option(PROJ_VERSION_DISPL "IF selected, project version will be displayed in the run window" ON)

get_property(PROJ_IS_MULTI_CONFIG GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(PROJ_IS_MULTI_CONFIG)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
endif()

configure_file(${PROJ_CONFIGURE_FILE_1} ${PROJ_RESULTING_FILE_1})
configure_file(${PROJ_CONFIGURE_FILE_2} ${PROJ_RESULTING_FILE_2})

add_executable(${CMAKE_PROJECT_NAME} ${PROJ_SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	${PROJ_INCLUDE_DIR}
	${PROJ_TEMP}
)
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${PROJ_LINK_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} ${PROJ_LINK_LIB})

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED YES)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJ_BINARY_DIR})

if(CMAKE_GENERATOR MATCHES "Visual Studio")
	target_link_options(${CMAKE_PROJECT_NAME} PRIVATE /SUBSYSTEM:WINDOWS /ENTRY:"mainCRTStartup")
endif()

if(PROJ_VERSION_PRINT)
	message("Project version: ${CMAKE_PROJECT_VERSION}")
endif()