/* Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include <gtest/gtest.h>
#include <iostream>

#include "paddle/phi/api/ext/exception.h"
#include "paddle/phi/common/backend.h"

namespace phi {
namespace tests {

TEST(Backend, OStream) {
  std::ostringstream oss;
  oss << phi::Backend::UNDEFINED;
  EXPECT_EQ(oss.str(), "Undefined");
  oss.str("");
  oss << phi::Backend::CPU;
  EXPECT_EQ(oss.str(), "CPU");
  oss.str("");
  oss << phi::Backend::GPU;
  EXPECT_EQ(oss.str(), "GPU");
  oss.str("");
  oss << phi::Backend::XPU;
  EXPECT_EQ(oss.str(), "XPU");
  oss.str("");
  oss << phi::Backend::NPU;
  EXPECT_EQ(oss.str(), "NPU");
  oss.str("");
  oss << phi::Backend::MKLDNN;
  EXPECT_EQ(oss.str(), "MKLDNN");
  oss.str("");
  oss << phi::Backend::CUDNN;
  EXPECT_EQ(oss.str(), "CUDNN");
  oss.str("");
  try {
    oss << phi::Backend::NUM_BACKENDS;
  } catch (const std::exception& exception) {
    std::string ex_msg = exception.what();
    EXPECT_TRUE(ex_msg.find("Invalid enum backend type") != std::string::npos);
  }
}

}  // namespace tests
}  // namespace phi
