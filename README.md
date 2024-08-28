### This application creates a library (libbooking.so in Linux/booking.dll in Windows) which can be used/integrated with an embedded/CLI application

There is also a main function in **main.cpp** file which can be used as a reference/guide for API invocation. For detailed API documentation please refer file
* **APIDOC.md** :  [here](./APIDOC.md).

If you are directly calling the library functions from another embedded/CLI application then you **must include in your cpp file the following header:**
```c++
#include "booking_manager.hpp"
```
To compile & run the application refer below. There are **four ways** as following:

### 1. Steps to Compile after integrating with other embedded/CLI application (WITHOUT USING MAKEFILE) in Linux/Unix:

Clone the repository. go inside the repository folder.
Open a terminal.

  * a) To create the library **libbooking.so** do the following
```bash
g++ -fPIC -shared -o libbooking.so src/seat.cpp src/theater.cpp src/movie.cpp src/movie_factory.cpp src/theater_factory.cpp src/booking_manager.cpp -I./include
```
  * b) Link the library to your application (Instead of main.cpp use your cpp file where you want to call APIS):
```bash
 g++ -o booking_app main.cpp -L. -lbooking -I./include
```
  * c) Copy the generated library to local lib:
```bash
 sudo cp libbooking.so /usr/local/lib/
```
  * d) After copying, you may need to update the linker cache with:
```bash
  sudo ldconfig
```
  * e) Run the application using :
```bash
 ./booking_app
```

### 2. Steps to run the application WITH MAKEFILE in Linux/Unix:
Clone the repository & go inside the repository project folder , then modify the Makefile inside the project as following:
change the following line inside Makefile

"MAIN_SRC = main.cpp"

Change it to your .cpp file as per your application from where you want to call Library APIs (for example: myapp.cpp)
```make
MAIN_SRC = myapp.cpp
```

Do the following steps in Linux terminal
* Enter the Clean command :
```bash
make clean
```
* Enter the build command :
```bash
 make
 ```
* Run the application :
```bash
 ./booking_app
 ```

### 3. Steps to run in Windows Operating system:
* ### Prerequisites :
 * g++ version: You must have the following g++ version in your windows system , open a terminal from anywhere and type g++ --version as below
 ```bash
 PS T:\> g++ --version
 g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
 Copyright (C) 2018 Free Software Foundation, Inc.
 This is free software; see the source for copying conditions.  There is NO
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 ```
  * make version: You must have following make version in windows system. Open a terminal from anywhere and type
make --version as following:
```bash
PS T:\> make --version
GNU Make 4.4.1
Built for x86_64-pc-msys
Copyright (C) 1988-2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```
  * Include the Header Files: Ensure your code includes the appropriate headers from booking.dll i.e
  ```c++
  #include "booking_manager.hpp"
  ```
  * Please refer the **main.cpp** and **APIDOC.md** file for how to invoke API functions

* ### Steps :
  * Clone the repository & go inside the repository project folder, replace all the content of the  **Makefile** with content of **Makefile-STABLE FOR WINDOWS**
  * You can Modify the Makefile inside the project as following: change the following line inside Makefile
  MAIN_SRC = main.cpp

  * Change it to your .cpp file as per your application from where you want to call Library APIs (for example: myapp.cpp)
  ```make
  MAIN_SRC = myapp.cpp
  ```
  * open a terminal for eg: powershell from the repository project folder

  * Enter the Clean command :
  ```bash
  make clean
  ```
  * Enter the build command :
  ```bash
   make
   ```
  * Run the application :Please Ensure that **booking.dll** is either in the same directory as your executable
  ```bash
   .\booking_app.exe
   ```

### 4. Steps to run the code irrespective of Operating system:
  * Clone the repository & go inside the repository project folder, replace all the content of the  **Makefile** with content of **Makefile-COMBINED**
  * If you **meet the Prerequisites mentioned in Step 3 for WINDOWS OS**, then

  * open any terminal for eg: powershell/ Linux bash depending upon OS inside the repository project folder

  * Enter the Clean command :
  ```bash
  make clean
  ```
  * Enter the build command :
  ```bash
   make
   ```
  * Run the application using following command if **windows OS:**
  ```bash
   .\booking_app.exe
   ```
  * OR  Run the application using following commands in **Linux:**
  ```bash
   ./booking_app
   ```
