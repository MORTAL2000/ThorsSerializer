
#include "SerializeConfig.h"
#ifdef NETWORK_BYTE_ORDER
#include "BinaryParser.h"
#include <sstream>

using namespace ThorsAnvil::Serialize;

BinaryParserUtilBase::~BinaryParserUtilBase()
{}

BinaryParserUtilBase::BinaryParserUtilBase(bool root, ParserToken first, ParserToken last, ParserToken nextValue)
    : nextToken(first)
    , objClose(last)
    , objNextValue(nextValue)
    , position(0)
    , end(0)
    , root(root)
    , started(false)
    , finished(false)
{}

ParserToken BinaryParserUtilBase::getNextToken(ParserInterface& parser, ParserState& state)
{
    if (!started)
    {
        started     = true;
        end         = readSize(parser);
        if (root)
        {
            return ParserToken::DocStart;
        }
    }
    if (nextToken == ParserToken::MapStart || nextToken == ParserToken::ArrayStart)
    {
        ParserToken     result  = nextToken;
        nextToken = objNextValue;
        return result;
    }
    if (position < end)
    {
        switch(nextToken)
        {
            case ParserToken::Key:
                nextToken = ParserToken::Value;
                return ParserToken::Key;
            case ParserToken::Value:
                nextToken = objNextValue;
                ++position;
                return pushNextState(position - 1, parser, state, ParserToken::Value);
            default:
            {
                std::stringstream  message;
                message << "ThorsAnvil::Serialize::BinaryParserUtilBase::getNextToken:"
                        << " Was expecting Key/Value"
                        << " Got: ParserToken(" << static_cast<int>(nextToken) << ")";
                throw std::runtime_error(message.str());
            }
        }
    }
    if (!finished)
    {
        finished    = true;
        if (!root)
        {
            state.pop_back();
        }
        return objClose;
    }
    state.pop_back();
    return ParserToken::DocEnd;
}

#ifdef COVERAGE_TEST

/*
 * This code is only compiled into the unit tests for code coverage purposes
 * It is not part of the live code.
 */
#include "BinaryParser.tpp"
#include "test/BinaryParserTest.h"

namespace TAS = ThorsAnvil::Serialize;

template TAS::BinaryParserUtil<MapWithMap,      (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<MapOneValue,     (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<MapTwoValue,     (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<MapEmptyTest,    (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<MapWithArray,    (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<MapThreeValue,   (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<MapWithTwoMap,   (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<MapWithTwoArray, (TAS::TraitType)3>::BinaryParserUtil(bool);

template TAS::BinaryParserUtil<Base,            (TAS::TraitType)3>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<Derived,         (TAS::TraitType)1>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<int,             (TAS::TraitType)2>::BinaryParserUtil(bool);

// Array Specialization
template TAS::BinaryParserUtil<std::vector<MapEmptyTest>,     (TAS::TraitType)4>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<std::vector<std::string>,      (TAS::TraitType)4>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<std::vector<std::vector<int>>, (TAS::TraitType)4>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<std::vector<int>,              (TAS::TraitType)4>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<std::vector<bool>,             (TAS::TraitType)4>::BinaryParserUtil(bool);
template TAS::BinaryParserUtil<std::vector<double>,           (TAS::TraitType)4>::BinaryParserUtil(bool);
#endif
#endif

