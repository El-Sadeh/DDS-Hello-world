

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "HelloWorld.hpp"
#include "HelloWorldPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- TemperatureStruct: 

TemperatureStruct::TemperatureStruct() :
    m_temp_ (0)  {
}   

TemperatureStruct::TemperatureStruct (
    int16_t temp)
    :
        m_temp_( temp ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
TemperatureStruct::TemperatureStruct(TemperatureStruct&& other_) OMG_NOEXCEPT  :m_temp_ (std::move(other_.m_temp_))
{
} 

TemperatureStruct& TemperatureStruct::operator=(TemperatureStruct&&  other_) OMG_NOEXCEPT {
    TemperatureStruct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void TemperatureStruct::swap(TemperatureStruct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_temp_, other_.m_temp_);
}  

bool TemperatureStruct::operator == (const TemperatureStruct& other_) const {
    if (m_temp_ != other_.m_temp_) {
        return false;
    }
    return true;
}
bool TemperatureStruct::operator != (const TemperatureStruct& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
int16_t& TemperatureStruct::temp() OMG_NOEXCEPT {
    return m_temp_;
}

const int16_t& TemperatureStruct::temp() const OMG_NOEXCEPT {
    return m_temp_;
}

void TemperatureStruct::temp(int16_t value) {
    m_temp_ = value;
}

std::ostream& operator << (std::ostream& o,const TemperatureStruct& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "temp: " << sample.temp() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<TemperatureStruct> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member TemperatureStruct_g_tc_members[1]=
                {

                    {
                        (char *)"temp",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode TemperatureStruct_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"TemperatureStruct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        TemperatureStruct_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for TemperatureStruct*/

                if (is_initialized) {
                    return &TemperatureStruct_g_tc;
                }

                TemperatureStruct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                is_initialized = RTI_TRUE;

                return &TemperatureStruct_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<TemperatureStruct>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<TemperatureStruct>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<TemperatureStruct>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                TemperatureStructPlugin_new,
                TemperatureStructPlugin_delete);
        }

        std::vector<char>& topic_type_support<TemperatureStruct>::to_cdr_buffer(
            std::vector<char>& buffer, const TemperatureStruct& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = TemperatureStructPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = TemperatureStructPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<TemperatureStruct>::from_cdr_buffer(TemperatureStruct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = TemperatureStructPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create TemperatureStruct from cdr buffer");
        }

        void topic_type_support<TemperatureStruct>::reset_sample(TemperatureStruct& sample) 
        {
            rti::topic::reset_sample(sample.temp());
        }

        void topic_type_support<TemperatureStruct>::allocate_sample(TemperatureStruct& sample, int, int) 
        {
        }

    }
}  

