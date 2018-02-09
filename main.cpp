/**
* TXT Image Manipulation Starter
*
* This code is a simple way to read in color information stored in a space
* delimited txt format. The expected file format is:
*                ---------------------------
*                | width height            |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                ---------------------------
* So a 10x10 img would have 11 total rows, 10 rows of data, with 30 values in row.
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb
{
	int r;
	int g;
	int b;
};

void grayScale(rgb** image, int width, int height) 
{
	int r, g, b, gray;
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++) 
		{
			r = image[i][j].r;
			g = image[i][j].g;
			b = image[i][j].b;

			gray = (r + g + b) / 3;

			image[i][j].r = gray;
			image[i][j].g = gray;
			image[i][j].b = gray;
		}
	}
}


void flipvert(rgb** image, int width, int height) 
{
	rgb ** tempArr;
	tempArr = new rgb*[height];    //This array points to every row

	for (int i = 0; i<height; i++)
	{
		tempArr[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	int j = 0, hght = height / 2;

	for (int k = 0; k < hght; k++)
	{
		for (int i = 0; i < hght; i++)
		{


			tempArr[k][i] = image[k][i];//copies first row into temp arra
			image[k][i] = image[i][hght - 1 - i];//copies bottom row into top row
			image[i][hght - 1 - i] = tempArr[k][0];

		}
	}

}
void fliphorz(rgb **image, int width, int height)
{
	rgb ** tempArr;
	tempArr = new rgb*[height];    //This array points to every row
	
	for (int i = 0; i<height; i++)
	{
		tempArr[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	int j = 0, wdth = width / 2, hght=height/2;

	for (int k = 0;  k < wdth; k++)
	{
		for (int i = 0; i < hght; i++)
		{


			tempArr[k][i] = image[k][i];//copies first row into temp arra
			image[k][i] = image[width-1-i][i];//copies bottom row into top row
			image[width-1-i][i] = tempArr[k][0];

		}
	} 

}

int main() {
	ifstream ifile;          //Input / output files
	ofstream ofile;

	ifile.open("bot.txt");
	ofile.open("bot2.txt");
	ofile.open("bot3.txt");
	ofile.open("bot4.txt");

	int r, g, b, gray;

	int width;               //width of image
	int height;              //height of image

	rgb **imgArray;         //Pointer var for our 2D array because we         
							//don't know how big the image will be!

	ifile >> width >> height;   //Read in width and height from top of input file
								//We need this so we can make the array the right 
								//size. After we get these two values, we can
								//now allocate memory for our 2D array.

	imgArray = new rgb*[height];    //This array points to every row

	for (int i = 0; i<height; i++) 
	{
		imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
	}

	//Read the color data in from our txt file
	for (int i = 0; i<height; i++) 
	{
		for (int j = 0; j<width; j++) 
		{
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}




	ofile.open("bot2.txt");
	flipvert(imageArray, width, height)
	 for (int i = 0; i<height; i++)
		{
			for (int j = 0; j<width; j++)
			{
				ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
			}
			ofile << endl;
		}

	

	ofile.open("bot3.txt");
	fliphorz(imgArray, width, height);
	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}
	


	ofile.open("bot4.txt");
	for (int i = 0; i<height; i++)
	{
		for (int j = 0; j<width; j++)
		{
			grayScale(imgArray, width, height);
		}
	}


	//Write out our color data to a new file
	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) 
	{
		for (int j = 0; j<width; j++) 
		{
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}
	ofile.close();

	return 0;
}

