cmake_minimum_required(VERSION 3.0)

project(speech)

# Add a C++ executable that calls into a C# DLL
add_executable(speech main.cpp)

# Set the .NET Framework version and target architecture
set_property(TARGET speech PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.8")
set_property(TARGET speech PROPERTY VS_DOTNET_REFERENCES "System;SpeechLib")

# Set the C++ source file that calls into the C# DLL
target_sources(speech PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
