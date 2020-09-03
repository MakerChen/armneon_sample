#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-combining-vectors

// -----------------------------------------------------------------------------
void NeonSample_Combine_U8_U8_U8()
{
	uint8_t		au8DataInLow[8];
	uint8_t		au8DataInHigh[8];
	uint8_t		au8DataOut[16];

	uint8x8_t	vu8x8InputLow;
	uint8x8_t	vu8x8InputHigh;
	uint8x16_t	vu8x16Output;

	uint32_t	u32Idx;

	// initial
	au8DataInLow[0] = 0;		au8DataInHigh[0] = 100;
	au8DataInLow[1] = 10;		au8DataInHigh[1] = 110;
	au8DataInLow[2] = 20;		au8DataInHigh[2] = 120;
	au8DataInLow[3] = 30;		au8DataInHigh[3] = 130;
	au8DataInLow[4] = 40;		au8DataInHigh[4] = 140;
	au8DataInLow[5] = 50;		au8DataInHigh[5] = 150;
	au8DataInLow[6] = 60;		au8DataInHigh[6] = 160;
	au8DataInLow[7] = 70;		au8DataInHigh[7] = 170;

	vu8x8InputLow	= vld1_u8(au8DataInLow);
	vu8x8InputHigh	= vld1_u8(au8DataInHigh);

	// uint8x16_t vcombine_u8(uint8x8_t low, uint8x8_t high);					// VMOV d0,d0
	// (high << (8 * 8) | low)
	vu8x16Output	= vcombine_u8(vu8x8InputLow, vu8x8InputHigh);
	vst1q_u8(au8DataOut, vu8x16Output);

	printf("== Combine u8 = u8, u8 (vcombine_u8) ==\n");
	printf("=> r(i) = low(i), i < 8              ==\n");
	printf("=> r(i) = high(j), i >= 8, j = i - 8 ==\n");

	printf("Input Low  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInLow[u32Idx]);
	}
	printf("\n");

	printf("Input High : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("    ");
	}
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInHigh[u32Idx]);
	}
	printf("\n");

	printf("Output     : ");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Combine_S8_S8_S8()
{
	int8_t		as8DataInLow[8];
	int8_t		as8DataInHigh[8];
	int8_t		as8DataOut[16];

	int8x8_t	vs8x8InputLow;
	int8x8_t	vs8x8InputHigh;
	int8x16_t	vs8x16Output;

	uint32_t	u32Idx;

	// initial
	as8DataInLow[0] = 0;		as8DataInHigh[0] = -100;
	as8DataInLow[1] = 10;		as8DataInHigh[1] = -90;
	as8DataInLow[2] = 20;		as8DataInHigh[2] = -80;
	as8DataInLow[3] = 30;		as8DataInHigh[3] = -70;
	as8DataInLow[4] = 40;		as8DataInHigh[4] = -60;
	as8DataInLow[5] = 50;		as8DataInHigh[5] = -50;
	as8DataInLow[6] = 60;		as8DataInHigh[6] = -40;
	as8DataInLow[7] = 70;		as8DataInHigh[7] = -30;

	vs8x8InputLow	= vld1_s8(as8DataInLow);
	vs8x8InputHigh	= vld1_s8(as8DataInHigh);

	// int8x16_t vcombine_s8(int8x8_t low, int8x8_t high);						// VMOV d0,d0
	// (high << (8 * 8) | low)
	vs8x16Output	= vcombine_s8(vs8x8InputLow, vs8x8InputHigh);
	vst1q_s8(as8DataOut, vs8x16Output);

	printf("== Combine s8 = s8, s8 (vcombine_s8) ==\n");
	printf("=> r(i) = low(i), i < 8              ==\n");
	printf("=> r(i) = high(j), i >= 8, j = i - 8 ==\n");

	printf("Input Low  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInLow[u32Idx]);
	}
	printf("\n");

	printf("Input High : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("     ");
	}
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInHigh[u32Idx]);
	}
	printf("\n");

	printf("Output     : ");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Combine_F32_F32_F32()
{
	float			af32DataInLow[2];
	float			af32DataInHigh[2];
	float			af32DataOut[4];

	float32x2_t		vf32x2InputLow;
	float32x2_t		vf32x2InputHigh;
	float32x4_t		vf32x4Output;

	uint32_t		u32Idx;

	// initial
	af32DataInLow[0] = 55.55;	af32DataInHigh[0] = -66.66;
	af32DataInLow[1] = 33.33;	af32DataInHigh[1] = -99.99;

	vf32x2InputLow	= vld1_f32(af32DataInLow);
	vf32x2InputHigh	= vld1_f32(af32DataInHigh);

	// float32x4_t vcombine_f32(float32x2_t low, float32x2_t high);				// VMOV d0,d0
	// (high << (8 * 8) | low)
	vf32x4Output	= vcombine_f32(vf32x2InputLow, vf32x2InputHigh);
	vst1q_f32(af32DataOut, vf32x4Output);

	printf("== Combine f32 = f32, f32 (vcombine_f32) ==\n");
	printf("=> r(i) = low(i), i < 2                  ==\n");
	printf("=> r(i) = high(j), i >= 2, j = i - 2     ==\n");

	printf("Input Low  : ");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataInLow[u32Idx]);
	}
	printf("\n");

	printf("Input High : ");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("          ");
	}
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataInHigh[u32Idx]);
	}
	printf("\n");

	printf("Output     : ");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%9.4f ", af32DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Combine_P8_P8_P8()
{
	poly8_t		ap8DataIn1[8];
	poly8_t		ap8DataIn2[8];
	poly8_t		ap8DataOut[16];

	poly8x8_t	vp8x8InputA;
	poly8x8_t	vp8x8InputB;
	poly8x16_t	vp8x16Output;

	uint32_t	u32Idx;

	// initial
	ap8DataIn1[0] = 0b00000001;		ap8DataIn2[0] = 0b00000101;
	ap8DataIn1[1] = 0b00000101;		ap8DataIn2[1] = 0b00000101;
	ap8DataIn1[2] = 0b00001111;		ap8DataIn2[2] = 0b00000101;
	ap8DataIn1[3] = 0b00000101;		ap8DataIn2[3] = 0b00000001;
	ap8DataIn1[4] = 0b00000101;		ap8DataIn2[4] = 0b00000101;
	ap8DataIn1[5] = 0b00000101;		ap8DataIn2[5] = 0b00001111;
	ap8DataIn1[6] = 0b11100111;		ap8DataIn2[6] = 0b10000001;
	ap8DataIn1[7] = 0b11100111;		ap8DataIn2[7] = 0b00000010;

	vp8x8InputA		= vld1_p8(ap8DataIn1);
	vp8x8InputB		= vld1_p8(ap8DataIn2);

	// poly8x16_t vcombine_p8(poly8x8_t low, poly8x8_t high);					// VMOV d0,d0
	vp8x16Output	= vcombine_p8(vp8x8InputA, vp8x8InputB);
	vst1q_p8(ap8DataOut, vp8x16Output);

	printf("== Combine p8 = p8, p8 (vcombine_p8) ==\n");
	printf("=> r(i) = low(i), i < 8              ==\n");
	printf("=> r(i) = high(j), i >= 8, j = i - 8 ==\n");

	printf("Input Low  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(ap8DataIn1[u32Idx]));
	}
	printf("\n");

	printf("Input High : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(ap8DataIn2[u32Idx]));
	}
	printf("\n");

	printf("Output     : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("\n");
	printf("             ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(ap8DataOut[u32Idx + 8]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
