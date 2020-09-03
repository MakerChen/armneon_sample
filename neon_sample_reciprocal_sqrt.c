#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-reciprocal-and-sqrt

// -----------------------------------------------------------------------------
void NeonSample_Reciprocal_F32_F32_F32()
{
	float			af32DataInA[4];
	float			af32DataInB[4];
	float			af32DataOut2[2];
	float			af32DataOut4[4];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	float32x4_t		vf32x4InputA;
	float32x4_t		vf32x4InputB;
	float32x4_t		vf32x4Output;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 0.5;		af32DataInB[0] = 1;
	af32DataInA[1] = 0.5;		af32DataInB[1] = 1.5;
	af32DataInA[2] = 100;		af32DataInB[2] = 1;
	af32DataInA[3] = 100;		af32DataInB[3] = 100;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);
	vf32x4InputA	= vld1q_f32(af32DataInA);
	vf32x4InputB	= vld1q_f32(af32DataInB);

	// float32x2_t vrecps_f32(float32x2_t a, float32x2_t b);					// VRECPS.F32 d0, d0, d0
	vf32x2Output	= vrecps_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOut2, vf32x2Output);

	// float32x4_t vrecpsq_f32(float32x4_t a, float32x4_t b);					// VRECPS.F32 q0, q0, q0
	vf32x4Output	= vrecpsq_f32(vf32x4InputA, vf32x4InputB);
	vst1q_f32(af32DataOut4, vf32x4Output);

	printf("== Reciprocal f32 = f32, f32 (vrecps_f32) ==\n");
	printf("=> 2.0 - (f32 * f32)                      ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f, %9.4f = \t%10.6f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut2[u32Idx]);
	}
	printf("========================================\n");

	printf("== Reciprocal f32 = f32, f32 (vrecpsq_f32) ==\n");
	printf("=> 2.0 - (f32 * f32)                       ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%9.4f, %9.4f = \t%10.6f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut4[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Reciprocal_F32_F32_F32_Example()
{
	float			af32DataInX[2];
	float			af32DataInB[2];
	float			af32DataOutXn[2];
	float			af32DataOutXn1[2];

	float32x2_t		vf32x2InputXn;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Temp;
	float32x2_t		vf32x2OutputXn1;

	uint32_t		u32Idx, u32RoundIdx;

	// Newton-Raphson iteration
	// performs a Newton-Raphson step for finding the reciprocal. It multiplies the elements of
	// one vector by the corresponding elements of another vector, subtracts each of the results
	// from 2, and places the final results into the elements of the destination vector

	// X = 1/B
	// => f(X) = 1/X - B
	// => f'(X) = -1/X^2 = - X^(-2)
	//
	// => Xn+1 = Xn - (f(Xn) / f'(Xn))		// Newton-Raphson
	// => Xn+1 = (2 - B * Xn) * Xn

	// initial (X, B)
	af32DataInX[0] = 0.1;		af32DataInB[0] = 7;			// 0.14285714285714285714285714285714
	af32DataInX[1] = 0.01;		af32DataInB[1] = 87;		// 0.01149425287356321839080459770115

	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("Initial B : %8.4f, Cand Xn : %8.4f, Find : 1.0 / %8.4f\n",
			af32DataInB[u32Idx], af32DataInX[u32Idx], af32DataInB[u32Idx]);
	}

	vf32x2InputXn	= vld1_f32(af32DataInX);			// Xn
	vf32x2InputB	= vld1_f32(af32DataInB);			// B

	// float32x2_t vrecps_f32(float32x2_t a, float32x2_t b);					// VRECPS.F32 d0, d0, d0
	for (u32RoundIdx = 0; u32RoundIdx < 5; ++u32RoundIdx)
	{
		vf32x2Temp			= vrecps_f32(vf32x2InputXn, vf32x2InputB);		// (2 - B * Xn)
		vf32x2OutputXn1		= vmul_f32(vf32x2Temp, vf32x2InputXn);			// (2 - B * Xn) * Xn	=> Xn+1

		vst1_f32(af32DataOutXn, vf32x2InputXn);
		vst1_f32(af32DataOutXn1, vf32x2OutputXn1);

		printf("=> Round %2d ==\n", u32RoundIdx);
		for (u32Idx = 0; u32Idx < 2; ++u32Idx)
		{
			printf("(1.0 / %8.4f) => Xn : %20.16f => Xn+1 : %20.16f\n",
				af32DataInB[u32Idx],
				af32DataOutXn[u32Idx], af32DataOutXn1[u32Idx]);
		}
		vf32x2InputXn		= vf32x2OutputXn1;
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sqrt_F32_F32_F32()
{
	float			af32DataInA[4];
	float			af32DataInB[4];
	float			af32DataOut2[2];
	float			af32DataOut4[4];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	float32x4_t		vf32x4InputA;
	float32x4_t		vf32x4InputB;
	float32x4_t		vf32x4Output;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 1;			af32DataInB[0] = 1;
	af32DataInA[1] = 1;			af32DataInB[1] = 100;
	af32DataInA[2] = 100;		af32DataInB[2] = 1;
	af32DataInA[3] = 100;		af32DataInB[3] = 100;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);
	vf32x4InputA	= vld1q_f32(af32DataInA);
	vf32x4InputB	= vld1q_f32(af32DataInB);

	// performs a Newton-Raphson step for finding the reciprocal square root.
	// It multiplies the elements of one vector by the corresponding elements of another vector,
	// subtracts each of the results from 3, divides these results by two, and places
	// the final results into the elements of the destination vector

	// float32x2_t vrsqrts_f32(float32x2_t a, float32x2_t b);					// VRSQRTS.F32 d0, d0, d0
	vf32x2Output	= vrsqrts_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOut2, vf32x2Output);

	// float32x4_t vrsqrtsq_f32(float32x4_t a, float32x4_t b);					// VRSQRTS.F32 q0, q0, q0
	vf32x4Output	= vrsqrtsq_f32(vf32x4InputA, vf32x4InputB);
	vst1q_f32(af32DataOut4, vf32x4Output);

	printf("== Sqrt f32 = f32, f32 (vrsqrts_f32) ==\n");
	printf("=> (3.0 - (f32 * f32)) / 2.0         ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f, %9.4f = \t%10.6f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut2[u32Idx]);
	}
	printf("========================================\n");

	printf("== Sqrt f32 = f32, f32 (vrsqrtsq_f32) ==\n");
	printf("=> (3.0 - (f32 * f32)) / 2.0          ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%9.4f, %9.4f = \t%10.6f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut4[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sqrt_F32_F32_F32_Example()
{
	float			af32DataInX[2];
	float			af32DataInB[2];
	float			af32DataOutXn[2];
	float			af32DataOutXn1[2];

	float32x2_t		vf32x2InputXn;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2TempDblXn;
	float32x2_t		vf32x2Temp3_BXn2;
	float32x2_t		vf32x2OutputXn1;

	uint32_t		u32Idx, u32RoundIdx;

	// Newton-Raphson iteration
	// performs a Newton-Raphson step for finding the reciprocal square root. It multiplies the
	// elements of one vector by the corresponding elements of another vector, subtracts each of
	// the results from 3, divides these results by two, and places the final results into the
	// elements of the destination vector

	// X^2 = 1/B
	// => f(X) = 1/(X^2) - B = X^(-2) - B
	// => f'(X) = -2 * X^(-3)
	//
	// => Xn+1 = Xn - (f(Xn) / f'(Xn))		// Newton-Raphson
	// => Xn+1 = Xn * (3 - B * Xn^2) / 2

	// initial (X, B)
	af32DataInX[0] = 0.14;		af32DataInB[0] = 49.0;		// 0.14285714285714285714285714285714
	af32DataInX[1] = 0.04;		af32DataInB[1] = 529.0;		// 0.04347826086956521739130434782609

	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("Initial B : %8.4f, Cand Xn : %8.4f, Find : 1.0 / sqrt(%8.4f)\n",
			af32DataInB[u32Idx], af32DataInX[u32Idx], af32DataInB[u32Idx]);
	}

	vf32x2InputXn	= vld1_f32(af32DataInX);			// Xn
	vf32x2InputB	= vld1_f32(af32DataInB);			// B

	// float32x2_t vrsqrts_f32(float32x2_t a, float32x2_t b);					// VRSQRTS.F32 d0, d0, d0
	for (u32RoundIdx = 0; u32RoundIdx < 20; ++u32RoundIdx)
	{
		vf32x2TempDblXn		= vmul_f32(vf32x2InputXn, vf32x2InputXn);		// Xn ^ 2
		vf32x2Temp3_BXn2	= vrecps_f32(vf32x2TempDblXn, vf32x2InputB);	// (3 - B * Xn^2) / 2
		vf32x2OutputXn1		= vmul_f32(vf32x2InputXn, vf32x2Temp3_BXn2);	// Xn * (3 - B * Xn^2) / 2	=> Xn+1

		vst1_f32(af32DataOutXn, vf32x2InputXn);
		vst1_f32(af32DataOutXn1, vf32x2OutputXn1);

		printf("=> Round %2d ==\n", u32RoundIdx);
		for (u32Idx = 0; u32Idx < 2; ++u32Idx)
		{
			printf("(1.0 / sqrt(%8.4f)) => Xn : %20.16f => Xn+1 : %20.16f\n",
				af32DataInB[u32Idx],
				af32DataOutXn[u32Idx], af32DataOutXn1[u32Idx]);
		}
		vf32x2InputXn		= vf32x2OutputXn1;
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
