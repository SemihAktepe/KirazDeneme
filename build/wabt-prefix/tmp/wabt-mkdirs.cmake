# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/semih/Masaüstü/kiraz_20401892_20401901-main/wabt"
  "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix/src/wabt-build"
  "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix"
  "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix/tmp"
  "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix/src/wabt-stamp"
  "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix/src"
  "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix/src/wabt-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix/src/wabt-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/semih/Masaüstü/kiraz_20401892_20401901-main/build/wabt-prefix/src/wabt-stamp${cfgdir}") # cfgdir has leading slash
endif()
