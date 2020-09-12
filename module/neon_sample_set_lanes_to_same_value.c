#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-setting-all-lanes-to-the-same-value

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_U8_SU8()
{
	uint8_t		au8DataOutDup[8];
	uint8_t		au8DataOutMov[8];

	uint8x8_t	vu8x8Output;

	uint8_t		u8CoefValue;

	uint32_t	u32Idx;

	// initial
	u8CoefValue = 100;

	// uint8x8_t vdup_n_u8(uint8_t value);										// VDUP.8 d0,r0
	vu8x8Output		= vdup_n_u8(u8CoefValue);
	vst1_u8(au8DataOutDup, vu8x8Output);

	// uint8x8_t vmov_n_u8(uint8_t value);										// VDUP.8 d0,r0
	vu8x8Output		= vdup_n_u8(u8CoefValue);
	vst1_u8(au8DataOutMov, vu8x8Output);

	printf("== Set Lanes With Value u8 = su8 (vdup_n_u8 / vmov_n_u8) ==\n");
	printf("Set Value : %3d\n", u8CoefValue);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d, %3d\n", au8DataOutDup[u32Idx], au8DataOutMov[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_S8_SS8()
{
	int8_t		as8DataOutDup[8];
	int8_t		as8DataOutMov[8];

	int8x8_t	vs8x8Output;

	int8_t		s8CoefValue;

	uint32_t	u32Idx;

	// initial
	s8CoefValue = -50;

	// int8x8_t vdup_n_s8(int8_t value);										// VDUP.8 d0,r0
	vs8x8Output		= vdup_n_s8(s8CoefValue);
	vst1_s8(as8DataOutDup, vs8x8Output);

	// int8x8_t vmov_n_s8(int8_t value);										// VDUP.8 d0,r0
	vs8x8Output		= vmov_n_s8(s8CoefValue);
	vst1_s8(as8DataOutMov, vs8x8Output);

	printf("== Set Lanes With Value s8 = ss8 (vdup_n_s8 / vmov_n_s8) ==\n");
	printf("Set Value : %4d\n", s8CoefValue);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d, %4d\n", as8DataOutDup[u32Idx], as8DataOutMov[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_P8_SP8()
{
	uint8_t		au8DataOutDup[8];
	uint8_t		au8DataOutMov[8];

	poly8x8_t	vp8x8Output;

	poly8_t		p8CoefValue;

	uint32_t	u32Idx;

	// initial
	p8CoefValue = 0b11001100;

	// poly8x8_t vdup_n_p8(poly8_t value);										// VDUP.8 d0,r0
	vp8x8Output		= vdup_n_p8(p8CoefValue);
	vst1_p8(au8DataOutDup, vp8x8Output);

	// poly8x8_t vmov_n_p8(poly8_t value);										// VDUP.8 d0,r0
	vp8x8Output		= vmov_n_p8(p8CoefValue);
	vst1_p8(au8DataOutMov, vp8x8Output);

	printf("== Set Lanes With Value p8 = sp8 (vdup_n_p8 / vmov_n_p8) ==\n");
	printf("Set Value : "UINT8_TO_BIT_PATTERN"\n", UINT8_TO_BIT(p8CoefValue));
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" "UINT8_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(au8DataOutDup[u32Idx]),
			UINT8_TO_BIT(au8DataOutMov[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_F32_SF32()
{
	float		af32DataOutDup[2];
	float		af32DataOutMov[2];

	float32x2_t	vf32x2Output;

	float		f32CoefValue;

	uint32_t	u32Idx;

	// initial
	f32CoefValue = 100.001;

	// float32x2_t vdup_n_f32(float32_t value);									// VDUP.32 d0,r0
	vf32x2Output	= vdup_n_f32(f32CoefValue);
	vst1_f32(af32DataOutDup, vf32x2Output);

	// float32x2_t vmov_n_f32(float32_t value);									// VDUP.32 d0,r0
	vf32x2Output	= vmov_n_f32(f32CoefValue);
	vst1_f32(af32DataOutMov, vf32x2Output);

	printf("== Set Lanes With Value f32 = sf32 (vdup_n_f32 / vmov_n_f32) ==\n");
	printf("Set Value : %9.4f\n", f32CoefValue);
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f, %9.4f\n", af32DataOutDup[u32Idx], af32DataOutMov[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_U8_U8_SU8()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8Input;
	uint8x8_t	vu8x8Output;

	uint8_t		u8CoefIndex;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 10;
	au8DataIn[1] = 20;
	au8DataIn[2] = 30;
	au8DataIn[3] = 40;
	au8DataIn[4] = 50;
	au8DataIn[5] = 60;
	au8DataIn[6] = 70;
	au8DataIn[7] = 80;

	u8CoefIndex = 5;

	vu8x8Input		= vld1_u8(au8DataIn);

	// uint8x8_t vdup_lane_u8(uint8x8_t vec, __constrange(0,7) int lane);		// VDUP.8 d0,d0[0]
	vu8x8Output		= vdup_lane_u8(vu8x8Input, u8CoefIndex);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Set Lanes With Value u8 = u8, su8 (vdup_lane_u8) ==\n");
	printf("Ref Index : %1d\n", u8CoefIndex);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %3d, %3d\n",
			u32Idx,
			au8DataIn[u32Idx], au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_S8_S8_SU8()
{
	int8_t		as8DataIn[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8Input;
	int8x8_t	vs8x8Output;

	uint8_t		u8CoefIndex;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = -80;
	as8DataIn[1] = -40;
	as8DataIn[2] = -20;
	as8DataIn[3] = -10;
	as8DataIn[4] = 10;
	as8DataIn[5] = 20;
	as8DataIn[6] = 40;
	as8DataIn[7] = 80;

	u8CoefIndex = 3;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int8x8_t vdup_lane_s8(int8x8_t vec, __constrange(0,7) int lane);			// VDUP.8 d0,d0[0]
	vs8x8Output		= vdup_lane_s8(vs8x8Input, u8CoefIndex);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Set Lanes With Value s8 = s8, su8 (vdup_lane_s8) ==\n");
	printf("Ref Index : %1d\n", u8CoefIndex);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %4d, %4d\n",
			u32Idx,
			as8DataIn[u32Idx], as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_P8_P8_SU8()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOut[8];

	poly8x8_t	vp8x8Input;
	poly8x8_t	vp8x8Output;

	uint8_t		u8CoefIndex;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 0b10000000;
	au8DataIn[1] = 0b01000000;
	au8DataIn[2] = 0b00100000;
	au8DataIn[3] = 0b00010000;
	au8DataIn[4] = 0b00001000;
	au8DataIn[5] = 0b00000100;
	au8DataIn[6] = 0b00000010;
	au8DataIn[7] = 0b00000001;

	u8CoefIndex = 6;

	vp8x8Input		= vld1_p8(au8DataIn);

	// poly8x8_t vdup_lane_p8(poly8x8_t vec, __constrange(0,7) int lane);		// VDUP.8 d0,d0[0]
	vp8x8Output		= vdup_lane_p8(vp8x8Input, u8CoefIndex);
	vst1_p8(au8DataOut, vp8x8Output);

	printf("== Set Lanes With Value p8 = p8, u8 (vdup_lane_p8) ==\n");
	printf("Ref Index : %1d\n", u8CoefIndex);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			u32Idx,
			UINT8_TO_BIT(au8DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_F32_F32_SU8()
{
	float		af32DataIn[2];
	float		af32DataOut[2];

	float32x2_t	vf32x2Input;
	float32x2_t	vf32x2Output;

	uint8_t		u8CoefIndex;

	uint32_t	u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = 100.001;

	u8CoefIndex = 1;

	vf32x2Input		= vld1_f32(af32DataIn);

	// float32x2_t vdup_lane_f32(float32x2_t vec, __constrange(0,1) int lane);	// VDUP.32 d0,d0[0]
	vf32x2Output	= vdup_lane_f32(vf32x2Input, u8CoefIndex);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Set Lanes With Value f32 = f32, u8 (vdup_lane_f32) ==\n");
	printf("Ref Index : %1d\n", u8CoefIndex);
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("[%1d] : %9.4f, %9.4f\n",
			u32Idx,
			af32DataIn[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
