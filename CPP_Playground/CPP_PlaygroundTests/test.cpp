#include "pch.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&__argc, __argv);
    return RUN_ALL_TESTS();
}