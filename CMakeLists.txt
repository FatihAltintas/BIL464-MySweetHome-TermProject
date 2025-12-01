cmake_minimum_required(VERSION 3.10)

project(MSH_MyModule_Req10_11_12)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Kaynak dosyaları ekle (src içindekiler + main.cpp)
add_executable(MSH_Test 
    main.cpp 
    src/MSHSystem.cpp
    # Device.cpp ve Light.cpp'ye gerek yok çünkü implementation'ları header içinde yaptık
    # Eğer src/Device.cpp içine taşırsan buraya eklemelisin.
    # Şu anki verdiğim kodda implementation .h içinde inline veya .cpp gerektirmeyecek kadar basit.
    # Ancak MSHSystem.cpp ayırdığımız için onu ekledik.
)