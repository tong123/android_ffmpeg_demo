# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )
add_library( avcodec SHARED IMPORTED )
set_target_properties( avcodec PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libavcodec-58.so )
add_library( avdevice SHARED IMPORTED )
set_target_properties( avdevice PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libavdevice-58.so )
add_library( avfilter SHARED IMPORTED )
set_target_properties( avfilter PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libavfilter-7.so )
add_library( avformat SHARED IMPORTED )
set_target_properties( avformat PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libavformat-58.so )
add_library( avutil SHARED IMPORTED )
set_target_properties( avutil PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libavutil-56.so )
add_library( postproc SHARED IMPORTED )
set_target_properties( postproc PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libpostproc-55.so )
add_library( swresample SHARED IMPORTED )
set_target_properties( swresample PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libswresample-3.so )
add_library( swscale SHARED IMPORTED )
set_target_properties( swscale PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/src/main/jni/libswscale-5.so )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_include_directories(native-lib PRIVATE
                           src/main/jni/include)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib
                       avcodec
                       avdevice
                       avfilter
                       avformat
                       avutil
                       postproc
                       swresample
                       swscale
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )