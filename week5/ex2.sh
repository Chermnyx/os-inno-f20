#!/usr/bin/env bash
if [ -e ./num.lock ]; then
	exit 1
fi

if ln -s ./num ./num.lock; then
	trap "rm ./num.lock" EXIT

	# this script could be in race condition
	if [ -e ./num ]; then
		n=$(cat ./num)
		n=$((n + 1))
		echo $n > ./num
	else
		echo 0 > ./num
	fi
fi
