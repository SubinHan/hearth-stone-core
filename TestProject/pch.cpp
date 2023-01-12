// pch.cpp: 미리 컴파일된 헤더에 해당하는 소스 파일

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

// 미리 컴파일된 헤더를 사용하는경우 컴파일이 성공하려면 이 소스 파일이 필요합니다.
