conan install . --output-folder=build --build=missing

cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
make -j


conan install --requires=nlohmann_json/3.11.3@ -b=missing --deployer=full_deploy
make -j