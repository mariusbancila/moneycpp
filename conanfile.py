from conans import ConanFile, CMake, tools


class MoneycppConan(ConanFile):
    name = "moneycpp"
    version = "2021-04-24"
    license = "MIT License"
    author = "Marius Bancila https://github.com/mariusbancila"
    url = "https://github.com/mariusbancila/moneycpp"
    description = "A C++ 17 header-only, cross-platform library for handling monetary values, currencies, rounding " \
                  "and other related features. "
    topics = ("monetary", "currency", "rounding")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake"
    exports_sources = "include/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def package(self):
        self.copy("*.h", src="include", dst="include/moneycpp")

    def build(self):
        # header only, nothing to build, add method to prevent warning from conan
        yield
