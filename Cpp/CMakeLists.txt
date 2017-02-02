cmake_minimum_required (VERSION 2.8)

#This is the name of the project // cppInterface
PROJECT( cvv )

#soueces to include
include_directories(.)
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( cvv main.cpp )
TARGET_LINK_LIBRARIES( cvv ${OpenCV_LIBS} )
