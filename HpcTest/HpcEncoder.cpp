#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

void usage(char *exe) {
	cout << "Usage: " << endl;
	cout << "  " << exe << " [options]" << endl << endl;

	cout << "DESCRIPTION" << endl;
	cout << "  " << "simulate HPM encoder for generating bit-stream or reconstruction or log" << endl << endl;

	cout << "Options" << endl;
	cout << "  -f <#frames>    \t Number of frames to encode" << endl;
	cout << "  -o <bit-stream> \t The generated bitstream file" << endl;
	cout << "  -r <rec-file>   \t The generated recontruction file" << endl;
}

void write_file(string& file_name)
{
	if (!file_name.empty()) {
		ofstream f;
		f.open(file_name, ios::out);
		f.write(file_name.c_str(), file_name.size());
		f.close();
	}
}

int main(int argc, char *argv[])
{
	int frames = 0;
	string bitstream_file;
	string reconstruction;
	for (size_t i = 0; i < argc; i++) {
		cout << argv[i] << " ";
		if (string(argv[i]) == "-f") {
			frames = atoi(argv[i + 1]);
		} else if (string(argv[i]) == "-o") {
			
			bitstream_file = string(argv[i + 1]);
		}
		else if (string(argv[i]) == "-r") {
			reconstruction = string(argv[i + 1]);
		}
	}
	cout << endl;

	if (frames <= 0) {
		usage(argv[0]);
		exit(1);
	}
	
	// write bitstream or reconstruction
	write_file(bitstream_file);
	write_file(reconstruction);

	// write log
	for (size_t i = 0; i < frames; i++) {
		cout << i << endl;
		Sleep(1000);
	}

	return 0;
}
