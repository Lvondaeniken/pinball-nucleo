# this is how to setup build 
cmake . -Bbuild -DCMAKE_TOOLCHAIN_FILE=./cmake/arm_none_eabi_gcc.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1
