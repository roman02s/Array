.PHONY: all clean build run rebuild unittest integrtest test 

all: clean build test

clean:
	rm -rf build

build:
	./build.sh -DCMAKE_BUILD_TYPE=Debug

array_project: build
	./build/array_project

rebuild: clean build

unittest: build
	./build/tests/unit/array_unit_test

integrtest: build
	python3 ./tests/integr/app.py

test: unittest integrtest