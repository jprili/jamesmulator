	# minimum CMake version required
	cmake_minimum_required(VERSION 3.15)
	# Project name, version and description
	project(jamesmulator VERSION 0.1 DESCRIPTION "A discord bot")
	 
	# Add DPP as dependency
	add_subdirectory(
        libs/DPP
    )
	# You can also add any other libs you want to use
	 
	# Create an executable
	add_executable(${PROJECT_NAME}
	    src/main.cpp
		src/cmd/slashCmds.cpp
		src/bot.cpp
	    # your other files...
	)
	 
	# Linking libraries
	target_link_libraries(${PROJECT_NAME}
	    dpp
	    # Add any other libs you want to use here
	)
	 
	# Specify includes
	target_include_directories(${PROJECT_NAME} PRIVATE
	    libs/DPP/include
	    # Remember to add the include directories of any other libraries too
	)
	 
	# Set C++ version
	set_target_properties(${PROJECT_NAME} PROPERTIES
	    CXX_STANDARD 20
	    CXX_STANDARD_REQUIRED ON
	)