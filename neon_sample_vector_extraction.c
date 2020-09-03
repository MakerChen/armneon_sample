#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-vector-extraction

// -----------------------------------------------------------------------------
void NeonSample_VectorExtraction_U8_U8_U8_SU8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint8_t		u8CoefC;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 1;		au8DataInB[0] = 10;
	au8DataInA[1] = 2;		au8DataInB[1] = 20;
	au8DataInA[2] = 3;		au8DataInB[2] = 30;
	au8DataInA[3] = 4;		au8DataInB[3] = 40;
	au8DataInA[4] = 5;		au8DataInB[4] = 50;
	au8DataInA[5] = 6;		au8DataInB[5] = 60;
	au8DataInA[6] = 7;		au8DataInB[6] = 70;
	au8DataInA[7] = 8;		au8DataInB[7] = 80;

	u8CoefC			= 5;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vext_u8(uint8x8_t a, uint8x8_t b, __constrange(0,7) int c);	// VEXT.8 d0,d0,d0,#0
	// r[0:7-c] = a[c:7]
	// r[8-c:]  = b[0:c-1]
	vu8x8Output		= vext_u8(vu8x8InputA, vu8x8InputB, u8CoefC);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Vector Extraction u8 = u8, u8, su8 (vext_u8) ==\n");
	printf("=> r[0 ~ 7-c] = a[c ~ 7]                        ==\n");
	printf("=> r[8-c ~]   = b[0 ~ c-1]                      ==\n");
	printf("Ref. Index : %1d\n", u8CoefC);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] %3d, %3d => %3d\n",
			u32Idx,
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorExtraction_S8_S8_S8_SU8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint8_t		u8CoefC;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 10;		as8DataInB[0] = -10;
	as8DataInA[1] = 20;		as8DataInB[1] = -20;
	as8DataInA[2] = 30;		as8DataInB[2] = -30;
	as8DataInA[3] = 40;		as8DataInB[3] = -40;
	as8DataInA[4] = 50;		as8DataInB[4] = -50;
	as8DataInA[5] = 60;		as8DataInB[5] = -60;
	as8DataInA[6] = 70;		as8DataInB[6] = -70;
	as8DataInA[7] = 80;		as8DataInB[7] = -80;

	u8CoefC			= 3;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vext_s8(int8x8_t a, int8x8_t b, __constrange(0,7) int c);		// VEXT.8 d0,d0,d0,#0
	// r[0:7-c] = a[c:7]
	// r[8-c:]  = b [0:c-1]
	vs8x8Output		= vext_s8(vs8x8InputA, vs8x8InputB, u8CoefC);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Vector Extraction s8 = s8, s8, su8 (vext_s8) ==\n");
	printf("=> r[0 ~ 7-c] = a[c ~ 7]                        ==\n");
	printf("=> r[8-c ~]   = b[0 ~ c-1]                      ==\n");
	printf("Ref. Index : %1d\n", u8CoefC);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] %4d, %4d => %4d\n",
			u32Idx,
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorExtraction_P8_P8_P8_SU8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	poly8x8_t	vp8x8InputA;
	poly8x8_t	vp8x8InputB;
	poly8x8_t	vp8x8Output;

	uint8_t		u8CoefC;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 0b00000001;		au8DataInB[0] = 0b11000000;
	au8DataInA[1] = 0b00000010;		au8DataInB[1] = 0b01100000;
	au8DataInA[2] = 0b00000100;		au8DataInB[2] = 0b00110000;
	au8DataInA[3] = 0b00001000;		au8DataInB[3] = 0b00011000;
	au8DataInA[4] = 0b00010000;		au8DataInB[4] = 0b00001100;
	au8DataInA[5] = 0b00100000;		au8DataInB[5] = 0b00000110;
	au8DataInA[6] = 0b01000000;		au8DataInB[6] = 0b00000011;
	au8DataInA[7] = 0b10000000;		au8DataInB[7] = 0b10000001;

	u8CoefC			= 2;

	vp8x8InputA		= vld1_p8(au8DataInA);
	vp8x8InputB		= vld1_p8(au8DataInB);

	// poly8x8_t vext_p8(poly8x8_t a, poly8x8_t b, __constrange(0,7) int c);	// VEXT.8 d0,d0,d0,#0
	// r[0:7-c] = a[c:7]
	// r[8-c:]  = b [0:c-1]
	vp8x8Output		= vext_p8(vp8x8InputA, vp8x8InputB, u8CoefC);
	vst1_p8(au8DataOut, vp8x8Output);

	printf("== Vector Extraction p8 = p8, p8, su8 (vext_p8) ==\n");
	printf("=> r[0 ~ 7-c] = a[c ~ 7]                        ==\n");
	printf("=> r[8-c ~]   = b[0 ~ c-1]                      ==\n");
	printf("Ref. Index : %1d\n", u8CoefC);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			u32Idx,
			UINT8_TO_BIT(au8DataInA[u32Idx]),
			UINT8_TO_BIT(au8DataInB[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
