#include "color.h"
#include "vec3.h"
#include <iostream>
int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    std::cout << "P3\n"
              << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {

            color pixel((double(i)) / (image_width - 1), (double(j)) / (image_height - 1), 0.25);
            write_color(std::cout, pixel);
        }
    }
}