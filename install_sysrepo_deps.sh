#!/usr/bin/env bash
ROOT_DIR=$(pwd)
CORES=16

echo "Root dir: ${ROOT_DIR}"
sudo apt install git cmake build-essential bison flex libpcre3-dev libev-dev libavl-dev \
libprotobuf-c-dev protobuf-c-compiler valgrind swig python-dev lua5.2
rm -rf ./deps
mkdir deps && cd deps

# cmocka
git clone git://git.cryptomilk.org/projects/cmocka.git
cd cmocka && mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j${CORES}
sudo make install
echo "CMocka has been installed"

cd ${ROOT_DIR}/deps
git clone https://github.com/CESNET/libyang.git
cd libyang && mkdir build && cd build
cmake ..
make -j${CORES}
sudo make install
echo "Libyang has been installed"
echo "Done."

cd ${ROOT_DIR}/sysrepo
rm -rf build
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j${CORES}
sudo make install