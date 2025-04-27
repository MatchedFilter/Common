#include "MF/EndianConverter.h"

namespace MF
{
    static const uint32_t s_TempValue = static_cast<uint32_t>(0x01UL);
    static const uint8_t *const s_TempPointer = reinterpret_cast<const uint8_t*>(&s_TempValue);
    static const EnumEndianType s_SystemEndianType = ((*s_TempPointer) == static_cast<uint8_t>(0x01U)) ? ENDIAN_TYPE_LITTLE : ENDIAN_TYPE_BIG;


    EnumEndianType EndianConverter::GetSystemEndiannes()
    {
        return s_SystemEndianType;
    }


    bool EndianConverter::IsSwapRequired(const EnumEndianType fromEndian, const EnumEndianType toEndian)
    {
        bool bResult = false;
        switch (fromEndian)
        {
        case ENDIAN_TYPE_BIG:
        {

            if ((toEndian == ENDIAN_TYPE_LITTLE) ||
                ((toEndian == ENDIAN_TYPE_NATIVE) && (s_SystemEndianType == ENDIAN_TYPE_LITTLE))
            )
            {
                bResult = true;
            }
            break;
        }
        
        case ENDIAN_TYPE_LITTLE:
        {
            if ((toEndian == ENDIAN_TYPE_BIG) ||
                ((toEndian == ENDIAN_TYPE_NATIVE) && (s_SystemEndianType == ENDIAN_TYPE_BIG))
            )
            {
                bResult = true;
            }
            break;
        }

        case ENDIAN_TYPE_NATIVE:
        {
            if (((s_SystemEndianType == ENDIAN_TYPE_BIG) && (toEndian == ENDIAN_TYPE_LITTLE)) ||
                ((s_SystemEndianType == ENDIAN_TYPE_LITTLE) && (toEndian == ENDIAN_TYPE_BIG))
            )
            {
                bResult = true;
            }
            break;
        }

        default:
            break;
        }
        return bResult;
    }


    void EndianConverter::Swap(uint16_t &u16)
    {
        u16 = static_cast<uint16_t>((u16 & static_cast<uint16_t>(0xFF00U)) >> static_cast<uint16_t>(8UL) |
                                    (u16 & static_cast<uint16_t>(0x00FFU)) << static_cast<uint16_t>(8UL));
    }

    void EndianConverter::Swap(uint32_t &u32)
    {
        u32 =   ((u32 & static_cast<uint32_t>(0xFF000000UL)) >> static_cast<uint32_t>(24UL)) |
                ((u32 & static_cast<uint32_t>(0x00FF0000UL)) >> static_cast<uint32_t>(8UL)) |
                ((u32 & static_cast<uint32_t>(0x0000FF00UL)) << static_cast<uint32_t>(8UL)) |
                ((u32 & static_cast<uint32_t>(0x000000FFUL)) << static_cast<uint32_t>(24UL));
    }

    void EndianConverter::Swap(uint64_t &u64)
    {
        u64 =   static_cast<uint64_t>((u64 & static_cast<uint64_t>(0xFF00000000000000ULL)) >> static_cast<uint64_t>(56UL)) |
                static_cast<uint64_t>((u64 & static_cast<uint64_t>(0x00FF000000000000ULL)) >> static_cast<uint64_t>(40UL)) |
                static_cast<uint64_t>((u64 & static_cast<uint64_t>(0x0000FF0000000000ULL)) >> static_cast<uint64_t>(24UL)) |
                static_cast<uint64_t>((u64 & static_cast<uint64_t>(0x000000FF00000000ULL)) >> static_cast<uint64_t>(8UL)) |
                static_cast<uint64_t>((u64 & static_cast<uint64_t>(0x00000000FF000000ULL)) << static_cast<uint64_t>(8UL)) |
                static_cast<uint64_t>((u64 & static_cast<uint64_t>(0x0000000000FF0000ULL)) << static_cast<uint64_t>(24UL)) |
                static_cast<uint64_t>((u64 & static_cast<uint64_t>(0x000000000000FF00ULL)) << static_cast<uint64_t>(40UL)) |
                static_cast<uint64_t>((u64 & static_cast<uint64_t>(0x00000000000000FFULL)) << static_cast<uint64_t>(56UL));
    }



} // namespace MF
