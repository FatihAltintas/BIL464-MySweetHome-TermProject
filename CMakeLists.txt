# Hocanin tahtadaki versiyonu
cmake_minimum_required(VERSION 3.15)

# Proje adi (Ayni zamanda cikti dosyasinin adi olacak)
project(MSH_System)

# Hocanin kirmizi cizgisi: C++98
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------------------------------------
# KAYNAK DOSYALARI AYARLAMA (Hocanin set(SRC ...) mantigi)
# -----------------------------------------------------------
# src klasorundeki tum .cpp dosyalari ve main.cpp'yi SRC degiskenine atiyoruz
file(GLOB SRC "src/*.cpp" "main.cpp")

# -----------------------------------------------------------
# BUILD ISLEMI (Hocanin degiskenli yapisi)
# -----------------------------------------------------------
# ${PROJECT_NAME} -> MSH_System demektir
# ${SRC} -> Yukarida buldugumuz dosya listesi
add_executable(${PROJECT_NAME} ${SRC})

# -----------------------------------------------------------
# HEADER AYARLARI (Hocanin target_include mantigi)
# -----------------------------------------------------------
# include klasorunu projeye tanitiyoruz
target_include_directories(${PROJECT_NAME} PUBLIC include)