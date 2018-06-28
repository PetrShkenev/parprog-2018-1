#include <fstream>
#include <cstdlib>

// generator ��������_���� ������ ������
int main(int argc, char *argv[])
{
	int width = atoi(argv[2]); // ������ �����������
	int height = atoi(argv[3]); // ������ �����������

	int imageLength = width * height * 3;
	unsigned char *image = new unsigned char[];
	image[0] = image[1] = image[2] = rand();
	for (int i = 1; i < width; i++)
	{
		for (int j = 1; j < height; j++)
		{
			image[width * j + i] = rand();
		}
	}

	std::ofstream ofs(argv[1], std::ios::binary);
	ofs.write((char *)&width, sizeof(width));
	ofs.write((char *)&height, sizeof(height));
	ofs.write((char *)image, imageLength);
	ofs.close();
	delete[] image;

	return 0;
}
