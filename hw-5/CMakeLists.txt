cmake_minimum_required(VERSION 3.14)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
project(VGraphicEditor VERSION 0.0.${PATCH_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VGraphicEditor
  main.cpp
  GDescriptor.h
  GView.h
  GWindow.h
  MainWindow.h
  GModel.h
  Elements/IGElement.h
  Elements/GElement1.h
  GManager.h
)

include(GNUInstallDirs)
install(TARGETS VGraphicEditor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(VGraphicEditor PUBLIC ${PROJECT_BINARY_DIR})

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT feschenko_n_s@list.ru)
include(CPack)
