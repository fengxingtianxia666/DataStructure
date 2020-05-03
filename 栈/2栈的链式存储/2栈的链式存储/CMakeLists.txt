# CMakeList.txt: 2栈的链式存储 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (CMakeTarget "demo02_中缀转后缀.c" "demo03_后缀计算.c" "栈的应用后缀表达式.c" "栈的链式存储.c" "linkstack.c" "linklist.c" "jiujin.h" "linkstack.h" "linklist.h")
# TODO: 如有需要，请添加测试并安装目标。
