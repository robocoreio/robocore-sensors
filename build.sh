#!/bin/bash -e
ARG=""
if [ ! -z "$TOOLCHAIN_PATH" ]; then
	TOOLCHAIN_PATH=$(readlink -f $TOOLCHAIN_PATH)
	ARG="-DTOOLCHAIN_PATH=$TOOLCHAIN_PATH"
fi

if [ ! -z "$HFRAMEWORK_PATH" ]; then
	HFRAMEWORK_PATH=$(readlink -f $HFRAMEWORK_PATH)
fi

ENABLE_DEBUG=0
if [ "$1" = "debug" ]; then
	ENABLE_DEBUG=1
fi

TYPES="mini big"
TYPES="big"
VERSIONS="0_9_5 0_9_6 0_9_7"
NAME=libhSensors

rm -rf libs/
mkdir -p libs

for type in $TYPES; do
	for ver in $VERSIONS; do
		mkdir -p libs/RoboCORE_${ver}_${type}

		if [ "$ENABLE_DEBUG" = "1" ]; then
			rm -rf build_tmp/
			cmake -DHFRAMEWORK_PATH=$HFRAMEWORK_PATH -DROBOCORE_VERSION=$ver -DROBOCORE_TYPE=$type $ARG -DDEBUG=1 -H. -Bbuild_tmp
			make -C build_tmp/
		fi

		rm -rf build_tmp/
		cmake -DHFRAMEWORK_PATH=$HFRAMEWORK_PATH -DROBOCORE_VERSION=$ver -DROBOCORE_TYPE=$type $ARG -DRELEASE=1 -H. -Bbuild_tmp
		make -C build_tmp/
	done
done

rm -rf build_tmp/
