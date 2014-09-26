
#ifndef THORSANVIL_SERIALIZER_SERIALIZER_H
#define THORSANVIL_SERIALIZER_SERIALIZER_H

#include "Parser/ScannerSax.h"
#include <boost/mpl/vector.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <boost/type_traits/is_same.hpp>
#include <istream>
#include <tuple>

#define THOR_BUILD_SERIALIZE_COUNT_ARGS(...)             THOR_BUILD_SERIALIZE_COUNT_ARGS_ACT( __VA_ARGS__, 20,19, 18, 17, 16, 15, 14,13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 )
#define THOR_BUILD_SERIALIZE_COUNT_ARGS_ACT(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,N,...)   N

#define THORSANVIL_SERIALIZE_JsonAttribute(x)                     typedef int x
#define THOR_BUILD_Attribute_Type(OType, Type, ...)                      THOR_BUILD_Attribute_TypeC1(THOR_BUILD_SERIALIZE_COUNT_ARGS(__VA_ARGS__), OType, Type, __VA_ARGS__)
#define THOR_BUILD_Attribute_TypeC1(Count, OType, Type, ...)             THOR_BUILD_Attribute_TypeC2(Count, OType, Type, __VA_ARGS__)
#define THOR_BUILD_Attribute_TypeC2(Count, OType, Type, ...)             THOR_BUILD_Attribute_Type ## Count(OType, Type, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type20(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type19(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type19(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type18(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type18(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type17(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type17(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type16(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type16(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type15(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type15(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type14(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type14(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type13(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type13(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type12(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type12(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type11(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type11(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type10(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type10(OType, Type, local, member, ...)     OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type9(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type9(OType, Type, local, member, ...)      OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type8(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type8(OType, Type, local, member, ...)      OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type7(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type7(OType, Type, local, member, ...)      OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type6(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type6(OType, Type, local, member, ...)      OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type5(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type5(OType, Type, local, member, ...)      OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type4(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type4(OType, Type, local, member, ...)      OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type3(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type3(OType, Type, local, member, ...)      OType<local, decltype(&local::member), Type>, THOR_BUILD_Attribute_Type2(OType, Type, local, __VA_ARGS__)
#define THOR_BUILD_Attribute_Type2(OType, Type, local, member)           OType<local, decltype(&local::member), Type>
#define THOR_BUILD_Attribute_Type1(OType, Type, local)

#define THOR_BUILD_Initialize_Val(Sc, Obj, ...)                  THOR_BUILD_Initialize_ValC1(THOR_BUILD_SERIALIZE_COUNT_ARGS(__VA_ARGS__), Sc, Obj, __VA_ARGS__)
#define THOR_BUILD_Initialize_ValC1(Count, Sc, Obj, ...)         THOR_BUILD_Initialize_ValC2(Count, Sc, Obj, __VA_ARGS__)
#define THOR_BUILD_Initialize_ValC2(Count, Sc, Obj, ...)         THOR_BUILD_Initialize_Val ## Count(Sc, Obj, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val20(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val19(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val19(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val18(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val18(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val17(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val17(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val16(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val16(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val15(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val15(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val14(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val14(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val13(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val13(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val12(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val12(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val11(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val11(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val10(Sc, Obj, local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val10(Sc, Obj, local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val9(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val9(Sc, Obj,  local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val8(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val8(Sc, Obj,  local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val7(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val7(Sc, Obj,  local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val6(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val6(Sc, Obj,  local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val5(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val5(Sc, Obj,  local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val4(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val4(Sc, Obj,  local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val3(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val3(Sc, Obj,  local, member, ...) { Sc, Obj, #member, &local::member }, THOR_BUILD_Initialize_Val2(Sc, Obj,  local, __VA_ARGS__)
#define THOR_BUILD_Initialize_Val2(Sc, Obj,  local, member)      { Sc, Obj, #member, &local::member }
#define THOR_BUILD_Initialize_Val1(Sc, Obj,  local)

#define THOR_BUILD_GetLocal(...)                THOR_BUILD_GetLocal_C1(THOR_BUILD_SERIALIZE_COUNT_ARGS(__VA_ARGS__), __VA_ARGS__)
#define THOR_BUILD_GetLocal_C1(Count, ...)      THOR_BUILD_GetLocal_C2(Count, __VA_ARGS__)
#define THOR_BUILD_GetLocal_C2(Count, ...)      THOR_BUILD_GetLocal ## Count(__VA_ARGS__)
#define THOR_BUILD_GetLocal20(local, ...)       local
#define THOR_BUILD_GetLocal19(local, ...)       local
#define THOR_BUILD_GetLocal18(local, ...)       local
#define THOR_BUILD_GetLocal17(local, ...)       local
#define THOR_BUILD_GetLocal16(local, ...)       local
#define THOR_BUILD_GetLocal15(local, ...)       local
#define THOR_BUILD_GetLocal14(local, ...)       local
#define THOR_BUILD_GetLocal13(local, ...)       local
#define THOR_BUILD_GetLocal12(local, ...)       local
#define THOR_BUILD_GetLocal11(local, ...)       local
#define THOR_BUILD_GetLocal10(local, ...)       local
#define THOR_BUILD_GetLocal9(local, ...)        local
#define THOR_BUILD_GetLocal8(local, ...)        local
#define THOR_BUILD_GetLocal7(local, ...)        local
#define THOR_BUILD_GetLocal6(local, ...)        local
#define THOR_BUILD_GetLocal5(local, ...)        local
#define THOR_BUILD_GetLocal4(local, ...)        local
#define THOR_BUILD_GetLocal3(local, ...)        local
#define THOR_BUILD_GetLocal2(local, ...)        local
#define THOR_BUILD_GetLocal1(local)             local

/*
#
# Arguments.
#   parent:     Type of the parent.
#   local:      Type of the class we want to serialize.
#   members*:   Name of 0 or more members that need to be serialized.
*/
#define THOR_BUILD_SERIALIZE(Type, parent, ...)                                         \
namespace ThorsAnvil                                                                    \
{                                                                                       \
    namespace Serialize                                                                 \
    {                                                                                   \
        namespace Json                                                                  \
        {                                                                               \
            template<>                                                                  \
            class JsonSerializeTraits<THOR_BUILD_GetLocal(__VA_ARGS__)>                 \
            {                                                                           \
                typedef std::tuple<                                                     \
                    THOR_BUILD_Attribute_Type(MemberScanner, Type, __VA_ARGS__)         \
                          >   Scanners;                                                 \
                typedef std::tuple<                                                     \
                    THOR_BUILD_Attribute_Type(MemberPrinter, Type, __VA_ARGS__)         \
                          >   Printers;                                                 \
                public:                                                                 \
                enum { type = Type };                                                   \
                using   LocalType = THOR_BUILD_GetLocal(__VA_ARGS__);                   \
                                                                                        \
                static void scanner(Parser::ScannerBaseSax& scanner, LocalType& object) \
                {                                                                       \
                    Scanners{                                                           \
                        THOR_BUILD_Initialize_Val(scanner, object, __VA_ARGS__)         \
                    };                                                                  \
                }                                                                       \
                static void printer(Parser::PrinterBaseSax& printer, LocalType const& object)   \
                {                                                                       \
                    ObjectPrinter<Type> objectPrinter(printer);                         \
                    Printers{                                                           \
                        THOR_BUILD_Initialize_Val(printer, object, __VA_ARGS__)         \
                    };                                                                  \
                }                                                                       \
            };                                                                          \
        }                                                                               \
    }                                                                                   \
}

#define JsonSerializeTraits_MAKE(parent, ...)    THOR_BUILD_SERIALIZE(ThorsAnvil::Serialize::Json::Map, parent, __VA_ARGS__)


namespace ThorsAnvil
{
    namespace Parser
    {
        class PrinterBaseSax
        {
            protected:
                std::ostream&   stream;

            public:
                PrinterBaseSax(std::ostream& stream)
                    : stream(stream)
                {}
                template<typename T>
                PrinterBaseSax& operator<<(T const& val)    {stream << val;return *this;}

                virtual void    docBeg()            {}
                virtual void    docEnd()            {}
                virtual void    arrayBeg()          = 0;
                virtual void    arrayEnd()          = 0;
                virtual void    mapBeg()            = 0;
                virtual void    mapEnd()            = 0;
        };
    }
    namespace Json
    {
        class JsonPrinterSax: public Parser::PrinterBaseSax
        {
            public:
                JsonPrinterSax(std::ostream& stream)
                    : PrinterBaseSax(stream)
                {}

                virtual void    arrayBeg()          {stream << '[';}
                virtual void    arrayEnd()          {stream << ']';}
                virtual void    mapBeg()            {stream << '{';}
                virtual void    mapEnd()            {stream << '}';}
        };
    }

    namespace Utility
    {
        template<typename T>
        struct FundamentalSerializable: boost::integral_constant<bool, boost::is_fundamental<T>::value && !boost::is_same<T, void>::value >
        { };
    }
    namespace Serialize
    {
        namespace Json
        {
            enum JsonSerializeType {Invalid, Array, Map};

            template<typename T, bool fundamental = Utility::FundamentalSerializable<T>::value>
            class JsonSerializeTraits
            {
                public:
                    enum { type = Invalid };
                    static void scanner(Parser::ScannerBaseSax&,T&)
                    {}
                    static void printer(Parser::PrinterBaseSax&,T const&)
                    {}
            };

            template<typename T>
            class JsonSerializeTraits<T, true>
            {
                public:
                    enum { type = Invalid };
                    static void scanner(Parser::ScannerBaseSax&,T&)
                    {}
                    static void printer(Parser::PrinterBaseSax& printer,T const& object)
                    {
                        printer << object;
                    }
            };
        }

template<typename ValueType, int TypeSpecialization>
struct DoActionForMember;
template<typename ValueType, int TypeSpecialization>
struct DoPreActionForMember;

template<int TypeSpecialization>
class ObjectPrinter;
template<int TypeSpecialization>
class PrefixPrinter;

template<>
class ObjectPrinter<Json::Map>
{
    Parser::PrinterBaseSax& printer;
    public:
        ObjectPrinter(Parser::PrinterBaseSax& printer)
            : printer(printer)
        {
            printer.mapBeg();
        }
        ~ObjectPrinter()
        {
            printer.mapEnd();
        }
};
template<>
class ObjectPrinter<Json::Array>
{
    Parser::PrinterBaseSax& printer;
    public:
        ObjectPrinter(Parser::PrinterBaseSax& printer)
            : printer(printer)
        {
            printer.arrayBeg();
        }
        ~ObjectPrinter()
        {
            printer.arrayEnd();
        }
};
template<>
class PrefixPrinter<Json::Map>
{
    public:
        PrefixPrinter(Parser::PrinterBaseSax& printer, std::string const& name)
        {
            printer << ",\"" << name << "\": ";
        }
};
template<>
class PrefixPrinter<Json::Array>
{
    public:
        PrefixPrinter(Parser::PrinterBaseSax& printer, std::string const&)
        {
            printer << ",";
        }
};


template<typename T, typename M, int TypeSpecialization>
class MemberScanner
{
    using SelfPtr       =  T*;
    using ValueTypeRef  =  decltype((SelfPtr(nullptr))->*(M(nullptr)));
    using ValueType     =  typename std::remove_reference<ValueTypeRef>::type;

    T&                  object;
    M                   dst;

    class MemberScannerAction: public Parser::SaxAction
    {
        MemberScanner&   member;
        virtual void doAction(Parser::ScannerBaseSax& scanner, Parser::Key const& key, Parser::ParserValue const& value)
        {
            T&      object   = this->member.object;
            M&      dst      = this->member.dst;

            DoActionForMember<ValueType, TypeSpecialization>    action;
            action(scanner, key, value, (object.*dst));
        }
        virtual void doPreAction(Parser::ScannerBaseSax& scanner, Parser::Key const& key)
        {
            T&      object   = this->member.object;
            M&      dst      = this->member.dst;

            DoPreActionForMember<ValueType, TypeSpecialization>    action;
            action(scanner, key, (object.*dst));
        }
        public:
            MemberScannerAction(MemberScanner& member)
                : member(member)
            {}
    };

    friend class MemberScannerAction;
    public:
        MemberScanner(Parser::ScannerBaseSax& serializer, T& object, std::string const& name, M dst)
            : object(object)
            , dst(dst)
        {
            // 87         ActionRefNote   registerAction(std::string const& mapItem, std::unique_ptr<SaxAction> action);
            // 88         ActionRefNote   registerActionNext(std::unique_ptr<SaxAction> action);
            // 89         ActionRefNote   registerActionOnAllMapItems(std::unique_ptr<SaxAction> action);
            // 90         ActionRefNote   registerActionOnAllArrItems(std::unique_ptr<SaxAction> action);
            std::unique_ptr<Parser::SaxAction>  action(new MemberScannerAction(*this));
            serializer.registerAction(name, std::move(action));
        }
};
template<typename T, typename M, int TypeSpecialization>
class MemberPrinter
{
    public:
        MemberPrinter(Parser::PrinterBaseSax& printer, T const& object, std::string const& name, M src)
        {
            PrefixPrinter<TypeSpecialization>   prefixPrinter(printer, name);

            using ObjRefType    = decltype(const_cast<T&>(object).*src);
            using ObjType       = typename std::remove_reference<ObjRefType>::type;
            using Traits        = ThorsAnvil::Serialize::Json::JsonSerializeTraits<ObjType>;
            Traits::printer(printer, (object.*src));
        }
};

template<typename ValueType>
struct DoActionForMember<ValueType, ThorsAnvil::Serialize::Json::Invalid>
{
    void operator()(Parser::ScannerBaseSax&, Parser::Key const&, Parser::ParserValue const& value, ValueType& dest)
    {
        dest    = value.getValue<ValueType>();
    }
};
template<typename ValueType>
struct DoActionForMember<ValueType, ThorsAnvil::Serialize::Json::Map>
{
    void operator()(Parser::ScannerBaseSax&, Parser::Key const&, Parser::ParserValue const&, ValueType&)
    {}
};
/*
template<typename ValueType>
struct DoActionForMember<ValueType, ThorsAnvil::Serialize::Json::Array>
{
    void operator()(Parser::ScannerBaseSax&, Parser::Key const&, Parser::ParserValue const&, ValueType&)
    {
    }
};
*/
template<typename ValueType>
struct DoPreActionForMember<ValueType, ThorsAnvil::Serialize::Json::Invalid>
{
    void operator()(Parser::ScannerBaseSax&, Parser::Key const&, ValueType&)
    {}
};
template<typename ValueType>
struct DoPreActionForMember<ValueType, ThorsAnvil::Serialize::Json::Map>
{
    void operator()(Parser::ScannerBaseSax&, Parser::Key const&, ValueType&)
    {
        /*
        typedef ThorsAnvil::Serialize::Json::JsonSerializeTraits<ValueType>    Traits;

        Traits          traits(serializer, object);
        serializer.parse(stream);
        */
    }
};
/*
template<typename ValueType>
struct DoPreActionForMember<ValueType, ThorsAnvil::Serialize::Json::Array>
{
    void operator()(Parser::ScannerBaseSax&, Parser::Key const&, ValueType&)
    {
    }
};
*/

template<typename T, typename Serializer>
class Importer
{
    T&  object;
    public:
        Importer(T& object)
            : object(object)
        {}

    friend std::istream& operator>>(std::istream& stream, Importer<T, Serializer> const& data)
    {
        typedef ThorsAnvil::Serialize::Json::JsonSerializeTraits<T>    Traits;

        Serializer      serializer;
        Traits::scanner(serializer, data.object);

        serializer.parse(stream);
        return stream;
    }
};
template<typename T, typename Printer>
class Exporter
{
    T const& object;
    public:
        Exporter(T const& object)
            : object(object)
        {}

    friend std::ostream& operator<<(std::ostream& stream, Exporter<T, Printer> const& data)
    {
        typedef ThorsAnvil::Serialize::Json::JsonSerializeTraits<T>    Traits;

        Printer      printer(stream);
        printer.docBeg();
        Traits::printer(printer, data.object);
        printer.docEnd();

        return stream;
    }
};

    }
}

#endif

