#Makefile for the Password Manager class


CXX = g++
CXXFLAGS = -std=c++11
EXECUTABLE = PasswordDriver

all: $(EXECUTABLE)

$(EXECUTABLE): PasswordDriver.o PasswordManager.o
	$(CXX) $(CXXFLAGS) -o $@ $^

PasswordDriver.o: PasswordDriver.cpp PasswordManager.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

PasswordManager.o: PasswordManager.cpp PasswordManager.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(EXECUTABLE) *.o

