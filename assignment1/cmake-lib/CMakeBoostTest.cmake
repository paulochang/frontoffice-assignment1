message("** CMakeBoostTest ..... Loading")

# Some boost doc: 
# http://www.boost.org/doc/libs/1_60_0/libs/test/doc/html/boost_test/usage_variants.html#boost_test.usage_variants.shared_lib
# http://www.boost.org/doc/libs/1_60_0/libs/test/doc/html/boost_test/section_faq.html#boost_test.section_faq.how_to_set_up_a_cmake_project_us

include(CMakeParseArguments)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

enable_testing()

function (boost_test_project)
	
	cmake_parse_arguments(
        PARSED_ARGS # prefix of output variables
        "" # list of names of the boolean arguments (only defined ones will be true)
        "NAME" # list of names of mono-valued arguments
        "DEPS" # list of names of multi-valued arguments (output variables are lists)
        ${ARGN} # arguments of the function to parse, here we take the all original ones
    )

    if(NOT PARSED_ARGS_NAME)
        message(FATAL_ERROR "You must provide a name")
    endif(NOT PARSED_ARGS_NAME)
    
    # find boost libraries and add includes
	if(Boost_FOUND)
  		include_directories(${Boost_INCLUDE_DIRS})
  	else()
  		message("Boost was not found !!!")
  	endif()
	
	message("--> Creating boost test project: " ${PARSED_ARGS_NAME})
	
	
	project (${PARSED_ARGS_NAME})
	
	# use this for use #include statement from previous folder
	include_directories(..) 

	file(GLOB SRC_FILES  ${CXX_FILE_EXTENSIONS})
	add_executable(${PARSED_ARGS_NAME}  ${SRC_FILES})
	target_link_libraries(${PARSED_ARGS_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

	foreach(lib_dep ${PARSED_ARGS_DEPS})
        target_link_libraries(${PARSED_ARGS_NAME} ${lib_dep})
    endforeach(lib_dep)
	
endfunction(boost_test_project)
message("** CMakeBoostTest ..... Loaded")