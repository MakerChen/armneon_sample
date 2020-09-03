#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-operations-with-a-scalar-value

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U16_U16_U16_SU16_SU8()
{
	uint16_t		au16DataInA[4];
	uint16_t		au16DataInB[4];
	uint16_t		au16DataInV[4];
	uint16_t		au16DataOutAdd[4][4];
	uint16_t		au16DataOutSub[4][4];

	uint16x4_t		vu16x4InputA;
	uint16x4_t		vu16x4InputB;
	uint16x4_t		vu16x4InputV;
	uint16x4_t		vu16x4Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	au16DataInA[0] = 10;		au16DataInB[0] = 1;		au16DataInV[0] = 10;
	au16DataInA[1] = 100;		au16DataInB[1] = 2;		au16DataInV[1] = 20;
	au16DataInA[2] = 1000;		au16DataInB[2] = 3;		au16DataInV[2] = 30;
	au16DataInA[3] = 10000;		au16DataInB[3] = 4;		au16DataInV[3] = 40;

	vu16x4InputA	= vld1_u16(au16DataInA);
	vu16x4InputB	= vld1_u16(au16DataInB);
	vu16x4InputV	= vld1_u16(au16DataInV);

	// uint16x4_t vmla_lane_u16(uint16x4_t a, uint16x4_t b, uint16x4_t v, __constrange(0,3) int l);	// VMLA.I16 d0, d0, d0[0]
	// r = a + (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vu16x4Output	= vmla_lane_u16(vu16x4InputA, vu16x4InputB, vu16x4InputV, u8CoefIndex);
		vst1_u16(au16DataOutAdd[u8CoefIndex], vu16x4Output);
	}

	// uint16x4_t vmls_lane_u16(uint16x4_t a, uint16x4_t b, uint16x4_t v, __constrange(0,3) int l);	// VMLS.I16 d0, d0, d0[0]
	// r = a - (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vu16x4Output	= vmls_lane_u16(vu16x4InputA, vu16x4InputB, vu16x4InputV, u8CoefIndex);
		vst1_u16(au16DataOutSub[u8CoefIndex], vu16x4Output);
	}

	printf("== Scalar Value u16 = u16 +/- (u16 * u16[su8]) (vmla_lane_u16 / vmls_lane_u16) ==\n");
	printf("=> vmla_lane_u16 : u16 = u16 + (u16 * u16[su8])                                ==\n");
	printf("=> vmls_lane_u16 : u16 = u16 - (u16 * u16[su8])                                ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 4; ++u32Idx)
		{
			printf("[%1d] : %5d +/- (%5d * %5d) = %5d, %5d\n",
				u8CoefIndex,
				au16DataInA[u32Idx],
				au16DataInB[u32Idx],
				au16DataInV[u8CoefIndex],
				au16DataOutAdd[u8CoefIndex][u32Idx],
				au16DataOutSub[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S16_S16_S16_SS16_SU8()
{
	int16_t			as16DataInA[4];
	int16_t			as16DataInB[4];
	int16_t			as16DataInV[4];
	int16_t			as16DataOutAdd[4][4];
	int16_t			as16DataOutSub[4][4];

	int16x4_t		vs16x4InputA;
	int16x4_t		vs16x4InputB;
	int16x4_t		vs16x4InputV;
	int16x4_t		vs16x4Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	as16DataInA[0] = 10000;		as16DataInB[0] = 1;		as16DataInV[0] = -10;
	as16DataInA[1] = 10000;		as16DataInB[1] = 2;		as16DataInV[1] = -20;
	as16DataInA[2] = 10000;		as16DataInB[2] = 3;		as16DataInV[2] = -30;
	as16DataInA[3] = 10000;		as16DataInB[3] = 4;		as16DataInV[3] = -40;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);
	vs16x4InputV	= vld1_s16(as16DataInV);

	// int16x4_t vmla_lane_s16(int16x4_t a, int16x4_t b, int16x4_t v, __constrange(0,3) int l);	// VMLA.I16 d0, d0, d0[0]
	// r = a + (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs16x4Output	= vmla_lane_s16(vs16x4InputA, vs16x4InputB, vs16x4InputV, u8CoefIndex);
		vst1_s16(as16DataOutAdd[u8CoefIndex], vs16x4Output);
	}

	// int16x4_t vmls_lane_s16(int16x4_t a, int16x4_t b, int16x4_t v, __constrange(0,3) int l);	// VMLS.I16 d0, d0, d0[0]
	// r = a - (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs16x4Output	= vmls_lane_s16(vs16x4InputA, vs16x4InputB, vs16x4InputV, u8CoefIndex);
		vst1_s16(as16DataOutSub[u8CoefIndex], vs16x4Output);
	}

	printf("== Scalar Value s16 = s16 +/- (s16 * s16[su8]) (vmla_lane_s16 / vmls_lane_s16) ==\n");
	printf("=> vmla_lane_s16 : s16 = s16 + (s16 * s16[su8])                                ==\n");
	printf("=> vmls_lane_s16 : s16 = s16 - (s16 * s16[su8])                                ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 4; ++u32Idx)
		{
			printf("[%1d] %6d +/- (%6d * %6d) = %6d, %6d\n",
				u8CoefIndex,
				as16DataInA[u32Idx],
				as16DataInB[u32Idx],
				as16DataInV[u8CoefIndex],
				as16DataOutAdd[u8CoefIndex][u32Idx],
				as16DataOutSub[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_F32_F32_F32_F32_SU8()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataInV[2];
	float			af32DataOutAdd[2][2];
	float			af32DataOutSub[2][2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2InputV;
	float32x2_t		vf32x2Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 30.1;		af32DataInB[0] = 0.001;		af32DataInV[0] = 10;
	af32DataInA[1] = 50.1;		af32DataInB[1] = 0.002;		af32DataInV[1] = 20;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);
	vf32x2InputV	= vld1_f32(af32DataInV);

	// float32x2_t vmla_lane_f32(float32x2_t a, float32x2_t b, float32x2_t v, __constrange(0,1) int l);	// VMLA.F32 d0, d0, d0[0]
	// r = a + (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 2; ++u8CoefIndex)
	{
		vf32x2Output	= vmla_lane_f32(vf32x2InputA, vf32x2InputB, vf32x2InputV, u8CoefIndex);
		vst1_f32(af32DataOutAdd[u8CoefIndex], vf32x2Output);
	}

	// float32x2_t vmls_lane_f32(float32x2_t a, float32x2_t b, float32x2_t v, __constrange(0,1) int l);	// VMLS.F32 d0, d0, d0[0]
	// r = a - (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 2; ++u8CoefIndex)
	{
		vf32x2Output	= vmls_lane_f32(vf32x2InputA, vf32x2InputB, vf32x2InputV, u8CoefIndex);
		vst1_f32(af32DataOutSub[u8CoefIndex], vf32x2Output);
	}

	printf("== Scalar Value f32 = f32 +/- (f32 * f32[su8]) (vmla_lane_f32 / vmls_lane_f32) ==\n");
	printf("=> vmla_lane_f32 : f32 = f32 + (f32 * f32[su8])                                ==\n");
	printf("=> vmls_lane_f32 : f32 = f32 - (f32 * f32[su8])                                ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 2; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 2; ++u32Idx)
		{
			printf("[%1d] %9.4f +/- (%9.4f * %9.4f) = %9.4f, %9.4f\n",
				u8CoefIndex,
				af32DataInA[u32Idx],
				af32DataInB[u32Idx],
				af32DataInV[u8CoefIndex],
				af32DataOutAdd[u8CoefIndex][u32Idx],
				af32DataOutSub[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U32_U32_U16_U16_SU8()
{
	uint32_t		au32DataInA[4];
	uint16_t		au16DataInB[4];
	uint16_t		au16DataInV[4];
	uint32_t		au32DataOutAdd[4][4];
	uint32_t		au32DataOutSub[4][4];

	uint32x4_t		vu32x4InputA;
	uint16x4_t		vu16x4InputB;
	uint16x4_t		vu16x4InputV;
	uint32x4_t		vu32x4Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	au32DataInA[0] = 70000;		au16DataInB[0] = 1;		au16DataInV[0] = 10;
	au32DataInA[1] = 80000;		au16DataInB[1] = 2;		au16DataInV[1] = 20;
	au32DataInA[2] = 90000;		au16DataInB[2] = 3;		au16DataInV[2] = 30;
	au32DataInA[3] = 100000;	au16DataInB[3] = 4;		au16DataInV[3] = 40;

	vu32x4InputA	= vld1q_u32(au32DataInA);
	vu16x4InputB	= vld1_u16(au16DataInB);
	vu16x4InputV	= vld1_u16(au16DataInV);

	// uint32x4_t vmlal_lane_u16(uint32x4_t a, uint16x4_t b, uint16x4_t v, __constrange(0,3) int l);	// VMLAL.U16 q0, d0, d0[0]
	// r = a + (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vu32x4Output	= vmlal_lane_u16(vu32x4InputA, vu16x4InputB, vu16x4InputV, u8CoefIndex);
		vst1q_u32(au32DataOutAdd[u8CoefIndex], vu32x4Output);
	}

	// uint32x4_t vmlsl_lane_u16(uint32x4_t a, uint16x4_t b, uint16x4_t v, __constrange(0,3) int l);	// VMLSL.U16 q0, d0, d0[0]
	// r = a - (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vu32x4Output	= vmlsl_lane_u16(vu32x4InputA, vu16x4InputB, vu16x4InputV, u8CoefIndex);
		vst1q_u32(au32DataOutSub[u8CoefIndex], vu32x4Output);
	}

	printf("== Scalar Value u32 = u32 +/- (u16 * u16[su8]) (vmlal_lane_u16 / vmlsl_lane_u16) ==\n");
	printf("=> vmlal_lane_u16 : u32 = u32 + (u16 * u16[su8])                                 ==\n");
	printf("=> vmlsl_lane_u16 : u32 = u32 - (u16 * u16[su8])                                 ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 4; ++u32Idx)
		{
			printf("[%1d] %10d +/- (%5d * %5d) = %10d, %10d\n",
				u8CoefIndex,
				au32DataInA[u32Idx],
				au16DataInB[u32Idx],
				au16DataInV[u8CoefIndex],
				au32DataOutAdd[u8CoefIndex][u32Idx],
				au32DataOutSub[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S32_S32_S16_S16_SU8()
{
	int32_t			as32DataInA[4];
	int16_t			as16DataInB[4];
	int16_t			as16DataInV[4];
	int32_t			as32DataOutAdd[4][4];
	int32_t			as32DataOutAddSaturate[4][4];
	int32_t			as32DataOutSub[4][4];
	int32_t			as32DataOutSubSaturate[4][4];

	int32x4_t		vs32x4InputA;
	int16x4_t		vs16x4InputB;
	int16x4_t		vs16x4InputV;
	int32x4_t		vs32x4Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	as32DataInA[0] = 80000;			as16DataInB[0] = 10;	as16DataInV[0] = -10;
	as32DataInA[1] = -80000;		as16DataInB[1] = 20;	as16DataInV[1] = -20;
	as32DataInA[2] = 1000000000;	as16DataInB[2] = 30000;	as16DataInV[2] = 30000;
	as32DataInA[3] = -1000000000;	as16DataInB[3] = 30000;	as16DataInV[3] = -30000;

	vs32x4InputA	= vld1q_s32(as32DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);
	vs16x4InputV	= vld1_s16(as16DataInV);

	// int32x4_t vmlal_lane_s16(int32x4_t a, int16x4_t b, int16x4_t v, __constrange(0,3) int l);	//VMLAL.S16 q0, d0, d0[0]
	// r = a + (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs32x4Output	= vmlal_lane_s16(vs32x4InputA, vs16x4InputB, vs16x4InputV, u8CoefIndex);
		vst1q_s32(as32DataOutAdd[u8CoefIndex], vs32x4Output);
	}

	// int32x4_t vqdmlal_lane_s16(int32x4_t a, int16x4_t b, int16x4_t v, __constrange(0,3) int l);	// VQDMLAL.S16 q0, d0, d0[0]
	// r = SATURATE(a + (2 * b * v[l]))
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs32x4Output	= vqdmlal_lane_s16(vs32x4InputA, vs16x4InputB, vs16x4InputV, u8CoefIndex);
		vst1q_s32(as32DataOutAddSaturate[u8CoefIndex], vs32x4Output);
	}

	// int32x4_t vmlsl_lane_s16(int32x4_t a, int16x4_t b, int16x4_t v, __constrange(0,3) int l);	// VMLSL.S16 q0, d0, d0[0]
	// r = a - (b * v[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs32x4Output	= vmlsl_lane_s16(vs32x4InputA, vs16x4InputB, vs16x4InputV, u8CoefIndex);
		vst1q_s32(as32DataOutSub[u8CoefIndex], vs32x4Output);
	}

	// int32x4_t vqdmlsl_lane_s16(int32x4_t a, int16x4_t b, int16x4_t v, __constrange(0,3) int l);	// VQDMLSL.S16 q0, d0, d0[0]
	// r = SATURATE(a - (2 * b * v[l]))
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs32x4Output	= vqdmlsl_lane_s16(vs32x4InputA, vs16x4InputB, vs16x4InputV, u8CoefIndex);
		vst1q_s32(as32DataOutSubSaturate[u8CoefIndex], vs32x4Output);
	}

	printf("== Scalar Value s32 = s32 +/- (s16 * s16[su8]) (vmlal_lane_s16 / vqdmlal_lane_s16 / vmlsl_lane_s16 / vqdmlsl_lane_s16) ==\n");
	printf("=> vmlal_lane_s16   : s32 = s32 + (s16 * s16[su8])                                                                     ==\n");
	printf("=> vqdmlal_lane_s16 : s32 = SATURATE(s32 + (2 * s16 * s16[su8]))                                                       ==\n");
	printf("=> vmlsl_lane_s16   : s32 = s32 - (s16 * s16[su8])                                                                     ==\n");
	printf("=> vqdmlsl_lane_s16 : s32 = SATURATE(s32 - (2 * s16 * s16[su8]))                                                       ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 4; ++u32Idx)
		{
			printf("[%1d] %11d +/- (%6d * %6d) = %11d, %11d, %11d, %11d\n",
				u8CoefIndex,
				as32DataInA[u32Idx],
				as16DataInB[u32Idx],
				as16DataInV[u8CoefIndex],
				as32DataOutAdd[u8CoefIndex][u32Idx],
				as32DataOutAddSaturate[u8CoefIndex][u32Idx],
				as32DataOutSub[u8CoefIndex][u32Idx],
				as32DataOutSubSaturate[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U16_U16_SU16()
{
	uint16_t		au16DataIn[4];
	uint16_t		au16DataOut[4];

	uint16x4_t		vu16x4InputA;
	uint16x4_t		vu16x4Output;

	uint16_t		u16CoefValue;

	uint32_t		u32Idx;

	// initial
	au16DataIn[0] = 10;
	au16DataIn[1] = 100;
	au16DataIn[2] = 1000;
	au16DataIn[3] = 10000;

	u16CoefValue	= 10;

	vu16x4InputA	= vld1_u16(au16DataIn);

	// uint16x4_t vmul_n_u16(uint16x4_t a, uint16_t b);							// VMUL.I16 d0,d0,d0[0]
	// r = a * b
	vu16x4Output	= vmul_n_u16(vu16x4InputA, u16CoefValue);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Scalar Value u16 = u16 * su16 (vmul_n_u16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d * %5d = %5d\n",
			au16DataIn[u32Idx],
			u16CoefValue,
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S16_S16_SS16()
{
	int16_t			as16DataIn[4];
	int16_t			as16DataOut[4];
	int16_t			as16DataOutSaturateHigh[4];
	int16_t			as16DataOutSaturateRoundHigh[4];

	int16x4_t		vs16x4InputA;
	int16x4_t		vs16x4Output;

	int16_t			s16CoefValue;

	uint32_t		u32Idx;

	// initial
	as16DataIn[0] = 10;
	as16DataIn[1] = 100;
	as16DataIn[2] = 1000;
	as16DataIn[3] = 10000;

	s16CoefValue	= 7;

	vs16x4InputA	= vld1_s16(as16DataIn);

	// int16x4_t vmul_n_s16(int16x4_t a, int16_t b);							// VMUL.I16 d0,d0,d0[0]
	// r = a * b
	vs16x4Output	= vmul_n_s16(vs16x4InputA, s16CoefValue);
	vst1_s16(as16DataOut, vs16x4Output);

	// int16x4_t vqdmulh_n_s16(int16x4_t vec1, int16_t val2);					// VQDMULH.S16 d0,d0,d0[0]
	// r = (SATURATE(2 * a * b)) >> 16
	vs16x4Output	= vqdmulh_n_s16(vs16x4InputA, s16CoefValue);
	vst1_s16(as16DataOutSaturateHigh, vs16x4Output);

	// int16x4_t vqrdmulh_n_s16(int16x4_t vec1, int16_t val2);					// VQRDMULH.S16 d0,d0,d0[0]
	// r = (SATURATE(ROUND(2 * a * b))) >> 16
	vs16x4Output	= vqrdmulh_n_s16(vs16x4InputA, s16CoefValue);
	vst1_s16(as16DataOutSaturateRoundHigh, vs16x4Output);

	printf("== Scalar Value s16 = s16 * ss16 (vmul_n_s16 / vqdmulh_n_s16 / vqrdmulh_n_s16) ==\n");
	printf("=> vmul_n_s16     : s16 = s16 * ss16                                           ==\n");
	printf("=> vqdmulh_n_s16  : s16 = (SATURATE(2 * s16 * ss16)) >> 16                     ==\n");
	printf("=> vqrdmulh_n_s16 : s16 = (SATURATE(ROUND(2 * s16 * ss16))) >> 16              ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d * %5d = %5d, %5d, %5d\n",
			as16DataIn[u32Idx],
			s16CoefValue,
			as16DataOut[u32Idx],
			as16DataOutSaturateHigh[u32Idx],
			as16DataOutSaturateRoundHigh[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_F32_F32_SF32()
{
	float			af32DataIn[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32624Output;

	float32_t		f32CoefValue;

	uint32_t		u32Idx;

	// initial
	af32DataIn[0] = 10.01;
	af32DataIn[1] = 99.0001;

	f32CoefValue	= -10.1;

	vf32x2InputA	= vld1_f32(af32DataIn);

	// float32x2_t vmul_n_f32(float32x2_t a, float32_t b);						// VMUL.F32 d0,d0,d0[0]
	// r = a * b
	vf32624Output	= vmul_n_f32(vf32x2InputA, f32CoefValue);
	vst1_f32(af32DataOut, vf32624Output);

	printf("== Scalar Value f32 = f32 * sf32 (vmul_n_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f * %9.4f = %9.4f\n",
			af32DataIn[u32Idx],
			f32CoefValue,
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U32_U16_SU16()
{
	uint16_t		au16DataIn[4];
	uint32_t		au32DataOut[4];

	uint16x4_t		vu16x4InputA;
	uint32x4_t		vu32x4Output;

	uint16_t		u16CoefValue;

	uint32_t		u32Idx;

	// initial
	au16DataIn[0] = 10;
	au16DataIn[1] = 100;
	au16DataIn[2] = 1000;
	au16DataIn[3] = 10000;

	u16CoefValue	= 10;

	vu16x4InputA	= vld1_u16(au16DataIn);

	// uint32x4_t vmull_n_u16(uint16x4_t vec1, uint16_t val2);					// VMULL.U16 q0,d0,d0[0]
	// r = a * b
	vu32x4Output	= vmull_n_u16(vu16x4InputA, u16CoefValue);
	vst1q_u32(au32DataOut, vu32x4Output);

	printf("== Scalar Value u32 = u16 * su16 (vmull_n_u16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d * %5d = %10d\n",
			au16DataIn[u32Idx],
			u16CoefValue,
			au32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S32_S16_SS16()
{
	int16_t			as16DataIn[4];
	int32_t			as32DataOut[4];
	int32_t			as32DataOutSaturate[4];

	int16x4_t		vs16x4InputA;
	int32x4_t		vs32x4Output;

	int16_t			s16CoefValue;

	uint32_t		u32Idx;

	// initial
	as16DataIn[0] = 10;
	as16DataIn[1] = 100;
	as16DataIn[2] = 1000;
	as16DataIn[3] = 10000;

	s16CoefValue	= -100;

	vs16x4InputA	= vld1_s16(as16DataIn);

	// int32x4_t vmull_n_s16(int16x4_t vec1, int16_t val2);						// VMULL.S16 q0,d0,d0[0]
	// r = a * b
	vs32x4Output	= vmull_n_s16(vs16x4InputA, s16CoefValue);
	vst1q_s32(as32DataOut, vs32x4Output);

	// int32x4_t vqdmull_n_s16(int16x4_t vec1, int16_t val2);					// VQDMULL.S16 q0,d0,d0[0]
	// r = SATURATE(2 * a * b)
	vs32x4Output	= vqdmull_n_s16(vs16x4InputA, s16CoefValue);
	vst1q_s32(as32DataOutSaturate, vs32x4Output);

	printf("== Scalar Value s32 = s16 * ss16 (vmull_n_s16 / vqdmull_n_s16) ==\n");
	printf("=> vmull_n_s16   : s32 = s16 * ss16                            ==\n");
	printf("=> vqdmull_n_s16 : s32 = SATURATE(2 * s16 * ss16)              ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%6d * %6d = %11d, %11d\n",
			as16DataIn[u32Idx],
			s16CoefValue,
			as32DataOut[u32Idx],
			as32DataOutSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U32_U16_U16_SU8()
{
	uint16_t		au16DataInA[4];
	uint16_t		au16DataInB[4];
	uint32_t		au32DataOutLong[4][4];

	uint16x4_t		vu16x4InputA;
	uint16x4_t		vu16x4InputB;
	uint32x4_t		vu32x4Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	au16DataInA[0] = 10;		au16DataInB[0] = 1;
	au16DataInA[1] = 100;		au16DataInB[1] = 2;
	au16DataInA[2] = 1000;		au16DataInB[2] = 3;
	au16DataInA[3] = 10000;		au16DataInB[3] = 4;

	vu16x4InputA	= vld1_u16(au16DataInA);
	vu16x4InputB	= vld1_u16(au16DataInB);

	// uint32x4_t vmull_lane_u16(uint16x4_t vec1, uint16x4_t val2, __constrange(0, 3) int val3);	// VMULL.U16 q0,d0,d0[0]
	// r = a * b[l]
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vu32x4Output	= vmull_lane_u16(vu16x4InputA, vu16x4InputB, u8CoefIndex);
		vst1q_u32(au32DataOutLong[u8CoefIndex], vu32x4Output);
	}

	printf("== Scalar Value u32 = u16 * u16[su8] (vmull_lane_u16) ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 4; ++u32Idx)
		{
			printf("[%1d] %5d * %5d = %10d\n",
				u8CoefIndex,
				au16DataInA[u32Idx],
				au16DataInB[u8CoefIndex],
				au32DataOutLong[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S32_S16_S16_SU8()
{
	int16_t			as16DataInA[4];
	int16_t			as16DataInB[4];
	int32_t			as32DataOutLong[4][4];
	int32_t			as32DataOutLongSaturate[4][4];

	int16x4_t		vs16x4InputA;
	int16x4_t		vs16x4InputB;
	int32x4_t		vs32x4Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	as16DataInA[0] = 20000;		as16DataInB[0] = 10;
	as16DataInA[1] = 10000;		as16DataInB[1] = 50;
	as16DataInA[2] = 20000;		as16DataInB[2] = -10;
	as16DataInA[3] = 10000;		as16DataInB[3] = -50;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int32x4_t vmull_lane_s16(int16x4_t vec1, int16x4_t val2, __constrange(0, 3) int val3);	// VMULL.S16 q0,d0,d0[0]
	// r = a * b[l]
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs32x4Output	= vmull_lane_s16(vs16x4InputA, vs16x4InputB, u8CoefIndex);
		vst1q_s32(as32DataOutLong[u8CoefIndex], vs32x4Output);
	}

	// int32x4_t vqdmull_lane_s16(int16x4_t vec1, int16x4_t val2, __constrange(0, 3) int val3);	// VQDMULL.S16 q0,d0,d0[0]
	// r = SATURATE(2 * a * b[l])
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs32x4Output	= vqdmull_lane_s16(vs16x4InputA, vs16x4InputB, u8CoefIndex);
		vst1q_s32(as32DataOutLongSaturate[u8CoefIndex], vs32x4Output);
	}

	printf("== Scalar Value s32 = s16 * s16[su8] (vmull_lane_s16 / vqdmull_lane_s16) ==\n");
	printf("=> vmull_lane_s16   : s32 = s16 * s16[su8]                               ==\n");
	printf("=> vqdmull_lane_s16 : s32 = SATURATE(2 * s16 * s16[su8])                 ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 4; ++u32Idx)
		{
			printf("[%1d] %6d * %6d = %11d, %11d\n",
				u8CoefIndex,
				as16DataInA[u32Idx],
				as16DataInB[u8CoefIndex],
				as32DataOutLong[u8CoefIndex][u32Idx],
				as32DataOutLongSaturate[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S16_S16_S16_SU8()
{
	int16_t			as16DataInA[4];
	int16_t			as16DataInB[4];
	int16_t			as16DataOutSaturateHigh[4][4];
	int16_t			as16DataOutRoundSaturateHigh[4][4];

	int16x4_t		vs16x4InputA;
	int16x4_t		vs16x4InputB;
	int16x4_t		vs16x4Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	as16DataInA[0] = 32767;		as16DataInB[0] = 10;
	as16DataInA[1] = 30000;		as16DataInB[1] = 10;
	as16DataInA[2] = -30000;	as16DataInB[2] = 10;
	as16DataInA[3] = -32768;	as16DataInB[3] = 10;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int16x4_t vqdmulh_lane_s16(int16x4_t vec1, int16x4_t val2, __constrange(0, 3) int val3);		// VQDMULH.S16 d0,d0,d0[0]
	// r = SATURATE(2 * a * b[l]) >> 16
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs16x4Output	= vqdmulh_lane_s16(vs16x4InputA, vs16x4InputB, u8CoefIndex);
		vst1_s16(as16DataOutSaturateHigh[u8CoefIndex], vs16x4Output);
	}

	// int16x4_t vqrdmulh_lane_s16(int16x4_t vec1, int16x4_t val2, __constrange(0, 3) int val3);	// VQRDMULH.S16 d0,d0,d0[0]
	// r = SATURATE(2 * a * b[l]) >> 16
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		vs16x4Output	= vqrdmulh_lane_s16(vs16x4InputA, vs16x4InputB, u8CoefIndex);
		vst1_s16(as16DataOutRoundSaturateHigh[u8CoefIndex], vs16x4Output);
	}

	printf("== Scalar Value s16 = (2 * s16 * s16[su8]) >> 16 (vqdmulh_lane_s16 / vqrdmulh_lane_s16) ==\n");
	printf("=> vqdmulh_lane_s16  : s16 = SATURATE(2 * s16 * s16[su8]) >> 16                         ==\n");
	printf("=> vqrdmulh_lane_s16 : s16 = ROUND(SATURATE(2 * s16 * s16[su8])) >> 16                  ==\n");
	for (u8CoefIndex = 0; u8CoefIndex < 4; ++u8CoefIndex)
	{
		for (u32Idx = 0; u32Idx < 4; ++u32Idx)
		{
			printf("[%1d] %11d * %11d = %11d, %11d\n",
				u8CoefIndex,
				as16DataInA[u32Idx],
				as16DataInB[u8CoefIndex],
				as16DataOutSaturateHigh[u8CoefIndex][u32Idx],
				as16DataOutRoundSaturateHigh[u8CoefIndex][u32Idx]);
		}
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U16_U16_U16_SU16()
{
	uint16_t		au16DataInA[4];
	uint16_t		au16DataInB[4];
	uint16_t		au16DataOutAdd[4];
	uint16_t		au16DataOutSub[4];

	uint16x4_t		vu16x4InputA;
	uint16x4_t		vu16x4InputB;
	uint16x4_t		vu16x4Output;

	uint16_t		u16CoefValue;

	uint32_t		u32Idx;

	// initial
	au16DataInA[0] = 10;		au16DataInB[0] = 1;
	au16DataInA[1] = 100;		au16DataInB[1] = 2;
	au16DataInA[2] = 1000;		au16DataInB[2] = 4;
	au16DataInA[3] = 10000;		au16DataInB[3] = 8;

	u16CoefValue	= 1024;

	vu16x4InputA	= vld1_u16(au16DataInA);
	vu16x4InputB	= vld1_u16(au16DataInB);

	// uint16x4_t vmla_n_u16(uint16x4_t a, uint16x4_t b, uint16_t c);			// VMLA.I16 d0, d0, d0[0]
	// r = a + (b * c)
	vu16x4Output	= vmla_n_u16(vu16x4InputA, vu16x4InputB, u16CoefValue);
	vst1_u16(au16DataOutAdd, vu16x4Output);

	// uint16x4_t vmls_n_u16(uint16x4_t a, uint16x4_t b, uint16_t c);			// VMLS.I16 d0, d0, d0[0]
	// r = a - (b * c)
	vu16x4Output	= vmls_n_u16(vu16x4InputA, vu16x4InputB, u16CoefValue);
	vst1_u16(au16DataOutSub, vu16x4Output);

	printf("== Scalar Value u16 = u16 +/- (u16 * su16) (vmla_n_u16 / vmls_n_u16) ==\n");
	printf("=> vmla_n_u16 : u16 = u16 + (u16 * su16)                             ==\n");
	printf("=> vmls_n_u16 : u16 = u16 - (u16 * su16)                             ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%10d +/- (%10d * %10d) = %10d, %10d\n",
			au16DataInA[u32Idx],
			au16DataInB[u32Idx],
			u16CoefValue,
			au16DataOutAdd[u32Idx],
			au16DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S16_S16_S16_SS16()
{
	int16_t			as16DataInA[4];
	int16_t			as16DataInB[4];
	int16_t			as16DataOutAdd[4];
	int16_t			as16DataOutSub[4];

	int16x4_t		vs16x4InputA;
	int16x4_t		vs16x4InputB;
	int16x4_t		vs16x4Output;

	int16_t			s16CoefValue;

	uint32_t		u32Idx;

	// initial
	as16DataInA[0] = 10000;		as16DataInB[0] = 1;
	as16DataInA[1] = 10000;		as16DataInB[1] = -2;
	as16DataInA[2] = -10000;	as16DataInB[2] = 3;
	as16DataInA[3] = -10000;	as16DataInB[3] = -4;

	s16CoefValue	= -1024;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int16x4_t vmla_n_s16(int16x4_t a, int16x4_t b, int16_t c);				// VMLA.I16 d0, d0, d0[0]
	// r = a + (b * c)
	vs16x4Output	= vmla_n_s16(vs16x4InputA, vs16x4InputB, s16CoefValue);
	vst1_s16(as16DataOutAdd, vs16x4Output);

	// int16x4_t vmls_n_s16(int16x4_t a, int16x4_t b, int16_t c);				// VMLS.I16 d0, d0, d0[0]
	// r = a - (b * c)
	vs16x4Output	= vmls_n_s16(vs16x4InputA, vs16x4InputB, s16CoefValue);
	vst1_s16(as16DataOutSub, vs16x4Output);

	printf("== Scalar Value s16 = s16 +/- (s16 * ss16) (vmla_n_s16 / vmls_n_s16) ==\n");
	printf("=> vmla_n_s16 : s16 = s16 + (s16 * ss16)                             ==\n");
	printf("=> vmls_n_s16 : s16 = s16 - (s16 * ss16)                             ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%11d +/- (%11d * %11d) = %11d, %11d\n",
			as16DataInA[u32Idx],
			as16DataInB[u32Idx],
			s16CoefValue,
			as16DataOutAdd[u32Idx],
			as16DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_F32_F32_F32_SF32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataOutAdd[2];
	float			af32DataOutSub[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	float			f32Coef;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 30.1;		af32DataInB[0] = 0.001;
	af32DataInA[1] = 50.1;		af32DataInB[1] = 0.002;

	f32Coef			= 1024.0001;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);

	// float32x2_t vmla_n_f32(float32x2_t a, float32x2_t b, float32_t c);		// VMLA.F32 d0, d0, d0[0]
	// r = a + (b * c)
	vf32x2Output	= vmla_n_f32(vf32x2InputA, vf32x2InputB, f32Coef);
	vst1_f32(af32DataOutAdd, vf32x2Output);

	// float32x2_t vmls_n_f32(float32x2_t a, float32x2_t b, float32_t c);		// VMLS.F32 d0, d0, d0[0]
	// r = a - (b * c)
	vf32x2Output	= vmls_n_f32(vf32x2InputA, vf32x2InputB, f32Coef);
	vst1_f32(af32DataOutSub, vf32x2Output);

	printf("== Scalar Value f32 = f32 +/- (f32 * sf32) (vmla_n_f32 / vmls_n_f32) ==\n");
	printf("=> vmla_n_f32 : f32 = f32 + (f32 * sf32)                             ==\n");
	printf("=> vmls_n_f32 : f32 = f32 - (f32 * sf32)                             ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f +/- (%9.4f * %9.4f) = %9.4f, %9.4f\n",
			af32DataInA[u32Idx],
			af32DataInB[u32Idx],
			f32Coef,
			af32DataOutAdd[u32Idx],
			af32DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U32_U32_U16_SU16()
{
	uint32_t		au32DataInA[4];
	uint16_t		au16DataInB[4];
	uint32_t		au32DataOutAdd[4];
	uint32_t		au32DataOutSub[4];

	uint32x4_t		vu32x4InputA;
	uint16x4_t		vu16x4InputB;
	uint32x4_t		vu32x4Output;

	uint16_t		u16CoefValue;

	uint32_t		u32Idx;

	// initial
	au32DataInA[0] = 50000;		au16DataInB[0] = 10000;
	au32DataInA[1] = 100000;	au16DataInB[1] = 10000;
	au32DataInA[2] = 150000;	au16DataInB[2] = 20000;
	au32DataInA[3] = 200000;	au16DataInB[3] = 20000;

	u16CoefValue	= 500;

	vu32x4InputA	= vld1q_u32(au32DataInA);
	vu16x4InputB	= vld1_u16(au16DataInB);

	// uint32x4_t vmlal_n_u16(uint32x4_t a, uint16x4_t b, uint16_t c);			// VMLAL.U16 q0, d0, d0[0]
	// r = a + (b * c)
	vu32x4Output	= vmlal_n_u16(vu32x4InputA, vu16x4InputB, u16CoefValue);
	vst1q_u32(au32DataOutAdd, vu32x4Output);

	// uint32x4_t vmlsl_n_u16(uint32x4_t a, uint16x4_t b, uint16_t c);			// VMLSL.U16 q0, d0, d0[0]
	// r = a - (b * c)
	vu32x4Output	= vmlsl_n_u16(vu32x4InputA, vu16x4InputB, u16CoefValue);
	vst1q_u32(au32DataOutSub, vu32x4Output);

	printf("== Scalar Value u32 = u32 +/- (u16 * su16) (vmlal_n_u16 / vmlsl_n_u16) ==\n");
	printf("=> vmlal_n_u16 : u32 = u32 + (u16 * su16)                              ==\n");
	printf("=> vmlsl_n_u16 : u32 = u32 - (u16 * su16)                              ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%10d +/- (%5d * %5d) = %10d, %10d\n",
			au32DataInA[u32Idx],
			au16DataInB[u32Idx],
			u16CoefValue,
			au32DataOutAdd[u32Idx],
			au32DataOutSub[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_S32_S32_S16_SS16()
{
	int32_t			as32DataInA[4];
	int16_t			as16DataInB[4];
	int32_t			as32DataOutAdd[4];
	int32_t			as32DataOutAddSaturate[4];
	int32_t			as32DataOutSub[4];
	int32_t			as32DataOutSubSaturate[4];

	int32x4_t		vs32x4InputA;
	int16x4_t		vs16x4InputB;
	int32x4_t		vs32x4Output;

	int16_t			s16CoefValue;

	uint32_t		u32Idx;

	// initial
	as32DataInA[0] = 50000;		as16DataInB[0] = -10000;
	as32DataInA[1] = -50000;	as16DataInB[1] = -10000;
	as32DataInA[2] = -100000;	as16DataInB[2] = -20000;
	as32DataInA[3] = -150000;	as16DataInB[3] = -20000;

	s16CoefValue	= 500;

	vs32x4InputA	= vld1q_s32(as32DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int32x4_t vmlal_n_s16(int32x4_t a, int16x4_t b, int16_t c);				// VMLAL.S16 q0, d0, d0[0]
	// r = a + (b * c)
	vs32x4Output	= vmlal_n_s16(vs32x4InputA, vs16x4InputB, s16CoefValue);
	vst1q_s32(as32DataOutAdd, vs32x4Output);

	// int32x4_t vqdmlal_n_s16(int32x4_t a, int16x4_t b, int16_t c);			// VQDMLAL.S16 q0, d0, d0[0]
	// r = SATURATE(a + (b * c))
	vs32x4Output	= vqdmlal_n_s16(vs32x4InputA, vs16x4InputB, s16CoefValue);
	vst1q_s32(as32DataOutAddSaturate, vs32x4Output);

	// int32x4_t vmlsl_n_s16(int32x4_t a, int16x4_t b, int16_t c);				// VMLSL.S16 q0, d0, d0[0]
	// r = a - (b * c)
	vs32x4Output	= vmlsl_n_s16(vs32x4InputA, vs16x4InputB, s16CoefValue);
	vst1q_s32(as32DataOutSub, vs32x4Output);

	// int32x4_t vqdmlsl_n_s16(int32x4_t a, int16x4_t b, int16_t c);			// VQDMLSL.S16 q0, d0, d0[0]
	// r = SATURATE(a - (b * c))
	vs32x4Output	= vqdmlsl_n_s16(vs32x4InputA, vs16x4InputB, s16CoefValue);
	vst1q_s32(as32DataOutSubSaturate, vs32x4Output);

	printf("== Scalar Value s32 = s32 + (s16 * ss16) (vmlal_n_s16 / vqdmlal_n_s16 / vmlsl_n_s16 / vqdmlsl_n_s16) ==\n");
	printf("=> vmlal_n_s16   : s32 = s32 + (s16 * ss16)                                                          ==\n");
	printf("=> vqdmlal_n_s16 : s32 = SATURATE(s32 + (2 * s16 * ss16))                                            ==\n");
	printf("=> vmlsl_n_s16   : s32 = s32 - (s16 * ss16)                                                          ==\n");
	printf("=> vqdmlsl_n_s16 : s32 = SATURATE(s32 - (2 * s16 * ss16))                                            ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%11d +/- (%6d * %6d) = %11d, %11d, %11d, %11d\n",
			as32DataInA[u32Idx],
			as16DataInB[u32Idx],
			s16CoefValue,
			as32DataOutAdd[u32Idx],
			as32DataOutAddSaturate[u32Idx],
			as32DataOutSub[u32Idx],
			as32DataOutSubSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
