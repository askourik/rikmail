/*
// Copyright (c) 2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once

#include <boost/asio/io_service.hpp>
#include <sdbusplus/asio/object_server.hpp>

static constexpr const char* RikmailServiceName =
    "xyz.openbmc_project.rikmail";
static constexpr const char* RikmailIface =
    "xyz.openbmc_project.Rikmail";
static constexpr const char* RikmailPath =
    "/xyz/openbmc_project/rikmail";

class RikmailMgr
{
    boost::asio::io_service& io;
    sdbusplus::asio::object_server& server;
    std::shared_ptr<sdbusplus::asio::connection> conn;
    std::shared_ptr<sdbusplus::asio::dbus_interface> iface;

    void readConf();
    void writeConf();

  public:
    RikmailMgr(boost::asio::io_service& io,
                sdbusplus::asio::object_server& srv,
                std::shared_ptr<sdbusplus::asio::connection>& conn);
};
