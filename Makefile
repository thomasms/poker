# ROOT headers and libraries
ROOT_INCLUDES  = -I$(shell root-config --incdir)
ROOT_LIBRARIES = $(shell root-config --glibs) -lMinuit -lGeom -lEG -lEGPythia6

INCLUDES := $(ROOT_INCLUDES) $(LINUX_SYS_INCLUDES)

LIBS = $(ROOT_LIBRARIES)

#local src and include directories for my own created cxx and header files
IDIR    = src
SDIR    = src
ODIR    = obj

VPATH   = $(SDIR) $(IDIR) 

#compiler
CC=clang
CXX=clang++
LD=clang++

RM=rm -f

CFLAGS = -c -g -std=c++14 -I$(IDIR) -I$(shell root-config --incdir)
LDFLAGS = -g -Wall
LDLIBS = $(shell root-config --glibs)

TARGET = poker

all: $(ODIR) $(TARGET) 

SOURCE1 = main
SOURCE2 = Card
SOURCE3 = Deck
SOURCE4 = Hand
SOURCE5 = Play
SOURCE6 = Game
SOURCE7 = Utils

OBJ = $(SOURCE1).o $(SOURCE2).o $(SOURCE3).o $(SOURCE4).o $(SOURCE5).o $(SOURCE6).o $(SOURCE7).o
OBJS = $(addprefix $(ODIR)/,$(OBJ))

#define root system location
ROOTSYS=$(shell root-config --incdir)

INC = $(IDIR)/*.hh $(ROOTSYS)/*.h

$(ODIR):
	mkdir $(ODIR)

#executable file linking always comes first!
$(TARGET): $(OBJS)
	@echo ........Compiling 
	$(CXX) $(LDFLAGS) $(LDLIBS) $(OBJS) -o $(TARGET)
	@echo Done!

#compile the libraries
$(ODIR)/$(SOURCE1).o: $(SOURCE1).cc $(INC)
	@echo ........Building Objects
	$(CXX) $(CFLAGS) $(LIBS) $(SOURCE1).cc -o $@

$(ODIR)/$(SOURCE2).o: $(SDIR)/$(SOURCE2).cc $(INC)
	$(CXX) $(CFLAGS) $(LIBS) $(SDIR)/$(SOURCE2).cc -o $@

$(ODIR)/$(SOURCE3).o: $(SDIR)/$(SOURCE3).cc $(INC)
	$(CXX) $(CFLAGS) $(LIBS) $(SDIR)/$(SOURCE3).cc -o $@

$(ODIR)/$(SOURCE4).o: $(SDIR)/$(SOURCE4).cc $(INC)
	$(CXX) $(CFLAGS) $(LIBS) $(SDIR)/$(SOURCE4).cc -o $@

$(ODIR)/$(SOURCE5).o: $(SDIR)/$(SOURCE5).cc $(INC)
	$(CXX) $(CFLAGS) $(LIBS) $(SDIR)/$(SOURCE5).cc -o $@

$(ODIR)/$(SOURCE6).o: $(SDIR)/$(SOURCE6).cc $(INC)
	$(CXX) $(CFLAGS) $(LIBS) $(SDIR)/$(SOURCE6).cc -o $@

$(ODIR)/$(SOURCE7).o: $(SDIR)/$(SOURCE7).cc $(INC)
	$(CXX) $(CFLAGS) $(LIBS) $(SDIR)/$(SOURCE7).cc -o $@

clean:
	$(RM) $(OBJS)
	@rm -rf $(ODIR)	
	$(RM) $(TARGET)

