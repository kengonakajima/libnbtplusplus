set -e
g++ -std=c++11 -I. -I./include hello.cpp ./libnbt++.a
echo compile finished
./a.out

