#!/bin/bash -e
ARG1=""
if [ ! -z "$TOOLCHAIN_PATH" ]; then
	ARG1="-DTOOLCHAIN_PATH=$TOOLCHAIN_PATH"
fi

ARG2=""
if [ ! -z "$HFRAMEWORK_PATH" ]; then
	HFRAMEWORK_PATH=$(readlink -f $HFRAMEWORK_PATH)
	ARG2="-DHFRAMEWORK_PATH=$HFRAMEWORK_PATH"
fi

if [ "$ARG1" = "" ]; then
	echo "No toolchain path"
	exit 1
fi
if [ "$ARG2" = "" ]; then
	echo "No hFramework path"
	exit 1
fi

TYPES="mini big"
TYPES="big"
VERSIONS="0_9_5 0_9_6"

EXAMPLES="lego_ultrasonic"

CURDIR=$(pwd)
echo $CURDIR

cd $HFRAMEWORK_PATH
./build.sh nodocs
cd $CURDIR/../
./build.sh
cd $CURDIR

for type in $TYPES; do
	for ver in $VERSIONS; do
		rm -rf build_tmp/
		cmake -DROBOCORE_VERSION=$ver -DROBOCORE_TYPE=$type $ARG1 $ARG2 -H. -Bbuild_tmp
		make -C build_tmp/
	done
done

rm -rf build_tmp/