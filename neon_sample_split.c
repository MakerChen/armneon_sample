#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-splitting-vectors

// -----------------------------------------------------------------------------
void NeonSample_Split_U8_U8()
{
	uint8_t		au8DataIn[16];
	uint8_t		au8DataOutLow[8];
	uint8_t		au8DataOutHigh[8];

	uint8x16_t	vu8x16Input;
	uint8x8_t	vu8x8OutputLow;
	uint8x8_t	vu8x8OutputHigh;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0]	= 0;
	au8DataIn[1]	= 10;
	au8DataIn[2]	= 20;
	au8DataIn[3]	= 30;
	au8DataIn[4]	= 40;
	au8DataIn[5]	= 50;
	au8DataIn[6]	= 60;
	au8DataIn[7]	= 70;
	au8DataIn[8]	= 100;
	au8DataIn[9]	= 110;
	au8DataIn[10]	= 120;
	au8DataIn[11]	= 130;
	au8DataIn[12]	= 140;
	au8DataIn[13]	= 150;
	au8DataIn[14]	= 160;
	au8DataIn[15]	= 170;

	vu8x16Input		= vld1q_u8(au8DataIn);

	// uint8x8_t vget_high_u8(uint8x16_t a);									// VMOV d0,d0
	// (a >> (8 * 8))
	vu8x8OutputHigh	= vget_high_u8(vu8x16Input);
	vst1_u8(au8DataOutHigh, vu8x8OutputHigh);

	// uint8x8_t vget_low_u8(uint8x16_t a);										// VMOV d0,d0
	// (a & 0xFFFFFFFFFFFFFFFF)
	vu8x8OutputLow	= vget_low_u8(vu8x16Input);
	vst1_u8(au8DataOutLow, vu8x8OutputLow);

	printf("== Split u8 = u8 (vget_high_u8 / vget_low_u8) ==\n");
	printf("=> vget_high_u8 : u8 = high(u8)               ==\n");
	printf("=> vget_low_u8  : u8 = low(u8)                ==\n");

	printf("Input       : ");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output High : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("    ");
	}
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutHigh[u32Idx]);
	}
	printf("\n");

	printf("Output Low  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutLow[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Split_S8_S8()
{
	int8_t		as8DataIn[16];
	int8_t		as8DataOutLow[8];
	int8_t		as8DataOutHigh[8];

	int8x16_t	vs8x16Input;
	int8x8_t	vs8x8OutputLow;
	int8x8_t	vs8x8OutputHigh;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0]	= 0;
	as8DataIn[1]	= 10;
	as8DataIn[2]	= 20;
	as8DataIn[3]	= 30;
	as8DataIn[4]	= 40;
	as8DataIn[5]	= 50;
	as8DataIn[6]	= 60;
	as8DataIn[7]	= 70;
	as8DataIn[8]	= -100;
	as8DataIn[9]	= -90;
	as8DataIn[10]	= -80;
	as8DataIn[11]	= -70;
	as8DataIn[12]	= -60;
	as8DataIn[13]	= -50;
	as8DataIn[14]	= -40;
	as8DataIn[15]	= -30;

	vs8x16Input		= vld1q_s8(as8DataIn);

	// int8x8_t vget_high_s8(int8x16_t a);										// VMOV d0,d0
	// (a >> (8 * 8))
	vs8x8OutputHigh	= vget_high_s8(vs8x16Input);
	vst1_s8(as8DataOutHigh, vs8x8OutputHigh);

	// int8x8_t vget_low_s8(int8x16_t a);										// VMOV d0,d0
	// (a & 0xFFFFFFFFFFFFFFFF)
	vs8x8OutputLow	= vget_low_s8(vs8x16Input);
	vst1_s8(as8DataOutLow, vs8x8OutputLow);

	printf("== Split s8 = s8 (vget_high_s8 / vget_low_s8) ==\n");
	printf("=> vget_high_s8 : s8 = high(s8)               ==\n");
	printf("=> vget_low_s8  : s8 = low(s8)                ==\n");

	printf("Input       : ");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output High : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("     ");
	}
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutHigh[u32Idx]);
	}
	printf("\n");

	printf("Output Low  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutLow[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Split_F32_F32()
{
	float			af32DataIn[4];
	float			af32DataOutLow[2];
	float			af32DataOutHigh[2];

	float32x4_t		vf32x4Input;
	float32x2_t		vf32x2OutputLow;
	float32x2_t		vf32x2OutputHigh;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0]	= 55.55;
	af32DataIn[1]	= 33.33;
	af32DataIn[2]	= -66.66;
	af32DataIn[3]	= -99.99;

	vf32x4Input			= vld1q_f32(af32DataIn);

	// float32x2_t vget_high_f32(float32x4_t a); 								// VMOV d0,d0
	// (a >> (8 * 8))
	vf32x2OutputHigh	= vget_high_f32(vf32x4Input);
	vst1_f32(af32DataOutHigh, vf32x2OutputHigh);

	// float32x2_t vget_low_f32(float32x4_t a);									// VMOV d0,d0
	// (a & 0xFFFFFFFFFFFFFFFF)
	vf32x2OutputLow		= vget_low_f32(vf32x4Input);
	vst1_f32(af32DataOutLow, vf32x2OutputLow);

	printf("== Split f32 = f32 (vget_high_f32 / vget_low_f32) ==\n");
	printf("=> vget_high_f32 : f32 = high(f32)                ==\n");
	printf("=> vget_low_f32  : f32 = low(f32)                 ==\n");

	printf("Input       : ");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%9.4f ", af32DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output High : ");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("          ");
	}
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataOutHigh[u32Idx]);
	}
	printf("\n");

	printf("Output Low  : ");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataOutLow[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Split_P8_P8()
{
	uint8_t			au8DataIn[16];
	uint8_t			au8DataOutLow[8];
	uint8_t			au8DataOutHigh[8];

	poly8x16_t		vp8x16Input;
	poly8x8_t		vp8x8OutputLow;
	poly8x8_t		vp8x8OutputHigh;

	uint32_t		u32Idx;

	// initial
	au8DataIn[0]	= 0b00000001;
	au8DataIn[1]	= 0b00000101;
	au8DataIn[2]	= 0b00001111;
	au8DataIn[3]	= 0b00000101;
	au8DataIn[4]	= 0b00000101;
	au8DataIn[5]	= 0b00000101;
	au8DataIn[6]	= 0b11100111;
	au8DataIn[7]	= 0b11100111;
	au8DataIn[8]	= 0b00000101;
	au8DataIn[9]	= 0b00000101;
	au8DataIn[10]	= 0b00000101;
	au8DataIn[11]	= 0b00000001;
	au8DataIn[12]	= 0b00000101;
	au8DataIn[13]	= 0b00001111;
	au8DataIn[14]	= 0b10000001;
	au8DataIn[15]	= 0b00000010;

	vp8x16Input		= vld1q_p8(au8DataIn);

	// poly8x8_t vget_high_p8(poly8x16_t a);									// VMOV d0,d0
	// (a >> (8 * 8))
	vp8x8OutputHigh		= vget_high_p8(vp8x16Input);
	vst1_p8(au8DataOutHigh, vp8x8OutputHigh);

	// poly8x8_t vget_low_p8(poly8x16_t a);										// VMOV d0,d0
	// (a & 0xFFFFFFFFFFFFFFFF)
	vp8x8OutputLow		= vget_low_p8(vp8x16Input);
	vst1_p8(au8DataOutLow, vp8x8OutputLow);

	printf("== Split p8 = p8 (vget_high_p8 / vget_low_p8) ==\n");
	printf("=> vget_high_p8 : p8 = high(p8)               ==\n");
	printf("=> vget_low_p8  : p8 = low(p8)                ==\n");

	printf("Input       : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(au8DataIn[u32Idx]));
	}
	printf("\n");

	printf("              ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(au8DataIn[u32Idx + 8]));
	}
	printf("\n");

	printf("Output Low  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(au8DataOutLow[u32Idx]));
	}
	printf("\n");

	printf("Output High : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(au8DataOutHigh[u32Idx]));
	}
	printf("\n");

	printf("========================================\n");
}

// -----------------------------------------------------------------------------
