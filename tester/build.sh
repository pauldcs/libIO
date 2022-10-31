#!/bin/bash

python3 tester/generate_suite.py
for i in tester/infiles/*.c; do
	name=$i
	base=${name::-2}
	echo "Generating" $base "..."
    gcc $i -o $base -I incs -L. -lstringf
done
