#ifndef MF_MFBUFFER_H
#define MF_MFBUFFER_H
#include <cinttypes>

namespace MF
{
    template<uint32_t SIZE>
    class MFBuffer
    {
    public:
        uint32_t m_Size;
        uint8_t m_Buffer[SIZE];
    
    public:
        void Reset();
    };

    template<uint32_t SIZE>
    void MFBuffer<SIZE>::Reset()
    {
        m_Size = static_cast<uint32_t>(0UL);
    }

} // namespace MF

#endif // MF_MFBUFFER_H