#include <gtest/gtest.h>
#include "Soundex.h"

// Test cases for the empty string check
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Test cases for the single character check
TEST(SoundexTest, HandlesSingleCharacter) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("B"), "B000");
    EXPECT_EQ(generateSoundex("C"), "C000");
    EXPECT_EQ(generateSoundex("D"), "D000");
    EXPECT_EQ(generateSoundex("E"), "E000");
    EXPECT_EQ(generateSoundex("F"), "F000");
    EXPECT_EQ(generateSoundex("G"), "G000");
    EXPECT_EQ(generateSoundex("H"), "H000");
    EXPECT_EQ(generateSoundex("I"), "I000");
    EXPECT_EQ(generateSoundex("J"), "J000");
    EXPECT_EQ(generateSoundex("K"), "K000");
    EXPECT_EQ(generateSoundex("L"), "L000");
    EXPECT_EQ(generateSoundex("M"), "M000");
    EXPECT_EQ(generateSoundex("N"), "N000");
    EXPECT_EQ(generateSoundex("O"), "O000");
    EXPECT_EQ(generateSoundex("P"), "P000");
    EXPECT_EQ(generateSoundex("Q"), "Q000");
    EXPECT_EQ(generateSoundex("R"), "R000");
    EXPECT_EQ(generateSoundex("S"), "S000");
    EXPECT_EQ(generateSoundex("T"), "T000");
    EXPECT_EQ(generateSoundex("U"), "U000");
    EXPECT_EQ(generateSoundex("V"), "V000");
    EXPECT_EQ(generateSoundex("W"), "W000");
    EXPECT_EQ(generateSoundex("X"), "X000");
    EXPECT_EQ(generateSoundex("Y"), "Y000");
    EXPECT_EQ(generateSoundex("Z"), "Z000");
}

// Test cases for the names with vowels and certain consonants that should be ignored
TEST(SoundexTest, HandlesIgnoredCharacters) {
    EXPECT_EQ(generateSoundex("AEIOU"), "A000");
    EXPECT_EQ(generateSoundex("HW"), "H000");
}

// Test cases for the names with adjacent consonants that should be ignored
TEST(SoundexTest, HandlesAdjacentConsonants) {
    EXPECT_EQ(generateSoundex("BB"), "B100");
    EXPECT_EQ(generateSoundex("CC"), "C200");
    EXPECT_EQ(generateSoundex("DD"), "D300");
    EXPECT_EQ(generateSoundex("FF"), "F100");
    EXPECT_EQ(generateSoundex("GG"), "G200");
    EXPECT_EQ(generateSoundex("JJ"), "J200");
    EXPECT_EQ(generateSoundex("KK"), "K200");
    EXPECT_EQ(generateSoundex("LL"), "L400");
    EXPECT_EQ(generateSoundex("MM"), "M500");
    EXPECT_EQ(generateSoundex("NN"), "N500");
    EXPECT_EQ(generateSoundex("PP"), "P100");
    EXPECT_EQ(generateSoundex("QQ"), "Q200");
    EXPECT_EQ(generateSoundex("RR"), "R600");
    EXPECT_EQ(generateSoundex("SS"), "S200");
    EXPECT_EQ(generateSoundex("TT"), "T300");
    EXPECT_EQ(generateSoundex("VV"), "V100");
    EXPECT_EQ(generateSoundex("XX"), "X200");
    EXPECT_EQ(generateSoundex("YY"), "Y000");
    EXPECT_EQ(generateSoundex("ZZ"), "Z200");
}

// Test cases for the longer names that require truncation
TEST(SoundexTest, HandlesLongNames) {
    EXPECT_EQ(generateSoundex("Kumarswamy"), "K562");
    EXPECT_EQ(generateSoundex("Abhishek"), "A120");
    EXPECT_EQ(generateSoundex("Yadiyurappa"), "Y361");
    EXPECT_EQ(generateSoundex("Madeshwara"), "M326");
    EXPECT_EQ(generateSoundex("GuruRandhaava"), "G653");
    EXPECT_EQ(generateSoundex("NeilNithinMukesh"), "N453");
    EXPECT_EQ(generateSoundex("KrishnaVamshi"), "K625");
    EXPECT_EQ(generateSoundex("SathishKumar"), "S325");
}

// Test cases for the names with hyphens or spaces
TEST(SoundexTest, HandlesHyphensAndSpaces) {
    EXPECT_EQ(generateSoundex("Sai-Sudarshan"), "S236");
    EXPECT_EQ(generateSoundex("Dinesh-Karthik"), "D526");
    EXPECT_EQ(generateSoundex("Om Shakthi"), "O523");
    EXPECT_EQ(generateSoundex("Shree Devi"), "S631");
    EXPECT_EQ(generateSoundex("Tik-tok"), "T232");
    EXPECT_EQ(generateSoundex("Virat Kohli"), "V632");
}

// Test cases for the names with non-alphabetic characters
TEST(SoundexTest, HandlesNonAlphabeticCharacters) {
    EXPECT_EQ(generateSoundex("R'Sharma"), "R265");
    EXPECT_EQ(generateSoundex("M@630Satellite"), "M234");
}
