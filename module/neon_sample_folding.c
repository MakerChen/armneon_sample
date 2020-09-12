#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-folding-maximum
// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-folding-minimum

// -----------------------------------------------------------------------------
void NeonSample_Folding_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOutMax[8];
	uint8_t		au8DataOutMin[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au8DataInA[0] = 100;	au8DataInA[1] = 20;
	au8DataInA[2] = 100;	au8DataInA[3] = 120;
	au8DataInA[4] = 180;	au8DataInA[5] = 200;
	au8DataInA[6] = 220;	au8DataInA[7] = 200;

	au8DataInB[0] = 50;		au8DataInB[1] = 0;
	au8DataInB[2] = 50;		au8DataInB[3] = 255;
	au8DataInB[4] = 0;		au8DataInB[5] = 150;
	au8DataInB[6] = 255;	au8DataInB[7] = 150;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vpmax_u8(uint8x8_t a, uint8x8_t b);							// VPMAX.U8 d0,d0,d0
	// r(i) = max(a(i * 2) + a(i * 2 + 1)), i < 4
	// r(i) = max(b(j * 2) + b(j * 2 + 1)), i >= 4, j = i - 4
	vu8x8Output		= vpmax_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutMax, vu8x8Output);

	// uint8x8_t vpmin_u8(uint8x8_t a, uint8x8_t b);							// VPMIN.U8 d0,d0,d0
	// r(i) = min(a(i * 2) + a(i * 2 + 1)), i < 4
	// r(i) = min(b(j * 2) + b(j * 2 + 1)), i >= 4, j = i - 4
	vu8x8Output		= vpmin_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutMin, vu8x8Output);

	printf("== Floding u8 = u8, u8 (vpmax_u8 / vpmin_u8)                  ==\n");
	printf("=> r(i) = max/min(a(i * 2) + a(i * 2 + 1)), i < 4             ==\n");
	printf("=> r(i) = max/min(b(j * 2) + b(j * 2 + 1)), i >= 4, j = i - 4 ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %3d, a[%1d], %3d = r[%1d], %3d, %3d\n",
			u32Idx2, au8DataInA[u32Idx2],
			u32Idx2 + 1, au8DataInA[u32Idx2 + 1],
			u32Idx, au8DataOutMax[u32Idx], au8DataOutMin[u32Idx]);
	}
	for (u32Idx = 4, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("b[%1d], %3d, b[%1d], %3d = r[%1d], %3d, %3d\n",
			u32Idx2, au8DataInB[u32Idx2],
			u32Idx2 + 1, au8DataInB[u32Idx2 + 1],
			u32Idx, au8DataOutMax[u32Idx], au8DataOutMin[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Folding_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOutMax[8];
	int8_t		as8DataOutMin[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataInA[0] = 0;		as8DataInA[1] = -100;
	as8DataInA[2] = 0;		as8DataInA[3] = 10;
	as8DataInA[4] = -10;	as8DataInA[5] = 50;
	as8DataInA[6] = 60;		as8DataInA[7] = 50;

	as8DataInB[0] = 100;	as8DataInB[1] = -50;
	as8DataInB[2] = 100;	as8DataInB[3] = 120;
	as8DataInB[4] = -99;	as8DataInB[5] = -100;
	as8DataInB[6] = -101;	as8DataInB[7] = -100;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vpmax_s8(int8x8_t a, int8x8_t b);								// VPMAX.S8 d0,d0,d0
	// r(i) = max(a(i * 2) + a(i * 2 + 1)), i < 4
	// r(i) = max(b(j * 2) + b(j * 2 + 1)), i >= 4, j = i - 4
	vs8x8Output		= vpmax_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutMax, vs8x8Output);

	// int8x8_t vpmin_s8(int8x8_t a, int8x8_t b);								// VPMIN.S8 d0,d0,d0
	// r(i) = min(a(i * 2) + a(i * 2 + 1)), i < 4
	// r(i) = min(b(j * 2) + b(j * 2 + 1)), i >= 4, j = i - 4
	vs8x8Output		= vpmin_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutMin, vs8x8Output);

	printf("== Floding s8 = s8, s8 (vpmax_s8 / vpmin_s8)                  ==\n");
	printf("=> r(i) = max/min(a(i * 2) + a(i * 2 + 1)), i < 4             ==\n");
	printf("=> r(i) = max/min(b(j * 2) + b(j * 2 + 1)), i >= 4, j = i - 4 ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %4d, a[%1d], %4d = r[%1d], %4d, %4d\n",
			u32Idx2, as8DataInA[u32Idx2],
			u32Idx2 + 1, as8DataInA[u32Idx2 + 1],
			u32Idx, as8DataOutMax[u32Idx], as8DataOutMin[u32Idx]);
	}
	for (u32Idx = 4, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("b[%1d], %4d, b[%1d], %4d = r[%1d], %4d, %4d\n",
			u32Idx2, as8DataInB[u32Idx2],
			u32Idx2 + 1, as8DataInB[u32Idx2 + 1],
			u32Idx, as8DataOutMax[u32Idx], as8DataOutMin[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Folding_F32_F32_F32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataOutMax[2];
	float			af32DataOutMin[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx, u32Idx2;

	// initial
	af32DataInA[0] = 99.99;		af32DataInA[1] = 120.01;

	af32DataInB[0] = -10.5;		af32DataInB[1] = 1.5;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);

	// float32x2_t vpmax_f32(float32x2_t a, float32x2_t b);						// VPMAX.F32 d0,d0,d0
	// r(i) = max(a(i * 2) + a(i * 2 + 1)), i < 1
	// r(i) = max(b(j * 2) + b(j * 2 + 1)), i >= 1, j = i - 1
	vf32x2Output	= vpmax_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOutMax, vf32x2Output);

	// float32x2_t vpmin_f32(float32x2_t a, float32x2_t b);						// VPMIN.F32 d0,d0,d0
	// r(i) = min(a(i * 2) + a(i * 2 + 1)), i < 1
	// r(i) = min(b(j * 2) + b(j * 2 + 1)), i >= 1, j = i - 1
	vf32x2Output	= vpmin_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOutMin, vf32x2Output);

	printf("== Floding f32 = f32, f32 (vpmax_f32 / vpmin_f32)             ==\n");
	printf("=> r(i) = max/min(a(i * 2) + a(i * 2 + 1)), i < 1             ==\n");
	printf("=> r(i) = max/min(b(j * 2) + b(j * 2 + 1)), i >= 1, j = i - 1 ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 1; ++u32Idx, u32Idx2 += 2)
	{
		printf("a[%1d], %9.4f, a[%1d], %9.4f = r[%1d], %9.4f, %9.4f\n",
			u32Idx2, af32DataInA[u32Idx2],
			u32Idx2 + 1, af32DataInA[u32Idx2 + 1],
			u32Idx, af32DataOutMax[u32Idx], af32DataOutMin[u32Idx]);
	}
	for (u32Idx = 1, u32Idx2 = 0; u32Idx < 2; ++u32Idx, u32Idx2 += 2)
	{
		printf("b[%1d], %9.4f, b[%1d], %9.4f = r[%1d], %9.4f, %9.4f\n",
			u32Idx2, af32DataInB[u32Idx2],
			u32Idx2 + 1, af32DataInB[u32Idx2 + 1],
			u32Idx, af32DataOutMax[u32Idx], af32DataOutMin[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
