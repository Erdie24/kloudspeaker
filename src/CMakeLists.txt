set(kloudspeaker_SRCS
    main.cpp
    kloudspeakerwindow.cpp
    kloudspeakerview.cpp
)

ecm_qt_declare_logging_category(kloudspeaker_SRCS
    HEADER kloudspeakerdebug.h
    IDENTIFIER KLOUDSPEAKER
    CATEGORY_NAME "kloudspeaker"
)
kconfig_add_kcfg_files(kloudspeaker_SRCS kloudspeakerSettings.kcfgc)
ki18n_wrap_ui(kloudspeaker_SRCS
    kloudspeakerview.ui
    settings.ui
)

add_executable(kloudspeaker ${kloudspeaker_SRCS})

target_link_libraries(kloudspeaker
    KF5::CoreAddons
    KF5::I18n
    KF5::XmlGui
    KF5::ConfigWidgets
    KF5::DBusAddons
    KF5::Crash
    Qt5::Widgets
)

install(TARGETS kloudspeaker ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
install(PROGRAMS org.example.kloudspeaker.desktop  DESTINATION ${KDE_INSTALL_APPDIR})
install(FILES org.example.kloudspeaker.appdata.xml DESTINATION ${KDE_INSTALL_METAINFODIR})
install(FILES kloudspeakerui.rc DESTINATION ${KDE_INSTALL_KXMLGUI5DIR}/kloudspeaker)
