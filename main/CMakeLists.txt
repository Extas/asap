# -----------------------------------------------------
# Meta information about this module
# -----------------------------------------------------
set(MODULE_NAME "main_module_name")

asap_push_module(${MODULE_NAME})
asap_declare_module(
        MODULE_NAME
        ${MODULE_NAME}
        DESCRIPTION
        "Main module for the `project_name` program"
        GITHUB_REPO
        "https://github.com/extas/project_name"
        AUTHOR_MAINTAINER
        "Extas"
        VERSION_MAJOR
        "1"
        VERSION_MINOR
        "0"
        VERSION_PATCH
        "0")

# =====================================================
# Build instructions
# =====================================================

# -----------------------------------------------------
# Main module target
# -----------------------------------------------------

set(MODULE_TARGET_NAME ${MODULE_NAME})

asap_add_executable(
        ${MODULE_TARGET_NAME}
        WARNING
        SOURCES
        # Sources
        src/main.cpp
        CXX_STANDARD 23)

target_link_libraries(
        ${MODULE_TARGET_NAME}
        PRIVATE
        fmt::fmt
        asap::logging)

target_include_directories(${MODULE_TARGET_NAME} PRIVATE ${CMAKE_BINARY_DIR}/include)
target_include_directories(${MODULE_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${MODULE_TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# =====================================================
# Deployment instructions
# =====================================================

# Executable
install(
        TARGETS ${MODULE_TARGET_NAME}
        RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT programs
        BUNDLE DESTINATION ${INSTALL_BIN} COMPONENT programs)

asap_pop_module(${MODULE_NAME})
