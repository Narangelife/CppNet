# CMakeList.txt : 最上位の CMake プロジェクト ファイル。グローバル構成を行います
# また、サブプロジェクトをここに含めます。
#
cmake_minimum_required (VERSION 3.8)

project ("CppNet")
project ("CppClient")
set(CMAKE_CXX_STANDARD 11)

# サブプロジェクトを含めます。
add_subdirectory ("CppNet")
add_subdirectory ("CppClient")