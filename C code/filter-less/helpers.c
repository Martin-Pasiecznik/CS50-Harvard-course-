#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double average;
    int round_average;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            round_average = round(average);

            // Update pixel values
            image[i][j].rgbtRed = round_average;
            image[i][j].rgbtGreen = round_average;
            image[i][j].rgbtBlue = round_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            double sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            double sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            double sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // round the values.
            int round_sapiaRed = round(sepiaRed);
            int round_sapiaGreen = round(sepiaGreen);
            int round_sapiaBlue = round(sepiaBlue);
            // capp colors to 255
            if (round_sapiaRed > 255)
                round_sapiaRed = 255;
            if (round_sapiaGreen > 255)
                round_sapiaGreen = 255;
            if (round_sapiaBlue > 255)
                round_sapiaBlue = 255;
            // Update pixel with sepia values
            image[i][j].rgbtRed = round_sapiaRed;
            image[i][j].rgbtGreen = round_sapiaGreen;
            image[i][j].rgbtBlue = round_sapiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) // error in function, pending to solve.
{
    // Loop over all pixels
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        // reflects each row
        int swap_row = (height - 1) - i;
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[swap_row][j];
            image[swap_row][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
// Create a copy of image
    RGBTRIPLE copy[height][width];

    // Copy original image to the copy array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int total_of_average_red = 0;
            int total_of_average_green = 0;
            int total_of_average_blue = 0;

            // Determine neighborhood bounds based on pixel position
            int start_i = (i == 0) ? 0 : i - 1;
            int end_i = (i == height - 1) ? i : i + 1;
            int start_j = (j == 0) ? 0 : j - 1;
            int end_j = (j == width - 1) ? j : j + 1;

            for (int k = start_i; k <= end_i; k++)
            {
                for (int s = start_j; s <= end_j; s++)
                {
                    total_of_average_red += copy[k][s].rgbtRed;
                    total_of_average_green += copy[k][s].rgbtGreen;
                    total_of_average_blue += copy[k][s].rgbtBlue;
                    count++;
                }
            }

            double average_red = total_of_average_red / (double)count;
            double average_green = total_of_average_green / (double)count;
            double average_blue = total_of_average_blue / (double)count;

            image[i][j].rgbtRed = round(average_red);
            image[i][j].rgbtGreen = round(average_green);
            image[i][j].rgbtBlue = round(average_blue);
        }
    }
    return;
}
