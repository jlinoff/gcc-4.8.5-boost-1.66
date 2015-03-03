# gcc-4.8.4-boost-1.57
Bash script and Makefile to install gcc 4.8.4 and boost 1.57 on CentOS and Mac OS X.

To use it:

    $ mkdir -p work/gcc
    $ cd work/gcc
    $ git clone https://github.com/jlinoff/gcc-4.8.4-boost-1.57.git 4.8.4
    $ cd 4.8.4
    $ make

For more detailed information see http://joelinoff.com/blog/?p=1678.

Added a new test file in this version called src/LOCAL-TEST/test4.cc that has even more C++-11 constructs. It implements a simple randomized quicksort.
