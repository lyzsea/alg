# alg
algorithm implementation by c++ that questions from leetcod or poj

# IDE
clion

# dependency
gtest install steps:
1).git clone https://github.com/google/googletest/
2).cd googletest
3).Directly execute the command [cmake CMakeLists.txt] may cause errors like following:
   error: deleted function definitions are a C++11 extension [-Werror,-Wc++11-extensions]
打开 CMakeLists.txt，加入内容支持C++14或者11，然后再cmake
#Adopt C++14 standard
set(CMAKE_CXX_STANDARD 14)
4).make
5).sudo cp ./lib/libgtest*.a  /usr/local/lib
　 sudo cp –a ./lib/include/gtest /usr/local/include
