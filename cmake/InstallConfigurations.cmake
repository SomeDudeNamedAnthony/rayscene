install(
        TARGETS rayscene EXPORT rayscene-targets
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

# PKG_CONFIG_LIBS_PRIVATE is used in raylib.pc.in
if (NOT BUILD_SHARED_LIBS)
    include(LibraryPathToLinkerFlags)
    set(PKG_CONFIG_LIBS_PRIVATE ${GLFW_PKG_LIBS})
    string(REPLACE ";" " " PKG_CONFIG_LIBS_PRIVATE "${raylib_LIBRARIES}")
elseif (BUILD_SHARED_LIBS)
    set(PKG_CONFIG_LIBS_EXTRA "")
endif ()

join_paths(libdir_for_pc_file "\${exec_prefix}" "${CMAKE_INSTALL_LIBDIR}")
join_paths(includedir_for_pc_file "\${prefix}" "${CMAKE_INSTALL_INCLUDEDIR}")
configure_file(../rayscene.pc.in rayscene.pc @ONLY)
configure_file(../cmake/rayscene-config-version.cmake rayscene-config-version.cmake @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/rayscene.pc DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/rayscene-config-version.cmake DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/rayscene")
install(FILES ${PROJECT_SOURCE_DIR}/../cmake/rayscene-config.cmake DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/rayscene")

# populates raylib_{FOUND, INCLUDE_DIRS, LIBRARIES, LDFLAGS, DEFINITIONS}
include(PopulateConfigVariablesLocally)
populate_config_variables_locally(rayscene)
