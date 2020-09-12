#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-loading-a-single-vector-or-lane
// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-storing-a-single-vector-or-lane

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_U8_PU8()
{
	uint8_t			au8DataIn[8];
	uint8_t			au8DataOut[8];

	uint8x8_t		vu8x8Data;

	uint32_t		u32Idx;

	// initial
	au8DataIn[0] = 1;
	au8DataIn[1] = 2;
	au8DataIn[2] = 3;
	au8DataIn[3] = 4;
	au8DataIn[4] = 5;
	au8DataIn[5] = 6;
	au8DataIn[6] = 7;
	au8DataIn[7] = 8;

	// uint8x8_t vld1_u8(__transfersize(8) uint8_t const * ptr);				// VLD1.8 {d0}, [r0]
	vu8x8Data		= vld1_u8(au8DataIn);

	// void vst1_u8(__transfersize(8) uint8_t * ptr, uint8x8_t val);			// VST1.8 {d0}, [r0]
	vst1_u8(au8DataOut, vu8x8Data);

	printf("== Load/Store Vector u8 = pu8 (vld1_u8/vst1_u8) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_S8_PS8()
{
	int8_t			as8DataIn[8];
	int8_t			as8DataOut[8];

	int8x8_t		vs8x8Data;

	uint32_t		u32Idx;

	// initial
	as8DataIn[0] = 1;
	as8DataIn[1] = 2;
	as8DataIn[2] = 3;
	as8DataIn[3] = 4;
	as8DataIn[4] = -5;
	as8DataIn[5] = -6;
	as8DataIn[6] = -7;
	as8DataIn[7] = -8;

	// int8x8_t vld1_s8(__transfersize(8) int8_t const * ptr);					// VLD1.8 {d0}, [r0]
	vs8x8Data		= vld1_s8(as8DataIn);

	// void vst1_s8(__transfersize(8) int8_t * ptr, int8x8_t val);				// VST1.8 {d0}, [r0]
	vst1_s8(as8DataOut, vs8x8Data);

	printf("== Load/Store Vector s8 = ps8 (vld1_s8/vst1_s8) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_F32_PF32()
{
	float			af32DataIn[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2Data;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = -100.001;

	// float32x2_t vld1_f32(__transfersize(2) float32_t const * ptr);			// VLD1.32 {d0}, [r0]
	vf32x2Data		= vld1_f32(af32DataIn);

	// void vst1_f32(__transfersize(2) float32_t * ptr, float32x2_t val);		// VST1.32 {d0}, [r0]
	vst1_f32(af32DataOut, vf32x2Data);

	printf("== Load/Store Vector f32 = pf32 (vld1_f32/vst1_f32) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataIn[u32Idx]);
	}
	printf("\n");
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_P8_PP8()
{
	poly8_t			ap8DataIn[8];
	poly8_t			ap8DataOut[8];

	poly8x8_t		vp8x8Data;

	uint32_t		u32Idx;

	// initial
	ap8DataIn[0] = 0b00000001;
	ap8DataIn[1] = 0b00000011;
	ap8DataIn[2] = 0b00000111;
	ap8DataIn[3] = 0b00001111;
	ap8DataIn[4] = 0b00011111;
	ap8DataIn[5] = 0b00111111;
	ap8DataIn[6] = 0b01111111;
	ap8DataIn[7] = 0b11111111;

	// poly8x8_t vld1_p8(__transfersize(8) poly8_t const * ptr);				// VLD1.8 {d0}, [r0]
	vp8x8Data		= vld1_p8(ap8DataIn);

	// void vst1_p8(__transfersize(8) poly8_t * ptr, poly8x8_t val);			// VST1.8 {d0}, [r0]
	vst1_p8(ap8DataOut, vp8x8Data);

	printf("== Load/Store Vector p8 = pp8 (vld1_p8/vst1_p8) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, UINT8_TO_BIT(ap8DataIn[u32Idx]));
	}
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_U8_PU8_U8_SU8()
{
	uint8_t			au8DataInBuf[1];
	uint8_t			au8DataIn[8];
	uint8_t			au8DataOut[8];
	uint8_t			au8DataOutBuf[1];

	uint8_t			u8CoefIndex;

	uint8x8_t		vu8x8Input;
	uint8x8_t		vu8x8Output;

	uint32_t		u32Idx;

	// initial
	au8DataIn[0] = 1;
	au8DataIn[1] = 2;
	au8DataIn[2] = 3;
	au8DataIn[3] = 4;
	au8DataIn[4] = 5;
	au8DataIn[5] = 6;
	au8DataIn[6] = 7;
	au8DataIn[7] = 8;

	au8DataInBuf[0] = 100;

	u8CoefIndex		= 5;

	vu8x8Input		= vld1_u8(au8DataIn);

	// uint8x8_t vld1_lane_u8(__transfersize(1) uint8_t const * ptr, uint8x8_t vec, __constrange(0,7) int lane);	// VLD1.8 {d0[0]}, [r0]
	vu8x8Output		= vld1_lane_u8(au8DataInBuf, vu8x8Input, u8CoefIndex);

	vst1_u8(au8DataOut, vu8x8Output);

	// void vst1_lane_u8(__transfersize(1) uint8_t * ptr, uint8x8_t val, __constrange(0,7) int lane);	// VST1.8 {d0[0]}, [r0]
	vst1_lane_u8(au8DataOutBuf, vu8x8Output, u8CoefIndex);

	printf("== Load/Store Vector u8 = pu8, u8, su8 (vld1_lane_u8/vst1_lane_u8) ==\n");
	printf("Load value of %3d to array index %1d\n", au8DataInBuf[0], u8CoefIndex);
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("Dump value of position %1d is %3d\n", u8CoefIndex, au8DataOutBuf[0]);
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_S8_PS8_S8_SU8()
{
	int8_t			as8DataInBuf[1];
	int8_t			as8DataIn[8];
	int8_t			as8DataOut[8];
	int8_t			as8DataOutBuf[1];

	uint8_t			u8CoefIndex;

	int8x8_t		vs8x8Input;
	int8x8_t		vs8x8Output;

	uint32_t		u32Idx;

	// initial
	as8DataIn[0] = 1;
	as8DataIn[1] = 2;
	as8DataIn[2] = 3;
	as8DataIn[3] = 4;
	as8DataIn[4] = -5;
	as8DataIn[5] = -6;
	as8DataIn[6] = -7;
	as8DataIn[7] = -8;

	as8DataInBuf[0] = -100;

	u8CoefIndex		= 2;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int8x8_t vld1_lane_s8(__transfersize(1) int8_t const * ptr, int8x8_t vec, __constrange(0,7) int lane);	// VLD1.8 {d0[0]}, [r0]
	vs8x8Output		= vld1_lane_s8(as8DataInBuf, vs8x8Input, u8CoefIndex);

	vst1_s8(as8DataOut, vs8x8Output);

	// void vst1_lane_s8(__transfersize(1) int8_t * ptr, int8x8_t val, __constrange(0,7) int lane);	// VST1.8 {d0[0]}, [r0]
	vst1_lane_s8(as8DataOutBuf, vs8x8Output, u8CoefIndex);

	printf("== Load/Store Vector s8 = ps8, s8, su8 (vld1_lane_s8/vst1_lane_s8) ==\n");
	printf("Load value of %4d to array index %1d\n", as8DataInBuf[0], u8CoefIndex);
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("Dump value of position %1d is %4d\n", u8CoefIndex, as8DataOutBuf[0]);
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_F32_PF32_F32_SU8()
{
	float			af32DataInBuf[1];
	float			af32DataIn[2];
	float			af32DataOut[2];
	float			af32DataOutBuf[1];

	uint8_t			u8CoefIndex;

	float32x2_t		vf32x2Input;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = -100.001;

	af32DataInBuf[0] = -20.01;

	u8CoefIndex		= 0;

	vf32x2Input		= vld1_f32(af32DataIn);

	// float32x2_t vld1_lane_f32(__transfersize(1) float32_t const * ptr, float32x2_t vec, __constrange(0,1) int lane);	// VLD1.32 {d0[0]}, [r0]
	vf32x2Output	= vld1_lane_f32(af32DataInBuf, vf32x2Input, u8CoefIndex);

	vst1_f32(af32DataOut, vf32x2Output);

	// void vst1_lane_f32(__transfersize(1) float32_t * ptr, float32x2_t val, __constrange(0,1) int lane);	// VST1.32 {d0[0]}, [r0]
	vst1_lane_f32(af32DataOutBuf, vf32x2Output, u8CoefIndex);

	printf("== Load/Store Vector f32 = pf32, f32, su8 (vld1_lane_f32/vst1_lane_f32) ==\n");
	printf("Load value of %9.4f to array index %1d\n", af32DataInBuf[0], u8CoefIndex);
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataIn[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataOut[u32Idx]);
	}
	printf("\n");
	printf("Dump value of position %1d is %9.4f\n", u8CoefIndex, af32DataOutBuf[0]);
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_P8_PP8_P8_SU8()
{
	poly8_t			ap8DataInBuf[1];
	poly8_t			ap8DataIn[8];
	poly8_t			ap8DataOut[8];
	poly8_t			ap8DataOutBuf[1];

	uint8_t			u8CoefIndex;

	poly8x8_t		vp8x8Input;
	poly8x8_t		vp8x8Output;

	uint32_t		u32Idx;

	// initial
	ap8DataIn[0] = 0b00000001;
	ap8DataIn[1] = 0b00000011;
	ap8DataIn[2] = 0b00000111;
	ap8DataIn[3] = 0b00001111;
	ap8DataIn[4] = 0b00011111;
	ap8DataIn[5] = 0b00111111;
	ap8DataIn[6] = 0b01111111;
	ap8DataIn[7] = 0b11111111;

	ap8DataInBuf[0] = 0b10101010;

	u8CoefIndex		= 6;

	vp8x8Input		= vld1_p8(ap8DataIn);

	// poly8x8_t vld1_lane_p8(__transfersize(1) poly8_t const * ptr, poly8x8_t vec, __constrange(0,7) int lane);	// VLD1.8 {d0[0]}, [r0]
	vp8x8Output		= vld1_lane_p8(ap8DataInBuf, vp8x8Input, u8CoefIndex);

	vst1_p8(ap8DataOut, vp8x8Output);

	// void vst1_lane_p8(__transfersize(1) poly8_t * ptr, poly8x8_t val, __constrange(0,7) int lane);	// VST1.8 {d0[0]}, [r0]
	vst1_lane_p8(ap8DataOutBuf, vp8x8Output, u8CoefIndex);

	printf("== Load/Store Vector p8 = pp8, p8, su8 (vld1_lane_p8/vst1_lane_p8) ==\n");
	printf("Load value of "UINT8_TO_BIT_PATTERN" to array index %1d\n",
		UINT8_TO_BIT(ap8DataInBuf[0]), u8CoefIndex);
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(ap8DataIn[u32Idx]));
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("\n");
	printf("Dump value of position %1d is "UINT8_TO_BIT_PATTERN"\n",
		u8CoefIndex, UINT8_TO_BIT(ap8DataOutBuf[0]));
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_U8_PSU8()
{
	uint8_t			au8DataInBuf[1];
	uint8_t			au8DataOut[8];

	uint8x8_t		vu8x8Output;

	uint32_t		u32Idx;

	// initial
	au8DataInBuf[0] = 100;

	// uint8x8_t vld1_dup_u8(__transfersize(1) uint8_t const * ptr);			// VLD1.8 {d0[]}, [r0]
	vu8x8Output		= vld1_dup_u8(au8DataInBuf);

	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Load Vector u8 = pu8 (vld1_dup_u8) ==\n");
	printf("Load ref. value : %3d\n", au8DataInBuf[0]);
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_S8_PSS8()
{
	int8_t			as8DataInBuf[1];
	int8_t			as8DataOut[8];

	int8x8_t		vs8x8Output;

	uint32_t		u32Idx;

	// initial
	as8DataInBuf[0] = -50;

	// int8x8_t vld1_dup_s8(__transfersize(1) int8_t const * ptr);				// VLD1.8 {d0[]}, [r0]
	vs8x8Output		= vld1_dup_s8(as8DataInBuf);

	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Load Vector s8 = ps8 (vld1_dup_s8) ==\n");
	printf("Load ref. value : %4d\n", as8DataInBuf[0]);
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_F32_PSF32()
{
	float			af32DataInBuf[1];
	float			af32DataOut[2];

	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataInBuf[0] = 100.999;

	// float32x2_t vld1_dup_f32(__transfersize(1) float32_t const * ptr);		// VLD1.32 {d0[]}, [r0]
	vf32x2Output		= vld1_dup_f32(af32DataInBuf);

	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Load Vector f32 = pf32 (vld1_dup_f32) ==\n");
	printf("Load ref. value : %9.4f\n", af32DataInBuf[0]);
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f ", af32DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_P8_PSP8()
{
	poly8_t			ap8DataInBuf[1];
	poly8_t			ap8DataOut[8];

	poly8x8_t		vp8x8Output;

	uint32_t		u32Idx;

	// initial
	ap8DataInBuf[0] = 0b01010101;

	// poly8x8_t vld1_dup_p8(__transfersize(1) poly8_t const * ptr);			// VLD1.8 {d0[]}, [r0]
	vp8x8Output		= vld1_dup_p8(ap8DataInBuf);

	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Load Vector u8 = pu8 (vld1_dup_p8) ==\n");
	printf("Load ref. value : "UINT8_TO_BIT_PATTERN"\n", UINT8_TO_BIT(ap8DataInBuf[0]));
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" ", UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
