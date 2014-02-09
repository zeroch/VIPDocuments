cmake_minimum_required (VERSION 2.8)
cmake_policy(SET CMP0011 NEW) #for version 2.6, we need to specify this to remove warnings
#  this "new" setting states that any include or find package commands will by default
#  perform an automatic policy push and pop, to keep these included files from affecting
#  the caller, and callers can use NO_POLICY_SCOPE during the call to turn it off

#
# This builds the ProjectName application, and sets various cache entries.
#
# This file will define the following:
# Required for Users (Only useful for library projects)
#  ProjectName_INCLUDE_DIRS, all include folders needed by users, absolute paths
#  ProjectName_LIBRARIES == ProjectName_RELEASE_LIBRARIES
#  ProjectName_RELEASE_LIBRARIES, filepaths, other project names, or system library names, for all required libraries, including this one
#  ProjectName_DEBUG_LIBRARIES, ...
#
# Used Internally:
#  ProjectName_INCLUDE_DIRS_INTERNAL, internal include dirs, both project and non-project, not for users
#  ProjectName_INCLUDES, full paths to project include files
#  ProjectName_SOURCE_DIRS, project source dirs
#  ProjectName_SOURCES, full paths to project source files

#StandardBuild
#  all list params are to be passed in as "${list}", i.e. already expanded and quoted
function (StandardBuild project_name                 # Name of Project
                        build_type                   # "executable", "library" (type set from the variable BUILD_SHARED_LIBS), "static_library", or "shared_library"
                        # include directories from this project
                        #   user include dirs (used to create ProjectName_INCLUDE_DIRS)
                        include_dirs_list_relative   #     RELATIVE TO CMAKE_CURRENT_SOURCE_DIR (automatically prefixed with CMAKE_CURRENT_SOURCE_DIR)
                        #   internal-only include dirs (used to create ProjectName_INCLUDE_DIRS_INTERNAL)
                        include_dirs_list_relative_internal   #   RELATIVE TO CMAKE_CURRENT_SOURCE_DIR (automatically prefixed with CMAKE_CURRENT_SOURCE_DIR)
                        # include files from this project (used to create ProjectName_INCLUDES)
                        include_filepaths_list_relative   # filenames of all project include files, relative to the paths in include_dirs_list_relative and include_dirs_list_relative_internal_absolute
                        # include directories from outside this project
                        #   user include dirs from outside this project  (used to create ProjectName_INCLUDE_DIRS)
                        include_dirs_list_absolute   #     absolute paths (other project's expanded ${ProjectName_INCLUDE_DIRS})
                        #   internal-only include dirs from outside this project  (used to create ProjectName_INCLUDE_DIRS_INTERNAL)
                        include_dirs_list_absolute_internal   #   absolute paths (other project's expanded ${ProjectName_INCLUDE_DIRS})
                        # source directories from this project (used to create ProjectName_SOURCE_DIRS)
                        source_dirs_list_relative   #   RELATIVE TO CMAKE_CURRENT_SOURCE_DIR (automatically prefixed with CMAKE_CURRENT_SOURCE_DIR)
                        # source files from this project (used to create ProjectName_SOURCES)
                        source_filepaths_list_relative   # filenames of all project source files, relative to the paths in source_dirs_list_relative
                        # libraries to link with
                        libraries_list                     #for both release and debug
                        libraries_release_list             #for release only
                        libraries_debug_list               #for debug only
                        )


###############  Project Name  ############
project( ${project_name} )
###########################################elseif(library STREQUAL ${build_type})

################  Includes  ##############
#  setup ProjectName_INCLUDE_DIRS
foreach (d ${include_dirs_list_relative})
  set ( include_dirs_list_relative_absolute ${include_dirs_list_relative_absolute} ${CMAKE_CURRENT_SOURCE_DIR}/${d})
endforeach (d)
#message(STATUS "include_dirs_list_relative_absolute = ${include_dirs_list_relative_absolute}")
if ( include_dirs_list_relative_absolute )
	list ( REMOVE_DUPLICATES include_dirs_list_relative_absolute )
endif ( include_dirs_list_relative_absolute )
set ( ${project_name}_include_dirs_list_absolute ${include_dirs_list_absolute} )
if ( ${project_name}_include_dirs_list_absolute  )
	list ( REMOVE_DUPLICATES ${project_name}_include_dirs_list_absolute  )
endif ( ${project_name}_include_dirs_list_absolute  )
set ( ${project_name}_INCLUDE_DIRS ${include_dirs_list_relative_absolute} ${${project_name}_include_dirs_list_absolute} CACHE INTERNAL "required user include folders" )
#  setup ProjectName_INCLUDE_DIRS_INTERNAL
foreach (d ${include_dirs_list_relative_internal})
  set ( include_dirs_list_relative_internal_absolute ${include_dirs_list_relative_internal_absolute} ${CMAKE_CURRENT_SOURCE_DIR}/${d})
endforeach (d)
#message(STATUS "include_dirs_list_relative_internal_absolute = ${include_dirs_list_relative_internal_absolute}")
set ( ${project_name}_INCLUDE_DIRS_INTERNAL ${include_dirs_list_relative_internal_absolute} ${include_dirs_list_absolute_internal})
if ( ${project_name}_INCLUDE_DIRS_INTERNAL )
	list ( REMOVE_DUPLICATES ${project_name}_INCLUDE_DIRS_INTERNAL )
endif ( ${project_name}_INCLUDE_DIRS_INTERNAL )
#  setup ProjectName_INCLUDES
foreach(f ${include_filepaths_list_relative})
  find_file( foundfile_cached ${f} PATHS ${include_dirs_list_relative_absolute} ${include_dirs_list_relative_internal_absolute} NO_DEFAULT_PATH )
  set(foundfile ${foundfile_cached}) #let's save the result immediately to a 'normal' variable, and remove the cached result
  unset(foundfile_cached CACHE)      #  allowing a follow up run to always try find_file again (the default will not try again if it already succeeded).
  if(NOT foundfile)
    message(STATUS "foundfile = ${foundfile}")
    message(FATAL_ERROR "Project ${project_name}: Cannot find file ${f}")
  endif(NOT foundfile)
  set( ${project_name}_INCLUDES ${${project_name}_INCLUDES} ${foundfile})
endforeach(f)
message(STATUS "${project_name}_INCLUDES = ${${project_name}_INCLUDES}")

################  Sources  ##############
#  setup ProjectName_SOURCE_DIRS
foreach (d ${source_dirs_list_relative})
  set ( source_dirs_list_relative_absolute ${source_dirs_list_relative_absolute} ${CMAKE_CURRENT_SOURCE_DIR}/${d})
endforeach (d)
message(STATUS "source_dirs_list_relative_absolute = ${source_dirs_list_relative_absolute}")
set ( ${project_name}_SOURCE_DIRS ${source_dirs_list_relative_absolute})
message(STATUS "${project_name}_SOURCE_DIRS = ${${project_name}_SOURCE_DIRS}")
#  setup ProjectName_SOURCES
foreach(f ${source_filepaths_list_relative})
  find_file( foundfile_cached ${f} PATHS ${source_dirs_list_relative_absolute} NO_DEFAULT_PATH )
  set(foundfile ${foundfile_cached}) #let's save the result immediately to a 'normal' variable, and remove the cached result
  unset(foundfile_cached CACHE)      #  allowing a follow up run to always try find_file again (the default will not try again if it already succeeded).
  if(NOT foundfile)
    message(STATUS "foundfile = ${foundfile}")
    message(FATAL_ERROR "Project ${project_name}: Cannot find file ${f}")
  endif(NOT foundfile)
  set( ${project_name}_SOURCES ${${project_name}_SOURCES} ${foundfile})
endforeach(f)
message(STATUS "${project_name}_SOURCES = ${${project_name}_SOURCES}")

################  Libraries  ##############
#  setup ProjectName_LIBRARIES, ProjectName_RELEASE_LIBRARIES, ProjectName_DEBUG_LIBRARIES
#    set the internal variabls to match the inputs
set ( ${project_name}_release_libs ${libraries_list} ${libraries_release_list})
if ( ${project_name}_release_libs )
	list ( REMOVE_DUPLICATES ${project_name}_release_libs )
endif ( ${project_name}_release_libs )

set ( ${project_name}_debug_libs ${libraries_list} ${libraries_debug_list})
if ( ${project_name}_debug_libs )
	list ( REMOVE_DUPLICATES ${project_name}_debug_libs )
endif ( ${project_name}_debug_libs )

#    set the user variables to also include this project's name
set ( ${project_name}_RELEASE_LIBRARIES ${project_name} ${${project_name}_release_libs} CACHE INTERNAL "required release libraries")
set ( ${project_name}_DEBUG_LIBRARIES ${project_name} ${${project_name}_debug_libs} CACHE INTERNAL "required debug libraries")
set ( ${project_name}_LIBRARIES ${${project_name}_RELEASE_LIBRARIES} CACHE INTERNAL "required release libraries")

#Finally, literally, add these requirements into a new CMake target
#  include dirs
include_directories( ${${project_name}_INCLUDE_DIRS} ${${project_name}_INCLUDE_DIRS_INTERNAL} )
message(STATUS "${project_name}: include_directories = ${${project_name}_INCLUDE_DIRS} ${${project_name}_INCLUDE_DIRS_INTERNAL}")
#  create projects from sources
#    add the sources and headers, some IDE's will show them all
if(executable STREQUAL ${build_type})
  message(STATUS "${project_name}: add executable")
  add_executable(${project_name} ${${project_name}_SOURCES} ${${project_name}_INCLUDES} )
elseif(library STREQUAL ${build_type})
  message(STATUS "${project_name}: add library")
  add_library(${project_name} ${${project_name}_SOURCES} ${${project_name}_INCLUDES} )
elseif(static_library STREQUAL ${build_type})
  message(STATUS "${project_name}: add static library")
  add_library(${project_name} STATIC ${${project_name}_SOURCES} ${${project_name}_INCLUDES} )
elseif(shared_library STREQUAL ${build_type})
  message(STATUS "${project_name}: add shared library")
  add_library(${project_name} SHARED ${${project_name}_SOURCES} ${${project_name}_INCLUDES} )
endif(executable STREQUAL ${build_type})
#  link
message(STATUS "${project_name}: release libraries = ${${project_name}_release_libs}")
foreach(f ${${project_name}_release_libs})
  target_link_libraries(${project_name} optimized ${f})
endforeach(f)
message(STATUS "${project_name}: debug libraries = ${${project_name}_debug_libs}")
foreach(f ${${project_name}_debug_libs} )
  target_link_libraries(${project_name} debug ${f})
endforeach(f)
#  target properties
#    filename
set_target_properties(${project_name} PROPERTIES OUTPUT_NAME_RELEASE ${project_name})
set_target_properties(${project_name} PROPERTIES OUTPUT_NAME_DEBUG ${project_name}d )
#    directories
#      we need to set the non-configuration specific variables for linux (single config build),
#      and the specific ones for windows (multi-config build)
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin32)
  set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin32)
  set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin32)
  set_target_properties(${project_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib32)
  set_target_properties(${project_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib32)
  set_target_properties(${project_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib32)
  set_target_properties(${project_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib32)
  set_target_properties(${project_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib32)
  set_target_properties(${project_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib32)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin64)
  set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin64)
  set_target_properties(${project_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin64)
  set_target_properties(${project_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib64)
  set_target_properties(${project_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib64)
  set_target_properties(${project_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib64)
  set_target_properties(${project_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib64)
  set_target_properties(${project_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib64)
  set_target_properties(${project_name} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib64)
endif(CMAKE_SIZEOF_VOID_P EQUAL 4)
#  install location
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
  install(TARGETS ${project_name} RUNTIME DESTINATION bin32 LIBRARY DESTINATION lib32 ARCHIVE DESTINATION lib32)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
  install(TARGETS ${project_name} RUNTIME DESTINATION bin64 LIBRARY DESTINATION lib64 ARCHIVE DESTINATION lib64)
endif(CMAKE_SIZEOF_VOID_P EQUAL 4)

endfunction(StandardBuild)


#StandardBuild_withFiles
#  This is exactly the same as StandardBuild, except that you can setup config, resource, and output files.
#  all list params are to be passed in as "${list}", i.e. already expanded and quoted
function (StandardBuild_withFiles project_name                 # Name of Project
                        build_type                   # "executable", "library" (type set from the variable BUILD_SHARED_LIBS), "static_library", or "shared_library"
                        # include directories from this project
                        #   user include dirs (used to create ProjectName_INCLUDE_DIRS)
                        include_dirs_list_relative   #     RELATIVE TO CMAKE_CURRENT_SOURCE_DIR (automatically prefixed with CMAKE_CURRENT_SOURCE_DIR)
                        #   internal-only include dirs (used to create ProjectName_INCLUDE_DIRS_INTERNAL)
                        include_dirs_list_relative_internal   #   RELATIVE TO CMAKE_CURRENT_SOURCE_DIR (automatically prefixed with CMAKE_CURRENT_SOURCE_DIR)
                        # include files from this project (used to create ProjectName_INCLUDES)
                        include_filepaths_list_relative   # filenames of all project include files, relative to the paths in include_dirs_list_relative and include_dirs_list_relative_internal_absolute
                        # include directories from outside this project
                        #   user include dirs from outside this project  (used to create ProjectName_INCLUDE_DIRS)
                        include_dirs_list_absolute   #     absolute paths (other project's expanded ${ProjectName_INCLUDE_DIRS})
                        #   internal-only include dirs from outside this project  (used to create ProjectName_INCLUDE_DIRS_INTERNAL)
                        include_dirs_list_absolute_internal   #   absolute paths (other project's expanded ${ProjectName_INCLUDE_DIRS})
                        # source directories from this project (used to create ProjectName_SOURCE_DIRS)
                        source_dirs_list_relative   #   RELATIVE TO CMAKE_CURRENT_SOURCE_DIR (automatically prefixed with CMAKE_CURRENT_SOURCE_DIR)
                        # source files from this project (used to create ProjectName_SOURCES)
                        source_filepaths_list_relative   # filenames of all project source files, relative to the paths in source_dirs_list_relative
                        # libraries to link with
                        libraries_list                     #for both release and debug
                        libraries_release_list             #for release only
                        libraries_debug_list               #for debug only
						#files and/or directories, placed inside the binary folders for output/install, 
						#  originals copied to binary dir, binary copies are copied to install
						config_list_relative               #config folder
						resource_list_relative             #resource folder
						output_list_relative               #output folder
                        )

StandardBuild("${project_name}"
              "${build_type}"
			  "${include_dirs_list_relative}"
			  "${include_dirs_list_relative_internal}"
			  "${include_filepaths_list_relative}"
			  "${include_dirs_list_absolute}"
			  "${include_dirs_list_absolute_internal}"
			  "${source_dirs_list_relative}"
			  "${source_filepaths_list_relative}"
			  "${libraries_list}"
			  "${libraries_release_list}"
			  "${libraries_debug_list}")

#set directory paths
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
  set(rel_config_dir bin32/config)
  set(rel_resource_dir bin32/resource)
  set(rel_output_dir bin32/output)
  set(binary_config_dir ${CMAKE_BINARY_DIR}/bin32/config)
  set(binary_resource_dir ${CMAKE_BINARY_DIR}/bin32/resource)
  set(binary_output_dir ${CMAKE_BINARY_DIR}/bin32/output)
  # set(install_config_dir bin32/config)
  # set(install_resource_dir bin32/resource)
  # set(install_output_dir bin32/output)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(rel_config_dir bin64/config)
  set(rel_resource_dir bin64/resource)
  set(rel_output_dir bin64/output)
  set(binary_config_dir ${CMAKE_BINARY_DIR}/bin64/config)
  set(binary_resource_dir ${CMAKE_BINARY_DIR}/bin64/resource)
  set(binary_output_dir ${CMAKE_BINARY_DIR}/bin64/output)
  # set(install_config_dir bin64/config)
  # set(install_resource_dir bin64/resource)
  # set(install_output_dir bin64/output)
endif(CMAKE_SIZEOF_VOID_P EQUAL 4)
			  
#copy files/dirs to binary destination from the input parameter location
#  config
foreach(f ${config_list_relative})
  #only do the copy if the original item exists and the binary copy doesn't already exist (in case the user has changed the binary version already)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${f} AND NOT EXISTS ${binary_config_dir}/${f})
    file(MAKE_DIRECTORY ${binary_config_dir}) #create the output directory, if it doesn't exist already
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${f} DESTINATION ${binary_config_dir}) #copies files or folders into binary folder
  endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${f} AND NOT EXISTS ${binary_config_dir}/${f})
endforeach(f)
#  resource
foreach(f ${resource_list_relative})
  #only do the copy if the original item exists and the binary copy doesn't already exist (in case the user has changed the binary version already)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${f} AND NOT EXISTS ${binary_resource_dir}/${f})
    file(MAKE_DIRECTORY ${binary_resource_dir}) #create the output directory, if it doesn't exist already
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${f} DESTINATION ${binary_resource_dir}) #copies files or folders into binary folder
  endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${f} AND NOT EXISTS ${binary_resource_dir}/${f})
endforeach(f)
#  output
foreach(f ${output_list_relative})
  #only do the copy if the original item exists and the binary copy doesn't already exist (in case the user has changed the binary version already)
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${f} AND NOT EXISTS ${binary_output_dir}/${f})
    file(MAKE_DIRECTORY ${binary_output_dir}) #create the output directory, if it doesn't exist already
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${f} DESTINATION ${binary_output_dir}) #copies files or folders into binary folder
  endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${f} AND NOT EXISTS ${binary_output_dir}/${f})
endforeach(f)

#copy files/dirs to install destination from the binary location
#  config
if(EXISTS ${binary_config_dir})
  install(DIRECTORY ${binary_config_dir}/ DESTINATION ${rel_config_dir}) #note the trailing slash on the input (so it won't append the final directory name to the ouput)
endif(EXISTS ${binary_config_dir})
#  resource
if(EXISTS ${binary_resource_dir})
  install(DIRECTORY ${binary_resource_dir}/ DESTINATION ${rel_resource_dir}) #note the trailing slash on the input (so it won't append the final directory name to the ouput)
endif(EXISTS ${binary_resource_dir})
#  output
if(EXISTS ${binary_output_dir})
  install(DIRECTORY ${binary_output_dir}/ DESTINATION ${rel_output_dir}) #note the trailing slash on the input (so it won't append the final directory name to the ouput)
endif(EXISTS ${binary_output_dir})

endfunction(StandardBuild_withFiles)
