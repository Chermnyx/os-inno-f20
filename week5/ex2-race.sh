#!/usr/bin/env bash

# this script could be in race condition
# when both scripts checked for ./num but ./num haven't been created yet
if [ -e ./num ]; then
	n=$(cat ./num)
	n=$((n + 1))
	echo $n > ./num
else
	echo 0 > ./num
fi
