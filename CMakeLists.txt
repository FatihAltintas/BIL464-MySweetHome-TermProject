cmake_minimum_required(VERSION 3.10)

# Proje Adi
project(MySweetHome_Final)

# C++98 Standarti
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header dosyalari
include_directories(include)

# SIHIRLI SATIR: src icindeki BUTUN .cpp dosyalarini bul
file(GLOB SOURCES "src/*.cpp" "main.cpp")

# Hepsini tek bir MSH_System.exe haline getir
add_executable(MSH_System ${SOURCES})