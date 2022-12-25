#define NOMINMAX

#include "framework.h"
#include "bc7enc.h"
#include "bc7decomp.h"

#ifdef BC7ENCDLL_EXPORTS
extern "C"
{
    #define EXPORT_STDCALL __declspec(dllexport) __stdcall

    bool EXPORT_STDCALL UnpackBC7(const void *pBlock, bc7decomp::color_rgba *pPixels)
    {
        return bc7decomp::unpack_bc7(pBlock, pPixels);
    }

    void EXPORT_STDCALL BC7EncCompressBlockInit()
    {
        bc7enc_compress_block_init();
    }

    bool EXPORT_STDCALL  BC7EncCompressBlock(void* pBlock, void* pPixelsRGBA, const bc7enc_compress_block_params* pComp_params)
    {
        return bc7enc_compress_block(pBlock, pPixelsRGBA, pComp_params);
    }
}
#endif
