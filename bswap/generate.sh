rustc +stage1 -Copt-level=0 -o opt0.ll --emit=llvm-ir test.rs
rustc +stage1 -Copt-level=0 -o opt1.ll --emit=llvm-ir test.rs

/opt/freeware/bin/sed -i -e 's/convert/convert_no_vec/g' opt0.ll
/opt/freeware/bin/sed -i -e 's/convert/convert_vec/g' opt1.ll

ibm-clang -O3 -c opt0.ll -o bswap_no_vec.o
ibm-clang -O3 -c opt1.ll -o bswap_vec.o -mllvm -slp-threshold=-100

objdump -d bswap_no_vec.o bswap_vec.o
