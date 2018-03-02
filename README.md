# gcc-4.8.5-boost-1.66
Bash script and Makefile to install gcc 4.8.5 and boost 1.66 on CentOS and Mac OS X.

To use it:
```bash
$ mkdir -p work/gcc
$ cd work/gcc
$ git clone https://github.com/jlinoff/gcc-4.8.5-boost-1.66.git 4.8.5
$ cd 4.8.5
$ chmod a+x bld.sh
$ make
```
To build and run the example do this:
```bash
#!/bin/bash
# Setup the environment.
MY_GXX_HOME="~/work/gcc/4.8.5/rtf"
export PATH="${MY_GXX_HOME}/bin:${PATH}"
export LD_LIBRARY_PATH="${MY_GXX_HOME}/lib:${MY_GXX_HOME}/lib64:${LD_LIBRARY_PATH}"
export LD_RUN_PATH="${MY_GXX_HOME}/lib:${MY_GXX_HOME}/lib64:${LD_LIBRARY_PATH}"
 
# Compile and link.
g++ -O3 -std=c++11 -Wall -o example.exe example.cc
 
# Run.
./example.exe
```
For more detailed information see http://joelinoff.com/blog/?p=1678.

Added a new test file in this version called src/LOCAL-TEST/test4.cc that has even more C++-11 constructs. It implements a simple randomized quicksort.
