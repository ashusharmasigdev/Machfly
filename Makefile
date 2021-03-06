PROJ_NAME = Machfly
CHAR_NAME = Mufli

MACHFLY_VERSION = 0.2
BUILD_ID = 20210420_xCsbbwuwnwop
MACHFLY_LISCENCE = Copyright@2021

BUILDDIR := Binary
SRCDIR := Machfly
OBJDIR := Build

GPPPARAMS := \
	-IMachfly/	\
	-DMACHFLY_VERSION='"$(MACHFLY_VERSION)"'	\
	-DBUILD_ID='"$(BUILD_ID)"'	\
	-DMACHFLY_LISCENCE='"$(MACHFLY_LISCENCE)"'	\
	-fno-stack-protector


rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,$(SRCDIR),*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
DIRS = $(wildcard $(SRCDIR)/*)

OUTS = $(call rwildcard,$(BUILDDIR)/Machfly.app.p,*.o)

obj: $(OBJS)


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	echo !=== COMPILING $^
	mkdir -p $(@D)
	g++ $(GPPPARAMS) -c -o $@ $<


link:
	g++ $(OBJS) -o $(BUILDDIR)/Machfly

run:
	$(BUILDDIR)/Machfly

all: obj	\
	 link	\
	 run


buildlib:
	ar -rc $(BUILDDIR)/libmachfly.a $(OUTS)

indexlib:
	nm $(BUILDDIR)/libmachfly.a