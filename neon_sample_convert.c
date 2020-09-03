#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-converting-vectors

// -----------------------------------------------------------------------------
void NeonSample_Convert_U32_F32()
{
	float			af32DataIn[2];
	uint32_t		au32DataOut[2];

	float32x2_t		vf32x2Input;
	uint32x2_t		vu32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = -150.01;

	vf32x2Input		= vld1_f32(af32DataIn);

	// uint32x2_t vcvt_u32_f32(float32x2_t a);									// VCVT.U32.F32 d0, d0
	vu32x2Output	= vcvt_u32_f32(vf32x2Input);
	vst1_u32(au32DataOut, vu32x2Output);

	printf("== Convert u32 = f32 (vcvt_u32_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("UINT(%9.4f) => %10d\n",
			af32DataIn[u32Idx],
			au32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_S32_F32()
{
	float			af32DataIn[2];
	int32_t			as32DataOut[2];

	float32x2_t		vf32x2Input;
	int32x2_t		vs32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = -150.01;

	vf32x2Input		= vld1_f32(af32DataIn);

	// int32x2_t vcvt_s32_f32(float32x2_t a);									// VCVT.S32.F32 d0, d0
	vs32x2Output	= vcvt_s32_f32(vf32x2Input);
	vst1_s32(as32DataOut, vs32x2Output);

	printf("== Convert s32 = f32 (vcvt_s32_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("INT(%9.4f) => %11d\n",
			af32DataIn[u32Idx],
			as32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_U32_F32_SU8()
{
	float			af32DataIn[2];
	uint32_t		au32DataOut[2];

	float32x2_t		vf32x2Input;
	uint32x2_t		vu32x2Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 15.1;
	af32DataIn[1] = -15.1;

	u8CoefIndex		= 4;

	vf32x2Input		= vld1_f32(af32DataIn);

	// uint32x2_t vcvt_n_u32_f32(float32x2_t a, __constrange(1,32) int b);		// VCVT.U32.F32 d0, d0, #32
	vu32x2Output	= vcvt_n_u32_f32(vf32x2Input, u8CoefIndex);
	vst1_u32(au32DataOut, vu32x2Output);

	printf("== Convert u32 = uint32_t(f32 * (1 << su8)) (vcvt_n_u32_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("UINT(%9.4f * (1 << %2d)) => %10d\n",
			af32DataIn[u32Idx], u8CoefIndex,
			au32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_S32_F32_SU8()
{
	float			af32DataIn[2];
	int32_t			as32DataOut[2];

	float32x2_t		vf32x2Input;
	int32x2_t		vs32x2Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = -150.01;

	u8CoefIndex		= 4;

	vf32x2Input		= vld1_f32(af32DataIn);

	// int32x2_t vcvt_n_s32_f32(float32x2_t a, __constrange(1,32) int b);		// VCVT.S32.F32 d0, d0, #32
	vs32x2Output	= vcvt_n_s32_f32(vf32x2Input, u8CoefIndex);
	vst1_s32(as32DataOut, vs32x2Output);

	printf("== Convert s32 = int32_t(f32 * (1 << su8)) (vcvt_n_s32_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("INT(%9.4f * (1 << %2d)) => %11d\n",
			af32DataIn[u32Idx], u8CoefIndex,
			as32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_F32_U32()
{
	uint32_t		au32DataIn[2];
	float			af32DataOut[2];

	uint32x2_t		vu32x2Input;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	au32DataIn[0] = 100;
	au32DataIn[1] = 10000;

	vu32x2Input		= vld1_u32(au32DataIn);

	// float32x2_t vcvt_f32_u32(uint32x2_t a);									// VCVT.F32.U32 d0, d0
	vf32x2Output	= vcvt_f32_u32(vu32x2Input);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Convert f32 = u32 (vcvt_f32_u32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("float(%10d) => %9.4f\n",
			au32DataIn[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_F32_S32()
{
	int32_t			as32DataIn[2];
	float			af32DataOut[2];

	int32x2_t		vs32x2Input;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	as32DataIn[0] = -100;
	as32DataIn[1] = -10000;

	vs32x2Input		= vld1_s32(as32DataIn);

	// float32x2_t vcvt_f32_s32(int32x2_t a);									// VCVT.F32.S32 d0, d0
	vf32x2Output	= vcvt_f32_s32(vs32x2Input);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Convert f32 = s32 (vcvt_f32_s32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("float(%11d) => %9.4f\n",
			as32DataIn[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_F32_U32_SU8()
{
	uint32_t		au32DataIn[2];
	float			af32DataOut[2];

	uint32x2_t		vu32x2Input;
	float32x2_t		vf32x2Output;

	uint8_t			u8CoefValue;

	uint32_t		u32Idx;

	// initial
	au32DataIn[0] = 100;
	au32DataIn[1] = 10000;

	u8CoefValue		= 4;

	vu32x2Input		= vld1_u32(au32DataIn);

	// float32x2_t vcvt_n_f32_u32(uint32x2_t a, __constrange(1,32) int b);		// VCVT.F32.U32 d0, d0, #32
	vf32x2Output	= vcvt_n_f32_u32(vu32x2Input, u8CoefValue);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Convert f32 = float(u32) / (1 << su8) (vcvt_n_f32_u32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("float(%10d) / (1 << %2d) => %9.4f\n",
			au32DataIn[u32Idx], u8CoefValue,
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_F32_S32_SU8()
{
	int32_t			as32DataIn[2];
	float			af32DataOut[2];

	int32x2_t		vs32x2Input;
	float32x2_t		vf32x2Output;

	uint8_t			u8CoefValue;

	uint32_t		u32Idx;

	// initial
	as32DataIn[0] = -100;
	as32DataIn[1] = -10000;

	u8CoefValue		= 4;

	vs32x2Input		= vld1_s32(as32DataIn);

	// float32x2_t vcvt_n_f32_s32(int32x2_t a, __constrange(1,32) int b);		// VCVT.F32.S32 d0, d0, #32
	vf32x2Output	= vcvt_n_f32_s32(vs32x2Input, u8CoefValue);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Convert f32 = float(s32) / (1 << su8) (vcvt_n_f32_s32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("float(%11d) / (1 << %2d) => %9.4f\n",
			as32DataIn[u32Idx], u8CoefValue,
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_U16_U8()
{
	uint8_t			au8DataIn[8];
	uint16_t		au16DataOut[8];

	uint8x8_t		vu8x8Input;
	uint16x8_t		vu16x8Output;

	uint32_t		u32Idx;

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

	// uint16x8_t vmovl_u8(uint8x8_t a);										// VMOVL.U8 q0,d0
	vu16x8Output	= vmovl_u8(vu8x8Input);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Convert u16 = u8 (vmovl_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d => %5d\n",
			au8DataIn[u32Idx],
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_S16_S8()
{
	int8_t			as8DataIn[8];
	int16_t			as16DataOut[8];

	int8x8_t		vs8x8Input;
	int16x8_t		vs16x8Output;

	uint32_t		u32Idx;

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

	// int16x8_t vmovl_s8(int8x8_t a);											// VMOVL.S8 q0,d0
	vs16x8Output	= vmovl_s8(vs8x8Input);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Convert s16 = s8 (vmovl_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d => %6d\n",
			as8DataIn[u32Idx],
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_F16_F32()
{
	// float16x4_t vcvt_f16_f32(float32x4_t a);                 // VCVT.F16.F32 d0, q0
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_F32_F16()
{
	// float32x4_t vcvt_f32_f16(float16x4_t a);                 // VCVT.F32.F16 q0, d0
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_U8_S16()
{
	int16_t			as16DataIn[8];
	uint8_t			au8DataOut[8];

	int16x8_t		vs16x8Input;
	uint8x8_t		vu8x8Output;

	uint32_t		u32Idx;

	// initial
	as16DataIn[0] = 64;
	as16DataIn[1] = 128;
	as16DataIn[2] = 255;
	as16DataIn[3] = 512;
	as16DataIn[4] = -64;
	as16DataIn[5] = -128;
	as16DataIn[6] = -255;
	as16DataIn[7] = -512;

	vs16x8Input		= vld1q_s16(as16DataIn);

	// uint8x8_t vqmovun_s16(int16x8_t a);										// VQMOVUN.S16 d0,q0
	vu8x8Output		= vqmovun_s16(vs16x8Input);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Convert u8 = SATURATE(NARROW(s16)) (vqmovun_s16) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d ("UINT16_TO_BIT_PATTERN") => %3d ("UINT8_TO_BIT_PATTERN")\n",
			as16DataIn[u32Idx], UINT16_TO_BIT(as16DataIn[u32Idx]),
			au8DataOut[u32Idx], UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_U8_U16()
{
	uint16_t		au16DataIn[8];
	uint8_t			au8DataOutNarrow[8];
	uint8_t			au8DataOutSaturateNarrow[8];

	uint16x8_t		vu16x8Input;
	uint8x8_t		vu8x8Output;

	uint32_t		u32Idx;

	// initial
	au16DataIn[0] = 32;
	au16DataIn[1] = 64;
	au16DataIn[2] = 128;
	au16DataIn[3] = 255;
	au16DataIn[4] = 256;
	au16DataIn[5] = 513;
	au16DataIn[6] = 1026;
	au16DataIn[7] = 36864;

	vu16x8Input		= vld1q_u16(au16DataIn);

	// uint8x8_t vmovn_u16(uint16x8_t a);										// VMOVN.I16 d0,q0
	vu8x8Output		= vmovn_u16(vu16x8Input);
	vst1_u8(au8DataOutNarrow, vu8x8Output);

	// uint8x8_t vqmovn_u16(uint16x8_t a); 										// VQMOVN.U16 d0,q0
	vu8x8Output		= vqmovn_u16(vu16x8Input);
	vst1_u8(au8DataOutSaturateNarrow, vu8x8Output);

	printf("== Convert u8 = u16 (vmovn_u16, vqmovn_u16) ==\n");
	printf("=> vmovn_u16  : u8 = NARROW(u16)            ==\n");
	printf("=> vqmovn_u16 : u8 = SATURATE(NARROW(u16))  ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d ("UINT16_TO_BIT_PATTERN") => %3d ("UINT8_TO_BIT_PATTERN"), %3d ("UINT8_TO_BIT_PATTERN")\n",
			au16DataIn[u32Idx], UINT16_TO_BIT(au16DataIn[u32Idx]),
			au8DataOutNarrow[u32Idx], UINT8_TO_BIT(au8DataOutNarrow[u32Idx]),
			au8DataOutSaturateNarrow[u32Idx], UINT8_TO_BIT(au8DataOutSaturateNarrow[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Convert_S8_S16()
{
	int16_t			as16DataIn[8];
	int8_t			as8DataOutNarrow[8];
	int8_t			as8DataOutSaturateNarrow[8];

	int16x8_t		vs16x8Input;
	int8x8_t		vs8x8Output;

	uint32_t		u32Idx;

	// initial
	as16DataIn[0] = -512;
	as16DataIn[1] = -255;
	as16DataIn[2] = -128;
	as16DataIn[3] = -64;
	as16DataIn[4] = 128;
	as16DataIn[5] = 255;
	as16DataIn[6] = 256;
	as16DataIn[7] = 1024;

	vs16x8Input		= vld1q_s16(as16DataIn);

	// int8x8_t vmovn_s16(int16x8_t a);											// VMOVN.I16 d0,q0
	vs8x8Output		= vmovn_s16(vs16x8Input);
	vst1_s8(as8DataOutNarrow, vs8x8Output);

	// int8x8_t vqmovn_s16(int16x8_t a);										// VQMOVN.S16 d0,q0
	vs8x8Output		= vqmovn_s16(vs16x8Input);
	vst1_s8(as8DataOutSaturateNarrow, vs8x8Output);

	printf("== Convert s8 = s16 (vmovn_s16, vqmovn_s16) ==\n");
	printf("=> vmovn_s16  : s8 = NARROW(s16)            ==\n");
	printf("=> vqmovn_s16 : s8 = SATURATE(NARROW(s16))  ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d ("UINT16_TO_BIT_PATTERN") => %4d ("UINT8_TO_BIT_PATTERN"), %4d ("UINT8_TO_BIT_PATTERN")\n",
			as16DataIn[u32Idx], UINT16_TO_BIT(as16DataIn[u32Idx]),
			as8DataOutNarrow[u32Idx], UINT8_TO_BIT(as8DataOutNarrow[u32Idx]),
			as8DataOutSaturateNarrow[u32Idx], UINT8_TO_BIT(as8DataOutSaturateNarrow[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
