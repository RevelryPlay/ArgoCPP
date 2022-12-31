#include <gtest/gtest.h>

#include "ColorConverter.h"

TEST(ColorConverter, ColorFromHexBlack) {
    CommonColor color = ConvertColor(0x00000000);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 0.0f);
}

TEST(ColorConverter, ColorFromHexWhite) {
    CommonColor color = ConvertColor(0xFFFFFFFF);
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexRed) {
    CommonColor color = ConvertColor(0xFF0000FF);
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexGreen) {
    CommonColor color = ConvertColor(0x00FF00FF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexBlue) {
    CommonColor color = ConvertColor(0x0000FFFF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexAlpha) {
    CommonColor color = ConvertColor(0x000000FF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexSoftBlue) {
    CommonColor color = ConvertColor(0x1f7fbfc9);
    EXPECT_FLOAT_EQ(color.red, 0.12156863f);
    EXPECT_FLOAT_EQ(color.green, 0.49803922f);
    EXPECT_FLOAT_EQ(color.blue, 0.74901962f);
    EXPECT_FLOAT_EQ(color.alpha, 0.78823531f);
}

TEST(ColorConverter, ColorFromRGBABlack) {
    CommonColor color = ConvertColor({0,0,0});
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBAWhite) {
    CommonColor color = ConvertColor({255,255,255});
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBARed) {
    CommonColor color = ConvertColor({255,0,0});
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBAGreen) {
    CommonColor color = ConvertColor({0,255,0});
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBABlue) {
    CommonColor color = ConvertColor({0,0,255});
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBALimeGreen) {
    CommonColor color = ConvertColor({133, 208, 79, 1});
    EXPECT_FLOAT_EQ(color.red, 0.52156866);
    EXPECT_FLOAT_EQ(color.green, 0.81568629);
    EXPECT_FLOAT_EQ(color.blue, 0.30980393);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}
