../../LLVM/install/bin/clang -Xclang -disable-O0-optnone -fno-discard-value-names -O0 -S -emit-llvm $1.c -o $1.ll
