#include "md5.h"

//Moves all bits in x left on n positions and fills the free last n bits
//with the values of the first n bits in source x value
DWORD cycle_move_left(DWORD x, int n) {
	return (((x) << (n)) | ((x) >> (32 - (n))));
}
DWORD F(DWORD X, DWORD Y, DWORD Z) {
	return (((X) & (Y)) | ((~X) & (Z)));
}
DWORD G(DWORD X, DWORD Y, DWORD Z) {
	return ((X) & (Z) | (Y) & (~Z));
}
DWORD H(DWORD X, DWORD Y, DWORD Z) {
	return ((X) ^ (Y) ^ (Z));
}
DWORD I(DWORD X, DWORD Y, DWORD Z) {
	return ((Y) ^ ((X) | (~Z)));
}

void round1_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X) {
	a = cycle_move_left(a + F(b, c, d) + X[k] + ti, s) + b;
	return;
}
void round2_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X) {
	a = cycle_move_left(a + G(b, c, d) + X[k] + ti, s) + b;
	return;
}
void round3_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X) {
	a = cycle_move_left(a + H(b, c, d) + X[k] + ti, s) + b;
	return;
}
void round4_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X) {
	a = cycle_move_left(a + I(b, c, d) + X[k] + ti, s) + b;
	return;
}


void Round_1(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X) {
	round1_conversion(A, B, C, D, 0, 7, T[1], X);
	round1_conversion(D, A, B, C, 1, 12, T[2], X);
	round1_conversion(C, D, A, B, 2, 17, T[3], X);
	round1_conversion(B, C, D, A, 3, 22, T[4], X);
	round1_conversion(A, B, C, D, 4, 7, T[5], X);
	round1_conversion(D, A, B, C, 5, 12, T[6], X);
	round1_conversion(C, D, A, B, 6, 17, T[7], X);
	round1_conversion(B, C, D, A, 7, 22, T[8], X);
	round1_conversion(A, B, C, D, 8, 7, T[9], X);
	round1_conversion(D, A, B, C, 9, 12, T[10], X);
	round1_conversion(C, D, A, B, 10, 17, T[11], X);
	round1_conversion(B, C, D, A, 11, 22, T[12], X);
	round1_conversion(A, B, C, D, 12, 7, T[13], X);
	round1_conversion(D, A, B, C, 13, 12, T[14], X);
	round1_conversion(C, D, A, B, 14, 17, T[15], X);
	round1_conversion(B, C, D, A, 15, 22, T[16], X);
	return;
}
void Round_2(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X) {
	round2_conversion(A, B, C, D, 1, 5, T[17], X);
	round2_conversion(D, A, B, C, 6, 9, T[18], X);
	round2_conversion(C, D, A, B, 11, 14, T[19], X);
	round2_conversion(B, C, D, A, 0, 20, T[20], X);
	round2_conversion(A, B, C, D, 5, 5, T[21], X);
	round2_conversion(D, A, B, C, 10, 9, T[22], X);
	round2_conversion(C, D, A, B, 15, 14, T[23], X);
	round2_conversion(B, C, D, A, 4, 20, T[24], X);
	round2_conversion(A, B, C, D, 9, 5, T[25], X);
	round2_conversion(D, A, B, C, 14, 9, T[26], X);
	round2_conversion(C, D, A, B, 3, 14, T[27], X);
	round2_conversion(B, C, D, A, 8, 20, T[28], X);
	round2_conversion(A, B, C, D, 13, 5, T[29], X);
	round2_conversion(D, A, B, C, 2, 9, T[30], X);
	round2_conversion(C, D, A, B, 7, 14, T[31], X);
	round2_conversion(B, C, D, A, 12, 20, T[32], X);
	return;
}
void Round_3(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X) {
	round3_conversion(A, B, C, D, 5, 4, T[33], X);
	round3_conversion(D, A, B, C, 8, 11, T[34], X);
	round3_conversion(C, D, A, B, 11, 16, T[35], X);
	round3_conversion(B, C, D, A, 14, 23, T[36], X);
	round3_conversion(A, B, C, D, 1, 4, T[37], X);
	round3_conversion(D, A, B, C, 4, 11, T[38], X);
	round3_conversion(C, D, A, B, 7, 16, T[39], X);
	round3_conversion(B, C, D, A, 10, 23, T[40], X);
	round3_conversion(A, B, C, D, 13, 4, T[41], X);
	round3_conversion(D, A, B, C, 0, 11, T[42], X);
	round3_conversion(C, D, A, B, 3, 16, T[43], X);
	round3_conversion(B, C, D, A, 6, 23, T[44], X);
	round3_conversion(A, B, C, D, 9, 4, T[45], X);
	round3_conversion(D, A, B, C, 12, 11, T[46], X);
	round3_conversion(C, D, A, B, 15, 16, T[47], X);
	round3_conversion(B, C, D, A, 2, 23, T[48], X);
	return;
}
void Round_4(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X) {
	round4_conversion(A, B, C, D, 0, 6, T[49], X);
	round4_conversion(D, A, B, C, 7, 10, T[50], X);
	round4_conversion(C, D, A, B, 14, 15, T[51], X);
	round4_conversion(B, C, D, A, 5, 21, T[52], X);
	round4_conversion(A, B, C, D, 12, 6, T[53], X);
	round4_conversion(D, A, B, C, 3, 10, T[54], X);
	round4_conversion(C, D, A, B, 10, 15, T[55], X);
	round4_conversion(B, C, D, A, 1, 21, T[56], X);
	round4_conversion(A, B, C, D, 8, 6, T[57], X);
	round4_conversion(D, A, B, C, 15, 10, T[58], X);
	round4_conversion(C, D, A, B, 6, 15, T[59], X);
	round4_conversion(B, C, D, A, 13, 21, T[60], X);
	round4_conversion(A, B, C, D, 4, 6, T[61], X);
	round4_conversion(D, A, B, C, 11, 10, T[62], X);
	round4_conversion(C, D, A, B, 2, 15, T[63], X);
	round4_conversion(B, C, D, A, 9, 21, T[64], X);
	return;
}
//Processes all the stream in blocks of 16 32-bit words
void process_stream_in_16words_blocks(BYTE *byte_stream, DWORD stream_size_before_align, DWORD output_digest[4]) {
	//X will contain a now processing block of words
	DWORD X[16];
	//Number of iterations needed to process all of 512-bit blocks of the stream
	const int block_quantity = (stream_size_before_align + 8) / 64;

	//Output array is used as MD5 buffer. Initialising start MD5 buffer.
	output_digest[0] = start_buffer_A;
	output_digest[1] = start_buffer_B;
	output_digest[2] = start_buffer_C;
	output_digest[3] = start_buffer_D;

	//"Array" of 32-bit words
	DWORD *words = (DWORD*)byte_stream;

	for (int n = 0; n < block_quantity; n++)
	{
		//Initialising 16-words X block
		for (int i = 0; i < 16; i++) {
			X[i] = words[0];
			words++;
		}

		DWORD A = output_digest[0];
		DWORD B = output_digest[1];
		DWORD C = output_digest[2];
		DWORD D = output_digest[3];

		//4 rounds of conversions on 16-word block
		Round_1(A, B, C, D, X);
		Round_2(A, B, C, D, X);
		Round_3(A, B, C, D, X);
		Round_4(A, B, C, D, X);

		output_digest[0] += A;
		output_digest[1] += B;
		output_digest[2] += C;
		output_digest[3] += D;
	}
}
//Reverses order of the bytes in each 32-bit word of the resultin MD5 digest
//Words are alrady in the right order
void reverse_byte_order_in_words(DWORD digest[4]) {
	for (int i = 0; i < 4; i++) {
		DWORD tmp[4];
		tmp[0] = ((BYTE*)(&digest[i]))[3];
		tmp[1] = ((BYTE*)(&digest[i]))[2];
		tmp[2] = ((BYTE*)(&digest[i]))[1];
		tmp[3] = ((BYTE*)(&digest[i]))[0];
		((BYTE*)(&digest[i]))[0] = tmp[0];
		((BYTE*)(&digest[i]))[1] = tmp[1];
		((BYTE*)(&digest[i]))[2] = tmp[2];
		((BYTE*)(&digest[i]))[3] = tmp[3];
	}
	return;
}
//Counts MD5 hash of the message in the "buffer" of size "size" and puts it to "output_digest"
//separately in 4 32-bit words
bool MD5(const char *buffer, DWORD size, DWORD output_digest[4])
{
	//Scpecial case if the buffer is empty of there is nowhere to return result
	if (buffer == NULL || output_digest == NULL) {
		return 0; 
	}
	//Stream size in bytes before stream alignment
	DWORD stream_size_before_align = ((size + 8) / 64) * 64 + 56;
	//Contains new stream of bytes
	BYTE *byte_stream = new BYTE[stream_size_before_align + 8];
	//Copying data from base buffer to a stream
	for (int i = 0; i < size; i++) {
		byte_stream[i] = buffer[i];
	}
	//Stream alingment
	//Adding one 1 bit to the end of the stream and seven 0 bits
	byte_stream[size] = 0x80;
	//Appending 0 bits to the stream up to its size become 448 modulo 512, i.e.
	//512 * m + 448, where "m" is minimal
	for (int i = size + 1; i < stream_size_before_align; i++) {
		byte_stream[i] = 0;
	}
	//Apending the size of the source buffer to the stream in 64-bit format
	*((DWORD*)(&byte_stream[stream_size_before_align])) = size*sizeof(char) * 8;
	//sizeof(DWORD) == 32, so last 32 bits are already empty. Let's set it to 0
	*((DWORD*)(&byte_stream[stream_size_before_align]) + 1) = 0;

	process_stream_in_16words_blocks(byte_stream, stream_size_before_align, output_digest);

	reverse_byte_order_in_words(output_digest);

	delete byte_stream;
	return 1;
}