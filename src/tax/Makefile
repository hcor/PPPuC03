##################
# Project Basics #
##################

# Project name and global directory layout
PROJECT       := tax
PROJECTDIR    := .

ROOT          := $(PROJECTDIR)/../..
BIN           := $(ROOT)/bin
INC           := $(ROOT)/inc
LIB           := $(ROOT)/lib
SRC           := $(ROOT)/src

# Project directories
OBJDIR        := $(PROJECTDIR)/obj
OUTPUTDIR      = $(BIN)/$(CONFIGURATION)

# Project files 
CFILES        := $(PROJECTDIR)/tax.c
CCFILES       := 
DEPFILES      := 

OBJFILES      := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(CFILES))) \
                 $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(CCFILES)))
TARGETFILE     = $(OUTPUTDIR)/$(PROJECT)

##################
# Compiler Setup #
##################

# Compiler
CC            := gcc
CFLAGS        := -DUNIX -std=c99
CXX           := g++
CXXFLAGS      := -DUNIX

# Linker
LINK          := g++ -fPIC -lm
LDFLAGS       := -DUNIX

# Libraries
INCLUDES      := -I$(PROJECTDIR) -I$(INC)
LIBRARIES     := -L$(LIB)

# Debug
ifeq ($(dbg),1)
    DEBUG          := -g -D_DEBUG
    CONFIGURATION  := debug
else
    DEBUG          := -O2 -fno-strict-aliasing
    CONFIGURATION  := release
endif

# Warnings
CXXWARN := \
#    -W -Wall \
#    -Wswitch \
#    -Wformat \
#    -Wchar-subscripts \
#    -Wparentheses \
#    -Wmultichar \
#    -Wtrigraphs \
#    -Wpointer-arith \
#    -Wcast-align \
#    -Wreturn-type \
#    -Wno-unused-function \
#    $(SPACE)
CWARN   := \
#    $(CXXWARN_FLAGS) \
#    -Wimplicit \
#    -Wstrict-prototypes \
#    -Wmissing-prototypes \
#    -Wmissing-declarations \
#    -Wnested-externs \
#    -Wmain \

# Final compiler options 
CFLAGS      += $(CWARN) $(ARCH) $(DEBUG) $(INCLUDES)
CXXFLAGS    += $(CXXWARN) $(ARCH) $(DEBUG) $(INCLUDES)
LDFLAGS     += $(LIBRARIES)

#########
# MISC. #
#########

# Verbose
ifeq ($(quiet), 1)
	QUIET := @
else
	QUIET := 
endif

#######################
# Project Build Rules #
#######################

.PHONY: all
all: build

.PHONY: build
build: $(TARGETFILE)

$(OBJDIR)/%.o: %.c $(DEPFILES)
	$(QUIET)$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/%.o: %.cpp $(DEPFILES)
	$(QUIET)$(CXX) $(CXXFLAGS) -o $@ -c $<

$(TARGETFILE): $(OBJFILES) | $(OUTPUTDIR)
	$(QUIET)$(LINK) $(LDFLAGS) -o $@ $+

$(OUTPUTDIR):
	mkdir -p $(BIN)/release
	mkdir -p $(BIN)/debug
	mkdir -p $(LIB)

$(OBJFILES): | $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: run
run: build
	$(QUIET)$(TARGETFILE)

.PHONY: tidy
tidy:
	$(QUIET)find . | egrep "#" | xargs rm -f
	$(QUIET)find . | egrep "\~" | xargs rm -f

.PHONY: clean
clean: tidy
	$(QUIET)rm -f $(OBJFILES)
	$(QUIET)rm -f $(TARGETFILE)

.PHONY: clobber
clobber: clean
	$(QUIET)rm -rf $(OBJDIR)
