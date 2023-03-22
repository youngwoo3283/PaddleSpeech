#include "utils/text_process.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(TextProcess, DelBlankTest) {
    std::string test_str = "我 今天     去 了 超市     花了   120 元。";
    std::string out_str = ppspeech::DelBlank(test_str);
    int ret = out_str.compare("我今天去了超市花了120元。");
    EXPECT_EQ(ret, 0);

    test_str = "how are you today";
    out_str = ppspeech::DelBlank(test_str);
    ret = out_str.compare("how are you today");
    EXPECT_EQ(ret, 0);

    test_str = "我 的 paper 在 哪里？";
    out_str = ppspeech::DelBlank(test_str);
    ret = out_str.compare("我的paper在哪里？");
    EXPECT_EQ(ret, 0);
}

TEST(TextProcess, AddBlankTest) {
    std::string test_str = "how are you";
    std::string out_str = ppspeech::AddBlank(test_str);
    int ret = out_str.compare(" how  are  you ");
    EXPECT_EQ(ret, 0);

    test_str = "欢迎来到China。";
    out_str = ppspeech::AddBlank(test_str);
    ret = out_str.compare("欢迎来到 China 。");
    EXPECT_EQ(ret, 0);
}

TEST(TextProcess, ReverseFractionTest) {
    std::string test_str = "<tag>3/1<tag>";
    std::string out_str = ppspeech::ReverseFraction(test_str);
    int ret = out_str.compare("1/3");
    std::cout<<out_str<<std::endl;
    EXPECT_EQ(ret, 0);

    test_str = "<tag>3/1<tag> <tag>100/10000<tag>";
    out_str = ppspeech::ReverseFraction(test_str);
    ret = out_str.compare("1/3 10000/100");
    std::cout<<out_str<<std::endl;
    EXPECT_EQ(ret, 0);
}