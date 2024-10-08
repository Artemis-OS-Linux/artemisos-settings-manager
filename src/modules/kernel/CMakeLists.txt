cmake_policy(SET CMP0063 NEW)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Common
file(GLOB KERNEL_GLOB
     msm_kernel.desktop
     changelogs/linux34.html
     changelogs/linux38.html
     changelogs/linux310.html
     changelogs/linux311.html
     changelogs/linux312.html
     changelogs/linux313.html
     changelogs/linux314.html
     changelogs/linux315.html
     changelogs/linux316.html
     changelogs/linux317.html
     changelogs/linux318.html
     changelogs/linux319.html
     changelogs/linux40.html
     changelogs/linux41.html
     changelogs/linux42.html
     changelogs/linux43.html
     changelogs/linux44.html
     changelogs/linux45.html
     changelogs/linux46.html
     changelogs/linux47.html
     changelogs/linux48.html
     changelogs/linux49.html
     changelogs/linux410.html
     changelogs/linux411.html
     changelogs/linux412.html
     changelogs/linux413.html
     changelogs/linux414.html
     changelogs/linux415.html
     changelogs/linux416.html
     changelogs/linux417.html
     changelogs/linux418.html
     changelogs/linux419.html
     changelogs/linux420.html
     changelogs/linux50.html
     changelogs/linux51.html
     changelogs/linux52.html
     changelogs/linux53.html
     changelogs/linux54.html
     changelogs/linux55.html
     changelogs/linux56.html
     changelogs/linux57.html
     changelogs/linux510.html
     changelogs/linux511.html
     changelogs/linux512.html
     changelogs/linux513.html
     changelogs/linux514.html
     changelogs/linux515.html
     changelogs/linux516.html
     changelogs/linux517.html
     changelogs/linux518.html
     changelogs/linux519.html
     changelogs/linux60.html
     changelogs/linux61.html
     changelogs/linux62.html
     changelogs/linux63.html
     changelogs/linux64.html
     changelogs/linux65.html
     changelogs/linux66.html)

set(KERNEL_SRCS
    ${KERNEL_GLOB}
    KernelCommon.cpp
    KernelInfoDialog.cpp
    KernelListViewDelegate.cpp)

set(KERNEL_UI
    ui/PageKernel.ui)
qt5_wrap_ui(KERNEL_SRCS ${KERNEL_UI})

set(KERNEL_RESOURCES
    kernel.qrc)
QT5_ADD_RESOURCES (KERNEL_SRCS ${KERNEL_RESOURCES})

# KCM Module
set(KERNEL_KCM_SRCS
    ${KERNEL_SRCS}
    KernelModule.cpp)
add_library(msm_kernel MODULE ${KERNEL_KCM_SRCS})
target_compile_definitions(msm_kernel PRIVATE -DPROJECT_VERSION="${PROJECT_VERSION}")
target_link_libraries(msm_kernel
    msm
    KF5::ConfigWidgets
    KF5::CoreAddons)

install(TARGETS msm_kernel DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES msm_kernel.desktop DESTINATION ${SERVICES_INSTALL_DIR})

# MSM Page
set(KERNEL_PAGE_SRCS
    ${KERNEL_SRCS}
    KernelPage.cpp)

add_library(msm_page_kernel STATIC ${KERNEL_PAGE_SRCS})
target_compile_definitions(msm_page_kernel PRIVATE -DPROJECT_VERSION="${PROJECT_VERSION}")
target_link_libraries(msm_page_kernel
    msm)

# Auth Helper
add_executable(msm_kernel_authhelper KernelAuthHelper.cpp)
target_link_libraries(msm_kernel_authhelper
    KF5::Auth)

install(TARGETS msm_kernel_authhelper DESTINATION ${KAUTH_HELPER_INSTALL_DIR})
kauth_install_helper_files(msm_kernel_authhelper org.manjaro.msm.kernel root)
kauth_install_actions(org.manjaro.msm.kernel msm_kernel.actions)
