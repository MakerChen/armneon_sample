#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

#include "neon_sample_test.h"

// -----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	neon_sample_Add();
	neon_sample_Multiple();
	neon_sample_Sub();
	neon_sample_Compare();
	neon_sample_AbsDiff();
	neon_sample_MaxMin();
	neon_sample_PairwiseAdd();
	neon_sample_Folding();
	neon_sample_ReciprocalSqrt();
	neon_sample_ShiftSignedVariable();
	neon_sample_ShiftConstant();
	neon_sample_ShiftInsert();
	neon_sample_LoadStore();
	neon_sample_LoadStoreElements();
	neon_sample_ExtractLanes();
	neon_sample_LoadLaneFromLiteral();
	neon_sample_InitialLiteral();
	neon_sample_SetLanesToValue();
	neon_sample_Combine();
	neon_sample_Split();
	neon_sample_Convert();					// f16 <-> f32
	neon_sample_TableLookUp();
	neon_sample_ScalarValue();				//
	neon_sample_VectorExtraction();
	neon_sample_ReverseVectorElements();
	neon_sample_SingleOperandArithemetic();	// need verify
	neon_sample_Bitwise();
	neon_sample_Transposition();
	neon_sample_VectorCast();				//

	exit(0);
}

// -----------------------------------------------------------------------------
