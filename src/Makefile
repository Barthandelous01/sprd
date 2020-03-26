DEFAULT_GOAL := default

.PHONY : clean install debug

default:
	g++ -std=c++11 -O3 -o sprd sprd.cpp

install:
	../scripts/install.sh

clean:
	rm sprd

debug:
	g++ -std=c++11 -ggdb -o sprd sprd.cpp
