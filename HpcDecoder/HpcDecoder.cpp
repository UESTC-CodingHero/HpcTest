#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	for (size_t i = 0; i < argc; i++) {
		cout << argv[i] << " ";
		if (string(argv[i]) == "-o") {
			ofstream f;
			f.open(argv[i + 1], ios::out);
			f.write(argv[i + 1], strlen(argv[i + 1]));
			f.close();
		}
	}
	cout << endl;
	return 0;
}
