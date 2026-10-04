# 🖼️ GRAYSCALE-IMAGE-ANALYSIS-AND-ENHANCEMENT-SYSTEM

> A C++ digital image processing project that converts colour images to grayscale and applies image enhancement and analysis techniques including histogram equalization, contrast stretching, gamma correction, and Sobel edge detection.

**Completed:** 2024
**Project Type:** Academic / Digital Image Processing
**Language:** C++

## 📌 Overview

The **Grayscale Image Analysis and Enhancement System** is a C++ image processing application designed to process colour images pixel by pixel.

The system converts RGB images into grayscale using multiple techniques and provides several image enhancement and analysis operations.

The project demonstrates fundamental concepts in **digital image processing, image enhancement, histogram analysis, and convolution-based edge detection**.

## 🎯 Objectives

The system was developed to:

* Convert RGB images to grayscale
* Compare different grayscale conversion techniques
* Analyse image intensity distributions
* Calculate histogram PDF and CDF
* Improve image contrast
* Apply histogram equalization
* Adjust image brightness using gamma correction
* Detect image edges using the Sobel operator
* Export histogram data for further analysis

## ⚙️ Image Processing Techniques

### 1. Average Grayscale

Calculates the grayscale value using the average of the RGB channels:

```text
Gray = (R + G + B) / 3
```

### 2. Luminosity Grayscale

Uses weighted RGB values based on human visual perception:

```text
Gray = 0.2126R + 0.7152G + 0.0722B
```

Green contributes the most because the human eye is more sensitive to green light.

### 3. Desaturation

Uses the midpoint between the maximum and minimum RGB values:

```text
Gray = (max(R,G,B) + min(R,G,B)) / 2
```

## 📊 Histogram Analysis

The system calculates an image intensity histogram containing pixel frequencies for intensity values from **0 to 255**.

From the histogram, it calculates:

* Probability Density Function (PDF)
* Cumulative Distribution Function (CDF)

The histogram data can be exported to a CSV file for further analysis.

## 🔆 Contrast Stretching

Contrast stretching expands the intensity range of an image.

The implementation uses:

```text
Output = (Input - Minimum) × 255 / (Maximum - Minimum)
```

This increases the effective contrast when the original image uses only a limited range of intensity values.

## 📈 Histogram Equalization

Histogram equalization improves contrast by redistributing image intensity values.

The process includes:

1. Calculating pixel frequencies
2. Calculating the PDF
3. Calculating the CDF
4. Mapping the original intensity values to new values

The mapping is based on:

```text
New Value = CDF × 255
```
## ☀️ Gamma Correction

Gamma correction adjusts image brightness using a nonlinear transformation.

```text
Output = 255 × (Input / 255)^γ
```

The implementation uses a gamma value of `0.8`.

Gamma values affect brightness differently depending on whether they are below, equal to, or above 1.


## 🔍 Sobel Edge Detection

The system uses the **Sobel operator** to detect areas of rapid intensity change.

Two convolution kernels are used:

```text
Gx:

-1   0   1
-2   0   2
-1   0   1
```

```text
Gy:

-1  -2  -1
 0   0   0
 1   2   1
```

The horizontal and vertical gradients are combined to estimate the edge magnitude.

This demonstrates the use of **convolution and image gradients** for edge detection.

## 🔄 System Workflow

```text
Input Colour Image
        ↓
RGB Image Processing
        ↓
Grayscale Conversion
        ↓
┌─────────────────────────────┐
│ Average                     │
│ Luminosity                  │
│ Desaturation                │
└─────────────────────────────┘
        ↓
Image Enhancement / Analysis
        ↓
┌─────────────────────────────┐
│ Contrast Stretching         │
│ Histogram Equalization      │
│ Gamma Correction            │
│ Sobel Edge Detection        │
└─────────────────────────────┘
        ↓
Processed Image
        +
Histogram Data
```
## 🛠️ Technologies & Concepts

* C++
* Digital Image Processing
* Pixel-level image manipulation
* RGB colour representation
* Grayscale conversion
* Histograms
* PDF and CDF
* Contrast enhancement
* Gamma correction
* Convolution
* Sobel edge detection
* CSV data export
* File I/O

## 📂 Repository Contents

```text
Grayscale-Image-Analysis-and-Enhancement/
│
├── README.md
├── Grayscale_Image_Analysis.cpp
└── Report.pdf
```

### Files

| File                           | Description                                  |
| ------------------------------ | -------------------------------------------- |
| `Grayscale_Image_Analysis.cpp` | Main C++ implementation                      |
| `Report.pdf`                   | Project report and technical documentation   |
| `README.md`                    | Project overview and technical documentation |

> **Note:** The current repository contains the main C++ source file and project report. The source references an `Image.h` dependency that is not included in the available project files.

## 🧠 Key Concepts Demonstrated

This project demonstrates practical understanding of:

* Image representation and pixel manipulation
* Mathematical image transformations
* Histogram-based image analysis
* Image enhancement techniques
* Convolution operations
* Gradient-based edge detection
* C++ programming
* File processing and data export

## 📄 Documentation

The complete technical report is available in **`Report.pdf`**.

The report contains the project's methodology, image processing techniques, system architecture, results, and source code documentation.
