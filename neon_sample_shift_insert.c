#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-shifts-with-insert

// -----------------------------------------------------------------------------
void NeonSample_ShiftInsert_U8_U8_U8_SU8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOutRight[8];
	uint8_t		au8DataOutLeft[8];

	uint8_t		u8CoefShiftRight;
	uint8_t		u8CoefShiftLeft;

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 0b01110000;		au8DataInB[0] = 0b00001111;
	au8DataInA[1] = 0b11110000;		au8DataInB[1] = 0b00001111;
	au8DataInA[2] = 0b01110000;		au8DataInB[2] = 0b10001111;
	au8DataInA[3] = 0b11110000;		au8DataInB[3] = 0b10001111;
	au8DataInA[4] = 0b01000011;		au8DataInB[4] = 0b00111100;
	au8DataInA[5] = 0b11000011;		au8DataInB[5] = 0b00111100;
	au8DataInA[6] = 0b01000011;		au8DataInB[6] = 0b10111100;
	au8DataInA[7] = 0b11000011;		au8DataInB[7] = 0b10111100;

	u8CoefShiftRight	= 3;
	u8CoefShiftLeft		= 2;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vsri_n_u8(uint8x8_t a, uint8x8_t b, __constrange(1,8) int c);	// VSRI.8 d0,d0,#8
	// r = a >> (8-c) << (8-c)	// a & 0b1110000
	// r |= b >> (c)			// (b >> c) & 0b00011111
	vu8x8Output		= vsri_n_u8(vu8x8InputA, vu8x8InputB, u8CoefShiftRight);
	vst1_u8(au8DataOutRight, vu8x8Output);

	printf("== Shift u8 = u8, u8, u8 (vsri_n_u8)                 ==\n");
	printf("=> vsri_n_u8 : r = (a >> (8-c) << (8-c)) || (b >> c) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ("UINT8_TO_BIT_PATTERN"), %3d ("UINT8_TO_BIT_PATTERN") >> %1d = %3d ("UINT8_TO_BIT_PATTERN")\n",
			au8DataInA[u32Idx], UINT8_TO_BIT(au8DataInA[u32Idx]),
			au8DataInB[u32Idx], UINT8_TO_BIT(au8DataInB[u32Idx]),
			u8CoefShiftRight,
			au8DataOutRight[u32Idx], UINT8_TO_BIT(au8DataOutRight[u32Idx]));
	}
	printf("========================================\n");

	// uint8x8_t vsli_n_u8(uint8x8_t a, uint8x8_t b, __constrange(0,7) int c);	// VSLI.8 d0,d0,#0
	// r = a << (8-c) >> (8-c)	// a & 0b00000011
	// r |= b << (c)			// (b << c) & 0b11111100
	vu8x8Output		= vsli_n_u8(vu8x8InputA, vu8x8InputB, u8CoefShiftLeft);
	vst1_u8(au8DataOutLeft, vu8x8Output);

	printf("== Shift u8 = u8, u8, u8 (vsli_n_u8)                 ==\n");
	printf("=> vsli_n_u8 : r = (a << (8-c) >> (8-c)) || (b << c) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ("UINT8_TO_BIT_PATTERN"), %3d ("UINT8_TO_BIT_PATTERN") << %1d = %3d ("UINT8_TO_BIT_PATTERN")\n",
			au8DataInA[u32Idx], UINT8_TO_BIT(au8DataInA[u32Idx]),
			au8DataInB[u32Idx], UINT8_TO_BIT(au8DataInB[u32Idx]),
			u8CoefShiftLeft,
			au8DataOutLeft[u32Idx], UINT8_TO_BIT(au8DataOutLeft[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftInsert_S8_S8_S8_SU8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOutRight[8];
	int8_t		as8DataOutLeft[8];

	uint8_t		u8CoefShiftRight;
	uint8_t		u8CoefShiftLeft;

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 0b01110000;		as8DataInB[0] = 0b00001111;
	as8DataInA[1] = 0b11110000;		as8DataInB[1] = 0b00001111;
	as8DataInA[2] = 0b01110000;		as8DataInB[2] = 0b10001111;
	as8DataInA[3] = 0b11110000;		as8DataInB[3] = 0b10001111;
	as8DataInA[4] = 0b01000011;		as8DataInB[4] = 0b00111100;
	as8DataInA[5] = 0b11000011;		as8DataInB[5] = 0b00111100;
	as8DataInA[6] = 0b01000011;		as8DataInB[6] = 0b10111100;
	as8DataInA[7] = 0b11000011;		as8DataInB[7] = 0b10111100;

	u8CoefShiftRight	= 3;
	u8CoefShiftLeft		= 5;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vsri_n_s8(int8x8_t a, int8x8_t b, __constrange(1,8) int c);		// VSRI.8 d0,d0,#8
	// r = a >> (8-c) << (8-c)	// a & 0b1110000
	// r |= b >> (c)			// (b >> c) & 0b00011111
	vs8x8Output		= vsri_n_s8(vs8x8InputA, vs8x8InputB, u8CoefShiftRight);
	vst1_s8(as8DataOutRight, vs8x8Output);

	printf("== Shift s8 = s8, s8, u8 (vsri_n_s8)                 ==\n");
	printf("=> vsri_n_s8 : r = (a >> (8-c) << (8-c)) || (b >> c) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ("UINT8_TO_BIT_PATTERN"), %4d ("UINT8_TO_BIT_PATTERN") >> %1d = %4d ("UINT8_TO_BIT_PATTERN")\n",
			as8DataInA[u32Idx], UINT8_TO_BIT(as8DataInA[u32Idx]),
			as8DataInB[u32Idx], UINT8_TO_BIT(as8DataInB[u32Idx]),
			u8CoefShiftRight,
			as8DataOutRight[u32Idx], UINT8_TO_BIT(as8DataOutRight[u32Idx]));
	}
	printf("========================================\n");

	// int8x8_t vsli_n_s8(int8x8_t a, int8x8_t b, __constrange(0,7) int c);		// VSLI.8 d0,d0,#0
	// r = a << (8-c) >> (8-c)	// a & 0b00000111
	// r |= b << (c)			// (b << c) & 0b11111000
	vs8x8Output		= vsli_n_s8(vs8x8InputA, vs8x8InputB, u8CoefShiftLeft);
	vst1_s8(as8DataOutLeft, vs8x8Output);

	printf("== Shift s8 = s8, s8, u8 (vsli_n_u8)                 ==\n");
	printf("=> vsli_n_s8 : r = (a << (8-c) >> (8-c)) || (b << c) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ("UINT8_TO_BIT_PATTERN"), %4d ("UINT8_TO_BIT_PATTERN") << %1d = %4d ("UINT8_TO_BIT_PATTERN")\n",
			as8DataInA[u32Idx], UINT8_TO_BIT(as8DataInA[u32Idx]),
			as8DataInB[u32Idx], UINT8_TO_BIT(as8DataInB[u32Idx]),
			u8CoefShiftLeft,
			as8DataOutLeft[u32Idx], UINT8_TO_BIT(as8DataOutLeft[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftInsert_P8_P8_P8_SU8()
{
	poly8_t		ap8DataInA[8];
	poly8_t		ap8DataInB[8];
	poly8_t		ap8DataOutRight[8];
	poly8_t		ap8DataOutLeft[8];

	uint8_t		u8CoefShiftRight;
	uint8_t		u8CoefShiftLeft;

	poly8x8_t	vp8x8InputA;
	poly8x8_t	vp8x8InputB;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx;

	// initial
	ap8DataInA[0] = 0b01110000;		ap8DataInB[0] = 0b00001111;
	ap8DataInA[1] = 0b11110000;		ap8DataInB[1] = 0b00001111;
	ap8DataInA[2] = 0b01110000;		ap8DataInB[2] = 0b10001111;
	ap8DataInA[3] = 0b11110000;		ap8DataInB[3] = 0b10001111;
	ap8DataInA[4] = 0b01000011;		ap8DataInB[4] = 0b00111100;
	ap8DataInA[5] = 0b11000011;		ap8DataInB[5] = 0b00111100;
	ap8DataInA[6] = 0b01000011;		ap8DataInB[6] = 0b10111100;
	ap8DataInA[7] = 0b11000011;		ap8DataInB[7] = 0b10111100;

	u8CoefShiftRight	= 2;
	u8CoefShiftLeft		= 4;

	vp8x8InputA		= vld1_p8(ap8DataInA);
	vp8x8InputB		= vld1_p8(ap8DataInB);

	// poly8x8_t vsri_n_p8(poly8x8_t a, poly8x8_t b, __constrange(1,8) int c);	// VSRI.8 d0,d0,#8
	// r = a >> (8-c) << (8-c)	// a & 0b1100000
	// r |= b >> (c)			// (b >> c) & 0b00111111
	vp8x8Output		= vsri_n_p8(vp8x8InputA, vp8x8InputB, u8CoefShiftRight);
	vst1_p8(ap8DataOutRight, vp8x8Output);

	printf("== Shift p8 = p8, p8, u8 (vsri_n_p8)                 ==\n");
	printf("=> vsri_n_p8 : r = (a >> (8-c) << (8-c)) || (b >> c) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ("UINT8_TO_BIT_PATTERN"), %3d ("UINT8_TO_BIT_PATTERN") >> %1d = %3d ("UINT8_TO_BIT_PATTERN")\n",
			ap8DataInA[u32Idx], UINT8_TO_BIT(ap8DataInA[u32Idx]),
			ap8DataInB[u32Idx], UINT8_TO_BIT(ap8DataInB[u32Idx]),
			u8CoefShiftRight,
			ap8DataOutRight[u32Idx], UINT8_TO_BIT(ap8DataOutRight[u32Idx]));
	}
	printf("========================================\n");

	// poly8x8_t vsli_n_p8(poly8x8_t a, poly8x8_t b, __constrange(0,7) int c);	// VSLI.8 d0,d0,#0
	// r = a << (8-c) >> (8-c)	// a & 0b00001111
	// r |= b << (c)			// (b << c) & 0b11110000
	vp8x8Output		= vsli_n_p8(vp8x8InputA, vp8x8InputB, u8CoefShiftLeft);
	vst1_p8(ap8DataOutLeft, vp8x8Output);

	printf("== Shift p8 = p8, p8, p8 (vsli_n_p8)                 ==\n");
	printf("=> vsli_n_p8 : r = (a << (8-c) >> (8-c)) || (b << c) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ("UINT8_TO_BIT_PATTERN"), %3d ("UINT8_TO_BIT_PATTERN") << %1d = %3d ("UINT8_TO_BIT_PATTERN")\n",
			ap8DataInA[u32Idx], UINT8_TO_BIT(ap8DataInA[u32Idx]),
			ap8DataInB[u32Idx], UINT8_TO_BIT(ap8DataInB[u32Idx]),
			u8CoefShiftLeft,
			ap8DataOutLeft[u32Idx], UINT8_TO_BIT(ap8DataOutLeft[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
