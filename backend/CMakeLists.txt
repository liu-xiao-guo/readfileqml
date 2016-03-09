include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
    ReadFileQMLbackend_SRCS
    modules/ReadFileQML/backend.cpp
    modules/ReadFileQML/mytype.cpp
    modules/ReadFileQML/fileio.cpp
)

add_library(ReadFileQMLbackend MODULE
    ${ReadFileQMLbackend_SRCS}
)

set_target_properties(ReadFileQMLbackend PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY ReadFileQML)

qt5_use_modules(ReadFileQMLbackend Gui Qml Quick)

# Copy qmldir file to build dir for running in QtCreator
add_custom_target(ReadFileQMLbackend-qmldir ALL
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/modules/ReadFileQML/qmldir ${CMAKE_CURRENT_BINARY_DIR}/ReadFileQML
    DEPENDS ${QMLFILES}
)

# Install plugin file
install(TARGETS ReadFileQMLbackend DESTINATION ${QT_IMPORTS_DIR}/ReadFileQML/)
install(FILES   modules/ReadFileQML/qmldir DESTINATION ${QT_IMPORTS_DIR}/ReadFileQML/)

