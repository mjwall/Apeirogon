CPPFLAGS=-g -std=c++11
LDFLAGS=-g
LDLIBS=
RM=rm -f
PWD=`pwd`

SRCS=zlibTest.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
DEPENDENCIES=../../../streaming/streaming.so ../compressors.so -lz


all: test

clean: 
	$(RM) $(OBJS)


test:	$(OBJS)
	cd ../../../streaming ; make clean; make ; cd $(PWD)
	cd ../ ; make clean; make ; cd $(PWD)
	g++ -o construct_test $(OBJS) $(DEPENDENCIES) $(CPPFLAGS)
	chmod 755 construct_test
	$(RM) $(OBJS)
	./construct_test
