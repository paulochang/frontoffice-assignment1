message("** CMakeAuxFunctions ..... Loading")

include(CMakeParseArguments)
function (create_library)
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
        LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
  	endif(Boost_FOUND)

  	# discover header files from current folder
	include_directories(.)

    # include all CXX_FILE_EXTENSIONS files placed in current folder inside the current folder
	file(GLOB SRC_FILES  ${CXX_FILE_EXTENSIONS})
	add_library(${PARSED_ARGS_NAME} SHARED ${SRC_FILES} )

    # add all PARSED_ARGS_DEPS as libraries to link with
    foreach(lib_dep ${PARSED_ARGS_DEPS})
        set(DEP_PPRINT  "${DEP_PPRINT} ${lib_dep} ")
        target_link_libraries(${PARSED_ARGS_NAME} ${lib_dep})
    endforeach(lib_dep)

    # print & quit
	message("+ Create '" ${PARSED_ARGS_NAME} "' library depending on [" ${DEP_PPRINT} "]")
endfunction(create_library)

message("** CMakeAuxFunctions ..... Loaded")

