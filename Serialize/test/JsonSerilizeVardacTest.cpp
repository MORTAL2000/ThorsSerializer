
#include "gtest/gtest.h"
#include "json.h"

#include <map>

using ThorsAnvil::Serialize::jsonImport;
using ThorsAnvil::Serialize::jsonExport;

struct Config
{
    int         valInt;
    double      valDouble;
};

BUILD_SERIALIZE(void, Config, valInt, valDouble)
template<typename T>
std::string testAction(std::string const& expected)
{
    T                   object;

    std::stringstream   input(expected);
    input  >> jsonImport(object);

    std::stringstream   output;
    output << jsonExport(object);

    return output.str();
}

extern void ValidateSerializedStrings(std::string lhs, std::string rhs);


TEST(JsonSerializeVardac, Serialize)
{
    std::string input   = "{\"valInt\": 12, \"valDouble\":1234.45}";
    std::string result  = testAction<Config>(input);
    ValidateSerializedStrings(input, result);
}
