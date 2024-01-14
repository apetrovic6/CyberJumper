cmake_minimum_required(VERSION 3.27)
project(CyberJumper)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib REQUIRED)


add_executable(${PROJECT_NAME} main.cpp
        private/Scarfy.cpp
        public/Scarfy.h
        public/ScarfyGameManager.h
        private/ScarfyGameManager.cpp
        private/Pawn.cpp
        public/Pawn.h
        private/Nebula.cpp
        public/Nebula.h
        private/NebulaeManager.cpp
        public/NebulaeManager.h
        private/Drawable.cpp
        public/Drawable.h
        private/BackgroundManager.cpp
        public/BackgroundManager.h
        private/BaseObject.cpp
        public/BaseObject.h
        private/SoundManager.cpp
        public/SoundManager.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)