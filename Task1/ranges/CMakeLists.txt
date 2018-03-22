cmake_minimum_required( VERSION 3.9.4 )


# Their cmake-files are not really appropriate for inclusion.
# I wrap them in my own cmake interface libraries instead
# of calling add_subdirectory()

# select fork of the library
set(FORK_ROOT range-v3-master)    # default. for gcc, clang etc
if(MSVC)
	# MSVC_VERSION 
	#
	# Known version numbers are (as of cmake version 3.11):
	#
	# 1200      = VS  6.0
	# 1300      = VS  7.0
	# 1310      = VS  7.1
	# 1400      = VS  8.0 (v80 toolset)
	# 1500      = VS  9.0 (v90 toolset)
	# 1600      = VS 10.0 (v100 toolset)
	# 1700      = VS 11.0 (v110 toolset)
	# 1800      = VS 12.0 (v120 toolset)
	# 1900      = VS 14.0 (v140 toolset)
	# 1910-1919 = VS 15.0 (v141 toolset)


	if( MSVC_VERSION EQUAL 1900 )
		#use fork with vs2015 patches
		set(FORK_ROOT Range-V3-VS2015-master)
	endif()
	
	# note: at the moment (mar 2018), the fork is not yet stable for vs2017. 
	# TODO revisit this!
endif()


add_library(ranges INTERFACE)

target_sources(ranges INTERFACE 
	# we dont include their sources into our project
)
target_include_directories(ranges INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/${FORK_ROOT}/include
)
message(STATUS "Adding include path ${FORK_ROOT}/include")

target_compile_definitions(ranges INTERFACE
    HAS_CPP_RANGES
)
