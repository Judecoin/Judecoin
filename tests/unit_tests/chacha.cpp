// Copyright (c) 2014-2024, The Jude Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#include <string>

#include "gtest/gtest.h"

#include "crypto/chacha.h"

namespace
{
  struct test_data {
    const uint8_t* key;
    const uint8_t* iv;
    const size_t text_length;
    const uint8_t* plain_text;
    const uint8_t* cipher_text;
  };

  #define ARR(...) __VA_ARGS__

  #define MAKE_TEST_DATA(index, key, iv, plain_text, cipher_text)  \
    static const uint8_t test_key_##index[]         = key;         \
    static const uint8_t test_iv_##index[]          = iv;          \
    static const uint8_t test_plain_text_##index[]  = plain_text;  \
    static const uint8_t test_cipher_text_##index[] = cipher_text; \
    static const test_data test_##index = {test_key_##index, test_iv_##index, sizeof(test_plain_text_##index), test_plain_text_##index, test_cipher_text_##index};

  MAKE_TEST_DATA(
    0,
    ARR({0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x65, 0x3f, 0x4a, 0x18, 0xe3, 0xd2, 0x7d, 0xaf, 0x51, 0xf8, 0x41, 0xa0, 0x0b, 0x6c, 0x1a, 0x2b, 0xd2, 0x48, 0x98, 0x52, 0xd4, 0xae, 0x07, 0x11, 0xe1, 0xa4, 0xa3, 0x2a, 0xd1, 0x66, 0xfa, 0x6f, 0x88, 0x1a, 0x28, 0x43, 0x23, 0x8c, 0x7e, 0x17, 0x78, 0x6b, 0xa5, 0x16, 0x2b, 0xc0, 0x19, 0xd5, 0x73, 0x84, 0x9c, 0x16, 0x76, 0x68, 0x51, 0x0a, 0xda, 0x2f, 0x62, 0xb4, 0xff, 0x31, 0xad, 0x04})
  )

  MAKE_TEST_DATA(
    1,
    ARR({0x0f, 0x62, 0xb5, 0x08, 0x5b, 0xae, 0x01, 0x54, 0xa7, 0xfa, 0x4d, 0xa0, 0xf3, 0x46, 0x99, 0xec, 0x3f, 0x92, 0xe5, 0x38, 0x8b, 0xde, 0x31, 0x84, 0xd7, 0x2a, 0x7d, 0xd0, 0x23, 0x76, 0xc9, 0x1c}),
    ARR({0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0xdb, 0x16, 0x58, 0x14, 0xf6, 0x67, 0x33, 0xb7, 0xa8, 0xe3, 0x4d, 0x1f, 0xfc, 0x12, 0x34, 0x27, 0x12, 0x56, 0xd3, 0xbf, 0x8d, 0x8d, 0xa2, 0x16, 0x69, 0x22, 0xe5, 0x98, 0xac, 0xac, 0x70, 0xf4, 0x12, 0xb3, 0xfe, 0x35, 0xa9, 0x41, 0x90, 0xad, 0x0a, 0xe2, 0xe8, 0xec, 0x62, 0x13, 0x48, 0x19, 0xab, 0x61, 0xad, 0xdc, 0xcc, 0xfe, 0x99, 0xd8, 0x67, 0xca, 0x3d, 0x73, 0x18, 0x3f, 0xa3, 0xfd})
  )

  MAKE_TEST_DATA(
    2,
    ARR({0x0f, 0x62, 0xb5, 0x08, 0x5b, 0xae, 0x01, 0x54, 0xa7, 0xfa, 0x4d, 0xa0, 0xf3, 0x46, 0x99, 0xec, 0x3f, 0x92, 0xe5, 0x38, 0x8b, 0xde, 0x31, 0x84, 0xd7, 0x2a, 0x7d, 0xd0, 0x23, 0x76, 0xc9, 0x1c}),
    ARR({0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0xdb, 0x16, 0x58, 0x14, 0xf6, 0x67, 0x33, 0xb7, 0xa8, 0xe3, 0x4d, 0x1f, 0xfc, 0x12, 0x34, 0x27, 0x12, 0x56, 0xd3, 0xbf, 0x8d, 0x8d, 0xa2, 0x16, 0x69, 0x22, 0xe5, 0x98, 0xac, 0xac, 0x70, 0xf4, 0x12, 0xb3, 0xfe, 0x35, 0xa9, 0x41, 0x90, 0xad, 0x0a, 0xe2, 0xe8, 0xec, 0x62, 0x13, 0x48, 0x19, 0xab, 0x61, 0xad, 0xdc, 0xcc, 0xfe, 0x99, 0xd8, 0x67, 0xca, 0x3d, 0x73, 0x18, 0x3f, 0xa3, 0xfd, 0x82, 0x87, 0x0F})
  )

  MAKE_TEST_DATA(
    3,
    ARR({0x0f, 0x62, 0xb5, 0x08, 0x5b, 0xae, 0x01, 0x54, 0xa7, 0xfa, 0x4d, 0xa0, 0xf3, 0x46, 0x99, 0xec, 0x3f, 0x92, 0xe5, 0x38, 0x8b, 0xde, 0x31, 0x84, 0xd7, 0x2a, 0x7d, 0xd0, 0x23, 0x76, 0xc9, 0x1c}),
    ARR({0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9}),
    ARR({0x00}),
    ARR({0xdb})
  )

  void run_test(const test_data* test)
  {
    std::string buf;
    buf.resize(test->text_length);

    crypto::chacha8(test->plain_text, test->text_length, test->key, test->iv, &buf[0]);
    ASSERT_EQ(buf, std::string(reinterpret_cast<const char*>(test->cipher_text), test->text_length));

    crypto::chacha8(test->cipher_text, test->text_length, test->key, test->iv, &buf[0]);
    ASSERT_EQ(buf, std::string(reinterpret_cast<const char*>(test->plain_text), test->text_length));
  }
}

#define TEST_CHACHA8(test_no)        \
  TEST(chacha8, is_correct_##test_no) \
  {                                  \
    run_test(&test_##test_no);         \
  }

TEST_CHACHA8(0)
TEST_CHACHA8(1)
TEST_CHACHA8(2)
TEST_CHACHA8(3)
