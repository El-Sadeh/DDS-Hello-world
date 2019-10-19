

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef HelloWorld_1436885486_hpp
#define HelloWorld_1436885486_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport TemperatureStruct {

  public:
    TemperatureStruct();

    explicit TemperatureStruct(
        int16_t temp);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    TemperatureStruct (TemperatureStruct&&) = default;
    TemperatureStruct& operator=(TemperatureStruct&&) = default;
    TemperatureStruct& operator=(const TemperatureStruct&) = default;
    TemperatureStruct(const TemperatureStruct&) = default;
    #else
    TemperatureStruct(TemperatureStruct&& other_) OMG_NOEXCEPT;  
    TemperatureStruct& operator=(TemperatureStruct&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int16_t& temp() OMG_NOEXCEPT; 
    const int16_t& temp() const OMG_NOEXCEPT;
    void temp(int16_t value);

    bool operator == (const TemperatureStruct& other_) const;
    bool operator != (const TemperatureStruct& other_) const;

    void swap(TemperatureStruct& other_) OMG_NOEXCEPT ;

  private:

    int16_t m_temp_;

};

inline void swap(TemperatureStruct& a, TemperatureStruct& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const TemperatureStruct& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<TemperatureStruct> {
            NDDSUSERDllExport static std::string value() {
                return "TemperatureStruct";
            }
        };

        template<>
        struct is_topic_type<TemperatureStruct> : public dds::core::true_type {};

        template<>
        struct topic_type_support<TemperatureStruct> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const TemperatureStruct& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(TemperatureStruct& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(TemperatureStruct& sample);

            NDDSUSERDllExport 
            static void allocate_sample(TemperatureStruct& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<TemperatureStruct> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<TemperatureStruct> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // HelloWorld_1436885486_hpp
