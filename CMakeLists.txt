# Build like this:
# cd </path/to/jeebox-master>
# cmake -BBuild; cd Build; sudo make install

cmake_minimum_required(VERSION 3.4)
project(Jeebox VERSION 1.2.3 DESCRIPTION "Extensible language to describe anything. The ultimate life-form of parsers.")

set(Root ${CMAKE_SOURCE_DIR})
set(JbCpp ${Root}/Cpp)
set(Exmp ${Root}/Examples/)

#set(ARCH -m32)
#set(ARCH -arch i386 -arch x86_64)
file(GLOB MainSrc ${JbCpp}/LibSrc/*.cpp)
set(MainSrc ${MainSrc} ${JbCpp}/JB.cpp)
set(AllocSrc ${JbCpp}/LibSrc/JB_Alloc.cpp)


set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS YES CACHE BOOL "Export all symbols")

add_compile_definitions(TARGET_UNIX=1 AS_LIBRARY=1)
add_compile_options(${ARCH} -Wno-return-type-c-linkage -Wno-invalid-source-encoding -std=gnu++1y -stdlib=libc++ -fno-strict-aliasing -fvisibility=hidden -march=core2 -mfpmath=sse -mmmx -msse -msse2 -msse4.1 -msse4.2 -mtune=native -Os)
add_link_options(${ARCH} -flto)

#message( "${MainSrc}" )
#message( "${JbCpp}/LibSrc" )


function (BuildLibrary Name Type Arch)
	add_library(${Name} 			   		${Type} ${MainSrc})
	set_target_properties(${Name}  			PROPERTIES VERSION ${PROJECT_VERSION})
	target_compile_options(${Name} PUBLIC ${Arch})
	set_target_properties(${Name} 			PROPERTIES PUBLIC_HEADER "${Exmp}jeebox_api.h;${Exmp}Jeebox.h")
	target_include_directories(${Name} 		PRIVATE ${JbCpp}/LibSrc)
	install(
		TARGETS ${Name}
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		RUNTIME DESTINATION bin
		PUBLIC_HEADER DESTINATION /usr/local/include
	)
endfunction()

BuildLibrary(JeeboxStatic STATIC "")        		    #64-bit is the default?
BuildLibrary(Jeebox SHARED "")
BuildLibrary(JeeboxStatic_32 STATIC "-m32")
#BuildLibrary(Jeebox_32 SHARED "-m32")



add_executable(example_xml ${Root}/Examples/xml.cpp)
target_link_libraries(example_xml JeeboxStatic) 		# test static

add_executable(example_test ${Root}/Examples/test.cpp)
target_link_libraries(example_test Jeebox)				# test dynamic

add_executable(example_userlist ${Root}/Examples/users.cpp)
target_link_libraries(example_userlist Jeebox)


add_executable(jb ${Root}/Examples/jb.cpp)
target_link_libraries(jb Jeebox)
install( TARGETS jb RUNTIME DESTINATION bin )


message( "${AllocSrc}" )
#[[
add_library(JBAlloc	 		   		STATIC ${AllocSrc})
target_include_directories(JBAlloc 	PRIVATE ${JbCpp}/LibSrc)
set_target_properties(JBAlloc  		PROPERTIES VERSION ${PROJECT_VERSION})
install(
	TARGETS JBAlloc
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	PUBLIC_HEADER DESTINATION /usr/local/include
)
]]


add_executable(alloc_speed ${Root}/Examples/alloc_speed.cpp ${AllocSrc})
target_compile_definitions(alloc_speed PUBLIC ALLOCATOR_ONLY=1) # seems to break everything?
target_include_directories(alloc_speed 	PRIVATE ${JbCpp}/LibSrc)


#lipo bin.darwin100x86/p4 bin.darwin100x86_64/p4 -create -output /tmp/p4