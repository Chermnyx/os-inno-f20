#!/usr/bin/env bash
while ! ln -s ./num ./num.lock; do
    sleep 0.01
done

trap "rm ./num.lock" EXIT

# this script no longer could be in race condition
if [ -e ./num ]; then
	n=$(cat ./num)
	n=$((n + 1))
	echo $n > ./num
else
	echo 0 > ./num
fi
