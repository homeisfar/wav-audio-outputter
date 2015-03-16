#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// void string_bytes_to_int(int *, char *);

void string_bytes_to_int (int *int_val, char *c_array)
{
	*int_val = (*int_val << 8) + c_array[3];
	*int_val = (*int_val << 8) + c_array[2];
	*int_val = (*int_val << 8) + c_array[1];
	*int_val = (*int_val << 8) + c_array[0];
}

void string_bytes_to_short (short *int_val, char *c_array)
{
	*int_val = (*int_val << 8) + c_array[1];
	*int_val = (*int_val << 8) + c_array[0];
}

int main()
{
	ifstream infile("duck_quack.wav", ios::in | ios::binary);
	if (!infile.is_open())
	{
		cerr << "Could not open file" << endl;
		exit(-1);
	}

/*	Begin reading the file header. 

	'RIFF'		- RIFF file identification (4 bytes)
	<length>		- length field (4 bytes)
	'WAVE'		- WAVE chunk identification (4 bytes)
	'fmt '		- format sub-chunk identification  (4 bytes)
	flength		- length of format sub-chunk (4 byte integer)
	format		- format specifier (2 byte integer)
	chans		- number of channels (2 byte integer)
	sampsRate	- sample rate in Hz (4 byte integer)
	bpsec		- bytes per second (4 byte integer)
	bpsample	- bytes per sample (2 byte integer)
	bpchan		- bits per channel (2 byte integer)
	'data'		- data sub-chunk identification  (4 bytes)
	dlength		- length of data sub-chunk (4 byte integer) 
	*/

	char 	riff[5];
	char 	length[5];
	int 	lengthint = 0;
	char 	wave[5];
	char 	fmt[5];
	char 	flength[5];
	int 	flengthint = 0;
	char 	format[3];
	short 	formatshort = 0;
	char 	chans[3];
	short 	chansshort = 0;
	char 	sampsRate[5];
	int 	sampsint = 0;
	char 	bpsec[5];
	int 	bpsecint = 0;
	char 	bpsample[3];
	short 	bpsampleshort = 0;
	char 	bpchan[3];
	short 	bpchanshort = 0;
	char 	data[5];
	char 	dlength[5];
	int 	dlengthint = 0;
	
	/* Eventually do the header reading in a separate function like a sane person */
	infile.get 				(riff, 5);
	infile.get 				(length, 5);
	string_bytes_to_int 	(&lengthint, length);
	infile.get 				(wave, 5);
	infile.get 				(fmt, 5);
	infile.get 				(flength, 5);
	string_bytes_to_int 	(&flengthint, flength);
	infile.get 				(format, 3);
	string_bytes_to_short 	(&formatshort, format);
	infile.get 				(chans, 3);
	string_bytes_to_short 	(&chansshort, chans);
	infile.get 				(sampsRate, 5);
	string_bytes_to_int 	(&sampsint, sampsRate);
	infile.get 				(bpsec, 5);
	string_bytes_to_int		(&bpsecint, bpsec);
	infile.get 				(bpsample, 3);
	string_bytes_to_short 	(&bpsampleshort, bpsample);
	infile.get 				(bpchan, 3);
	string_bytes_to_short 	(&bpchanshort, bpchan);
	infile.get 				(data, 5);
	infile.get 				(dlength, 5);
	string_bytes_to_int 	(&dlengthint, dlength);



	cout << riff << endl;
	cout << lengthint << endl;
	cout << wave << endl;
	cout << fmt << endl;
	cout << flengthint << endl;
	cout << formatshort << endl;
	cout << chansshort << endl;
	cout << sampsint << endl;

	cout << bpsecint << endl;
	cout << bpsampleshort << endl;
	cout << bpchanshort << endl;
	cout << data << endl;
	cout << dlengthint << endl;

	cout << "Time to decode some audio" << endl;

	infile.close();	
}



