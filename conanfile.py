from conan import ConanFile
from conan.tools.build import check_max_cppstd, check_min_cppstd
...

class BookingConan(ConanFile):
    name = "bookingconan"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = ["nlohmann_json/3.11.3", "catch2/3.5.2"]
    generators = "CMakeDeps", "CMakeToolchain", "PkgConfigDeps"
