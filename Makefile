# Detect the operating system
UNAME := $(shell uname -s)

# Common settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include

# OS-specific settings
ifeq ($(UNAME), Linux)
    CXXFLAGS += -fPIC  # Ensure -fPIC is added for Linux
    LIBRARY = libbooking.so
    LDFLAGS = -L. -lbooking
    INSTALL_DIR = /usr/local/lib
    LIB_LDFLAGS = -shared
else ifeq ($(UNAME), Windows)
    LIBRARY = booking.dll
    LDFLAGS = -L. -lbooking
    INSTALL_DIR = C:/Windows/System32
    LIB_LDFLAGS = -shared
endif

TARGET = booking_app
SRC = $(wildcard src/*.cpp)  # Include all source files
OBJ = $(SRC:.cpp=.o)
MAIN_SRC = main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

all: $(LIBRARY) $(TARGET)

$(LIBRARY): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LIB_LDFLAGS) -o $(LIBRARY) $(OBJ)

$(TARGET): $(MAIN_OBJ) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_OBJ) $(OBJ) $(LDFLAGS)

install: $(LIBRARY)
ifeq ($(UNAME), Linux)
	sudo cp $(LIBRARY) $(INSTALL_DIR)
	sudo ldconfig
else ifeq ($(UNAME), Windows)
	cmd /c copy $(LIBRARY) $(INSTALL_DIR)
endif

clean:
	rm -f $(OBJ) $(MAIN_OBJ) $(LIBRARY) $(TARGET)