# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.5)

project("opencvsharp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SOURCE FILES
set(OPENCVSHARP_FILES
        core.cpp
        imgproc.cpp
        utils.cpp
        native-lib.cpp
        )

add_library( # Sets the name of the library.
        opencvsharp

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${OPENCVSHARP_FILES})

set(OpenCV_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../../opencv/native/jni")


set(OpenCV_STATIC ON)
find_package(OpenCV REQUIRED COMPONENTS core imgproc)

#add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE opencv_core opencv_imgproc)

# Declares and names the project.

#project("opencvsharp")
#
### headerファイルのセット
##set( OPENCV_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/OpenCV/native/jni/include")
##
##add_library(
##        lib_opencv
##        STATIC
##        IMPORTED
##)
##set( OPENCV_LIB_DIR "${PROJECT_SOURCE_DIR}/OpenCV/native/staticlibs ")
##
##set_target_properties(
##        lib_opencv
##        PROPERTIES IMPORTED_LOCATION
##        ${OPENCV_LIB_DIR}/${CMAKE_ANDROID_ARCH_ABI}/
##)
#
## Creates and names a library, sets it as either STATIC
## or SHARED, and provides the relative paths to its source code.
## You can define multiple libraries, and CMake builds them for you.
## Gradle automatically packages shared libraries with your APK.
#
## cppファイルすべて読み込む
##file(GLOB OPENCVSHARP_FILES *.cpp)
#
## SOURCE FILES
#set(OPENCVSHARP_FILES
#        core.cpp
#        imgproc.cpp
#        utils.cpp
#        )
#
#add_library( # Sets the name of the library.
#        opencvsharp
#
#        # Sets the library as a shared library.
#        SHARED
#
#        # Provides a relative path to your source file(s).
#        ${OPENCVSHARP_FILES})
#
#set(OpenCV_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../../opencv/native/jni")
#
#
#
## Opencvのdirを集めてくる
#find_package(OpenCV 4.7 REQUIRED COMPONENTS core imgproc)
##if(OpenCV_FOUND)
##    target_include_directories( opencvsharp PUBLIC ${OpenCV_INCLUDE_DIRS} )
#target_link_libraries(opencvsharp ${OpenCV_LIBRARIES})
##endif()
#

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

#find_library( # Sets the name of the path variable.
#        log-lib
#
#        # Specifies the name of the NDK library that
#        # you want CMake to locate.
#        log)
#
## Specifies libraries CMake should link to your target library. You
## can link multiple libraries, such as libraries you define in this
## build script, prebuilt third-party libraries, or system libraries.
#
#target_link_libraries( # Specifies the target library.
#        opencvsharp
#
#        # Links the target library to the log library
#        # included in the NDK.
#        ${log-lib})

# 静的ライブラリ 出力先を指定
# set_target_properties( ライブラリ名 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR} )
#set( OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../build_android/${CMAKE_ANDROID_ARCH_ABI}/")
#set_target_properties( opencvsharp PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR} )

# ライブラリプロジェクトのルート
# ここではこのファイルから２階層上を指定
set( LIB_ROOT ${CMAKE_CURRENT_LIST_DIR}/../../.. )

# ライブラリの出力先
# 対応するプロセッサごとにフォルダを分けて出力
set( OUTPUT_DIR ${LIB_ROOT}/build_android/${CMAKE_ANDROID_ARCH_ABI} )

# 出力先を指定（※STATICとはプロパティ名が違うので注意！）
set_target_properties( opencvsharp
        PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR} )