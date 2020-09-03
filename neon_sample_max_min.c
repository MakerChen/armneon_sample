#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-maximum-and-minimum

// -----------------------------------------------------------------------------
void NeonSample_MaxMin_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOutMax[8];
	uint8_t		au8DataOutMin[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 0;		au8DataInB[0] = 0;
	au8DataInA[1] = 10;		au8DataInB[1] = 20;
	au8DataInA[2] = 20;		au8DataInB[2] = 10;
	au8DataInA[3] = 100;	au8DataInB[3] = 100;
	au8DataInA[4] = 150;	au8DataInB[4] = 0;
	au8DataInA[5] = 0;		au8DataInB[5] = 150;
	au8DataInA[6] = 255;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 255;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vmax_u8(uint8x8_t a, uint8x8_t b);								// VMAX.U8 d0,d0,d0
	// max(a, b)
	vu8x8Output		= vmax_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutMax, vu8x8Output);

	// uint8x8_t vmin_u8(uint8x8_t a, uint8x8_t b);								// VMIN.U8 d0,d0,d0
	// min(a, b)
	vu8x8Output		= vmin_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutMin, vu8x8Output);

	printf("== Max/Min u8 = u8, u8 (vmax_u8 / vmin_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("(%3d, %3d) => %3d, %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOutMax[u32Idx],
			au8DataOutMin[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_MaxMin_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOutMax[8];
	int8_t		as8DataOutMin[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 0;		as8DataInB[0] = 0;
	as8DataInA[1] = -10;	as8DataInB[1] = 20;
	as8DataInA[2] = 20;		as8DataInB[2] = -10;
	as8DataInA[3] = 20;		as8DataInB[3] = 30;
	as8DataInA[4] = -20;	as8DataInB[4] = -30;
	as8DataInA[5] = 30;		as8DataInB[5] = 20;
	as8DataInA[6] = -30;	as8DataInB[6] = -20;
	as8DataInA[7] = -127;	as8DataInB[7] = 127;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vmax_s8(int8x8_t a, int8x8_t b); 								// VMAX.S8 d0,d0,d0
	// max(a, b)
	vs8x8Output		= vmax_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutMax, vs8x8Output);

	// int8x8_t vmin_s8(int8x8_t a, int8x8_t b);								// VMIN.S8 d0,d0,d0
	// min(a, b)
	vs8x8Output		= vmin_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutMin, vs8x8Output);

	printf("== Max/Min s8 = s8, s8 (vmax_s8 / vmin_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("(%4d, %4d) => %4d, %4d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as8DataOutMax[u32Idx],
			as8DataOutMin[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_MaxMin_F32_F32_F32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataOutMax[2];
	float			af32DataOutMin[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 99.99;		af32DataInB[0] = -10.5;
	af32DataInA[1] = 120.01;	af32DataInB[1] = 1.5;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);

	// float32x2_t vmax_f32(float32x2_t a, float32x2_t b);						// VMAX.F32 d0,d0,d0
	// max(a, b)
	vf32x2Output	= vmax_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOutMax, vf32x2Output);

	// float32x2_t vmin_f32(float32x2_t a, float32x2_t b);						// VMIN.F32 d0,d0,d0
	// min(a, b)
	vf32x2Output	= vmin_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOutMin, vf32x2Output);

	printf("== Max/Min f32 = f32, f32 (vmax_f32 / vmin_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("(%9.4f, %9.4f) => %9.4f, %9.4f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOutMax[u32Idx],
			af32DataOutMin[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
