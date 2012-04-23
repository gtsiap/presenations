project (hellokdeprogramming)
find_package(KDE4 REQUIRED)
include (KDE4Defaults)
include_directories(${KDE4_INCLUDES} ${QT_INCLUDES})
set(hellokdeprogramming_SRCS
    main.cpp
    hellokdeprogramming.cpp
)
    
qt4_automoc(${hellokdeprogramming_SRCS})
kde4_add_executable(hellokdeprogramming ${hellokdeprogramming_SRCS})
target_link_libraries(hellokdeprogramming ${KDE4_KDEUI_LIBS})
install(TARGETS hellokdeprogramming  ${INSTALL_TARGETS_DEFAULT_ARGS})
