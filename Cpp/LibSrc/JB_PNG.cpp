
#ifndef AS_LIBRARY
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBIW_WINDOWS_UTF8
#include "stb_image_write.h"


extern "C" {
    extern stbi_write_func JB_File_WriteRaw_;
    int JB_File_WritePng(void* file, int w, int h, const void *data) {
        stbi_write_png_compression_level = 9;
        return stbi_write_png_to_func(JB_File_WriteRaw_, file, w, h, 4, data, w*4);
    }
}
#else

// stop linker errors.
extern "C" void Stub_JB_PNG () {
    
}

#endif
