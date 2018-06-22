LIBDIR = 
LIBS = -lm

#CC = /usr/local/bin/gcc
#CPP = /usr/local/bin/g++
CC = gcc
CPP = g++

CFLAGS = -g -O0 -Wall 
RM = rm -f

OBJECTS =  parse_argument.o \
util.o \
phon.o \
syllable.o \
phrase.o \
emoSyn.o	

all: $(OBJECTS)
	$(CPP) -o emoSyn $(OBJECTS) $(LIBS)

emoSyn.o:  emoSyn.cc 
	$(CPP) -c $(CFLAGS)  emoSyn.cc

util.o:  util.cc util.h
	$(CPP) -c $(CFLAGS)  util.cc

phon.o:  phon.cc phon.h 
	$(CPP) -c $(CFLAGS)  phon.cc

syllable.o:  syllable.cc syllable.h  
	$(CPP) -c $(CFLAGS)  syllable.cc

phrase.o:  phrase.cc phrase.h 
	$(CPP) -c $(CFLAGS)  phrase.cc

parse_argument.o:  parse_argument.c   parse_argument.h
	$(CC) -c $(CFLAGS)  parse_argument.c


clean:
	$(RM) *.o *~ *fspec* *BAK* tmp?* .\#* \#* sensOut.* *.aux *.dvi *.log *out

backup: clean
	tar cvzf /home/felixbur/archive/emoSyn-all-0.1.tgz /home/felixbur/development/emoSyn/

