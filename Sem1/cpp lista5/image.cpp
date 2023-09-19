#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::load(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    std::ifstream in(filename, std::ios::binary);
    if (!in) throw std::invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;
    if (magic != MAGIC) throw std::logic_error("unknown magic naumber " + magic);

    in >> my_width >> my_height >> color_depth;

    if (!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw std::logic_error("invalid image parameter(s): " + std::to_string(my_width) + " " +
                               std::to_string(my_height) + " " + std::to_string(color_depth));
    in.ignore(1);
    pixels.resize(my_height);
    for (auto& line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
        if (!in) throw std::logic_error("failed to read binary pixel data from file " + filename);
    }
}
void Image::save_as(const std::string& filename)
{
    std::ofstream out(filename, std::ios::binary);
    if (!out) throw std::invalid_argument("failed to open \"" + filename + "\"");

    out << magic << "\n" << my_width << " " << my_height << "\n" << color_depth << "\n";

    for (const auto& line : pixels)
    {
        out.write(reinterpret_cast<const char*>(&line[0]), my_width * sizeof(RGB));
        if (!out) throw std::logic_error("failed to write binary pixel data to file " + filename);
    }
}
void Image::add_watermark()
{
    for(auto& line : pixels)
    {
        for(int i = 0; i < my_width; i++)
        {
            if(!(i<my_width/2|| i>my_width*6/11))
            {
                line[i].red = line[i].red/2;
                line[i].green = line[i].green/2;
                line[i].blue = line[i].blue/2;
            }
        }
    }
}
void Image::blurr()
{
    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            if(i != 0 && i != my_height-1 && j != 0 && j != my_width-1)
            {
                pixels[i][j].red = (pixels[i-1][j-1].red + pixels[i-1][j].red + pixels[i-1][j+1].red + pixels[i][j-1].red + pixels[i][j].red + pixels[i][j+1].red + pixels[i+1][j-1].red + pixels[i+1][j].red + pixels[i+1][j+1].red)/9;
                pixels[i][j].green = (pixels[i-1][j-1].green + pixels[i-1][j].green + pixels[i-1][j+1].green + pixels[i][j-1].green + pixels[i][j].green + pixels[i][j+1].green + pixels[i+1][j-1].green + pixels[i+1][j].green + pixels[i+1][j+1].green)/9;
                pixels[i][j].blue = (pixels[i-1][j-1].blue + pixels[i-1][j].blue + pixels[i-1][j+1].blue + pixels[i][j-1].blue + pixels[i][j].blue + pixels[i][j+1].blue + pixels[i+1][j-1].blue + pixels[i+1][j].blue + pixels[i+1][j+1].blue)/9;
            }
        }
    }
}
void Image::extract_layer(ColorLayer color_layer) {

    for (int w = 0; w <= my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            if (color_layer == ColorLayer::Red) {
                pixels[h][w].green = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Green) {
                pixels[h][w].red = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Blue) {
                pixels[h][w].red = 0;
                pixels[h][w].green = 0;
            }
        }
    }
}
void Image::flip_horizontally()
{
    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width/2; j++)
        {
            std::swap(pixels[i][j], pixels[i][my_width-j-1]);
        }
    }
}
void Image::flip_vertically()
{
    for(int i = 0; i < my_height/2; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            std::swap(pixels[i][j], pixels[my_height-i-1][j]);
        }
    }
}
void Image::inflate()
{
    int x = 0;
    int y = 0;

    for (int w = 0; w <= my_width - 1; w += 2) {
        for (int h = 0; h < my_height - 1; h += 2) {
            pixels[h][w] = pixels[y][x];
            pixels[h][w + 1] = pixels[y][x];
            pixels[h + 1][w] = pixels[y][x];
            pixels[h + 1][w + 1] = pixels[y][x];
            y++;
        }

        y = 0;
        x++;
    }
}
void Image::negative()
{
    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            pixels[i][j].red = 255 - pixels[i][j].red;
            pixels[i][j].green = 255 - pixels[i][j].green;
            pixels[i][j].blue = 255 - pixels[i][j].blue;
        }
    }
}
void Image::rotate_clockwise_90()
{
    std::vector<std::vector<RGB>> temp;
    temp.resize(my_width);
    for(auto& line : temp)
    {
        line.resize(my_height);
    }
    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            temp[j][my_height-i-1] = pixels[i][j];
        }
    }
    std::swap(my_height, my_width);
    pixels = temp;
}
void Image::sepia()
{
    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            int r = pixels[i][j].red;
            int g = pixels[i][j].green;
            int b = pixels[i][j].blue;
            pixels[i][j].red = std::min(255, static_cast<int>(0.393 * r + 0.769 * g + 0.189 * b));
            pixels[i][j].green = std::min(255, static_cast<int>(0.349 * r + 0.686 * g + 0.168 * b));
            pixels[i][j].blue = std::min(255, static_cast<int>(0.272 * r + 0.534 * g + 0.131 * b));
        }
    }
}
void Image::shrink()
{
    int x = 0;
    int y = 0;

    std::vector<std::vector<RGB>> temp;
    temp.resize(my_height/2);
    for(auto& line : temp)
    {
        line.resize(my_width/2);
    }
    for (int w = 0; w <= my_width - 1; w += 2) {
        for (int h = 0; h < my_height - 1; h += 2) {
            temp[y][x] = pixels[h][w];
            y++;
        }

        y = 0;
        x++;
    }
    std::swap(my_height, my_width);
    pixels = temp;
}
void Image::to_grayscale()
{
    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            int r = pixels[i][j].red;
            int g = pixels[i][j].green;
            int b = pixels[i][j].blue;
            pixels[i][j].red = static_cast<int>(0.2126 * r + 0.7152 * g + 0.0722 * b);
            pixels[i][j].green = static_cast<int>(0.2126 * r + 0.7152 * g + 0.0722 * b);
            pixels[i][j].blue = static_cast<int>(0.2126 * r + 0.7152 * g + 0.0722 * b);
        }
    }
}
void Image::filter()
{
        for (int w = 0; w <= (my_width - 1); w++) {
        for (int h = 0; h < (my_height - 1); h++) {
            
            pixels[h][w].red = abs(pixels[h][w].red - pixels[h+1][w+1].red);
            pixels[h][w].green = abs(pixels[h][w].green - pixels[h+1][w+1].green);
            pixels[h][w].blue = abs(pixels[h][w].blue - pixels[h+1][w+1].blue);
        }
    }
}
int Image::height() const
{
    return my_height;
}
int Image::width() const
{
    return my_width;
}