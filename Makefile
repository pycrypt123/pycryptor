CC = gcc
CXX = g++

# define compile flags
CFLAGS = -g -Wall -O2

# define link flags
#LDFALGS =

# macro definitions
#DFLAGS =

# libraries to link
# LIBS = -lm -lz

# add include search path
#INCLUDES = -I. -I/foo/bar/include

# add library search path
#LIBPATH = -L. -L/foo/bar/lib

OBJS = pycryptor.o pydecrypt.o

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: pycryptor pydecrypt

pycryptor: pycryptor.o
	$(CC) $(CFLAGS) -o $@ $^

pydecrypt: pydecrypt.o
	$(CC) $(CFLAGS) -o $@ $^

pycryptor.o: pycrypt.h
pydecrypt.o: pycrypt.h

.PHONY : clean

clean:
	rm $(OBJS)

