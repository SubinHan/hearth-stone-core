//
// pch.h
//

#pragma once
#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

#include <vector>
#include <map>
#include <string>
#include <memory>

#include <gmock/gmock.h>
#include "gtest/gtest.h"