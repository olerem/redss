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
int32_t g_unc_rw_array15_3D0420[15];
int32_t g_unc_rw_array15_3D045C[15];

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
	int16_t *abuff_swap_ptr; // eax@2
	int v12; // edx@2
	int i;

	if (word_3D041C) {

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

	reconstr_abuff->subframe_something[0] = (abuff_swap_ptr[3] >> 7) & 0x1F;

	// instead of "*((uint8_t *)abuff_swap_ptr + 11)" can be "(abuff_swap_ptr[5] >> 8) & 0xf"
	reconstr_abuff->sf[0].combined_pulse_pos =
			*((uint8_t *) abuff_swap_ptr + 11)
					+ ((abuff_swap_ptr[4] + ((abuff_swap_ptr[3] & 0x7F) << 16))
							<< 8);
	reconstr_abuff->sf[0].gain = (abuff_swap_ptr[5] >> 2) & 0x3F;

	reconstr_abuff->sf[0].pulse_val[0] = ((abuff_swap_ptr[6] >> 15) & 1)
			+ 2 * (abuff_swap_ptr[5] & 3);
	reconstr_abuff->sf[0].pulse_val[1] = (abuff_swap_ptr[6] >> 12) & 7;
	reconstr_abuff->sf[0].pulse_val[2] = (abuff_swap_ptr[6] >> 9) & 7;
	reconstr_abuff->sf[0].pulse_val[3] = (abuff_swap_ptr[6] >> 6) & 7;
	reconstr_abuff->sf[0].pulse_val[4] = (abuff_swap_ptr[6] >> 3) & 7;
	reconstr_abuff->sf[0].pulse_val[5] = abuff_swap_ptr[6] & 7;
	reconstr_abuff->sf[0].pulse_val[6] = (abuff_swap_ptr[7] >> 13) & 7;

	reconstr_abuff->subframe_something[1] = (abuff_swap_ptr[7] >> 8) & 0x1F;

	reconstr_abuff->sf[1].combined_pulse_pos = ((abuff_swap_ptr[9] >> 9) & 0x7F)
			+ ((abuff_swap_ptr[8] + (abuff_swap_ptr[7] << 16)) << 7);
	reconstr_abuff->sf[1].gain = (abuff_swap_ptr[9] >> 3) & 0x3F;

	reconstr_abuff->sf[1].pulse_val[0] = abuff_swap_ptr[9] & 7;
	reconstr_abuff->sf[1].pulse_val[1] = (abuff_swap_ptr[10] >> 13) & 7;
	reconstr_abuff->sf[1].pulse_val[2] = (abuff_swap_ptr[10] >> 10) & 7;
	reconstr_abuff->sf[1].pulse_val[3] = (abuff_swap_ptr[10] >> 7) & 7;
	reconstr_abuff->sf[1].pulse_val[4] = (abuff_swap_ptr[10] >> 4) & 7;
	reconstr_abuff->sf[1].pulse_val[5] = (abuff_swap_ptr[10] >> 1) & 7;
	reconstr_abuff->sf[1].pulse_val[6] = ((abuff_swap_ptr[11] >> 14) & 3)
			+ 4 * (abuff_swap_ptr[10] & 1);

	reconstr_abuff->subframe_something[2] = (abuff_swap_ptr[11] >> 9) & 0x1F;

	reconstr_abuff->sf[2].combined_pulse_pos =
			((abuff_swap_ptr[13] >> 10) & 0x3F)
					+ ((abuff_swap_ptr[12]
							+ ((abuff_swap_ptr[11] & 0x1FF) << 16)) << 6);

	reconstr_abuff->sf[2].gain = (abuff_swap_ptr[13] >> 4) & 0x3F;

	reconstr_abuff->sf[2].pulse_val[0] = (abuff_swap_ptr[13] >> 1) & 7;
	reconstr_abuff->sf[2].pulse_val[1] = ((abuff_swap_ptr[14] >> 14) & 3)
			+ 4 * (abuff_swap_ptr[14] & 1);
	reconstr_abuff->sf[2].pulse_val[2] = (abuff_swap_ptr[14] >> 11) & 7;
	reconstr_abuff->sf[2].pulse_val[3] = (abuff_swap_ptr[14] >> 8) & 7;
	reconstr_abuff->sf[2].pulse_val[4] = (abuff_swap_ptr[14] >> 5) & 7;
	reconstr_abuff->sf[2].pulse_val[5] = (abuff_swap_ptr[14] >> 2) & 7;
	reconstr_abuff->sf[2].pulse_val[6] = ((abuff_swap_ptr[15] >> 15) & 1)
			+ 2 * (abuff_swap_ptr[14] & 3);

	reconstr_abuff->subframe_something[3] = (abuff_swap_ptr[15] >> 10) & 0x1F;

	reconstr_abuff->sf[3].combined_pulse_pos = ((abuff_swap_ptr[17] >> 11)
			& 0x1F)
			+ 32 * (abuff_swap_ptr[16] + ((abuff_swap_ptr[15] & 0x3FF) << 16));
	reconstr_abuff->sf[3].gain = (abuff_swap_ptr[17] >> 5) & 0x3F;

	reconstr_abuff->sf[3].pulse_val[0] = (abuff_swap_ptr[17] >> 2) & 7;
	reconstr_abuff->sf[3].pulse_val[1] = ((abuff_swap_ptr[18] >> 15) & 1)
			+ 2 * (abuff_swap_ptr[17] & 3);
	reconstr_abuff->sf[3].pulse_val[2] = (abuff_swap_ptr[18] >> 12) & 7;
	reconstr_abuff->sf[3].pulse_val[3] = (abuff_swap_ptr[18] >> 9) & 7;
	reconstr_abuff->sf[3].pulse_val[4] = (abuff_swap_ptr[18] >> 6) & 7;
	reconstr_abuff->sf[3].pulse_val[5] = (abuff_swap_ptr[18] >> 3) & 7;
	reconstr_abuff->sf[3].pulse_val[6] = abuff_swap_ptr[18] & 7;

////////////////////////////////////////////////////////////////////
	int subframe_idx;
	for (subframe_idx = 0; subframe_idx < 4; subframe_idx++) {
		unsigned int C72_binomials[PULSE_MAX] = { 72, 2556, 59640, 1028790,
				13991544, 156238908, 1473109704, 3379081753 };
		unsigned int combined_pulse_pos =
				reconstr_abuff->sf[subframe_idx].combined_pulse_pos;
		int index = 6;

		if (combined_pulse_pos < C72_binomials[PULSE_MAX - 1])
			if (word_3D0C26 != 0)
				goto LABEL_22;
			else
				word_3D0C26 = 0;

		/* why do we need this? */
		reconstr_abuff->sf[subframe_idx].pulse_pos[6] = 0;

		//////////////////
		for (i = 71; i >= 0; i--) {
			if (C72_binomials[index] <= combined_pulse_pos) {
				combined_pulse_pos -= C72_binomials[index];

				reconstr_abuff->sf[subframe_idx].pulse_pos[(index ^ 7) - 1] = i;

				if (!index)
					break;
				--index;
			}
			--C72_binomials[0];
			if (index) {
				int a;
				for (a = 0; a < index; a++)
					C72_binomials[a + 1] -= C72_binomials[a];
			}
		};
		////////////////////////////

		if (word_3D0C26) {
			int pulse, pulse_idx;
LABEL_22:
			pulse = PULSE_MAX - 1;
			pulse_idx = 71; //GRID_SIZE
			combined_pulse_pos =
					reconstr_abuff->sf[subframe_idx].combined_pulse_pos;

			/* this part seems to be close to g723.1 gen_fcb_excitation() RATE_6300 */
			/* TODO: 7 is what? size of subframe? */
			for (i = 0; i < 7; i++) {
				for (;
						combined_pulse_pos
								< dss2_combinatorial_table[pulse][pulse_idx];
						--pulse_idx)
					;
				combined_pulse_pos -=
						dss2_combinatorial_table[pulse][pulse_idx];
				pulse--;
				reconstr_abuff->sf[subframe_idx].pulse_pos[i] = pulse_idx;
			}
		}
	}

/////////////////////////////////////////////////////////////////////////
	int16_t v43;
	int v46;

	v43 = abuff_swap_ptr[19];

	v46 = ((v43 << 8) + *((int8_t *) abuff_swap_ptr + 0x29)) / 151;
	// TODO, is filed_1e part of array_20?
	reconstr_abuff->filed_1e =
			((v43 << 8) + *((int8_t *) abuff_swap_ptr + 0x29)) % 151 + 36;
	for (i = 0; i < 3; i++) {
		int v47 = v46;
		v46 /= 48;
		reconstr_abuff->array_20[i] = v47 - 48 * v46;
	}
////////////////////////////////////////////////////////////////////////
	int16_t v51;
	int16_t v48;

	v48 = reconstr_abuff->filed_1e;
	for (i = 0; i < 3; i++) {
		if (v48 > 162) {
			reconstr_abuff->array_20[i] += 139;
		} else {
			v51 = v48 - 23;
			if (v51 < 36)
				v51 = 36;
			reconstr_abuff->array_20[i] += v51;
		}
		v48 = reconstr_abuff->array_20[i];

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
LABEL_9:
		++v3;
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
		if ((tmp & 0xFFFF8000) != 0xFFFF8000)
			break;

		tmp = (struc_6_a1->array14_stage1[v5] * v7 + (v8 << 15) + 0x4000) >> 15;
		struc_6_v2->array14_stage2[v5 - counter] = tmp;
		if ((tmp & 0xFFFF8000) != 0xFFFF8000)
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

void dss2_sub_3B9080(int32_t *array72, int32_t *array36, int a3, int a4) {

	int i;

	/* do we actually need this check? we can use just [a3 - i % a3] for both cases */
	if (a3 < 72)
		for (i = 0; i < 72; i++)
			array72[i] = array36[a3 - i % a3];
	else
		for (i = 0; i < 72; i++)
			array72[i] = array36[a3 - i];

	for (i = 0; i < 72; i++) {
		int tmp = a4 * array72[i] >> 11;
		array72[i] = tmp;
		tmp = tmp & 0xFFFF8000;
		if (tmp && tmp != 0xFFFF8000)
			array72[i] = (((tmp <= 0) - 1) & 0xFFFE) - 0x7FFF;

	};
}

void dss2_normalize(int32_t *array_a1, int normalize_bits, int array_a1_size) {
	int i;

	if (array_a1_size <= 0)
		return;

	if (normalize_bits < 0)
		for (i = 0; i < array_a1_size; i++)
			array_a1[i] = array_a1[i] >> abs(normalize_bits);
	else
		for (i = 0; i < array_a1_size; i++)
			array_a1[i] = array_a1[i] << normalize_bits;
}

void g_unc_sub_3B9FB0(int32_t *array72, int32_t *arrayXX) {
	int i;

	for (i = 0; i < 114; i++)
		arrayXX[114 - i] = arrayXX[186 - i];

	for (i = 0; i < 72; i++)
		arrayXX[72 - i] = array72[i];
}

void dss2_shift_sq_sub(const int32_t *array_a1, int32_t *array_a2,
		int32_t *array_a3_dst) {
	int a, shift;

	shift = 13 - word_3D9B7C;

	for (a = 0; a < 72; a++) {
		int i, tmp;

		tmp = array_a3_dst[a] * array_a1[0];

		for (i = 14; i > 0; i--)
			tmp -= array_a2[i] * array_a1[i];

		/* original code overwrite array_a2[1] two times - makes no sense for me. */
		for (i = 14; i > 1; i--)
			array_a2[i] = array_a2[i - 1];

		tmp = (tmp + 4096) >> shift;

		array_a2[1] = tmp;

		array_a3_dst[a] = tmp;
		tmp &= 0xFFFF8000;
		if (tmp && tmp != 0xFFFF8000) {
			if (tmp <= 0)
				array_a2[1] = array_a3_dst[a] = 0xFFFF8000;
			else
				array_a2[1] = array_a3_dst[a] = 0x7FFF;
		}
	}
}

void dss2_vec_mult(const int32_t *array15_ro_src, int32_t *array15_dst, const int32_t *array15_ro_a3)
{
  int i;

  array15_dst[0] = array15_ro_src[0];

  /* TODO: pseudocode and my result are too different. May be my version is wrong */
  for (i = 1; i < 14; i++)
	  array15_dst[i] = (array15_ro_src[i] * array15_ro_a3[i] + 0x4000) >> 15;
}

int dss2_get_normalize_bits(int32_t *array_var, int16_t size)
{
  unsigned int val;
  int max_val;
  int i;

  val = 1;
  if (size)
    for (i = 0; i < size; i++)
    	val |= abs(array_var[i]);

  for ( max_val = 0; (val & 0xFFFFC000) == 0 | (val & 0xFFFFC000) == 0xFFFFC000; ++max_val )
    val *= 2;
  return max_val;
}


void g_unc_sub_3B80F0(__int32 a0, __int32 *array15_a1, __int32 *array72_a3, __int32 *array72_a4, __int16 size)
{
  signed int v5; // esi@1
  __int32 *array_a3_tmp; // ecx@2
  int size_tmp; // edx@2
  __int32 v8; // eax@3
  int normalize_bits_v9; // eax@9
  int normalize_bits_v10; // edi@9
  __int32 v11; // esi@9
  __int32 *v12; // ecx@12
  int v13; // eax@13
  int v14; // eax@13
  __int32 v15; // eax@17
  int v16; // eax@17
  int v17; // edi@20
  signed int v18; // ecx@20
  __int32 *v19; // edx@21
  int v20; // esi@21
  __int32 v21; // eax@22
  int v22; // eax@27
  int v23; // esi@29
  int v24; // eax@29
  int v25; // eax@29
  __int32 *local_rw_array_v41_ptr; // edx@33
  int size_v27; // edi@33
  int v28; // eax@34
  int v29; // eax@34
  __int32 *array72_a4_v30; // ecx@39
  int v31; // ebp@39
  __int32 v32; // eax@40
  int v33; // eax@40
  signed int v34; // [sp+10h] [bp-1A8h]@1
  int v35; // [sp+14h] [bp-1A4h]@12
  __int32 v36; // [sp+18h] [bp-1A0h]@9
  __int32 local_rw_array15_v1a[15]; // [sp+1Ch] [bp-19Ch]@9
  __int32 local_rw_array15_v39[15]; // [sp+58h] [bp-160h]@9
  int v39; // [sp+94h] [bp-124h]@29
  __int32 local_rw_array_v41[72]; // [sp+98h] [bp-120h]@33

  v5 = 0;
  v34 = 0;
  if ( size > 0 )
  {
    array_a3_tmp = array72_a3;
    size_tmp = size;
    do
    {
      v8 = *array_a3_tmp;
      if ( *array_a3_tmp >= 0 )
        v5 += v8;
      else
        v5 -= v8;
      ++array_a3_tmp;
      --size_tmp;
    }
    while ( size_tmp );
    v34 = v5;
    if ( v5 > (signed int)0xFFFFFu )
      v34 = 0xFFFFFu;
  }

  normalize_bits_v9 = dss2_get_normalize_bits(array72_a3, size);
  normalize_bits_v10 = normalize_bits_v9;
  dss2_normalize(array72_a3, normalize_bits_v9 - 3, size);
  dss2_normalize(g_unc_rw_array15_3D0420, normalize_bits_v10, 15);
  dss2_normalize(g_unc_rw_array15_3D045C, normalize_bits_v10, 15);
  v36 = g_unc_rw_array15_3D045C[1];
  dss2_vec_mult(array15_a1, local_rw_array15_v39, g_unc_ro_array37_3C845C);
  g_unc_shift_sq_add(local_rw_array15_v39, g_unc_rw_array15_3D0420, array72_a3);
  dss2_vec_mult(array15_a1, local_rw_array15_v1a, g_unc_ro_array15_3C8420);
  dss2_shift_sq_sub(local_rw_array15_v1a, g_unc_rw_array15_3D045C, array72_a3);
  v11 = a0 >> 1;
  if ( a0 >> 1 >= 0 )
    v11 = 0;
  if ( size > 1 )
  {
    v12 = &array72_a3[size - 1];
    v35 = size - 1;
    do
    {
      v13 = (v11 * *(v12 - 1) + (*v12 << 15) + 16384) >> 15;
      *v12 = v13;
      v14 = v13 & 0xFFFF8000;
      if ( v14 && v14 != -32768 )
        *v12 = (unsigned __int16)(((v14 <= 0) - 1) & 0xFFFE) - 32767;
      --v12;
      --v35;
    }
    while ( v35 );
  }
  v15 = (v36 * v11 + (*array72_a3 << 15) + 16384) >> 15;
  *array72_a3 = v15;
  v16 = v15 & 0xFFFF8000;
  if ( v16 && v16 != -32768 )
    *array72_a3 = (unsigned __int16)(((v16 <= 0) - 1) & 0xFFFE) - 32767;
  v17 = -normalize_bits_v10;
  dss2_normalize(array72_a3, v17, size);
  dss2_normalize(g_unc_rw_array15_3D0420, v17, 15);
  dss2_normalize(g_unc_rw_array15_3D045C, v17, 15);
  v18 = 0;
  if ( size > 0 )
  {
    v19 = array72_a3;
    v20 = size;
    do
    {
      v21 = *v19;
      if ( *v19 >= 0 )
        v18 += v21;
      else
        v18 -= v21;
      ++v19;
      --v20;
    }
    while ( v20 );
  }
  if ( v18 & 0xFFFFFFC0 )
    v22 = (v34 << 11) / v18;
  else
    v22 = 1;
  v23 = 409 * v22 >> 15 << 15;
  v24 = (v23 + 32358 * dword_3D0498) >> 15;
  v39 = v24;
  v25 = v24 & 0xFFFF8000;
  if ( v25 && v25 != -32768 )
    v39 = (unsigned __int16)(((v25 <= 0) - 1) & 0xFFFE) - 32767;
  if ( size > 1 )
  {
    local_rw_array_v41_ptr = local_rw_array_v41;
    size_v27 = size - 1;
    do
    {
      v28 = (v23 + 32358 * *(local_rw_array_v41_ptr - 1)) >> 15;
      *local_rw_array_v41_ptr = v28;
      v29 = v28 & 0xFFFF8000;
      if ( v29 && v29 != -32768 )
        *local_rw_array_v41_ptr = (unsigned __int16)(((v29 <= 0) - 1) & 0xFFFE) - 32767;
      ++local_rw_array_v41_ptr;
      --size_v27;
    }
    while ( size_v27 );
  }
  dword_3D0498 = local_rw_array15_v39[size + 14];// wrong array, should be v41
  if ( size > 0 )
  {
    array72_a4_v30 = array72_a4;
    v31 = size;
    do
    {
      v32 = *(__int32 *)((char *)array72_a4_v30 + (char *)&v39 - (char *)array72_a4)
          * *(__int32 *)((char *)array72_a4_v30 + (char *)&v39 - (char *)array72_a4 + (char *)array72_a3 - (char *)&v39) >> 11;
      *array72_a4_v30 = v32;
      v33 = v32 & 0xFFFF8000;
      if ( v33 )
      {
        if ( v33 != -32768 )
          *array72_a4_v30 = (unsigned __int16)(((v33 <= 0) - 1) & 0xFFFE) - 32767;
      }
      ++array72_a4_v30;
      --v31;
    }
    while ( v31 );
  }
}
