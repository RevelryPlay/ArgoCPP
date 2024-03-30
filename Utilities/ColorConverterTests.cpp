#include "include/ColorConverter.hpp"
#include "../Core/include/Types/CommonColor.hpp"
#include "../Core/include/Types/Vec4.hpp"

#include <gtest/gtest.h>

TEST(ColorConverter, ColorFromHexBlackPointer) {
    constexpr unsigned int inColor = 0x00000000;
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex(&inColor);
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 0.0F);
}

TEST(ColorConverter, ColorFromHexWhite) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex(0xFFFFFFFF);
    EXPECT_FLOAT_EQ(red, 1.0F);
    EXPECT_FLOAT_EQ(green, 1.0F);
    EXPECT_FLOAT_EQ(blue, 1.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexRed) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex(0xFF0000FF);
    EXPECT_FLOAT_EQ(red, 1.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexGreen) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex(0x00FF00FF);
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 1.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexBlue) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex(0x0000FFFF);
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 1.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexAlpha) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex(0x000000FF);
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexSoftBlue) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex(0x1f7fbfc9);
    EXPECT_FLOAT_EQ(red, 0.12156863F);
    EXPECT_FLOAT_EQ(green, 0.49803922F);
    EXPECT_FLOAT_EQ(blue, 0.74901962F);
    EXPECT_FLOAT_EQ(alpha, 0.78823531F);
}

TEST(ColorConverter, ColorFromHexString6White) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex("FFFFFF");
    EXPECT_FLOAT_EQ(red, 1.0F);
    EXPECT_FLOAT_EQ(green, 1.0F);
    EXPECT_FLOAT_EQ(blue, 1.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexString6Black) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex("000000");
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexString8White) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex("FFFFFFFF");
    EXPECT_FLOAT_EQ(red, 1.0F);
    EXPECT_FLOAT_EQ(green, 1.0F);
    EXPECT_FLOAT_EQ(blue, 1.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromHexString8Black) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex("00000000");
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 0.0F);
}

TEST(ColorConverter, ColorFromHexStringSoftBlue) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromHex("1f7fbfc9");
    EXPECT_FLOAT_EQ(red, 0.12156863F);
    EXPECT_FLOAT_EQ(green, 0.49803922F);
    EXPECT_FLOAT_EQ(blue, 0.74901962F);
    EXPECT_FLOAT_EQ(alpha, 0.78823531F);
}

TEST(ColorConverter, ColorFromRGBABlack) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromRGBA({0, 0, 0});
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromRGBAWhite) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromRGBA({255, 255, 255});
    EXPECT_FLOAT_EQ(red, 1.0F);
    EXPECT_FLOAT_EQ(green, 1.0F);
    EXPECT_FLOAT_EQ(blue, 1.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromRGBARed) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromRGBA({255, 0, 0});
    EXPECT_FLOAT_EQ(red, 1.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromRGBAGreen) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromRGBA({0, 255, 0});
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 1.0F);
    EXPECT_FLOAT_EQ(blue, 0.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromRGBABlue) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromRGBA({0, 0, 255});
    EXPECT_FLOAT_EQ(red, 0.0F);
    EXPECT_FLOAT_EQ(green, 0.0F);
    EXPECT_FLOAT_EQ(blue, 1.0F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromRGBALimeGreen) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromRGBA({133, 208, 79});
    EXPECT_FLOAT_EQ(red, 0.52156866F);
    EXPECT_FLOAT_EQ(green, 0.81568629F);
    EXPECT_FLOAT_EQ(blue, 0.30980393F);
    EXPECT_FLOAT_EQ(alpha, 1.0F);
}

TEST(ColorConverter, ColorFromRGBAAlpha) {
    auto [red, green, blue, alpha] = Argo::Utilities::ColorConverter::FromRGBA({51, 51, 51, 0.45});
    EXPECT_FLOAT_EQ(red, 0.2F);
    EXPECT_FLOAT_EQ(green, 0.2F);
    EXPECT_FLOAT_EQ(blue, 0.2F);
    EXPECT_FLOAT_EQ(alpha, 0.45F);
}

TEST(ColorConverter, Vec4FromCommonColor) {
    const auto [w, x, y, z] = Argo::Utilities::ColorConverter::FromRGBA({133, 208, 79}).ToVec4();
    EXPECT_FLOAT_EQ(w, 0.52156866F);
    EXPECT_FLOAT_EQ(x, 0.81568629F);
    EXPECT_FLOAT_EQ(y, 0.30980393F);
    EXPECT_FLOAT_EQ(z, 1.0F);
}
