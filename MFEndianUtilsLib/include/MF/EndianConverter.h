#ifndef MF_ENDIANCONVERTER_H
#define MF_ENDIANCONVERTER_H
#include "MF/EnumEndianType.h"
#include <cinttypes>
namespace MF
{
    class EndianConverter
    {
    public:
        static EnumEndianType GetSystemEndiannes();
        template<typename T>
        static void Convert(const EnumEndianType fromEndian, const EnumEndianType toEndian, T &t);

    private:
        static bool IsSwapRequired(const EnumEndianType fromEndian, const EnumEndianType toEndian);
        static void Swap(uint16_t &u16);
        static void Swap(uint32_t &u32);
        static void Swap(uint64_t &u64);
    };

    template<typename T>
    void EndianConverter::Convert(const EnumEndianType fromEndian, const EnumEndianType toEndian, T &t)
    {
        if (IsSwapRequired(fromEndian, toEndian))
        {
            constexpr uint8_t TSIZE = static_cast<uint8_t>(sizeof(T));
            switch (TSIZE)
            {
            case 2U:
                Swap(reinterpret_cast<uint16_t&>(t));
                break;

            case 4U:
                Swap(reinterpret_cast<uint32_t&>(t));
                break;

            case 8U:
                Swap(reinterpret_cast<uint64_t&>(t));
                break;
            
            default:
                break;
            }
        }
    }

} // namespace MF

#endif // MF_ENDIANCONVERTER_H