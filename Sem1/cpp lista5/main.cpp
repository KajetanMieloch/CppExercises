#include "image.h"

int main()
{
    Image image;
    image.load("obrazek.ppm");
    for(int i = 0; i < 20; i++)
    {
        image.blurr();
    }
    image.add_watermark();
    image.extract_layer(ColorLayer::Red);
    image.flip_horizontally();
    image.flip_vertically();
    image.inflate();
    image.negative();
    image.rotate_clockwise_90();
    image.sepia();
    image.shrink();
    image.to_grayscale();
    image.filter();
    image.save_as("x.ppm");
    image.height();
    image.width();
    return 0;
}
