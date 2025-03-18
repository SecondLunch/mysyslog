# Makefile для libmysyslog

CC = gcc
CFLAGS = -Wall -Wextra -fPIC -g -Iinclude -I../libmysyslog-text/include -I../libmysyslog-json/include
LDFLAGS = -shared

TARGET = libmysyslog.so
SRC = src/mysyslog.c
OBJ = $(SRC:.c=.o)
INCLUDE = include

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

deb: all
	mkdir -p deb_tmp/usr/lib
	mkdir -p deb_tmp/usr/include/mysyslog
	cp $(TARGET) deb_tmp/usr/lib/
	cp include/mysyslog.h deb_tmp/usr/include/mysyslog/
	dpkg-deb --build deb_tmp mysyslog.deb
