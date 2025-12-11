cmake_minimum_required(VERSION 3.10)

project(MySweetHome_Erhan_Only)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# SADECE SENIN YAZDIGIN DOSYALAR
# (GLOB kullanmiyoruz ki digerleri araya kaynamasin)
add_executable(MSH_Erhan_Test 
    main.cpp
    src/MSHSystem.cpp
    src/Light.cpp
    src/Device.cpp
    src/HomeMemento.cpp
    src/StateCaretaker.cpp
    # Diger arkadaslarin (Logger, Tv, Camera vs.) dosyalari burada YOK.
)
