cmake_minimum_required(VERSION 3.27)
project(artemisos-settings-manager VERSION 2.0.2)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ECM is required
find_package(ECM 5.249 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(FeatureSummary)
include(ECMInstallIcons)

# Required Qt6 modules
find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    DBus
    LinguistTools
    Qml
)

# Required KDE Frameworks 6 modules
find_package(KF6 REQUIRED COMPONENTS
    CoreAddons
    Auth
    ConfigWidgets
    ItemModels
    Notifications
    KCMUtils
)

# Optional
find_package(ICU REQUIRED)

# Subdirectories
add_subdirectory(resources)
add_subdirectory(src)

# Summary
feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
