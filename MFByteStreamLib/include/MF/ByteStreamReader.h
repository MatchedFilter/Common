#ifndef MF_BYTESTREAMREADER_H
#define MF_BYTESTREAMREADER_H
#include "MF/MFBuffer.h"
#include "MF/EnumEndianType.h"
#include "MF/EndianConverter.h"
namespace MF
{
    template<uint32_t SIZE>
    class ByteStreamReader
    {
    public:
        ByteStreamReader(const MFBuffer<SIZE> &buffer);
        ~ByteStreamReader();
        inline uint32_t GetStreamIndex() const { return m_Index; }
        inline uint32_t GetRemainingSize() const { return m_MFBuffer.m_Size - m_Index; }
        bool SetStreamIndex(const uint32_t index);
        template<typename T>
        bool ReadByte(T &t);
        template<typename T>
        bool Read2Bytes(T &t, const EnumEndianType endianType);
        template<typename T>
        bool Read4Bytes(T &t, const EnumEndianType endianType);
        template<typename T>
        bool Read8Bytes(T &t, const EnumEndianType endianType);

    private:
        const MFBuffer<SIZE> &m_MFBuffer;
        uint32_t m_Index;
    };

    template<uint32_t SIZE>
    ByteStreamReader<SIZE>::ByteStreamReader(const MFBuffer<SIZE> &buffer) :
        m_MFBuffer { buffer },
        m_Index { static_cast<uint32_t>(0UL) }
    {
    }

    template<uint32_t SIZE>
    ByteStreamReader<SIZE>::~ByteStreamReader() { }

    template<uint32_t SIZE>
    bool ByteStreamReader<SIZE>::SetStreamIndex(const uint32_t index)
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
    bool ByteStreamReader<SIZE>::ReadByte(T &t)
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
                        const T &tCopy = reinterpret_cast<const T&>(m_MFBuffer.m_Buffer[m_Index]);
                        t = tCopy;
                    }
                    else
                    {
                        t = static_cast<T>(m_MFBuffer.m_Buffer[m_Index]);
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }

    template<uint32_t SIZE>
    template<typename T>
    bool ByteStreamReader<SIZE>::Read2Bytes(T &t, const EnumEndianType endianType)
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
                    const uint16_t &lReadValue = reinterpret_cast<const uint16_t&>(m_MFBuffer.m_Buffer[m_Index]);
                    uint32_t readValue = lReadValue;
                    EndianConverter::Convert(endianType, ENDIAN_TYPE_NATIVE, readValue);
                    if (TSIZE == 2U)
                    {
                        const T &tCopy = reinterpret_cast<const T&>(readValue);
                        t = tCopy;
                    }
                    else
                    {
                        t = static_cast<T>(readValue);
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }

    template<uint32_t SIZE>
    template<typename T>
    bool ByteStreamReader<SIZE>::Read4Bytes(T &t, const EnumEndianType endianType)
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
                    const uint32_t &lReadValue = reinterpret_cast<const uint32_t&>(m_MFBuffer.m_Buffer[m_Index]);
                    uint32_t readValue = lReadValue;
                    EndianConverter::Convert(endianType, ENDIAN_TYPE_NATIVE, readValue);
                    if (TSIZE == 4U)
                    {
                        const T &tCopy = reinterpret_cast<const T&>(readValue);
                        t = tCopy;
                    }
                    else
                    {
                        t = static_cast<T>(readValue);
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }

    template<uint32_t SIZE>
    template<typename T>
    bool ByteStreamReader<SIZE>::Read8Bytes(T &t, const EnumEndianType endianType)
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
                    const uint64_t &lReadValue = reinterpret_cast<const uint64_t&>(m_MFBuffer.m_Buffer[m_Index]);
                    uint64_t readValue = lReadValue;
                    EndianConverter::Convert(endianType, ENDIAN_TYPE_NATIVE, readValue);
                    if (TSIZE == 8U)
                    {
                        const T &tCopy = reinterpret_cast<const T&>(readValue);
                        t = tCopy;
                    }
                    else
                    {
                        t = static_cast<T>(readValue);
                    }
                    m_Index = nextIndex;
                }
            }
        }
        return bResult;
    }


} // namespace MF

#endif // MF_BYTESTREAMREADER_H
