from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps
from conan.tools.files import copy
import os

class MovieTicketBooking(ConanFile):
    name = "movieticketbookingapi"
    version = "0.2"
    license = "MIT"
    author = "Sourav Pal <infosourav28@gmail.com>"
    url = "https://github.com/infosourav28/movieticketbookingapp"
    description = "This repository is basically creating APIs for backend of movie ticket booking application"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    exports_sources = "src/*", "CMakeLists.txt"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            if "fPIC" in self.options:
                del self.options.fPIC

    def requirements(self):
        # This will load requirements from the conanfile.txt if needed
        pass



    def build(self):
        cmake = CMake(self)
        cmake.configure(variables={"BUILD_SHARED_LIBS": "ON" if self.options.shared else "OFF"})
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

        build_dir = os.path.join(self.build_folder)
        bin_dir = os.path.join(self.package_folder, "bin")

        # Ensure the bin directory exists
        os.makedirs(bin_dir, exist_ok=True)

        # Debugging outputs
        print(f"Build directory: {build_dir}")
        print(f"Package bin directory: {bin_dir}")
        if not os.path.exists(build_dir):
            raise Exception(f"Build directory does not exist: {build_dir}")
        print(f"Files in build directory: {os.listdir(build_dir)}")

        if self.settings.os == "Windows":
            dll_file = "libbooking.dll"
            if os.path.isfile(os.path.join(build_dir, dll_file)):
                copy(self, dll_file, src=build_dir, dst=bin_dir)
            else:
                raise Exception(f"{dll_file} not found in build directory")
        else:
            so_file = "libbooking.so"
            so_file_path = os.path.join(build_dir, so_file)
            if os.path.isfile(so_file_path):
                copy(self, so_file, src=build_dir, dst=bin_dir)
            else:
                raise Exception(f"{so_file} not found in build directory: {so_file_path}")


    def package_info(self):
        # Define how to use this package, e.g., libraries, headers, etc.
        self.cpp_info.libs = ["booking_app_lib"]

