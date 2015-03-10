#!/bin/sh
pwd
cd gmake

#make -f behaviac.make config=debug32
#make -f behaviac.make config=release32

make

cd ..

echo "press any key to exit"
read


