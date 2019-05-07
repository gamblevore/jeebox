# Build like this:
# cd </path/to/jeebox-master>
# cmake -BBuild; cd Build; sudo make install

cmake_minimum_required(VERSION 3.4)
project(Jeebox VERSION 1.1.2 DESCRIPTION "Extensible language to describe anything. The ultimate life-form of parsers.")

set(Root ${CMAKE_SOURCE_DIR})
set(JbCpp ${Root}/Cpp)
set(Exmp ${Root}/Examples/)

set(ARCH -m32)
file(GLOB MainSrc ${JbCpp}/LibSrc/*.cpp)
set(MainSrc ${MainSrc} ${JbCpp}/JB.cpp)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

add_compile_definitions(TARGET_UNIX=1 AS_LIBRARY=1)
add_compile_options(${ARCH} -Wno-return-type-c-linkage -Wno-invalid-source-encoding -std=gnu++1y -stdlib=libc++ -fno-strict-aliasing -fvisibility=hidden -march=core2 -mfpmath=sse -mmmx -msse -msse2 -msse4.1 -msse4.2 -mtune=native -Os)
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
	PUBLIC_HEADER DESTINATION /usr/local/include
)


add_executable(example_xml ${Root}/Examples/xml.cpp)
target_link_libraries(example_xml JeeboxStatic) 		# test static

add_executable(example_test ${Root}/Examples/test.cpp)
target_link_libraries(example_test Jeebox)				# test dynamic

add_executable(example_userlist ${Root}/Examples/users.cpp)
target_link_libraries(example_userlist Jeebox)

add_executable(alloc_speed ${Root}/Examples/alloc_speed.cpp)
target_link_libraries(alloc_speed JeeboxStatic)
target_include_directories(alloc_speed 	PRIVATE ${JbCpp}/LibSrc)

add_executable(jb ${Root}/Examples/jb.cpp)
target_link_libraries(jb Jeebox)
install( TARGETS jb RUNTIME DESTINATION bin )

