# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/root/oop-laba-4/build/_deps/googletest-src"
  "/root/oop-laba-4/build/_deps/googletest-build"
  "/root/oop-laba-4/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/root/oop-laba-4/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/root/oop-laba-4/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/root/oop-laba-4/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/root/oop-laba-4/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/root/oop-laba-4/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/root/oop-laba-4/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
