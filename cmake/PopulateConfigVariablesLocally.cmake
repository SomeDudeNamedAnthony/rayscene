macro(populate_config_variables_locally target)
  get_property(rayscene_INCLUDE_DIRS TARGET ${target} PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
  #get_property(rayscene_LIBRARIES    TARGET ${target} PROPERTY LOCATION) # only works for SHARED
  get_property(rayscene_LDFLAGS      TARGET ${target} PROPERTY INTERFACE_LINK_LIBRARIES)
  get_property(rayscene_DEFINITIONS  TARGET ${target} PROPERTY DEFINITIONS)

  set(rayscene_INCLUDE_DIRS "${rayscene_INCLUDE_DIRS}" PARENT_SCOPE)
  #set(rayscene_LIBRARIES   "${rayscene_INCLUDE_DIRS}" PARENT_SCOPE)
  set(rayscene_LDFLAGS      "${rayscene_LDFLAGS}" PARENT_SCOPE)
  set(rayscene_DEFINITIONS  "${rayscene_DEFINITIONS}" PARENT_SCOPE)
endmacro()
