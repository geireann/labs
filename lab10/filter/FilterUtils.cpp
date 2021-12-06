#include "FilterUtils.h"
#include <algorithm>
#include "math.h"
#include <cstring>

namespace FilterUtils {

inline unsigned char REAL2byte(float f) {
    int i = static_cast<int>((f * 255.0 + 0.5));
    return (i < 0) ? 0 : (i > 255) ? 255 : i;
}

void Convolve2D(RGBA* data, int width, int height, const std::vector<float> &kernel) {
    // TODO: Task 9 Create buffer to store new image data
    RGBA result[width * height];

    // TODO: Task 10 Obtain kernel dimension
    int dimension = sqrt(kernel.size());

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            size_t centerIndex = r * width + c;

            // TODO: Task 11 Initialize color to accumulate convolution data
            float red_acc = 0.f;
            float green_acc = 0.f;
            float blue_acc = 0.f;

            // TODO: Task 12
            // Iterate over the kernel using the value from task 10
            // Obtain the value at current index of kernel
            // Find correct index in original image data
            // Accumulate the kernel applied to pixel value in color_acc
            for (int i = -dimension / 2; i <= dimension /2; i++) {
                for (int j = -dimension / 2; j <= dimension /2; j++){
                    int row = r + i;
                    int col = c + j;
                    int pixIndex = centerIndex + (i * width) + j;
                    if (row < 0 || row > height - 1 || col < 0 || col > width - 1) {
                        continue;
                    }
                    int kernIndex = (i + dimension / 2) * dimension + (j + dimension / 2);
                    RGBA pixel = data[pixIndex];
                    red_acc += kernel[kernIndex] * (pixel.r / 255.f);
                    green_acc += kernel[kernIndex] * (pixel.g / 255.f);
                    blue_acc += kernel[kernIndex] * (pixel.b / 255.f);
                }
            }

            // TODO: Task 13 Ignore outside bounds


            // TODO: Task 14 Update buffer with accumulated color
            result[centerIndex] = RGBA(REAL2byte(red_acc), REAL2byte(green_acc), REAL2byte(blue_acc));

        }
    }

    // TODO: Task 15 Copy over buffer to canvas data
    memcpy(data, result, width * height * sizeof(RGBA));
}

}
