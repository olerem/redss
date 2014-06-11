/*
 * dss2_decoder
 *
 *  Created on: 03.06.2014
 *      Autor: lex
 */

#include <stdio.h>
#include <stdint.h>
#include "dss.h"
#define __int8 int8_t
#define __int16 int16_t

#define DSS_CBUF_SIZE 21

unsigned int word_3D1264;
unsigned int word_3D1266;
unsigned int word_3D041C;
unsigned int word_3D0C26;
unsigned int word_3D9B7C;
unsigned int flip;

void g_unc_byte_swap(__int8 *abuff_swap, __int8 **abuff_src, int dec_flag) {
	uint8_t *abuff_tmp;
	int size; // si@1
	int i;

	word_3D1264 = 1;
	abuff_tmp = *abuff_src;
	size = DSS_CBUF_SIZE;
	if (flip) {
		unsigned int tmp = abuff_tmp[0];
#if 0
		if (dec_flag & 2 && !(tmp & 0x80) )
		{
			size = 5;
			word_3D1264 = 0;
		}
#endif
		abuff_tmp++;

		for (i = 0; i < size - 1; i++) {
			abuff_swap[0] = tmp;
			abuff_swap[1] = abuff_tmp[0];
			tmp = abuff_tmp[1];
			abuff_tmp += 2;
			abuff_swap += 2;
		}

		word_3D1266 = tmp;
		abuff_swap[0] = 0;
		abuff_swap[1] = abuff_tmp[0];
		*abuff_src = abuff_tmp;
		flip ^= 1;
	} else {
#if 0
		if ( dec_flag & 2 && !(*(abuff_tmp - 1) & 0x80) ) // Never executed
		{
			size = 5;
			word_3D1264 = 0;
		}
#endif
		abuff_swap[0] = abuff_tmp[2];
		abuff_swap[1] = word_3D1266;
		abuff_tmp++;
		abuff_swap += 2;

		for (i = 0; i < size - 2; i++) {
			abuff_swap[0] = abuff_tmp[3];
			abuff_swap[1] = abuff_tmp[0];
			abuff_swap += 2;
			abuff_tmp += 2;
		}

		abuff_swap[1] = abuff_tmp[0];
		*abuff_src = abuff_tmp + 2;
		flip ^= 1;
	}
}

void g_unc_unpack_coeffs(struct struc_1 *reconstr_abuff, int16_t *abuff_swap_a2) {
	__int16 v2; // bp@1
	__int16 *abuff_swap_ptr; // eax@2
	struct struc_1 *reconstr_abuff_v4; // esi@2
	int v5; // ecx@2
	int v6; // edx@2
	signed int v7; // edx@2
	signed int v8; // edx@2
	int v9; // ecx@2
	int v10; // edx@2
	signed int v11; // ecx@2
	int v12; // edx@2
	int v13; // edx@3
	signed int v14; // edx@3
	signed int v15; // edx@3
	int v16; // ecx@3
	int v17; // edx@3
	signed int v18; // ecx@7
	signed int v19; // edx@7
	int v20; // ecx@7
	signed int v21; // ecx@7
	signed int v22; // ecx@7
	int v23; // edx@7
	signed int v24; // edx@7
	signed int v25; // edx@7
	signed int v26; // edx@7
	int v27; // ecx@7
	signed int v28; // ecx@7
	signed int v29; // ecx@7
	int v30; // edx@7
	signed int v31; // edi@9
	int *v32; // ebx@12
	signed int v33; // ecx@12
	int *v34; // edx@16
	int v35; // ebx@16
	unsigned int v36; // edx@22
	signed int v37; // ebx@22
	signed int v38; // ecx@22
	signed int v39; // edi@22
	int v40; // ebp@25
	int v41; // ebp@25
	bool v42; // zf@26
	signed int v45; // ebp@27
	int v46; // ecx@27
	__int16 v47; // di@28
	signed int v50; // edx@29
	int v52; // [sp+8h] [bp-30h]@7
	__int16 *v53; // [sp+Ch] [bp-2Ch]@7
	int *v54; // [sp+10h] [bp-28h]@12
	signed int v55; // [sp+14h] [bp-24h]@7
	int v57; // [sp+1Ch] [bp-1Ch]@9
	int v58; // [sp+20h] [bp-18h]@9
	int v59; // [sp+24h] [bp-14h]@9
	int v60; // [sp+28h] [bp-10h]@9
	int v61; // [sp+2Ch] [bp-Ch]@9
	int v62; // [sp+30h] [bp-8h]@9
	int v63; // [sp+34h] [bp-4h]@9
	struct struc_1 *reconstr_abuffa; // [sp+3Ch] [bp+4h]@0
	__int16 *abuff_swap_ptra; // [sp+40h] [bp+8h]@12
	__int8 *abuff_swap_ptrb; // [sp+40h] [bp+8h]@22
	__int8 *abuff_swap_ptrc; // [sp+40h] [bp+8h]@27
	int i;

	v2 = 0;
	if (word_3D041C) {
		reconstr_abuff_v4 = reconstr_abuff;

		word_3D1264 = reconstr_abuff->field_0 = (abuff_swap_ptr[0] >> 15) & 1;

		reconstr_abuff->array14_stage0[0] = (abuff_swap_ptr[0] >> 10) & 0x1F;
		reconstr_abuff->array14_stage0[1] = (abuff_swap_ptr[0] >> 5) & 0x1F;
		reconstr_abuff->array14_stage0[2] = (abuff_swap_ptr[0] >> 1) & 0xF;
		reconstr_abuff->array14_stage0[3] = ((abuff_swap_ptr[1] >> 13) & 7)
				+ 8 * (abuff_swap_ptr[0] & 1);

		reconstr_abuff->array14_stage0[4] = (abuff_swap_ptr[1] >> 9) & 0xF;
		reconstr_abuff->array14_stage0[5] = (abuff_swap_ptr[1] >> 5) & 0xF;
		reconstr_abuff->array14_stage0[6] = (abuff_swap_ptr[1] >> 1) & 0xF;
		reconstr_abuff->array14_stage0[7] = ((abuff_swap_ptr[2] >> 13) & 7)
				+ 8 * (abuff_swap_ptr[1] & 1);

		reconstr_abuff->array14_stage0[8] = (abuff_swap_ptr[2] >> 10) & 7;
		reconstr_abuff->array14_stage0[9] = (abuff_swap_ptr[2] >> 7) & 7;
		reconstr_abuff->array14_stage0[10] = (abuff_swap_ptr[2] >> 4) & 7;
		reconstr_abuff->array14_stage0[11] = (abuff_swap_ptr[2] >> 1) & 7;
		reconstr_abuff->array14_stage0[12] = ((abuff_swap_ptr[3] >> 14) & 3)
				+ 4 * (abuff_swap_ptr[2] & 1);

		v12 = (abuff_swap_ptr[3] >> 12) & 3;
	} else {
		reconstr_abuff_v4 = reconstr_abuffa;
		word_3D1264 = 1;

		reconstr_abuff->array14_stage0[0] = (abuff_swap_ptr[0] >> 11) & 0x1F;
		reconstr_abuff->array14_stage0[1] = (abuff_swap_ptr[0] >> 6) & 0x1F;
		reconstr_abuff->array14_stage0[2] = (abuff_swap_ptr[0] >> 2) & 0xF;
		reconstr_abuff->array14_stage0[3] = ((abuff_swap_ptr[1] >> 14) & 3)
				+ 4 * (abuff_swap_ptr[0] & 3);

		reconstr_abuff->array14_stage0[4] = (abuff_swap_ptr[1] >> 10) & 0xF;
		reconstr_abuff->array14_stage0[5] = (abuff_swap_ptr[1] >> 6) & 0xF;
		reconstr_abuff->array14_stage0[6] = (abuff_swap_ptr[1] >> 2) & 0xF;
		reconstr_abuff->array14_stage0[7] = ((abuff_swap_ptr[2] >> 14) & 3)
				+ 4 * (abuff_swap_ptr[1] & 3);

		reconstr_abuff->array14_stage0[8] = (abuff_swap_ptr[2] >> 11) & 7;
		reconstr_abuff->array14_stage0[9] = (abuff_swap_ptr[2] >> 8) & 7;
		reconstr_abuff->array14_stage0[10] = (abuff_swap_ptr[2] >> 5) & 7;
		reconstr_abuff->array14_stage0[11] = (abuff_swap_ptr[2] >> 2) & 7;
		reconstr_abuff->array14_stage0[12] = ((abuff_swap_ptr[3] >> 15) & 1)
				+ 2 * (abuff_swap_ptr[2] & 3);

		v12 = (abuff_swap_ptr[3] >> 12) & 7;
	}

	reconstr_abuff->array14_stage0[13] = v12;

	if (word_3D041C && !word_3D1264) {
		reconstr_abuff->subframe_something[0] = (abuff_swap_ptr[3] >> 7) & 0x1F;
		reconstr_abuff->subframe_something[1] = (abuff_swap_ptr[3] >> 2) & 0x1F;
		reconstr_abuff->subframe_something[2] = (abuff_swap_ptr[4] >> 13) & 7;
		reconstr_abuff->subframe_something[3] = (abuff_swap_ptr[4] >> 8) & 0x1F;
		return;
	}

	reconstr_abuff_v4->subframe_something[0] = (abuff_swap_ptr[3] >> 7) & 0x1F;

	// instead of "*((uint8_t *)abuff_swap_ptr + 11)" can be "(abuff_swap_ptr[5] >> 8) & 0xf"
	reconstr_abuff_v4->sf[0].field_4 = *((uint8_t *) abuff_swap_ptr + 11)
			+ ((abuff_swap_ptr[4] + ((abuff_swap_ptr[3] & 0x7F) << 16)) << 8);
	reconstr_abuff_v4->sf[0].gain = (abuff_swap_ptr[5] >> 2) & 0x3F;

	reconstr_abuff_v4->sf[0].pulse_val[0] = ((abuff_swap_ptr[6] >> 15) & 1)
			+ 2 * (abuff_swap_ptr[5] & 3);
	reconstr_abuff_v4->sf[0].pulse_val[1] = (abuff_swap_ptr[6] >> 12) & 7;
	reconstr_abuff_v4->sf[0].pulse_val[2] = (abuff_swap_ptr[6] >> 9) & 7;
	reconstr_abuff_v4->sf[0].pulse_val[3] = (abuff_swap_ptr[6] >> 6) & 7;
	reconstr_abuff_v4->sf[0].pulse_val[4] = (abuff_swap_ptr[6] >> 3) & 7;
	reconstr_abuff_v4->sf[0].pulse_val[5] = abuff_swap_ptr[6] & 7;
	reconstr_abuff_v4->sf[0].pulse_val[6] = (abuff_swap_ptr[7] >> 13) & 7;

	reconstr_abuff_v4->subframe_something[1] = (abuff_swap_ptr[7] >> 8) & 0x1F;

	reconstr_abuff_v4->sf[1].field_4 = ((abuff_swap_ptr[9] >> 9) & 0x7F)
			+ ((abuff_swap_ptr[8] + (abuff_swap_ptr[7] << 16)) << 7);
	reconstr_abuff_v4->sf[1].gain = (abuff_swap_ptr[9] >> 3) & 0x3F;

	reconstr_abuff_v4->sf[1].pulse_val[0] = abuff_swap_ptr[9] & 7;
	reconstr_abuff_v4->sf[1].pulse_val[1] = (abuff_swap_ptr[10] >> 13) & 7;
	reconstr_abuff_v4->sf[1].pulse_val[2] = (abuff_swap_ptr[10] >> 10) & 7;
	reconstr_abuff_v4->sf[1].pulse_val[3] = (abuff_swap_ptr[10] >> 7) & 7;
	reconstr_abuff_v4->sf[1].pulse_val[4] = (abuff_swap_ptr[10] >> 4) & 7;
	reconstr_abuff_v4->sf[1].pulse_val[5] = (abuff_swap_ptr[10] >> 1) & 7;
	reconstr_abuff_v4->sf[1].pulse_val[6] = ((abuff_swap_ptr[11] >> 14) & 3)
			+ 4 * (abuff_swap_ptr[10] & 1);

	reconstr_abuff_v4->subframe_something[2] = (abuff_swap_ptr[11] >> 9) & 0x1F;

	reconstr_abuff_v4->sf[2].field_4 =
			((abuff_swap_ptr[13] >> 10) & 0x3F)
					+ ((abuff_swap_ptr[12]
							+ ((abuff_swap_ptr[11] & 0x1FF) << 16)) << 6);

	reconstr_abuff_v4->sf[2].gain = (abuff_swap_ptr[13] >> 4) & 0x3F;

	reconstr_abuff_v4->sf[2].pulse_val[0] = (abuff_swap_ptr[13] >> 1) & 7;
	reconstr_abuff_v4->sf[2].pulse_val[1] = ((abuff_swap_ptr[14] >> 14) & 3)
			+ 4 * (abuff_swap_ptr[14] & 1);
	reconstr_abuff_v4->sf[2].pulse_val[2] = (abuff_swap_ptr[14] >> 11) & 7;
	reconstr_abuff_v4->sf[2].pulse_val[3] = (abuff_swap_ptr[14] >> 8) & 7;
	reconstr_abuff_v4->sf[2].pulse_val[4] = (abuff_swap_ptr[14] >> 5) & 7;
	reconstr_abuff_v4->sf[2].pulse_val[5] = (abuff_swap_ptr[14] >> 2) & 7;
	reconstr_abuff_v4->sf[2].pulse_val[6] = ((abuff_swap_ptr[15] >> 15) & 1)
			+ 2 * (abuff_swap_ptr[14] & 3);

	reconstr_abuff_v4->subframe_something[3] = (abuff_swap_ptr[15] >> 10)
			& 0x1F;

	reconstr_abuff_v4->sf[3].field_4 = ((abuff_swap_ptr[17] >> 11) & 0x1F)
			+ 32 * (abuff_swap_ptr[16] + ((abuff_swap_ptr[15] & 0x3FF) << 16));
	reconstr_abuff_v4->sf[3].gain = (abuff_swap_ptr[17] >> 5) & 0x3F;

	reconstr_abuff_v4->sf[3].pulse_val[0] = (abuff_swap_ptr[17] >> 2) & 7;
	reconstr_abuff_v4->sf[3].pulse_val[1] = ((abuff_swap_ptr[18] >> 15) & 1)
			+ 2 * (abuff_swap_ptr[17] & 3);
	reconstr_abuff_v4->sf[3].pulse_val[2] = (abuff_swap_ptr[18] >> 12) & 7;
	reconstr_abuff_v4->sf[3].pulse_val[3] = (abuff_swap_ptr[18] >> 9) & 7;
	reconstr_abuff_v4->sf[3].pulse_val[4] = (abuff_swap_ptr[18] >> 6) & 7;
	reconstr_abuff_v4->sf[3].pulse_val[5] = (abuff_swap_ptr[18] >> 3) & 7;
	reconstr_abuff_v4->sf[3].pulse_val[6] = abuff_swap_ptr[18] & 7;

////////////////////////////////////////////////////////////////////
	int subframe_idx;
	for (subframe_idx = 0; subframe_idx < 4; subframe_idx++) {
		/* looks like Binomial coefficients C(72,n). But 3379081753 do not fit to this sequence */
		unsigned int v56[8] = { 72, 2556, 59640, 1028790, 13991544, 156238908,
				1473109704, 3379081753 };

		v31 = reconstr_abuff_v4->sf[subframe_idx].field_4;

		if (v31 < v56[7])
			if (word_3D0C26 != 0)
				goto LABEL_22;
			else
				word_3D0C26 = 0;

		v33 = 6;
		/* why do we need this? */
		reconstr_abuff_v4->sf[subframe_idx].pulse_pos[6] = 0;

		//////////////////
		for (i = 71; i >= 0; i--) {
			if (v56[v33] <= v31) {
				v31 -= v56[v33];

				reconstr_abuff_v4->sf[subframe_idx].pulse_pos[(v33 ^ 7) - 1] =
						i;

				if (!v33)
					break;
				--v33;
			}
			--v56[0];
			if (v33 >= 1) {
				int a;
				for (a = 0; a < v33; a++)
					v56[a + 1] -= v56[a];
			}
		};
		////////////////////////////

		if (word_3D0C26) {
LABEL_22:
			v36 = reconstr_abuff_v4->sf[subframe_idx].field_4;
			v38 = 71; //GRID_SIZE
			v39 = 7; //MAX_PULSES

			/* this part seems to be close to g723.1 gen_fcb_excitation() RATE_6300 */
			for (i = 0; i < 7; i++) {
				for (; v36 < dss2_combinatorial_table[v39][v38]; --v38)
					;
				v36 -= dss2_combinatorial_table[v39][v38];
				v39--;
				reconstr_abuff_v4->sf[subframe_idx].pulse_pos[i] = v38;
			}
		}
	}

/////////////////////////////////////////////////////////////////////////
	int16_t *v44;
	int16_t v43;

	v43 = abuff_swap_ptr[19];
	v44 = &reconstr_abuff_v4[8];

	v46 = ((v43 << 8) + *((int8_t *) abuff_swap_ptr + 41)) / 151;
	reconstr_abuff_v4[15] = ((v43 << 8) + *((int8_t *) abuff_swap_ptr + 41))
			% 151 + 36;
	for (i = 3; i > 0; i--) {
		v47 = v46;
		++v44;
		v46 /= 48;
		*(v44 - 1) = v47 - 48 * v46;
	}
////////////////////////////////////////////////////////////////////////
	int16_t v51;
	int16_t v48;
	int16_t *v49;

	v48 = reconstr_abuff_v4[15];
	v49 = &reconstr_abuff_v4[8];
	for (i = 3; i > 0; i--) {
		if (v48 > 162) {
			*v49 += 139;
		} else {
			v51 = v48 - 23;
			if (v51 < 36)
				v51 = 36;
			*v49 += v51;
		}
		v48 = *v49;
		v49++;
	}

}

/* create stage 1 array14_stage0 based on stage0 and some kind of pulse table */
void g_unc_sub_3B8740(int32_t *array14_stage1, const struct struc_1 *a2) {
	int i;

	for (i = 0; i < 14; i++)
		array14_stage1[i] = g_unc_array_3C84F0[i][a2->array14_stage0[i]];

	if (word_3D041C)
		array14_stage1[13] = g_unc_array_3C8870[a2->array14_stage0[13]];
}

void g_unc_sub_3B8410(struct struc_6 *struc_6_a1,
		struct struc_8 *struc_6_stg2_a2) {
	struct struc_8 *struc_6_v2; // ecx@1
	int v3; // esi@1
	int v5; // ebx@2
	signed int v6; // eax@2
	int v7; // esi@3
	int v8; // edi@3
	int v9; // edx@3
	int v10; // edx@3
	int v11; // edx@5
	int v12; // edx@5
	struct struc_6 *struc_6_v14; // ebx@11
	int v14; // ebp@11
	int v15; // esi@12
	signed int v16; // esi@13
	int v17; // ebp@15
	int v18; // eax@15
	int v19; // edi@15
	int v20; // edx@15
	int v21; // edx@15
	int v22; // edx@18
	int v23; // edx@18
	int v24; // zf@25
	int v25; // [sp+10h] [bp-14h]@1
	int v26; // [sp+10h] [bp-14h]@11
	struct struc_6 *struc_6_v29; // [sp+14h] [bp-10h]@11
	signed int v28; // [sp+18h] [bp-Ch]@11
	int v29; // [sp+1Ch] [bp-8h]@12
	int v30; // [sp+20h] [bp-4h]@12
	int32_t *array14a; // [sp+28h] [bp+4h]@11
	int counter; // [sp+2Ch] [bp+8h]@2
	signed int struc_6_a2b; // [sp+2Ch] [bp+8h]@12
	int tmp;

	struc_6_v2 = struc_6_stg2_a2;
	v3 = 0;
	word_3D9B7C = 0;
	struc_6_stg2_a2->field_0 = 0x2000u;
	while (1) {
		v5 = v3;
		v6 = v3 + 1;
		struc_6_v2->array14_stage2[v3] = struc_6_a1->array14_stage1[v3] >> 2;
		if (v6 / 2 >= 1)
			break;
		LABEL_9: ++v3;
		if (v3 >= 14)
			return;
	}

	/////////////////////////////
	counter = 1;
	while (1) {
		v7 = struc_6_v2->array14_stage2[counter - 1];
		// 4, 4, 4
		v8 = struc_6_v2->array14_stage2[v5 - counter];
		// 8, 8, c
		tmp = (struc_6_a1->array14_stage1[v5] * v8 + (v7 << 15) + 0x4000) >> 15;
		struc_6_v2->array14_stage2[counter - 1] = tmp;
		if (tmp != 0xFFFF8000)
			break;

		tmp = (struc_6_a1->array14_stage1[v5] * v7 + (v8 << 15) + 0x4000) >> 15;
		struc_6_v2->array14_stage2[v5 - counter] = tmp;
		if (tmp != 0xFFFF8000)
			break;

		++counter;
		if (counter > v6 / 2)
			goto LABEL_9;
	}
	//////////////////////////////////
	// looks like sort of cleanup part. In case "tmp != 0xFFFF8000" check will fail.
	// or may be not used at all. With my test file it was never triggered
#if 0
	struc_6_v14 = struc_6_a1;
	v14 = 0;
	word_3D9B7C = 1;
	struc_6_v2->gain = 0x1000;
	v26 = 0;
	struc_6_v29 = struc_6_a1;
	array14a = struc_6_v2->array14_stage2;
	v28 = 14;
	do
	{
		v15 = v14 + 1;
		*array14a = struc_6_v14->array14_stage1[0] >> 3;
		counter = 1;
		v30 = v14 + 1;
		v29 = (v14 + 1) / 2;
		if ( (v14 + 1) / 2 >= 1 )
		{
			v16 = 1;
			while ( 1 )
			{
				v17 = v14 - v16;
				v18 = struc_6_v2->array14_stage2[v16 - 1];
				v19 = struc_6_v2->array14_stage2[v17];
				v20 = (v19 * struc_6_v14->array14_stage1[0] + (struc_6_v2->array14_stage2[v16 - 1] << 15) + 0x4000) >> 15;
				struc_6_v2->array14_stage2[v16 - 1] = v20;
				v21 = v20 & 0xFFFF8000;
				if ( v21 && v21 != 0xFFFF8000 )
				struc_6_v2->array14_stage2[v16 - 1] = ((v21 <= 0) - 1) - 0x8000;
				struc_6_v14 = struc_6_v29;
				v22 = (v18 * struc_6_v29->array14_stage1[0] + (v19 << 15) + 0x4000) >> 15;
				struc_6_v2->array14_stage2[v17] = v22;
				v23 = v22 & 0xFFFF8000;
				if ( v23 && v23 != 0xFFFF8000 )
				{
					if ( v23 <= 0 )
					struc_6_v2->array14_stage2[v17] = 0xFFFF8000;
					else
					struc_6_v2->array14_stage2[v17] = 0x7FFF;
				}
				++counter;
				v16 = counter;
				if ( counter > v29 )
				break;
				v14 = v26;
			}
			v15 = v30;
		}
		v14 = v15;
		struc_6_v14 = (struct struc_6 *)((char *)struc_6_v14 + 4);
		v24 = v28 == 1;
		v26 = v15;
		array14a++;
		struc_6_v29 = struc_6_v14;
		--v28;
	}
	while ( !v24 );
#endif
}

/* this function will get pointer to one of 4 subframes */
void g_unc_add_pulses(int32_t *array72_a1, struct dss2_subframe *sf) {
	int i;

	//looks like "output[sf->pulse_pos[i]] += g_gains[sf->gain] * g_pulse_val[sf->pulse_val[i]] + 0x4000 >> 15;"
	for (i = 0; i < 7; i++)
		array72_a1[sf->pulse_pos[i]] += (dss2_fixed_cb_gain[sf->gain]
				* dss2_pulse_val[sf->pulse_val[i]] + 0x4000) >> 15;

}

void dss2_sub_3B9080(__int32 *array72, __int32 *array36, __int16 a3, int a4) {
	__int32 *array72_ptr0; // edx@2
	signed int size1; // esi@2
	__int32 *v6; // eax@2
	__int32 v7; // ecx@3
	__int32 *array72_ptr_v8; // edi@5
	int v9; // esi@5
	signed int size0; // ebp@5
	int v11; // eax@6
	__int32 *array72_ptr1; // ecx@7
	signed int size2; // edi@7
	int v14; // eax@8
	int v15; // eax@8

	if (a3 < 72) {
		array72_ptr_v8 = array72;
		v9 = 0;
		size0 = 72;
		do {
			++array72_ptr_v8;
			v11 = a3 - v9++ % a3;
			--size0;
			*(array72_ptr_v8 - 1) = array36[v11];
		} while (size0);
	} else {
		array72_ptr0 = array72;
		size1 = 72;
		v6 = &array36[a3];
		do {
			v7 = *v6;
			--v6;
			*array72_ptr0 = v7;
			++array72_ptr0;
			--size1;
		} while (size1);
	}
	array72_ptr1 = array72;
	size2 = 72;
	do {
		v14 = a4 * *array72_ptr1 >> 11;
		*array72_ptr1 = v14;
		v15 = v14 & 0xFFFF8000;
		if (v15) {
		if ( v15 != 0xFFFF8000 )
		*array72_ptr1 = (unsigned __int16)(((v15 <= 0) - 1) & 0xFFFE) - 0x7FFF;
	}
	++array72_ptr1;
	--size2;
} while (size2);
}

void g_unc_normalize(__int32 *array_a1, __int16 normalize_bits,
	__int16 array_a1_size) {
__int32 *v3; // eax@3
int t_size2; // edx@3
__int32 val2; // esi@4
__int32 *v6; // eax@7
int t_size1; // edx@7
__int32 val1; // esi@8

if (normalize_bits < 0) {
	if (array_a1_size > 0) {
		v6 = array_a1;
		t_size1 = array_a1_size;
		do {
			val1 = *v6;
			++v6;
			--t_size1;
			*(v6 - 1) = val1 >> -(char) normalize_bits;
		} while (t_size1);
	}
} else {
	if (array_a1_size > 0) {
		v3 = array_a1;
		t_size2 = array_a1_size;
		do {
			val2 = *v3;
			++v3;
			--t_size2;
			*(v3 - 1) = val2 << normalize_bits;
		} while (t_size2);
	}
}
}

