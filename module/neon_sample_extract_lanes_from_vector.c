#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-extracting-lanes-from-a-vector-into-a-register

// -----------------------------------------------------------------------------
void NeonSample_ExtractLanes_U8_U8_SU8()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8Input;

	uint8_t		u8CoefLaneIndex;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 20;
	au8DataIn[1] = 40;
	au8DataIn[2] = 60;
	au8DataIn[3] = 80;
	au8DataIn[4] = 100;
	au8DataIn[5] = 120;
	au8DataIn[6] = 140;
	au8DataIn[7] = 160;

	vu8x8Input		= vld1_u8(au8DataIn);

	// uint8_t vget_lane_u8(uint8x8_t vec, __constrange(0,7) int lane);			// VMOV.U8 r0, d0[0]
	for (u8CoefLaneIndex = 0; u8CoefLaneIndex < 8; ++u8CoefLaneIndex)
	{
		au8DataOut[u8CoefLaneIndex] = vget_lane_u8(vu8x8Input, u8CoefLaneIndex);
	}

	printf("== Extract Lanes u8 = u8, su8 (vget_lane_u8) ==\n");
	printf("Input : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%1d -> %3d\n",
			u32Idx,
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ExtractLanes_S8_S8_SU8()
{
	int8_t		as8DataIn[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8Input;

	uint8_t		u8CoefLaneIndex;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = 20;
	as8DataIn[1] = 40;
	as8DataIn[2] = 60;
	as8DataIn[3] = 80;
	as8DataIn[4] = -80;
	as8DataIn[5] = -60;
	as8DataIn[6] = -40;
	as8DataIn[7] = -20;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int8_t vget_lane_s8(int8x8_t vec, __constrange(0,7) int lane);			// VMOV.S8 r0, d0[0]
	for (u8CoefLaneIndex = 0; u8CoefLaneIndex < 8; ++u8CoefLaneIndex)
	{
		as8DataOut[u8CoefLaneIndex] = vget_lane_s8(vs8x8Input, u8CoefLaneIndex);
	}

	printf("== Extract Lanes s8 = s8, su8 (vget_lane_s8) ==\n");
	printf("Input : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", as8DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%1d -> %3d\n",
			u32Idx,
			as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ExtractLanes_F32_F32_SU8()
{
	float			af32DataIn[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2Input;

	uint8_t			u8CoefLaneIndex;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = 101.101;

	vf32x2Input		= vld1_f32(af32DataIn);

	// float32_t vget_lane_f32(float32x2_t vec, __constrange(0,1) int lane);	// VMOV.32 r0, d0[0]
	for (u8CoefLaneIndex = 0; u8CoefLaneIndex < 2; ++u8CoefLaneIndex)
	{
		af32DataOut[u8CoefLaneIndex] = vget_lane_f32(vf32x2Input, u8CoefLaneIndex);
	}

	printf("== Extract Lanes f32 = f32, su8 (vget_lane_f32) ==\n");
	printf("Input : ");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%1d -> %9.4f\n",
			u32Idx,
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ExtractLanes_P8_P8_SU8()
{
	uint8_t		au8DataIn[8];
	poly8_t		ap8DataOut[8];

	poly8x8_t	vp8x8Input;

	uint8_t		u8CoefLaneIndex;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0]	= 0b00000001;
	au8DataIn[1]	= 0b00000010;
	au8DataIn[2]	= 0b00000101;
	au8DataIn[3]	= 0b00001010;
	au8DataIn[4]	= 0b00010101;
	au8DataIn[5]	= 0b00101010;
	au8DataIn[6]	= 0b01010101;
	au8DataIn[7]	= 0b10101010;

	vp8x8Input		= vld1_p8(au8DataIn);

	// poly8_t vget_lane_p8(poly8x8_t vec, __constrange(0,7) int lane);			// VMOV.U8 r0, d0[0]
	for (u8CoefLaneIndex = 0; u8CoefLaneIndex < 8; ++u8CoefLaneIndex)
	{
		ap8DataOut[u8CoefLaneIndex] = vget_lane_p8(vp8x8Input, u8CoefLaneIndex);
	}

	printf("== Extract Lanes p8 = p8 (vget_lane_p8) ==\n");
	printf("Input : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(au8DataIn[u32Idx]));
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%1d -> "UINT8_TO_BIT_PATTERN"\n",
			u32Idx,
			UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
