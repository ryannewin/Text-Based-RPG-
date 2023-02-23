CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(gamex
    Characters/main.cpp
    Characters/Armory.cpp
    Characters/Beast.cpp
    Characters/Elf.cpp
    Characters/Knight.cpp
    Characters/Wizard.cpp
    Characters/Hospital.cpp
    Characters/Character.cpp

)

ADD_EXECUTABLE(test
   Characters/test.cpp
   Characters/Character.cpp
   Characters/Knight.cpp
   Characters/Beast.cpp
   Characters/Wizard.cpp
   Characters/Elf.cpp
   Characters/Hospital.cpp
   Characters/Armory.cpp


)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)