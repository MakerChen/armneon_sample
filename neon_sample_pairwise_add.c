#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-pairwise-addition

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au8DataInA[0] = 1;		au8DataInA[1] = 10;
	au8DataInA[2] = 100;	au8DataInA[3] = 151;
	au8DataInA[4] = 100;	au8DataInA[5] = 255;
	au8DataInA[6] = 100;	au8DataInA[7] = 200;

	au8DataInB[0] = 1;		au8DataInB[1] = 10;
	au8DataInB[2] = 101;	au8DataInB[3] = 150;
	au8DataInB[4] = 150;	au8DataInB[5] = 255;
	au8DataInB[6] = 200;	au8DataInB[7] = 200;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// r0 = a0 + a1, ..., r3 = a6 + a7, r4 = b0 + b1, ..., r7 = b6 + b7

	// uint8x8_t vpadd_u8(uint8x8_t a, uint8x8_t b);							// VPADD.I8 d0,d0,d0
	// r(i) = a(i * 2) + a(i * 2 + 1), i < 4
	// r(i) = b(j * 2) + b(j * 2 + 1), i >= 4, j = i - 4
	vu8x8Output		= vpadd_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Pairwise Add u8 = u8, u8 (vpadd_u8)               ==\n");
	printf("=> r(i) = a(i * 2) + a(i * 2 + 1), i < 4             ==\n");
	printf("=> r(i) = b(j * 2) + b(j * 2 + 1), i >= 4, j = i - 4 ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %3d + a[%1d], %3d = r[%1d], %3d\n",
			u32Idx2, au8DataInA[u32Idx2],
			u32Idx2 + 1, au8DataInA[u32Idx2 + 1],
			u32Idx, au8DataOut[u32Idx]);
	}
	for (u32Idx = 4, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("b[%1d], %3d + b[%1d], %3d = r[%1d], %3d\n",
			u32Idx2, au8DataInB[u32Idx2],
			u32Idx2 + 1, au8DataInB[u32Idx2 + 1],
			u32Idx, au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataInA[0] = 1;		as8DataInA[1] = 10;
	as8DataInA[2] = 100;	as8DataInA[3] = 151;
	as8DataInA[4] = 100;	as8DataInA[5] = 127;
	as8DataInA[6] = 100;	as8DataInA[7] = -120;

	as8DataInB[0] = 1;		as8DataInB[1] = 10;
	as8DataInB[2] = -101;	as8DataInB[3] = 110;
	as8DataInB[4] = 110;	as8DataInB[5] = -120;
	as8DataInB[6] = 100;	as8DataInB[7] = 100;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vpadd_s8(int8x8_t a, int8x8_t b);								// VPADD.I8 d0,d0,d0
	// r(i) = a(i * 2) + a(i * 2 + 1), i < 4
	// r(i) = b(j * 2) + b(j * 2 + 1), i >= 4, j = i - 4
	vs8x8Output		= vpadd_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Pairwise Add s8 = s8, s8 (vpadd_s8)               ==\n");
	printf("=> r(i) = a(i * 2) + a(i * 2 + 1), i < 4             ==\n");
	printf("=> r(i) = b(j * 2) + b(j * 2 + 1), i >= 4, j = i - 4 ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %4d + a[%1d], %4d = r[%1d], %4d\n",
			u32Idx2, as8DataInA[u32Idx2],
			u32Idx2 + 1, as8DataInA[u32Idx2 + 1],
			u32Idx, as8DataOut[u32Idx]);
	}
	for (u32Idx = 4, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("b[%1d], %4d + b[%1d], %4d = r[%1d], %4d\n",
			u32Idx2, as8DataInB[u32Idx2],
			u32Idx2 + 1, as8DataInB[u32Idx2 + 1],
			u32Idx, as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_F32_F32_F32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx, u32Idx2;

	// initial
	af32DataInA[0] = 5.99;		af32DataInA[1] = 4.01;

	af32DataInB[0] = 100.9999;	af32DataInB[1] = 200;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);

	// r0 = a0 + a1, ..., r3 = a6 + a7, r4 = b0 + b1, ..., r7 = b6 + b7

	// float32x2_t vpadd_f32(float32x2_t a, float32x2_t b);						// VPADD.F32 d0,d0,d0
	// r(i) = a(i * 2) + a(i * 2 + 1), i < 4
	// r(i) = b(j * 2) + b(j * 2 + 1), i >= 4, j = i - 4
	vf32x2Output	= vpadd_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Pairwise Add f32 = f32, f32 (vpadd_f32)           ==\n");
	printf("=> r(i) = a(i * 2) + a(i * 2 + 1), i < 4             ==\n");
	printf("=> r(i) = b(j * 2) + b(j * 2 + 1), i >= 4, j = i - 4 ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 1; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %9.4f + a[%1d], %9.4f = r[%1d], %9.4f\n",
			u32Idx2, af32DataInA[u32Idx2],
			u32Idx2 + 1, af32DataInA[u32Idx2 + 1],
			u32Idx, af32DataOut[u32Idx]);
	}
	for (u32Idx = 1, u32Idx2 = 0; u32Idx < 2; ++u32Idx, u32Idx2 += 2)
	{
		printf("b[%1d], %9.4f + b[%1d], %9.4f = r[%1d], %9.4f\n",
			u32Idx2, af32DataInB[u32Idx2],
			u32Idx2 + 1, af32DataInB[u32Idx2 + 1],
			u32Idx, af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_U16_U8()
{
	uint8_t		au8DataIn[8];
	uint16_t	au16DataOut[4];

	uint8x8_t	vu8x8Input;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au8DataIn[0] = 1;		au8DataIn[1] = 10;
	au8DataIn[2] = 100;		au8DataIn[3] = 151;
	au8DataIn[4] = 100;		au8DataIn[5] = 255;
	au8DataIn[6] = 100;		au8DataIn[7] = 200;

	vu8x8Input		= vld1_u8(au8DataIn);

	// uint16x4_t vpaddl_u8(uint8x8_t a);										// VPADDL.U8 d0,d0
	// r0 = a0 + a1, ..., r3 = a6 + a7
	vu16x4Output	= vpaddl_u8(vu8x8Input);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Pairwise Add u16 = u8 (vpaddl_u8) ==\n");
	printf("=> r(i) = a(i * 2) + a(i * 2 + 1)    ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %3d + a[%1d], %3d = r[%1d], %5d\n",
			u32Idx2, au8DataIn[u32Idx2],
			u32Idx2 + 1, au8DataIn[u32Idx2 + 1],
			u32Idx, au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_S16_S8()
{
	int8_t		as8DataIn[8];
	int16_t		as16DataOut[4];

	int8x8_t	vs8x8Input;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataIn[0] = 1;		as8DataIn[1] = 10;
	as8DataIn[2] = 100;		as8DataIn[3] = 151;
	as8DataIn[4] = 100;		as8DataIn[5] = 255;
	as8DataIn[6] = 100;		as8DataIn[7] = 200;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int16x4_t vpaddl_s8(int8x8_t a);											// VPADDL.S8 d0,d0
	// r0 = a0 + a1, ..., r3 = a6 + a7
	vs16x4Output	= vpaddl_s8(vs8x8Input);
	vst1_s16(as16DataOut, vs16x4Output);

	printf("== Pairwise Add s16 = s8 (vpaddl_s8) ==\n");
	printf("=> r(i) = a(i * 2) + a(i * 2 + 1)    ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %4d + a[%1d], %4d = r[%1d], %4d\n",
			u32Idx2, as8DataIn[u32Idx2],
			u32Idx2 + 1, as8DataIn[u32Idx2 + 1],
			u32Idx, as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_U16_U16_U8()
{
	uint16_t	au16DataInA[4];
	uint8_t		au8DataInB[8];
	uint16_t	au16DataOut[4];

	uint16x4_t	vu16x4InputA;
	uint8x8_t	vu8x8InputB;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au16DataInA[0] = 1;		au8DataInB[0] = 1;		au8DataInB[1] = 10;
	au16DataInA[1] = 10;	au8DataInB[2] = 101;	au8DataInB[3] = 150;
	au16DataInA[2] = 100;	au8DataInB[4] = 150;	au8DataInB[5] = 255;
	au16DataInA[3] = 151;	au8DataInB[6] = 200;	au8DataInB[7] = 200;

	vu16x4InputA	= vld1_u16(au16DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint16x4_t vpadal_u8(uint16x4_t a, uint8x8_t b);							// VPADAL.U8 d0,d0
	// r(i) = a(i) + (b(i * 2) + b(i * 2 + 1))
	vu16x4Output	= vpadal_u8(vu16x4InputA, vu8x8InputB);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Pairwise Add & Accumulate u16 = u16 + u8 (vpadal_u8) ==\n");
	printf("=> r(i) = a(i) + (b(i * 2) + b(i * 2 + 1))              ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 +=2)
	{
		printf("a[%1d], %5d + (b[%1d], %3d + b[%1d], %3d) = r[%1d], %5d\n",
			u32Idx, au16DataInA[u32Idx],
			u32Idx2, au8DataInB[u32Idx2],
			u32Idx2 + 1, au8DataInB[u32Idx2 + 1],
			u32Idx, au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_S16_S16_S8()
{
	int16_t		as16DataInA[4];
	int8_t		as8DataInB[8];
	int16_t		as16DataOut[4];

	int16x4_t	vs16x4InputA;
	int8x8_t	vs8x8InputB;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as16DataInA[0] = 1;		as8DataInB[0] = 1;		as8DataInB[1] = 10;
	as16DataInA[1] = 10;	as8DataInB[2] = 101;	as8DataInB[3] = 150;
	as16DataInA[2] = 100;	as8DataInB[4] = 150;	as8DataInB[5] = 255;
	as16DataInA[3] = 151;	as8DataInB[6] = 200;	as8DataInB[7] = 200;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int16x4_t vpadal_s8(int16x4_t a, int8x8_t b);							// VPADAL.S8 d0,d0
	// r(i) = a(i) + (b(i * 2) + b(i * 2 + 1))
	vs16x4Output	= vpadal_s8(vs16x4InputA, vs8x8InputB);
	vst1_s16(as16DataOut, vs16x4Output);

	printf("== Pairwise Add & Accumulate s16 = s16 + s8 (vpadal_s8) ==\n");
	printf("=> r(i) = a(i) + (b(i * 2) + b(i * 2 + 1))              ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 +=2)
	{
		printf("a[%1d], %5d + (b[%1d], %4d + b[%1d], %4d) = r[%1d], %5d\n",
			u32Idx, as16DataInA[u32Idx],
			u32Idx2, as8DataInB[u32Idx2],
			u32Idx2 + 1, as8DataInB[u32Idx2 + 1],
			u32Idx, as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
