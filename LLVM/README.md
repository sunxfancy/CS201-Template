# Installation
Under your project root directory:
$ cd LLVM

Get LLVM 11:
$ wget
https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/llvm-11.0.0.src.tar.xz
$ tar xf llvm-11.0.0.src.tar.xz
$ mv llvm-11.0.0.src llvm/

Get Clang 11:
$ wget https://github.com/llvm/llvm-project/releases/download/llvmorg-11.0.0/clang-11.0.0.src.tar.xz
$ tar xf clang-11.0.0.src.tar.xz
$ mv clang-11.0.0.src clang/

Build LLVM and Clang:
$ mkdir build
$ mkdir install
$ cd build
$ cmake -G "Unix Makefiles" -DLLVM_ENABLE_PROJECTS=clang -DCMAKE_INSTALL_PREFIX=../install -DCMAKE_BUILD_TYPE=Release ../llvm
$ make -j 8 installl  #replace 8 with the number of cores on your machine

Building process may take from 40 mins to nearly 3 hours, depending on how powerful your machine is
This builds both LLVM and Clang for release mode

Add “install/bin/” to your PATH 
Append export PATH=/PathToYourLLVM/install/bin/:$PATH to .bash_profile

Verify the installation
$ clang --version should show your Clang and LLVM version.
$ opt -version should show the LLVM version.
