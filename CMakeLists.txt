set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(vcardtool main.cpp contact.cpp vcardreader.cpp vcardwriter.cpp phone.cpp email.cpp)
