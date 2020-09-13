#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-multiplication

// -----------------------------------------------------------------------------
void NeonSample_Multiple_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 1;		au8DataInB[0] = 1;
	au8DataInA[1] = 10;		au8DataInB[1] = 10;
	au8DataInA[2] = 100;	au8DataInB[2] = 101;
	au8DataInA[3] = 151;	au8DataInB[3] = 150;
	au8DataInA[4] = 100;	au8DataInB[4] = 150;
	au8DataInA[5] = 255;	au8DataInB[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 200;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vmul_u8(uint8x8_t a, uint8x8_t b);								// VMUL.I8 d0,d0,d0
	// (a * b)
	vu8x8Output		= vmul_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Multiple u8 = u8 * u8 (vmul_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d * %3d = %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 10;		as8DataInB[0] = 27;
	as8DataInA[1] = 12;		as8DataInB[1] = -11;
	as8DataInA[2] = 10;		as8DataInB[2] = -126;
	as8DataInA[3] = -100;	as8DataInB[3] = -100;
	as8DataInA[4] = -126;	as8DataInB[4] = 127;
	as8DataInA[5] = -100;	as8DataInB[5] = 15;
	as8DataInA[6] = -10;	as8DataInB[6] = -30;
	as8DataInA[7] = 100;	as8DataInB[7] = 100;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vmul_s8(int8x8_t a, int8x8_t b);								// VMUL.I8 d0,d0,d0
	// (a * b)
	vs8x8Output		= vmul_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Multiple s8 = s8 * s8 (vmul_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d * %4d = %4d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_U8_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataInC[8];
	uint8_t		au8DataOutAdd[8];
	uint8_t		au8DataOutSub[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8InputC;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 1;		au8DataInB[0] = 1;		au8DataInC[0] = 1;
	au8DataInA[1] = 10;		au8DataInB[1] = 10;		au8DataInC[1] = 1;
	au8DataInA[2] = 10;		au8DataInB[2] = 10;		au8DataInC[2] = 4;
	au8DataInA[3] = 151;	au8DataInB[3] = 10;		au8DataInC[3] = 4;
	au8DataInA[4] = 100;	au8DataInB[4] = 150;	au8DataInC[4] = 1;
	au8DataInA[5] = 255;	au8DataInB[5] = 255;	au8DataInC[5] = 1;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;	au8DataInC[6] = 1;
	au8DataInA[7] = 200;	au8DataInB[7] = 200;	au8DataInC[7] = 1;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// uint8x8_t vmla_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c);				// VMLA.I8 d0,d0,d0
	// a + (b * c)
	vu8x8Output		= vmla_u8(vu8x8InputA, vu8x8InputB, vu8x8InputC);
	vst1_u8(au8DataOutAdd, vu8x8Output);

	// uint8x8_t vmls_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c);				// VMLS.I8 d0,d0,d0
	// a - (b * c)
	vu8x8Output		= vmls_u8(vu8x8InputA, vu8x8InputB, vu8x8InputC);
	vst1_u8(au8DataOutSub, vu8x8Output);

	printf("== Multiple u8 = u8 +- (u8 * u8) (vmla_u8 / vmls_u8) ==\n");
	printf("=> vmla_u8 : u8 = u8 + (u8 * u8)                     ==\n");
	printf("=> vmls_u8 : u8 = u8 - (u8 * u8)                     ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d +/- (%3d * %3d) = %3d, %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx], au8DataInC[u32Idx],
			au8DataOutAdd[u32Idx],
			au8DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S8_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataInC[8];
	int8_t		as8DataOutAdd[8];
	int8_t		as8DataOutSub[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8InputC;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 10;		as8DataInB[0] = 1;		as8DataInC[0] = 1;
	as8DataInA[1] = 100;	as8DataInB[1] = 10;		as8DataInC[1] = 1;
	as8DataInA[2] = 100;	as8DataInB[2] = 10;		as8DataInC[2] = 2;
	as8DataInA[3] = 151;	as8DataInB[3] = 150;	as8DataInC[3] = 1;
	as8DataInA[4] = 100;	as8DataInB[4] = 150;	as8DataInC[4] = 1;
	as8DataInA[5] = 255;	as8DataInB[5] = 255;	as8DataInC[5] = 1;
	as8DataInA[6] = 100;	as8DataInB[6] = 200;	as8DataInC[6] = 1;
	as8DataInA[7] = 200;	as8DataInB[7] = 200;	as8DataInC[7] = 1;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);
	vs8x8InputC		= vld1_s8(as8DataInC);

	// int8x8_t vmla_s8(int8x8_t a, int8x8_t b, int8x8_t c);					// VMLA.I8 d0,d0,d0
	// a + (b * c)
	vs8x8Output		= vmla_s8(vs8x8InputA, vs8x8InputB, vs8x8InputC);
	vst1_s8(as8DataOutAdd, vs8x8Output);

	// int8x8_t vmls_s8(int8x8_t a, int8x8_t b, int8x8_t c);					// VMLS.I8 d0,d0,d0
	// a - (b * c)
	vs8x8Output		= vmls_s8(vs8x8InputA, vs8x8InputB, vs8x8InputC);
	vst1_s8(as8DataOutSub, vs8x8Output);

	printf("== Multiple s8 = s8 +- (s8 * s8) (vmla_s8 / vmls_s8) ==\n");
	printf("=> vmla_s8 : s8 = s8 + (s8 * s8)                     ==\n");
	printf("=> vmls_s8 : s8 = s8 - (s8 * s8)                     ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d +/- (%4d * %4d) = %4d, %4d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx], as8DataInC[u32Idx],
			as8DataOutAdd[u32Idx],
			as8DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_U16_U16_U8_U8()
{
	uint16_t	au16DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataInC[8];
	uint16_t	au16DataOutAdd[8];
	uint16_t	au16DataOutSub[8];

	uint16x8_t	vu16x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8InputC;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 1;		au8DataInB[0] = 1;		au8DataInC[0] = 1;
	au16DataInA[1] = 10;	au8DataInB[1] = 10;		au8DataInC[1] = 1;
	au16DataInA[2] = 100;	au8DataInB[2] = 50;		au8DataInC[2] = 2;
	au16DataInA[3] = 1000;	au8DataInB[3] = 100;	au8DataInC[3] = 2;
	au16DataInA[4] = 200;	au8DataInB[4] = 100;	au8DataInC[4] = 3;
	au16DataInA[5] = 300;	au8DataInB[5] = 200;	au8DataInC[5] = 3;
	au16DataInA[6] = 400;	au8DataInB[6] = 100;	au8DataInC[6] = 4;
	au16DataInA[7] = 500;	au8DataInB[7] = 200;	au8DataInC[7] = 4;

	vu16x8InputA	= vld1q_u16(au16DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// uint16x8_t vmlal_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c);				// VMLAL.U8 q0,d0,d0
	// a + (b * c)
	vu16x8Output	= vmlal_u8(vu16x8InputA, vu8x8InputB, vu8x8InputC);
	vst1q_s16(au16DataOutAdd, vu16x8Output);

	// uint16x8_t vmlsl_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c);				// VMLAL.U8 q0,d0,d0
	// a - (b * c)
	vu16x8Output	= vmlsl_u8(vu16x8InputA, vu8x8InputB, vu8x8InputC);
	vst1q_s16(au16DataOutSub, vu16x8Output);

	printf("== Multiple u16 = u16 +- (u8 * u8) (vmlal_u8 / vmlsl_u8) ==\n");
	printf("=> vmlal_u8 : u16 = u16 + (u8 * u8)                      ==\n");
	printf("=> vmlsl_u8 : u16 = u16 - (u8 * u8)                      ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d +/- (%3d * %3d) = %5d, %5d\n",
			au16DataInA[u32Idx], au8DataInB[u32Idx], au8DataInC[u32Idx],
			au16DataOutAdd[u32Idx],
			au16DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S16_S16_S8_S8()
{
	int16_t		as16DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataInC[8];
	int16_t		as16DataOutAdd[8];
	int16_t		as16DataOutSub[8];

	int16x8_t	vs16x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8InputC;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 1;		as8DataInB[0] = 1;		as8DataInC[0] = 1;
	as16DataInA[1] = 10;	as8DataInB[1] = 10;		as8DataInC[1] = 1;
	as16DataInA[2] = 100;	as8DataInB[2] = 50;		as8DataInC[2] = -2;
	as16DataInA[3] = 1000;	as8DataInB[3] = 100;	as8DataInC[3] = 2;
	as16DataInA[4] = 200;	as8DataInB[4] = 100;	as8DataInC[4] = -3;
	as16DataInA[5] = 300;	as8DataInB[5] = 200;	as8DataInC[5] = 3;
	as16DataInA[6] = 400;	as8DataInB[6] = 100;	as8DataInC[6] = -4;
	as16DataInA[7] = 500;	as8DataInB[7] = 200;	as8DataInC[7] = 4;

	vs16x8InputA	= vld1q_s16(as16DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);
	vs8x8InputC		= vld1_s8(as8DataInC);

	// int16x8_t vmlal_s8(int16x8_t a, int8x8_t b, int8x8_t c);					// VMLAL.S8 q0,d0,d0
	// a + (b * c)
	vs16x8Output	= vmlal_s8(vs16x8InputA, vs8x8InputB, vs8x8InputC);
	vst1q_s16(as16DataOutAdd, vs16x8Output);

	// int16x8_t vmlsl_s8(int16x8_t a, int8x8_t b, int8x8_t c);					// VMLAL.U8 q0,d0,d0
	// a - (b * c)
	vs16x8Output	= vmlsl_s8(vs16x8InputA, vs8x8InputB, vs8x8InputC);
	vst1q_s16(as16DataOutSub, vs16x8Output);

	printf("== Multiple s16 = s16 +- (s8 * s8) (vmlal_s8 / vmlsl_s8) ==\n");
	printf("=> vmlal_s8 : s16 = s16 + (s8 * s8)                      ==\n");
	printf("=> vmlsl_s8 : s16 = s16 - (s8 * s8)                      ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d +/- (%4d * %4d) = %6d, %6d\n",
			as16DataInA[u32Idx], as8DataInB[u32Idx], as8DataInC[u32Idx],
			as16DataOutAdd[u32Idx],
			as16DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_U16_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint16_t	au16DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 1;		au8DataInB[0] = 1;
	au8DataInA[1] = 10;		au8DataInB[1] = 10;
	au8DataInA[2] = 100;	au8DataInB[2] = 101;
	au8DataInA[3] = 151;	au8DataInB[3] = 150;
	au8DataInA[4] = 100;	au8DataInB[4] = 150;
	au8DataInA[5] = 255;	au8DataInB[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 200;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint16x8_t vmull_u8(uint8x8_t a, uint8x8_t b);							// VMULL.U8 q0,d0,d0
	// (a * b)
	vu16x8Output	= vmull_u8(vu8x8InputA, vu8x8InputB);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Multiple u16 = u8 * u8 (vmull_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d * %3d = %5d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S16_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int16_t		as16DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 1;		as8DataInB[0] = 1;
	as8DataInA[1] = -10;	as8DataInB[1] = 10;
	as8DataInA[2] = 100;	as8DataInB[2] = 101;
	as8DataInA[3] = -100;	as8DataInB[3] = 101;
	as8DataInA[4] = 100;	as8DataInB[4] = -101;
	as8DataInA[5] = -100;	as8DataInB[5] = -101;
	as8DataInA[6] = 100;	as8DataInB[6] = -10;
	as8DataInA[7] = -10;	as8DataInB[7] = -10;

	vs8x8InputA		= vld1_u8(as8DataInA);
	vs8x8InputB		= vld1_u8(as8DataInB);

	// int16x8_t vmull_s8(int8x8_t a, int8x8_t b);								// VMULL.S8 q0,d0,d0
	// (a * b)
	vs16x8Output	= vmull_s8(vs8x8InputA, vs8x8InputB);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Multiple s16 = s8 * s8 (vmull_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d * %4d = %6d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S16_S16_S16()
{
	int16_t		as16DataInA[4];
	int16_t		as16DataInB[4];
	int16_t		as16DataOutSaturateDoubleMultipleHigh[4];
	int16_t		as16DataOutSaturateRoundDoubleMultipleHigh[4];

	int16x4_t	vs16x4InputA;
	int16x4_t	vs16x4InputB;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 1000;		as16DataInB[0] = 1000;
	as16DataInA[1] = 500;		as16DataInB[1] = 500;
	as16DataInA[2] = 100;		as16DataInB[2] = 10;
	as16DataInA[3] = 1000;		as16DataInB[3] = 2000;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int16x4_t vqdmulh_s16(int16x4_t a, int16x4_t b);							// VQDMULH.S16 d0,d0,d0
	// (2 * a * b) >> 16
	vs16x4Output	= vqdmulh_s16(vs16x4InputA, vs16x4InputB);
	vst1_s16(as16DataOutSaturateDoubleMultipleHigh, vs16x4Output);

	// int16x4_t vqrdmulh_s16(int16x4_t a, int16x4_t b);						// VQRDMULH.S16 d0,d0,d0
	// ROUND((2 * a * b) >> 16)
	vs16x4Output	= vqrdmulh_s16(vs16x4InputA, vs16x4InputB);
	vst1_s16(as16DataOutSaturateRoundDoubleMultipleHigh, vs16x4Output);

	printf("== Multiple s16 = s16 * s16 (vqdmulh_s16 / vqrdmulh_s16) ==\n");
	printf("=> vqdmulh_s16  : s16 = (2 * s16 * s16) >> 16            ==\n");
	printf("=> vqrdmulh_s16 : s16 = ROUND((2 * s16 * s16) >> 16)     ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("2 * %6d * %6d = %6d, %6d\n",
			as16DataInA[u32Idx], as16DataInB[u32Idx],
			as16DataOutSaturateDoubleMultipleHigh[u32Idx],
			as16DataOutSaturateRoundDoubleMultipleHigh[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S32_S32_S16_S16()
{
	int32_t		as32DataInA[4];
	int16_t		as16DataInB[4];
	int16_t		as16DataInC[4];
	int32_t		as32DataOutSaturateDoubleMultipleAddLong[4];
	int32_t		as32DataOutSaturateDoubleMultipleSubLong[4];

	int32x4_t	vs32x4InputA;
	int16x4_t	vs16x4InputB;
	int16x4_t	vs16x4InputC;
	int32x4_t	vs32x4Output;

	uint32_t	u32Idx;

	// initial
	as32DataInA[0] = 10000;		as16DataInB[0] = 1;		as16DataInC[0] = 1;
	as32DataInA[1] = 10000;		as16DataInB[1] = 10;	as16DataInC[1] = 10;
	as32DataInA[2] = 10000;		as16DataInB[2] = 100;	as16DataInC[2] = 101;
	as32DataInA[3] = 10000;		as16DataInB[3] = 151;	as16DataInC[3] = 150;

	vs32x4InputA	= vld1q_s32(as32DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);
	vs16x4InputC	= vld1_s16(as16DataInC);

	// int32x4_t vqdmlal_s16(int32x4_t a, int16x4_t b, int16x4_t c);			// VQDMLAL.S16 q0,d0,d0
	// (a + (2 * b * c)) > MAX ? MAX : (a + (2 * b * c))
	vs32x4Output	= vqdmlal_s16(vs32x4InputA, vs16x4InputB, vs16x4InputC);
	vst1q_s32(as32DataOutSaturateDoubleMultipleAddLong, vs32x4Output);

	// int32x4_t vqdmlsl_s16(int32x4_t a, int16x4_t b, int16x4_t c);			// VQDMLSL.S16 q0,d0,d0
	// (a - (2 * b * c)) > MAX ? MAX : (a - (2 * b * c))
	vs32x4Output	= vqdmlsl_s16(vs32x4InputA, vs16x4InputB, vs16x4InputC);
	vst1q_s32(as32DataOutSaturateDoubleMultipleSubLong, vs32x4Output);

	printf("== Multiple s32 = SATURATION(s32 +- s16 * s16) (vqdmlal_s16 / vqdmlsl_s16) ==\n");
	printf("=> vqdmlal_s16 : s32 = SATURATE(s32 + (2 * s16 * s16))                     ==\n");
	printf("=> vqdmlsl_s16 : s32 = SATURATE(s32 - (2 * s16 * s16))                     ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%11d +/- (2 * %6d * %6d) = %11d, %11d\n",
			as32DataInA[u32Idx], as16DataInB[u32Idx], as16DataInC[u32Idx],
			as32DataOutSaturateDoubleMultipleAddLong[u32Idx],
			as32DataOutSaturateDoubleMultipleSubLong[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S32_S16_S16()
{
	int16_t		as16DataInA[4];
	int16_t		as16DataInB[4];
	int32_t		as32DataOut[4];

	int16x4_t	vs16x4InputA;
	int16x4_t	vs16x4InputB;
	int32x4_t	vs32x4Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 1;		as16DataInB[0] = 1;
	as16DataInA[1] = 10;	as16DataInB[1] = 10;
	as16DataInA[2] = 100;	as16DataInB[2] = 101;
	as16DataInA[3] = 151;	as16DataInB[3] = 150;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int32x4_t vqdmull_s16(int16x4_t a, int16x4_t b);							// VQDMULL.S16 q0,d0,d0
	// SATURATE(2 * a * b)
	vs32x4Output	= vqdmull_s16(vs16x4InputA, vs16x4InputB);
	vst1q_s32(as32DataOut, vs32x4Output);

	printf("== Multiple s32 = SATURATE(2 * s16 * s16) (vqdmull_s16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("2 * %6d * %6d = %11d\n",
			as16DataInA[u32Idx], as16DataInB[u32Idx],
			as32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_S64_S32_S32()
{
	int32_t		as32DataInA[2];
	int32_t		as32DataInB[2];
	int64_t		as64DataOut[2];

	int32x2_t	vs32x2InputA;
	int32x2_t	vs32x2InputB;
	int64x2_t	vs64x2Output;

	uint32_t	u32Idx;

	// initial
	as32DataInA[0] = 100;	as32DataInB[0] = 101;
	as32DataInA[1] = 151;	as32DataInB[1] = 150;

	vs32x2InputA	= vld1_s32(as32DataInA);
	vs32x2InputB	= vld1_s32(as32DataInB);

	// int64x2_t vqdmull_s32(int32x2_t a, int32x2_t b);							// VQDMULL.S32 q0,d0,d0
	// SATURATE(2 * a * b)
	vs64x2Output	= vqdmull_s32(vs32x2InputA, vs32x2InputB);
	vst1q_s64(as64DataOut, vs64x2Output);

	printf("== Multiple s64 = SATURATE(2 * s32 * s32) (vqdmull_s32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("2 * %11d * %11d = %ld\n",
			as32DataInA[u32Idx], as32DataInB[u32Idx],
			as64DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_F32_F32_F32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 99.99;		af32DataInB[0] = -10.5;
	af32DataInA[1] = 120.01;	af32DataInB[1] = 1.5;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);

	// float32x2_t vmul_f32(float32x2_t a, float32x2_t b);						// VMUL.F32 d0,d0,d0
	// (a * b)
	vf32x2Output	= vmul_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Multiple f32 = f32 * f32 (vmul_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f * %9.4f = %9.4f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_F32_F32_F32_F32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataInC[2];
	float			af32DataOutAdd[2];
	float			af32DataOutSub[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2InputC;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 40.01;		af32DataInB[0] = -10.5;		af32DataInC[0] = 99.99;
	af32DataInA[1] = 889.1;		af32DataInB[1] = 1.5;		af32DataInC[1] = 120.01;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);
	vf32x2InputC	= vld1_f32(af32DataInC);

	// float32x2_t vmla_f32(float32x2_t a, float32x2_t b, float32x2_t c);		// VMLA.F32 d0,d0,d0
	// a + (b * c)
	vf32x2Output	= vmla_f32(vf32x2InputA, vf32x2InputB, vf32x2InputC);
	vst1_f32(af32DataOutAdd, vf32x2Output);

	// float32x2_t vmls_f32(float32x2_t a, float32x2_t b, float32x2_t c);		// VMLA.F32 d0,d0,d0
	// a - (b * c)
	vf32x2Output	= vmls_f32(vf32x2InputA, vf32x2InputB, vf32x2InputC);
	vst1_f32(af32DataOutSub, vf32x2Output);

	printf("== Multiple f32 = f32 +- f32 * f32 (vmla_f32 / vmls_f32) ==\n");
	printf("=> vmla_f32 : f32 = f32 + (f32 * f32)                    ==\n");
	printf("=> vmls_f32 : f32 = f32 - (f32 * f32)                    ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f +/- (%9.4f * %9.4f) = %9.4f, %9.4f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx], af32DataInC[u32Idx],
			af32DataOutAdd[u32Idx], af32DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Multiple_P16_P8_P8()
{
	poly8_t		ap8DataInA[8];
	poly8_t		ap8DataInB[8];
	poly16_t	ap16DataOut[8];

	poly8x8_t	vp8x8InputA;
	poly8x8_t	vp8x8InputB;
	poly16x8_t	vp16x8Output;

	uint32_t	u32Idx;

	// initial
	ap8DataInA[0] = 0b00000001;		ap8DataInB[0] = 0b00000101;
	ap8DataInA[1] = 0b00000101;		ap8DataInB[1] = 0b00000101;
	ap8DataInA[2] = 0b00001111;		ap8DataInB[2] = 0b00000101;
	ap8DataInA[3] = 0b00000101;		ap8DataInB[3] = 0b00000001;
	ap8DataInA[4] = 0b00000101;		ap8DataInB[4] = 0b00000101;
	ap8DataInA[5] = 0b00000101;		ap8DataInB[5] = 0b00001111;
	ap8DataInA[6] = 0b11100111;		ap8DataInB[6] = 0b10000001;
	ap8DataInA[7] = 0b11100111;		ap8DataInB[7] = 0b00000010;

	vp8x8InputA		= vld1_p8(ap8DataInA);
	vp8x8InputB		= vld1_p8(ap8DataInB);

	// poly16x8_t vmull_p8(poly8x8_t a, poly8x8_t b);							// VMULL.P8 q0,d0,d0
	vp16x8Output	= vmull_p8(vp8x8InputA, vp8x8InputB);
	vst1q_p16(ap16DataOut, vp16x8Output);

	printf("== Multiple p16 = p8 * p8 (vmull_p8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("("UINT8_TO_BIT_PATTERN") * ("UINT8_TO_BIT_PATTERN")\n",
			UINT8_TO_BIT(ap8DataInA[u32Idx]), UINT8_TO_BIT(ap8DataInB[u32Idx]));

		printf("==> "UINT16_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(ap16DataOut[u32Idx]));
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
