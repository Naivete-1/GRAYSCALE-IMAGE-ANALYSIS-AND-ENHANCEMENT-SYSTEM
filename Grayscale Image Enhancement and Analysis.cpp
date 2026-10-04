
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "Image.h"

using namespace std;

// Image to Grayscale Methods

double grayAverage( double r, double g, double b) {
    return (r + g + b) / 3.0;
}

double grayLuminosity(double r, double g, double b) {
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

double grayDesaturation(double r, double g, double b) {

    double maxv = max({ r, g, b });
    double minv = min({ r, g, b });

    return (maxv + minv) / 2.0;
}

// Gamma Correction

double gammaCorrection(double Ixy, float gamma) {
    int B = 8;
    int maxVal = (int)pow(2, B) - 1;
    float normalized = (float)Ixy / maxVal;
    float Oxy = maxVal *pow(normalized, gamma);
    return (double)Oxy;
}

int main() {

    ColorImage img;

    img.Load("input.png");

    int w = img.GetWidth();
    int h = img.GetHeight();

    int choice;

    cout << "GRAYSCALE IMAGE ENHANCEMENT ANALYSIS SYSTEM" << endl;
    cout << "1  Average Grayscale" << endl;
    cout << "2  Luminosity Grayscale" << endl;
    cout << "3  Desaturation Grayscale" << endl;
    cout << "4  Histogram Equalization" << endl;
    cout << "5  Contrast Stretching" << endl;
    cout << "6  Gamma Correction" << endl;
    cout << "7  Edge Detection" << endl;
    cout << "Choose: ";

    cin >> choice;

    // 1. Average Grayscale

    if (choice == 1) {

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                RGBA p = img(x, y);

                double g =
                    grayAverage(p.r, p.g, p.b);

                img(x, y).r = g;
                img(x, y).g = g;
                img(x, y).b = g;
            }
        }

        img.Save("Average Grayscale Image.png");

        cout << "Saved Image (average.png)" << endl;
    }

    // 2. Luminosity Grayscale

    else if (choice == 2) {

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                RGBA p = img(x, y);

                double  g =
                    grayLuminosity(p.r, p.g, p.b);

                img(x, y).r = g;
                img(x, y).g = g;
                img(x, y).b = g;
            }
        }

        img.Save("Grayscale luminosity Image .png");

        cout << "luminosity.png saved" << endl;
    }

    // 3. Desaturation Grayscale

    else if (choice == 3) {

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                RGBA p = img(x, y);

                double g =
                    grayDesaturation(p.r, p.g, p.b);

                img(x, y).r = g;
                img(x, y).g = g;
                img(x, y).b = g;
            }
        }

        img.Save("GrayScale desaturation Image.png");

        cout << " desaturation.png has been saved" << endl;
    }

    // 4. Histogram Equalization

    else if (choice == 4) {

        int histogram[256] = {};
        float pdf[256] = {};
        float cdf[256] = {};
        int equalized[256] = {};

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                RGBA p = img(x, y);

                int g =
                    (int)grayLuminosity(p.r, p.g, p.b);

                img(x, y).r = g;
                img(x, y).g = g;
                img(x, y).b = g;

                histogram[g]++;
            }
        }

        int pixels = w * h;

        for (int i = 0; i < 256; i++) {

            pdf[i] =
                histogram[i] / (float)pixels;
        }

        cdf[0] = pdf[0];

        for (int i = 1; i < 256; i++) {

            cdf[i] =
                cdf[i - 1] + pdf[i];
        }

        for (int i = 0; i < 256; i++) {

            equalized[i] =
                (int)(255 * cdf[i]);
        }

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                int v = img(x, y).r;

                img(x, y).r = equalized[v];
                img(x, y).g = equalized[v];
                img(x, y).b = equalized[v];
            }
        }

        img.Save("Image equalized.png");

        ofstream file("histogram.csv");

        file << "Value,Count,PDF,CDF\n";

        for (int i = 0; i < 256; i++) {

            file << i << ","
                << histogram[i] << ","
                << pdf[i] << ","
                << cdf[i] << "\n";
        }

        file.close();

        cout << "Saved equalized.png" << endl;
        cout << "Saved histogram.csv" << endl;
    }

    // 5. Contrast Stretching

    else if (choice == 5) {

        int minv = 255;
        int maxv = 0;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                RGBA p = img(x, y);

                double g =
                    grayLuminosity(p.r, p.g, p.b);

                img(x, y).r = g;
                img(x, y).g = g;
                img(x, y).b = g;

                if (g < minv) minv = g;
                if (g > maxv) maxv = g;
            }
        }

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                int v = img(x, y).r;

                v = (v - minv) * 255 / (maxv - minv);

                img(x, y).r = v;
                img(x, y).g = v;
                img(x, y).b = v;
            }
        }

        img.Save("GrayScale contrast Image.png");

        cout << "Saved contrasted GrayScale Image.png" << endl;
    }

    // 6. Gamma Correction

    else if (choice == 6) {

        float gamma = 0.8f;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                RGBA p = img(x, y);

                double g =
                    grayLuminosity(p.r, p.g, p.b);

                g = gammaCorrection(g, gamma);

                img(x, y).r = g;
                img(x, y).g = g;
                img(x, y).b = g;
            }
        }

        img.Save("Image gamma.png");

        cout << "Grayscale gamma image .png" << endl;
    }

    // 7. Edge Detection

    else if (choice == 7) {

        ColorImage temp = img;

        int Gx[3][3] = {
            {1,0,-1},
            {2,0,-2},
            {1,0,-1}
        };

        int Gy[3][3] = {
            {1,2,1},
            {0,0,0},
            {-1,-2,-1}
        };

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {

                RGBA p = img(x, y);

                double g =
                    grayLuminosity(p.r, p.g, p.b);

                temp(x, y).r = g;
            }
        }

        for (int y = 1; y < h - 1; y++) {
            for (int x = 1; x < w - 1; x++) {

                int sx = 0;
                int sy = 0;

                for (int j = -1; j <= 1; j++) {
                    for (int i = -1; i <= 1; i++) {

                        int pixel =
                            temp(x + i, y + j).r;

                        sx += pixel *
                            Gx[j + 1][i + 1];

                        sy += pixel *
                            Gy[j + 1][i + 1];
                    }
                }

                int value =
                    sqrt(sx * sx + sy * sy);

                if (value > 255)
                    value = 255;

                img(x, y).r = value;
                img(x, y).g = value;
                img(x, y).b = value;
            }
        }

        img.Save("GrayScale Image edge Detection.png");

        cout << "edge Detection.png" << endl;
    }

    else {

        cout << "option not found" << endl;
    }

    return 0;
}