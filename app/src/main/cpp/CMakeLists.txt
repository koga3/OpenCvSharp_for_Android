# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.22.1)

# Declares and names the project.

project("opencvsharp")

## headerファイルのセット
#set( OPENCV_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/OpenCV/native/jni/include")
#
#add_library(
#        lib_opencv
#        STATIC
#        IMPORTED
#)
#set( OPENCV_LIB_DIR "${PROJECT_SOURCE_DIR}/OpenCV/native/staticlibs ")
#
#set_target_properties(
#        lib_opencv
#        PROPERTIES IMPORTED_LOCATION
#        ${OPENCV_LIB_DIR}/${CMAKE_ANDROID_ARCH_ABI}/
#)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# cppファイルすべて読み込む
file(GLOB OPENCVSHARP_FILES *.cpp)

add_library( # Sets the name of the library.
        opencvsharp

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        ${OPENCVSHARP_FILES})

# OPencvのdirを集めてくる
set(OpenCV_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../../sdk/native/jni")
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    target_include_directories( opencvsharp PUBLIC ${OpenCV_INCLUDE_DIRS} )
    target_link_libraries( opencvsharp ${OpenCV_LIBS} )
endif()


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        opencvsharp

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})

# 静的ライブラリ 出力先を指定
# set_target_properties( ライブラリ名 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR} )
set( OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../build_android/${CMAKE_ANDROID_ARCH_ABI}/")
set_target_properties( opencvsharp PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR} )