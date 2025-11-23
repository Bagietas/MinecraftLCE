#pragma once

#include "NX/Render/C4JRender.h"
#include "TextureAtlas.h"
#include "net/minecraft/world/ArrayWithLength.h"
#include <string>

class BufferedImage;
class TexturePackRepository;
class Options;
class ResourceLocation;

enum _TEXTURE_NAME : unsigned int { GRASS_COLOR, FOLIAGE_COLOR };

class Textures {
public:
    Textures(TexturePackRepository*, Options*);

    void stitch();
    arrayWithLength<int> loadTexturePixels(_TEXTURE_NAME name, const std::wstring&);
    arrayWithLength<int> loadTexturePixels(BufferedImage* image);
    int loadTexture(int);
    void readImage(_TEXTURE_NAME name, const std::wstring&);
    int getTexture(BufferedImage* image, C4JRender::eTextureFormat format, bool);
    void replaceTextureDirect(arrayWithLength<int> pixels, int width, int height, int textureId);
    void bind(int textureId);
    void bindTexture(const ResourceLocation*);

    static bool IsTUImage(_TEXTURE_NAME name, const std::wstring&);
    static bool IsOriginalImage(_TEXTURE_NAME name, const std::wstring&);

    unsigned char padding[256];
    TextureAtlas* atlas;
    TextureAtlas* atlas2;
    void* padding2;
};
