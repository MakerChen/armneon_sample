#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-other-single-operand-arithmetic

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_S8_S8()
{
	int8_t		as8DataIn[8];
	int8_t		as8DataOutAbs[8];
	int8_t		as8DataOutSaturateAbs[8];
	int8_t		as8DataOutNegative[8];
	int8_t		as8DataOutSaturateNegative[8];

	int8x8_t	vs8x8Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = 120;
	as8DataIn[1] = 90;
	as8DataIn[2] = 60;
	as8DataIn[3] = 30;
	as8DataIn[4] = -30;
	as8DataIn[5] = -60;
	as8DataIn[6] = -90;
	as8DataIn[7] = -128;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int8x8_t vabs_s8(int8x8_t a);											// VABS.S8 d0,d0
	// | a |
	vs8x8Output		= vabs_s8(vs8x8Input);
	vst1_s8(as8DataOutAbs, vs8x8Output);

	// int8x8_t vqabs_s8(int8x8_t a);											// VQABS.S8 d0,d0
	// SATURATE(| a |)
	vs8x8Output		= vqabs_s8(vs8x8Input);
	vst1_s8(as8DataOutSaturateAbs, vs8x8Output);

	// int8x8_t vneg_s8(int8x8_t a);											// VNEG.S8 d0,d0
	// -a
	vs8x8Output		= vneg_s8(vs8x8Input);
	vst1_s8(as8DataOutNegative, vs8x8Output);

	// int8x8_t vqneg_s8(int8x8_t a);											// VQNEG.S8 d0,d0
	// SATURATE(-a)
	vs8x8Output		= vqneg_s8(vs8x8Input);
	vst1_s8(as8DataOutSaturateNegative, vs8x8Output);

	printf("== Single Operand Arithmetic s8 = s8 (vabs_s8 / vqabs_s8 / vneg_s8 / vqneg_s8) ==\n");
	printf("=> vabs_s8  : r = | a |                                                        ==\n");
	printf("=> vqabs_s8 : r = SATURATE(| a |)                                              ==\n");
	printf("=> vneg_s8  : r = -a                                                           ==\n");
	printf("=> vqneg_s8 : r = SATURATE(-a)                                                 ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d => %3d, %3d, %4d, %4d\n",
			as8DataIn[u32Idx],
			as8DataOutAbs[u32Idx],
			as8DataOutSaturateAbs[u32Idx],
			as8DataOutNegative[u32Idx],
			as8DataOutSaturateNegative[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_F32_F32()
{
	float			af32DataIn[2];
	float			af32DataOutAbs[2];
	float			af32DataOutNegative[2];

	float32x2_t		vf32x2Input;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 99.99;
	af32DataIn[1] = -100.001;

	vf32x2Input		= vld1_f32(af32DataIn);

	// float32x2_t vabs_f32(float32x2_t a);										// VABS.F32 d0,d0
	// | a |
	vf32x2Output	= vabs_f32(vf32x2Input);
	vst1_f32(af32DataOutAbs, vf32x2Output);

	// float32x2_t vneg_f32(float32x2_t a);										// VNEG.F32 d0,d0
	// -a
	vf32x2Output	= vneg_f32(vf32x2Input);
	vst1_f32(af32DataOutNegative, vf32x2Output);

	printf("== Single Operand Arithmetic f32 = f32 (vabs_f32 / vneg_f32) ==\n");
	printf("=> vabs_f32 : r = | a |                                      ==\n");
	printf("=> vneg_f32 : r = -a                                         ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f => %9.4f, %9.4f\n",
			af32DataIn[u32Idx],
			af32DataOutAbs[u32Idx],
			af32DataOutNegative[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_U8_U8_v2()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOutLeadZeros[8];
	uint8_t		au8DataOutSetBits[8];

	uint8x8_t	vu8x8Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 0b01111111;
	au8DataIn[1] = 0b11111111;
	au8DataIn[2] = 0b01010101;
	au8DataIn[3] = 0b11010101;
	au8DataIn[4] = 0b00001111;
	au8DataIn[5] = 0b10001111;
	au8DataIn[6] = 0b00111100;
	au8DataIn[7] = 0b10111100;

	vu8x8Input		= vld1_u8(au8DataIn);

	// uint8x8_t vclz_u8(uint8x8_t a);											// VCLZ.I8 d0,d0
	// count leading zeros
	vu8x8Output		= vclz_u8(vu8x8Input);
	vst1_u8(au8DataOutLeadZeros, vu8x8Output);

	// uint8x8_t vcnt_u8(uint8x8_t a);											// VCNT.8 d0,d0
	// count set bits (non-zero)
	vu8x8Output		= vcnt_u8(vu8x8Input);
	vst1_u8(au8DataOutSetBits, vu8x8Output);

	printf("== Single Operand Arithmetic u8 = u8 (vclz_u8 / vcnt_u8) ==\n");
	printf("=> vclz_u8 : leading zeros                               ==\n");
	printf("=> vcnt_u8 : set bits (non-zero)                         ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d, "UINT8_TO_BIT_PATTERN" => %1d, %1d\n",
			au8DataIn[u32Idx], UINT8_TO_BIT(au8DataIn[u32Idx]),
			au8DataOutLeadZeros[u32Idx],
			au8DataOutSetBits[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_S8_S8_v2()
{
	int8_t		as8DataIn[8];
	int8_t		as8DataOutLeadSignBits[8];
	int8_t		as8DataOutLeadZeros[8];
	int8_t		as8DataOutSetBits[8];

	int8x8_t	vs8x8Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = 0b01111111;
	as8DataIn[1] = 0b11111111;
	as8DataIn[2] = 0b01010101;
	as8DataIn[3] = 0b11010101;
	as8DataIn[4] = 0b00001111;
	as8DataIn[5] = 0b10001111;
	as8DataIn[6] = 0b00111100;
	as8DataIn[7] = 0b10111100;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int8x8_t vcls_s8(int8x8_t a);											// VCLS.S8 d0,d0
	// count leading sign bits (consecutive bits)
	vs8x8Output		= vcls_s8(vs8x8Input);
	vst1_s8(as8DataOutLeadSignBits, vs8x8Output);

	// int8x8_t vclz_s8(int8x8_t a);											// VCLZ.I8 d0,d0
	// count leading zeros
	vs8x8Output		= vclz_s8(vs8x8Input);
	vst1_s8(as8DataOutLeadZeros, vs8x8Output);

	// int8x8_t vcnt_s8(int8x8_t a);											// VCNT.8 d0,d0
	// count set bits (non-zero)
	vs8x8Output		= vcnt_s8(vs8x8Input);
	vst1_s8(as8DataOutSetBits, vs8x8Output);

	printf("== Single Operand Arithmetic s8 = s8 (vcls_s8 / vclz_s8 / vcnt_s8) ==\n");
	printf("=> vcls_s8 : leading sign bits (consecutive bits)                  ==\n");
	printf("=> vclz_s8 : leading zeros                                         ==\n");
	printf("=> vcnt_s8 : set bits (non-zero)                                   ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d, "UINT8_TO_BIT_PATTERN" => %1d, %1d, %1d\n",
			as8DataIn[u32Idx], UINT8_TO_BIT(as8DataIn[u32Idx]),
			as8DataOutLeadSignBits[u32Idx],
			as8DataOutLeadZeros[u32Idx],
			as8DataOutSetBits[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_P8_P8_v2()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOutSetBits[8];

	poly8x8_t	vp8x8Input;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 0b01111111;
	au8DataIn[1] = 0b11111111;
	au8DataIn[2] = 0b01010101;
	au8DataIn[3] = 0b11010101;
	au8DataIn[4] = 0b00001111;
	au8DataIn[5] = 0b10001111;
	au8DataIn[6] = 0b00111100;
	au8DataIn[7] = 0b10111100;

	vp8x8Input		= vld1_p8(au8DataIn);

	// poly8x8_t vcnt_p8(poly8x8_t a);											// VCNT.8 d0,d0
	// count set bits (non-zero)
	vp8x8Output		= vcnt_p8(vp8x8Input);
	vst1_p8(au8DataOutSetBits, vp8x8Output);

	printf("== Single Operand Arithmetic p8 = p8 (vcnt_p8) ==\n");
	printf("=> vcnt_p8 : set bits                          ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d, "UINT8_TO_BIT_PATTERN" => %1d\n",
			au8DataIn[u32Idx], UINT8_TO_BIT(au8DataIn[u32Idx]),
			au8DataOutSetBits[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_U32_U32_v3()
{
	uint32_t	au32DataIn[2];
	uint32_t	au32DataOutReciprocal[2];
	uint32_t	au32DataOutReciprocalSquareRoot[2];

	uint32x2_t	vu32x2Input;
	uint32x2_t	vu32x2Output;

	uint32_t	u32Idx;

	// initial
	au32DataIn[0] = 1600;
	au32DataIn[1] = 8100;

	vu32x2Input		= vld1_u32(au32DataIn);

// finds an approximate reciprocal of each element in a vector,
// and places it in the result vector
	// uint32x2_t vrecpe_u32(uint32x2_t a);										// VRECPE.U32 d0,d0
	// Reciprocal estimate
	vu32x2Output	= vrecpe_u32(vu32x2Input);
	vst1_u32(au32DataOutReciprocal, vu32x2Output);

// vrsqrte -> ; finds an approximate reciprocal square root of each element
// in a vector, and places it in the return vector.
	// uint32x2_t vrsqrte_u32(uint32x2_t a);									// VRSQRTE.U32 d0,d0
	// Reciprocal square root estimate
	vu32x2Output	= vrsqrte_u32(vu32x2Input);
	vst1_u32(au32DataOutReciprocalSquareRoot, vu32x2Output);

	printf("== Single Operand Arithmetic u32 = u32 (vrecpe_u32 / vrsqrte_u32) ==\n");
	printf("=> vrecpe_u32  : Reciprocal estimate                              ==\n");
	printf("=> vrsqrte_u32 : Reciprocal square root estimate                  ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%10d => %10d, %10d\n",
			au32DataIn[u32Idx],
			au32DataOutReciprocal[u32Idx],
			au32DataOutReciprocalSquareRoot[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_F32_F32_v3()
{
	float		af32DataIn[2];
	float		af32DataOutReciprocal[2];
	float		af32DataOutReciprocalSquareRoot[2];

	float32x2_t	vf32x2Input;
	float32x2_t	vf32x2Output;

	uint32_t	u32Idx;

	// initial
	af32DataIn[0] = 1600.0;
	af32DataIn[1] = 8100.0;

	vf32x2Input		= vld1_f32(af32DataIn);

	// Reciprocal estimate
	// float32x2_t vrecpe_f32(float32x2_t a);									// VRECPE.F32 d0,d0
	vf32x2Output	= vrecpe_f32(vf32x2Input);
	vst1_f32(af32DataOutReciprocal, vf32x2Output);

	// Reciprocal square root estimate
	// float32x2_t vrsqrte_f32(float32x2_t a);									// VRSQRTE.F32 d0,d0
	vf32x2Output	= vrsqrte_f32(vf32x2Input);
	vst1_f32(af32DataOutReciprocalSquareRoot, vf32x2Output);

	printf("== Single Operand Arithmetic f32 = f32 (vrecpe_f32 / vrsqrte_f32) ==\n");
	printf("=> vrecpe_f32  : 1 / f32                                          ==\n");
	printf("=> vrsqrte_f32 : SQRT(1 / f32)                                    ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f => %12.8f, %12.8f\n",
			af32DataIn[u32Idx],
			af32DataOutReciprocal[u32Idx],
			af32DataOutReciprocalSquareRoot[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
