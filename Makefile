CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include -fPIC
LDFLAGS = -L/usr/local/lib -lbooking
LIBRARY = libbooking.so
TARGET = booking_app
INSTALL_DIR = /usr/local/lib

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
MAIN_SRC = main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

all: $(TARGET)

$(LIBRARY): $(OBJ)
	$(CXX) -shared -o $(LIBRARY) $(OBJ)

$(TARGET): $(MAIN_OBJ) install
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(MAIN_OBJ) $(LDFLAGS)

install: $(LIBRARY)
	sudo cp $(LIBRARY) $(INSTALL_DIR)
	sudo ldconfig

clean:
	rm -f $(OBJ) $(MAIN_OBJ) $(LIBRARY) $(TARGET)
