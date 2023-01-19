#include <gtest/gtest.h>

#include "ColorConverter.hpp"

TEST(ColorConverter, ColorFromHexBlack) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor(0x00000000);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 0.0f);
}

TEST(ColorConverter, ColorFromHexWhite) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor(0xFFFFFFFF);
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexRed) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor(0xFF0000FF);
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexGreen) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor(0x00FF00FF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexBlue) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor(0x0000FFFF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexAlpha) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor(0x000000FF);
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromHexSoftBlue) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor(0x1f7fbfc9);
    EXPECT_FLOAT_EQ(color.red, 0.12156863f);
    EXPECT_FLOAT_EQ(color.green, 0.49803922f);
    EXPECT_FLOAT_EQ(color.blue, 0.74901962f);
    EXPECT_FLOAT_EQ(color.alpha, 0.78823531f);
}

TEST(ColorConverter, ColorFromRGBABlack) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor({0,0,0});
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBAWhite) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor({255,255,255});
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBARed) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor({255,0,0});
    EXPECT_FLOAT_EQ(color.red, 1.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBAGreen) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor({0,255,0});
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 1.0f);
    EXPECT_FLOAT_EQ(color.blue, 0.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBABlue) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor({0,0,255});
    EXPECT_FLOAT_EQ(color.red, 0.0f);
    EXPECT_FLOAT_EQ(color.green, 0.0f);
    EXPECT_FLOAT_EQ(color.blue, 1.0f);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBALimeGreen) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor({133, 208, 79});
    EXPECT_FLOAT_EQ(color.red, 0.52156866);
    EXPECT_FLOAT_EQ(color.green, 0.81568629);
    EXPECT_FLOAT_EQ(color.blue, 0.30980393);
    EXPECT_FLOAT_EQ(color.alpha, 1.0f);
}

TEST(ColorConverter, ColorFromRGBAAlpha) {
    Argo::Utilities::CommonColor color = Argo::Utilities::ConvertColor({51, 51, 51, 0.45});
    EXPECT_FLOAT_EQ(color.red, 0.2);
    EXPECT_FLOAT_EQ(color.green, 0.2);
    EXPECT_FLOAT_EQ(color.blue, 0.2);
    EXPECT_FLOAT_EQ(color.alpha, 0.45f);
}

TEST(ColorConverter, Vec4FromCommonColor) {
    Argo::Utilities::Vec4 color = Argo::Utilities::ConvertColor({133, 208, 79}).ToVec4();
    EXPECT_FLOAT_EQ(color.x, 0.52156866);
    EXPECT_FLOAT_EQ(color.y, 0.81568629);
    EXPECT_FLOAT_EQ(color.z, 0.30980393);
    EXPECT_FLOAT_EQ(color.w, 1.0f);
}
