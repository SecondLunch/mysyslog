# Makefile для libmysyslog-json

CC = gcc
CFLAGS = -Wall -Wextra -fPIC -g -Iinclude -I../libmysyslog/include
LDFLAGS = -shared

TARGET = libmysyslog_json.so
SRC = src/libmysyslog_json.c
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
	mkdir -p deb_tmp/usr/include
	cp $(TARGET) deb_tmp/usr/lib/
	cp include/libmysyslog_json.h deb_tmp/usr/include/
	dpkg-deb --build deb_tmp libmysyslog-json.deb
