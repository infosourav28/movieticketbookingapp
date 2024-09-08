### This application creates a library (libbooking.so in Linux/booking.dll in Windows) which can be used/integrated with an embedded/CLI application

There is also a main function in **main.cpp** file which can be used as a reference/guide for API invocation. For detailed API documentation please refer file
* **APIDOC.md** :  [here](./APIDOC.md).

If you are directly calling the library functions from another embedded/CLI application then you **must include in your cpp file the following header:**
```c++
#include "booking_manager.hpp"
```
To compile & run the application refer below. There are **Four ways** as following:


### 1. Steps to run the application WITH MAKEFILE in Linux/Unix:
Clone the repository & go inside the repository project folder , then you can  modify the Makefile inside the project as following:
change the following line inside Makefile

"MAIN_SRC = main.cpp"

Change it to your .cpp file as per your application from where you want to call Library APIs (for example: myapp.cpp). You should contain your main function.
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

### 2. Steps to run in Windows Operating system:
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
  * Clone the repository & go inside the repository project folder,
  * You can Modify the Makefile inside the project as following: change the following line inside Makefile
  MAIN_SRC = main.cpp

  * You can change it to your .cpp file as per your application from where you want to call Library APIs (for example: myapp.cpp). It should contain your main function.
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

### 3. Steps to run the code irrespective of Operating system:
  * Clone the repository & go inside the repository project folder,
  * If you **meet the Prerequisites mentioned in Step 2 for WINDOWS OS**, then

  * Open any terminal for eg: powershell/ Linux bash depending upon OS inside the repository project folder

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

### 4. Steps to build & run the code using conan
  * Clone the repository and go inside the repository project folder,
  * In order to run the code using conan , you must have the conan & Cmake installed in your OS.
  * You must have the following conan & Cmake version installed to your system. Please check the conan & Cmake version by opening any terminal for eg: Linux
  ```bash
  sourav@LAPTOP-G862M1F7:~$ cmake --version
  cmake version 3.22.1

  CMake suite maintained and supported by Kitware (kitware.com/cmake).
  sourav@LAPTOP-G862M1F7:~$ conan --version
  Conan version 2.7.0
  ```
  Powershell terminal in Windows
  ```bash
  PS S:\> conan --version
  Conan version 2.7.0
  PS S:\> cmake --version
  cmake version 3.22.1

  CMake suite maintained and supported by Kitware (kitware.com/cmake).
  ```

  #### For Linux :

  * There is a script **build.sh** ([contents here](./build.sh)) located inside the repository which has conan install , build and package commands inside it.
  * Run the following commands for building.
  ```bash
  chmod +x build.sh
  ./build.sh
  ```
  It will create a conan package **movieticketbookingapi/0.2@user/channel** in a Package Folder something similar like this :
  ```bash

  Package folder ~/.conan2/p/b/movied5b372be072e9/p

  ```
  * After running the script there will be a **build** folder which gets generated inside the repository. For running the code run the command as below
  ```bash

  ./build/booking_app

  ```
  There will be shared Library (**libbooking.so**) which will be generated inside **build** folder and copied to the **bin** folder of Package Folder.
  ```bash

  sourav@LAPTOP-G862M1F7:~$ ls ~/.conan2/p/b/movied5b372be072e9/p/bin
  libbooking.so

  ```

  #### For WINDOWS :

  * There is a script **build.bat** ([contents here](./build.bat)) located inside the repository which has conan install , build and package commands inside it.
  * Run the following commands for building.
  ```bash
  .\build.bat
  ```
  It will create a conan package **movieticketbookingapi/0.2@user/channel** in a Package Folder something similar like this :
  ```bash
  Package folder C:\Users\Sourav Pal\.conan2\p\b\movie7f7716a877c68\p
  ```
  * After running the build script there will be a  **build** folder which gets generated inside the repository. Inside the generated **build** folder there will be executable as well as the shared Library.  For running the code run the command as below
  ```bash
  .\build\booking_app.exe
  ```
  There will be shared Library (**libbooking.dll**) which will be copied to  the **bin** folder of Package Folder.
  Navigate to the Package folder
  ```bash
  C:\Users\Sourav Pal\.conan2\p\b\movie7f7716a877c68\p\bin
  ```
  and there will be shared library libbooking.dll .
