cmake_minimum_required(VERSION 3.1.0)
project(main)

#增加qrc文件
file(GLOB_RECURSE QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)
# 在相应的构建目录中查找头文件
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# 设置CMake在需要时自动运行moc
set(CMAKE_AUTOMOC ON)
# 从Qt设计师文件列表中创建代码
set(CMAKE_AUTOUIC ON)
#设置qrc变量
set(QRC_SOURCE_FILES Resources.qrc)
# 设置Qt的环境变量
set(CMAKE_PREFIX_PATH /Users/xiongzhiyao/Qt5.9.8/5.9.8/clang_64/lib/cmake/)
set(Qt5Widgets_DIR /Users/xiongzhiyao/Qt5.9.8/5.9.8/clang_64/lib/cmake/Qt5Widgets)
set(Qt5Multimedia_DIR /Users/xiongzhiyao/Qt5.9.8/5.9.8/clang_64/lib/cmake/Qt5Multimedia)
set(Qt5MultimediaWidgets_DIR /Users/xiongzhiyao/Qt5.9.8/5.9.8/clang_64/lib/cmake/Qt5MultimediaWidgets)
find_package(Qt5 COMPONENTS Multimedia MultimediaWidgets Widgets REQUIRED)
#添加资源
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})
#add_library(${PROJECT_NAME} QRC_FILES)
# 搜索当前目录下的源文件
aux_source_directory(. SRC_DIR)
add_executable(${PROJECT_NAME} ${SRC_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Multimedia)






