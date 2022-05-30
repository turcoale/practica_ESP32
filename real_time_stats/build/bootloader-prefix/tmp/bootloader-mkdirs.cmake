# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/nbusuario11/esp/esp-idf/components/bootloader/subproject"
  "/home/nbusuario11/esp/practica_ESP32/real_time_stats/build/bootloader"
  "/home/nbusuario11/esp/practica_ESP32/real_time_stats/build/bootloader-prefix"
  "/home/nbusuario11/esp/practica_ESP32/real_time_stats/build/bootloader-prefix/tmp"
  "/home/nbusuario11/esp/practica_ESP32/real_time_stats/build/bootloader-prefix/src/bootloader-stamp"
  "/home/nbusuario11/esp/practica_ESP32/real_time_stats/build/bootloader-prefix/src"
  "/home/nbusuario11/esp/practica_ESP32/real_time_stats/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/nbusuario11/esp/practica_ESP32/real_time_stats/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
