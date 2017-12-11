#include <windows.h>

//MD5 buffer starting values
static const DWORD start_buffer_A = 0x67452301;
static const DWORD start_buffer_B = 0xefcdab89;
static const DWORD start_buffer_C = 0x98badcfe;
static const DWORD start_buffer_D = 0x10325476;

//Pre-counted T[i] constants.
//T[0] = 0,
//T[i] = 4294967296 * abs(sin(i)), i=1->64
static const DWORD T[65] = {
	0,
	0xd76aa478,
	0xe8c7b756,
	0x242070db,
	0xc1bdceee,
	0xf57c0faf,
	0x4787c62a,
	0xa8304613,
	0xfd469501,
	0x698098d8,
	0x8b44f7af,
	0xffff5bb1,
	0x895cd7be,
	0x6b901122,
	0xfd987193,
	0xa679438e,
	0x49b40821,


	0xf61e2562,
	0xc040b340,
	0x265e5a51,
	0xe9b6c7aa,
	0xd62f105d,
	0x2441453,
	0xd8a1e681,
	0xe7d3fbc8,
	0x21e1cde6,
	0xc33707d6,
	0xf4d50d87,
	0x455a14ed,
	0xa9e3e905,
	0xfcefa3f8,
	0x676f02d9,
	0x8d2a4c8a,

	0xfffa3942,
	0x8771f681,
	0x6d9d6122,
	0xfde5380c,
	0xa4beea44,
	0x4bdecfa9,
	0xf6bb4b60,
	0xbebfbc70,
	0x289b7ec6,
	0xeaa127fa,
	0xd4ef3085,
	0x4881d05,
	0xd9d4d039,
	0xe6db99e5,
	0x1fa27cf8,
	0xc4ac5665,


	0xf4292244,
	0x432aff97,
	0xab9423a7,
	0xfc93a039,
	0x655b59c3,
	0x8f0ccc92,
	0xffeff47d,
	0x85845dd1,
	0x6fa87e4f,
	0xfe2ce6e0,
	0xa3014314,
	0x4e0811a1,
	0xf7537e82,
	0xbd3af235,
	0x2ad7d2bb,
	0xeb86d391
};

//Moves all bits in x left on n positions and fills the free last n bits
//with the values of the first n bits in source x value
DWORD cycle_move_left(DWORD x, int n);

//Used logical functions. They are defined as the same in RFC specification
DWORD F(DWORD X, DWORD Y, DWORD Z);
DWORD G(DWORD X, DWORD Y, DWORD Z);
DWORD H(DWORD X, DWORD Y, DWORD Z);
DWORD I(DWORD X, DWORD Y, DWORD Z);


void round1_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X);
void round2_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X);
void round3_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X);
void round4_conversion(DWORD& a, DWORD& b, DWORD& c, DWORD& d, DWORD k, DWORD s, DWORD ti, DWORD* X);


void Round_1(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X);
void Round_2(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X);
void Round_3(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X);
void Round_4(DWORD& A, DWORD& B, DWORD& C, DWORD& D, DWORD* X);

//Counts MD5 hash of the message in the "buffer" of size "size" and puts it to "output_digest"
//separately in 4 32-bit words
bool MD5(const char *buffer, DWORD size, DWORD output_digest[4]);

//Processes all the stream in blocks of 16 32-bit words
void process_stream_in_16words_blocks(BYTE *byte_stream, DWORD stream_size_before_align, DWORD output_digest[4]);
//Reverses order of the bytes in each 32-bit word of the resultin MD5 digest
//Words are alrady in the right order
void reverse_byte_order_in_words(DWORD digest[4]);