#include <util/string.h>

#include <catch/catch.hpp>

TEST_CASE("split", "[string]") {
    SECTION("zero") {
        CHECK(util::split("", ',') == std::vector<std::string>{ "" });
        CHECK(util::split(" ", ',') == std::vector<std::string>{ " " });
        CHECK(util::split("a", ',') == std::vector<std::string>{ "a" });
        CHECK(util::split("abcd", ',') == std::vector<std::string>{ "abcd" });
    }

    SECTION("positive") {
        CHECK(util::split(",", ',') == std::vector<std::string>{ "", "" });
        CHECK(util::split("a,b", ',') == std::vector<std::string>{ "a", "b" });
        CHECK(util::split("a,b,c", ',') == std::vector<std::string>{ "a", "b", "c" });
        CHECK(util::split(",,,", ',') == std::vector<std::string>{ "", "", "", "" });
        CHECK(util::split("one,two,three", ',') == std::vector<std::string>{ "one", "two", "three" });
    }

    SECTION("negative") {
        CHECK(util::split("one,two,three", ' ') == std::vector<std::string>{ "one,two,three" });
    }
}

TEST_CASE("strip", "[string]") {
    std::string empty = "";
    std::string abc = "abc";

    SECTION("negative") {
        util::strip(empty, '"');
        CHECK(empty == "");

        util::strip(abc, '"');
        CHECK(abc == "abc");
    }

    SECTION("positive") {
        util::strip(abc, 'a');
        CHECK(abc == "bc");

        std::string a = "\"hello\"";
        util::strip(a, '"');
        CHECK(a == "hello");
    }
}
