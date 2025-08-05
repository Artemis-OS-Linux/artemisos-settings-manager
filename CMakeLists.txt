cmake_minimum_required(VERSION 3.5...3.27)

project(artemisos-settings-manager VERSION 1.5.7 LANGUAGES C CXX)

# Minimum Qt6 and KF6 versions
set(QT_MIN_VERSION "6.0")
set(KF6_MIN_VERSION "6.0")

# Find ECM (Extra CMake Modules)
find_package(ECM 1.4.0 REQUIRED NO_MODULE)

# Extend module path for KDE macros and modules
set(CMAKE_MODULE_PATH
    ${ECM_MODULE_PATH}
    ${ECM_KDE_MODULE_DIR}
    ${PROJECT_SOURCE_DIR}/cmake
)

# Compiler standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include KDE/ECM modules
include(ECMInstallIcons)
include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)

# Find Qt6 packages required
find_package(Qt6 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    DBus
    LinguistTools
)

# Find KDE Frameworks 6 packages required
find_package(KF6 ${KF6_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons
    Auth
    ConfigWidgets
    ItemModels
    Notifications
    KCMUtils
)

# Find ICU (optional, but recommended)
find_package(ICU REQUIRED)

# Add your project subdirectories
add_subdirectory(resources)
add_subdirectory(src)

# Print summary of required features/packages
feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
