PROJ_NAME = Machfly
CHAR_NAME = Mufli

MACHFLY_VERSION = 0.1
BUILD_ID = 20210420_xCsbbwuwnwop
MACHFLY_LISCENCE = Copyright@2021

BUILD_DIR := Build

GPPPARAMS := \
	-IMachfly/	\
	-DMACHFLY_VERSION='"$(MACHFLY_VERSION)"'	\
	-DBUILD_ID='"$(BUILD_ID)"'	\
	-DMACHFLY_LISCENCE='"$(MACHFLY_LISCENCE)"'


Build/%.o: Machfly/%.cpp
	mkdir -p $(@D)
	g++ $(GPPPARAMS) -c -o $@ $<