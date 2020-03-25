DEFAULT_GOAL := default

.PHONY : clean install debug

default:
	g++ -O3 -o sprd sprd.cpp

instal:
	../scripts/install.sh

clean:
	rm sprd

debug:
	g++ -ggdb -o sprd sprd.cpp
