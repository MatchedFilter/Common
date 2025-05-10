#ifndef MF_BYTESTREAMWRITER_H
#define MF_BYTESTREAMWRITER_H
#include "MF/MFBuffer.h"
#include "MF/EnumEndianType.h"
#include "MF/EndianConverter.h"
namespace MF
{
    template<uint32_t SIZE>
    class ByteStreamWriter
    {
    public:
        ByteStreamWriter(MFBuffer<SIZE> &buffer);
        ~ByteStreamWriter();
        inline uint32_t GetStreamIndex() const { return m_Index; }
        inline uint32_t GetRemainingSize() const { return m_MFBuffer.m_Size - m_Index; }
        bool SetStreamIndex(const uint32_t index);
        template<typename T>
        bool WriteByte(const T t);
        template<typename T>
        bool Write2Bytes(const T t, const EnumEndianType endianType);
        template<typename T>
        bool Write4Bytes(const T t, const EnumEndianType endianType);
        template<typename T>
        bool Write8Bytes(const T t, const EnumEndianType endianType);

    private:
        MFBuffer<SIZE> &m_MFBuffer;
        uint32_t m_Index;
    };

    template<uint32_t SIZE>
    ByteStreamWriter<SIZE>::ByteStreamWriter(MFBuffer<SIZE> &buffer) :
        m_MFBuffer { buffer },
        m_Index { static_cast<uint32_t>(0UL) }
    {
    }

    template<uint32_t SIZE>
    ByteStreamWriter<SIZE>::~ByteStreamWriter() { }

    template<uint32_t SIZE>
    bool ByteStreamWriter<SIZE>::SetStreamIndex(const uint32_t index)
    {
        bool bResult = false;
        if (index < SIZE)
        {
            bResult = true,
            m_Index = index;
        }
        return bResult;
    }

    template<uint32_t SIZE>
    template<typename T>
    bool ByteStreamWriter<SIZE>::WriteByte(const T t)
    {
        bool bResult = false;
        constexpr uint8_t TSIZE = static_cast<uint8_t>(sizeof(T));
        if (TSIZE >= 1U)
        {
            const uint32_t nextIndex = m_Index + static_cast<uint32_t>(1UL);
            if (nextIndex < SIZE)
            {
                if (nextIndex <= m_MFBuffer.m_Size)
                {
                    bResult = true;
                    if (TSIZE == 1U)
                    {
                        const uint8_t &writeValue = reinterpret_cast<const uint8_t&>(t);
                        m_MFBuffer.m_Buffer[m_Index] = writeValue;
                    }
                    else
                    {
                        const uint8_t writeValue = static_cast<uint8_t>(t);
                        m_MFBuffer.m_Buffer[m_Index] = writeValue;
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }

    template<uint32_t SIZE>
    template<typename T>
    bool ByteStreamWriter<SIZE>::Write2Bytes(const T t, const EnumEndianType endianType)
    {
        bool bResult = false;
        constexpr uint8_t TSIZE = static_cast<uint8_t>(sizeof(T));
        if (TSIZE >= 2U)
        {
            const uint32_t nextIndex = m_Index + static_cast<uint32_t>(2UL);
            if (nextIndex < SIZE)
            {
                if (nextIndex <= m_MFBuffer.m_Size)
                {
                    bResult = true;

                    uint16_t &u16R = reinterpret_cast<uint16_t&>(m_MFBuffer.m_Buffer[m_Index]);
                    if (TSIZE == 2U)
                    {
                        T tCopy = t;
                        uint16_t &u16Ref = reinterpret_cast<uint16_t&>(tCopy);
                        EndianConverter::Convert(ENDIAN_TYPE_NATIVE, endianType, u16Ref);
                        u16R = u16Ref;
                    }
                    else
                    {
                        uint16_t u16 = static_cast<uint16_t>(t);
                        EndianConverter::Convert(ENDIAN_TYPE_NATIVE, endianType, u16);
                        u16R = u16;
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }

    template<uint32_t SIZE>
    template<typename T>
    bool ByteStreamWriter<SIZE>::Write4Bytes(const T t, const EnumEndianType endianType)
    {
        bool bResult = false;
        constexpr uint8_t TSIZE = static_cast<uint8_t>(sizeof(T));
        if (TSIZE >= 4U)
        {
            const uint32_t nextIndex = m_Index + static_cast<uint32_t>(4UL);
            if (nextIndex < SIZE)
            {
                if (nextIndex <= m_MFBuffer.m_Size)
                {
                    bResult = true;

                    uint32_t &u32R = reinterpret_cast<uint32_t&>(m_MFBuffer.m_Buffer[m_Index]);
                    if (TSIZE == 4U)
                    {
                        T tCopy = t;
                        uint32_t &u32Ref = reinterpret_cast<uint32_t&>(tCopy);
                        EndianConverter::Convert(ENDIAN_TYPE_NATIVE, endianType, u32Ref);
                        u32R = u32Ref;
                    }
                    else
                    {
                        uint32_t u32 = static_cast<uint32_t>(t);
                        EndianConverter::Convert(ENDIAN_TYPE_NATIVE, endianType, u32);
                        u32R = u32;
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }


    template<uint32_t SIZE>
    template<typename T>
    bool ByteStreamWriter<SIZE>::Write8Bytes(const T t, const EnumEndianType endianType)
    {
        bool bResult = false;
        constexpr uint8_t TSIZE = static_cast<uint8_t>(sizeof(T));
        if (TSIZE >= 8U)
        {
            const uint32_t nextIndex = m_Index + static_cast<uint32_t>(8UL);
            if (nextIndex < SIZE)
            {
                if (nextIndex <= m_MFBuffer.m_Size)
                {
                    bResult = true;

                    uint64_t &u64R = reinterpret_cast<uint64_t&>(m_MFBuffer.m_Buffer[m_Index]);
                    if (TSIZE == 8U)
                    {
                        T tCopy = t;
                        uint64_t &u64Ref = reinterpret_cast<uint64_t&>(tCopy);
                        EndianConverter::Convert(ENDIAN_TYPE_NATIVE, endianType, u64Ref);
                        u64R = u64Ref;
                    }
                    else
                    {
                        uint64_t u64 = static_cast<uint32_t>(t);
                        EndianConverter::Convert(ENDIAN_TYPE_NATIVE, endianType, u64);
                        u64R = u64;
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }

} // namespace MF

#endif // MF_BYTESTREAMWRITER_H
