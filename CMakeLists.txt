# Build like this:
# cd </path/to/jeebox-master>
# cmake -BBuild; cd Build; sudo make

cmake_minimum_required(VERSION 3.4)
project(Jeebox VERSION 1.0.0 DESCRIPTION "Beautiful, extensible language to describe anything. The ultimate life-form of parsers.")

set(Root ${CMAKE_SOURCE_DIR})
set(JbCpp ${Root}/Cpp)
set(Exmp ${Root}/Examples/)

set(ARCH -m32)
file(GLOB MainSrc ${JbCpp}/LibSrc/*.cpp)
set(MainSrc ${MainSrc} ${JbCpp}/JB.cpp)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

add_compile_definitions(TARGET_UNIX=1 AS_LIBRARY=1)
add_compile_options(${ARCH} -Wno-return-type-c-linkage -Wno-invalid-source-encoding -std=gnu++1y -stdlib=libc++ -fno-strict-aliasing -march=core2 -mfpmath=sse -mmmx -msse -msse2 -msse4.1 -msse4.2 -mtune=native -Os)
add_link_options(${ARCH} -flto)

message( "${MainSrc}" )
message( ${JbCpp}/LibSrc )


# It wasnt worth merging these into a func, too many bugs too awkward debug!
add_library(JeeboxStatic 		   		STATIC ${MainSrc})
set_target_properties(JeeboxStatic  	PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(JeeboxStatic 		PROPERTIES PUBLIC_HEADER "${Exmp}jeebox_api.h;${Exmp}Jeebox.h")
target_include_directories(JeeboxStatic PRIVATE ${JbCpp}/LibSrc)
install(
	TARGETS JeeboxStatic
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	PUBLIC_HEADER DESTINATION /usr/local/include
)


add_library(Jeebox 		   			SHARED ${MainSrc})
set_target_properties(Jeebox  		PROPERTIES VERSION ${PROJECT_VERSION})
target_include_directories(Jeebox 	PRIVATE ${JbCpp}/LibSrc)
set_target_properties(Jeebox 		PROPERTIES PUBLIC_HEADER "${Exmp}jeebox_api.h;${Exmp}Jeebox.h")
install(
	TARGETS Jeebox
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	PUBLIC_HEADER DESTINATION /usr/local/include
)


add_executable(xml ${Root}/Examples/xml.cpp)
target_link_libraries(xml JeeboxStatic)

add_executable(test ${Root}/Examples/test.cpp)
target_link_libraries(test Jeebox)


# export.sym? -fvisibility=hidden?
# CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS? we don't want that?

