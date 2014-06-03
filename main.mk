CXX			:= i686-w64-mingw32-g++
CXXFLAGS	:= -std=c++11 -Wall -ggdb
LDFLAGS		:= -mwindows
AR			:= i686-w64-mingw32-ar

SUBMAKEFILES := src/main.mk
