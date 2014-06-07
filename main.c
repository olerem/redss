
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
unsigned int flip;


void g_unc_byte_swap(__int8 *abuff_swap, __int8 **abuff_src, int dec_flag)
{
  uint8_t *abuff_tmp;
  int size; // si@1
  int i;

  word_3D1264 = 1;
  abuff_tmp = *abuff_src;
  size = DSS_CBUF_SIZE;
  if (flip)
  {
	  unsigned int tmp = abuff_tmp[0];
#if 0
    if (dec_flag & 2 && !(tmp & 0x80) )
    {
      size = 5;
      word_3D1264 = 0;
    }
#endif
    abuff_tmp++;

    for (i = 0; i < size - 1; i++)
    {
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
    if ( dec_flag & 2 && !(*(abuff_tmp - 1) & 0x80) )// Never executed
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

void g_unc_sub_3B9120(uint16_t *reconstr_abuff, int16_t *abuff_swap_a2)
{
  __int16 v2; // bp@1
  __int16 *abuff_swap_ptr; // eax@2
  __int16 *reconstr_abuff_v4; // esi@2
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
  __int16 *reconstr_abuffa; // [sp+3Ch] [bp+4h]@0
  __int16 *abuff_swap_ptra; // [sp+40h] [bp+8h]@12
  __int8 *abuff_swap_ptrb; // [sp+40h] [bp+8h]@22
  __int8 *abuff_swap_ptrc; // [sp+40h] [bp+8h]@27
  int i;

  v2 = 0;
  if ( word_3D041C )
  {
    abuff_swap_ptr = abuff_swap_ptr;
    reconstr_abuff_v4 = reconstr_abuffa;

    v5 = (abuff_swap_ptr[0] >> 15) & 1;
    reconstr_abuffa[0] = v5;
    word_3D1264 = v5;
    reconstr_abuffa[1] = (abuff_swap_ptr[0] >> 10) & 0x1F;
    reconstr_abuffa[2] = (abuff_swap_ptr[0] >> 5) & 0x1F;
    reconstr_abuffa[3] = (abuff_swap_ptr[0] >> 1) & 0xF;
    reconstr_abuffa[4] = ((abuff_swap_ptr[1] >> 13) & 7)
    		+ 8 * (abuff_swap_ptr[0] & 1);

    reconstr_abuffa[5] = (abuff_swap_ptr[1] >> 9) & 0xF;
    reconstr_abuffa[6] = (abuff_swap_ptr[1] >> 5) & 0xF;
    reconstr_abuffa[7] = (abuff_swap_ptr[1] >> 1) & 0xF;
    reconstr_abuffa[8] = ((abuff_swap_ptr[2] >> 13) & 7)
    		+ 8 * (abuff_swap_ptr[1] & 1);

    reconstr_abuffa[9] = (abuff_swap_ptr[2] >> 10) & 7;
    reconstr_abuffa[10] = (abuff_swap_ptr[2] >> 7) & 7;
    reconstr_abuffa[11] = (abuff_swap_ptr[2] >> 4) & 7;
    reconstr_abuffa[12] = (abuff_swap_ptr[2] >> 1) & 7;
    reconstr_abuffa[13] = ((abuff_swap_ptr[3] >> 14) & 3)
    		+ 4 * (abuff_swap_ptr[2] & 1);

    v12 = (abuff_swap_ptr[3] >> 12) & 3;
  }
  else
  {
    abuff_swap_ptr = abuff_swap_ptr;
    reconstr_abuff_v4 = reconstr_abuffa;
    word_3D1264 = 1;

    reconstr_abuffa[1] = (abuff_swap_ptr[0] >> 11) & 0x1F;
    reconstr_abuffa[2] = (abuff_swap_ptr[0] >> 6) & 0x1F;
    reconstr_abuffa[3] = (abuff_swap_ptr[0] >> 2) & 0xF;
    reconstr_abuffa[4] = ((abuff_swap_ptr[1] >> 14) & 3)
    		+ 4 * (abuff_swap_ptr[0] & 3);

    reconstr_abuffa[5] = (abuff_swap_ptr[1] >> 10) & 0xF;
    reconstr_abuffa[6] = (abuff_swap_ptr[1] >> 6) & 0xF;
    reconstr_abuffa[7] = (abuff_swap_ptr[1] >> 2) & 0xF;
    reconstr_abuffa[8] = ((abuff_swap_ptr[2] >> 14) & 3)
    		+ 4 * (abuff_swap_ptr[1] & 3);

    reconstr_abuffa[9] = (abuff_swap_ptr[2] >> 11) & 7;
    reconstr_abuffa[10] = (abuff_swap_ptr[2] >> 8) & 7;
    reconstr_abuffa[11] = (abuff_swap_ptr[2] >> 5) & 7;
    reconstr_abuffa[12] = (abuff_swap_ptr[2] >> 2) & 7;
    reconstr_abuffa[13] = ((abuff_swap_ptr[3] >> 15) & 1)
    		+ 2 * (abuff_swap_ptr[2] & 3);

    v12 = (abuff_swap_ptr[3] >> 12) & 7;
  }

  reconstr_abuff[14] = v12;
  if ( word_3D041C && !word_3D1264 )
  {
    reconstr_abuff[19] = (abuff_swap_ptr[3] >> 7) & 0x1F;
    reconstr_abuff[20] = (abuff_swap_ptr[3] >> 2) & 0x1F;
    reconstr_abuff[21] = (abuff_swap_ptr[4] >> 13) & 7;
    reconstr_abuff[22] = (abuff_swap_ptr[4] >> 8) & 0x1F;
    return;
  }

  reconstr_abuff_v4[19] = (abuff_swap_ptr[3] >> 7) & 0x1F;
  // instead of "*((uint8_t *)abuff_swap_ptr + 11)" can be "(abuff_swap_ptr[5] >> 8) & 0xf"
  reconstr_abuff_v4[26] = *((uint8_t *)abuff_swap_ptr + 11)
		  + ((abuff_swap_ptr[4] + ((abuff_swap_ptr[3] & 0x7F) << 16)) << 8);
  reconstr_abuff_v4[24] = (abuff_swap_ptr[5] >> 2) & 0x3F;
  reconstr_abuff_v4[35] = ((abuff_swap_ptr[6] >> 15) & 1) + 2 * (abuff_swap_ptr[5] & 3);
  reconstr_abuff_v4[36] = (abuff_swap_ptr[6] >> 12) & 7;
  reconstr_abuff_v4[37] = (abuff_swap_ptr[6] >> 9) & 7;
  reconstr_abuff_v4[38] = (abuff_swap_ptr[6] >> 6) & 7;
  reconstr_abuff_v4[39] = (abuff_swap_ptr[6] >> 3) & 7;
  reconstr_abuff_v4[40] = abuff_swap_ptr[6] & 7;
  reconstr_abuff_v4[41] = (abuff_swap_ptr[7] >> 13) & 7;

  reconstr_abuff_v4[20] = (abuff_swap_ptr[7] >> 8) & 0x1F;

  reconstr_abuff_v4[44] = ((abuff_swap_ptr[9] >> 9) & 0x7F)
		  + ((abuff_swap_ptr[8] + (abuff_swap_ptr[7] << 16)) << 7);
  reconstr_abuff_v4[42] = (abuff_swap_ptr[9] >> 3) & 0x3F;
  reconstr_abuff_v4[53] = abuff_swap_ptr[9] & 7;
  reconstr_abuff_v4[54] = (abuff_swap_ptr[10] >> 13) & 7;
  reconstr_abuff_v4[55] = (abuff_swap_ptr[10] >> 10) & 7;
  reconstr_abuff_v4[56] = (abuff_swap_ptr[10] >> 7) & 7;
  reconstr_abuff_v4[57] = (abuff_swap_ptr[10] >> 4) & 7;
  reconstr_abuff_v4[58] = (abuff_swap_ptr[10] >> 1) & 7;
  reconstr_abuff_v4[59] = ((abuff_swap_ptr[11] >> 14) & 3)
		  + 4 * (abuff_swap_ptr[10] & 1);

  reconstr_abuff_v4[21] = (abuff_swap_ptr[11] >> 9) & 0x1F;

  reconstr_abuff_v4[62] = ((abuff_swap_ptr[13] >> 10) & 0x3F)
  	  	  + ((abuff_swap_ptr[12] + ((abuff_swap_ptr[11] & 0x1FF) << 16)) << 6);

  reconstr_abuff_v4[60] = (abuff_swap_ptr[13] >> 4) & 0x3F;
  reconstr_abuff_v4[71] = (abuff_swap_ptr[13] >> 1) & 7;
  reconstr_abuff_v4[72] = ((abuff_swap_ptr[14] >> 14) & 3)
		  + 4 * (abuff_swap_ptr[14] & 1);
  reconstr_abuff_v4[73] = (abuff_swap_ptr[14] >> 11) & 7;
  reconstr_abuff_v4[74] = (abuff_swap_ptr[14] >> 8) & 7;
  reconstr_abuff_v4[75] = (abuff_swap_ptr[14] >> 5) & 7;
  reconstr_abuff_v4[76] = (abuff_swap_ptr[14] >> 2) & 7;
  reconstr_abuff_v4[77] = ((abuff_swap_ptr[15] >> 15) & 1)
		  + 2 * (abuff_swap_ptr[14] & 3);

  reconstr_abuff_v4[22] = (abuff_swap_ptr[15] >> 10) & 0x1F;

  reconstr_abuff_v4[80] = ((abuff_swap_ptr[17] >> 11) & 0x1F)
		  + 32 * (abuff_swap_ptr[16] + ((abuff_swap_ptr[15] & 0x3FF) << 16));
  reconstr_abuff_v4[78] = (abuff_swap_ptr[17] >> 5) & 0x3F;
  reconstr_abuff_v4[89] = (abuff_swap_ptr[17] >> 2) & 7;
  reconstr_abuff_v4[90] = ((abuff_swap_ptr[18] >> 15) & 1)
		  + 2 * (abuff_swap_ptr[17] & 3);
  reconstr_abuff_v4[91] = (abuff_swap_ptr[18] >> 12) & 7;
  reconstr_abuff_v4[92] = (abuff_swap_ptr[18] >> 9) & 7;
  reconstr_abuff_v4[93] = (abuff_swap_ptr[18] >> 6) & 7;
  reconstr_abuff_v4[94] = (abuff_swap_ptr[18] >> 3) & 7;
  reconstr_abuff_v4[95] = abuff_swap_ptr[18] & 7;
  v30 = &reconstr_abuff_v4[26];
  v53 = &reconstr_abuff_v4[26];

  v52 = 0;
  v55 = 4;
////////////////////////////////////////////////////////////////////
  int some_val = 0;
  while ( 1 )
  {
	/* looks like Binomial coefficients C(72,n). But 3379081753 do not fit to this sequence */
    unsigned int v56[8] = {72, 2556, 59640, 1028790, 13991544, 156238908, 1473109704, 3379081753};

    v31 = *(int16_t *)v30;

    if ( v31 < 1473109704 )
      if ( word_3D0C26 != v2 )
        goto LABEL_22;
    else
      word_3D0C26 = v2;

    v32 = &v56[7];
    v33 = 7;
    v30[8] = v2;
    v54 = &v56[7];
    for (i = 71; i >= 0; i--) {
      if ( (signed int)*(v32 - 1) <= v31 )
      {
        --v33;
        v32 = &v56[v33];
        v31 -= v56[v33];
        v54 = &v56[v33];
        reconstr_abuff_v4[v52 - v33 + 34] = i; //some structs, TODO
        // difference between start of each block is 18
        // 28, 29, 30, 31, 32, 33, 34,
        // 46, 47, 48, 49, 50, 51, 52,
        // 64, 65, 66, 67, 68, 69, 70,
        // 82, 83, 84, 85, 86, 87, 88,
        if (!v33)
          break;
      }
      --v56[0];
      if ( v33 > 1 )
      {
        int a = 1, b;
        for (b = v33 - 1 ; b > 0; b--) {
        	v56[a] -= v56[a - 1];
        	a++;
        }
        v32 = v54;
      }
    };


    if ( word_3D0C26 )
    {
      v30 = v53;
LABEL_22:
      v36 = *(_DWORD *)v30;
      v37 = 7;
      v38 = 71; //GRID_SIZE
      v39 = 7; //MAX_PULSES

      /* this part seems to be close to g723.1 gen_fcb_excitation() RATE_6300 */
      for (i = 7; i > 0; i--) {
        for ( ; v36 < g_unc_combinatorial_table[v39][v38]; --v38 )
          ;
        v36 -= g_unc_combinatorial_table[v39][v38];
        v39--;
        v41 = 18 * some_val - v37;
        v37--;
        reconstr_abuff_v4[v41 + 35] = v38; // on first run reconstr_abuff_v4[28],
        // difference between start of each block is 18
        // 28, 29, 30, 31, 32, 33, 34,
        // 46, 47, 48, 49, 50, 51, 52,
        // 64, 65, 66, 67, 68, 69, 70,
        // 82, 83, 84, 85, 86, 87, 88,
        //
      }
    }
    v30 = v53 + 18;
    v42 = v55 == 1;
    some_val = some_val + 1;
    v52 += 18;
    v53 += 18;
    --v55;
    if ( v42 )
      break;
    v2 = 0;
  }

/////////////////////////////////////////////////////////////////////////
  int16_t *v44;
  int16_t v43;

  v43 = abuff_swap_ptr[19];
  v44 = &reconstr_abuff_v4[8];

  v46 = ((v43 << 8) + *((int8_t *)abuff_swap_ptr + 41)) / 151;
  reconstr_abuff_v4[15] = ((v43 << 8) + *((int8_t *)abuff_swap_ptr + 41)) % 151 + 36;
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
    if ( v48 > 162 )
    {
      *v49 += 139;
    }
    else {
      v51 = v48 - 23;
      if ( v51 < 36 )
        v51 = 36;
      *v49 += v51;
    }
    v48 = *v49;
    v49++;
  }

}

void g_unc_sub_3B8740(int32_t *array14, int a2, int null_a3, int null_a4, int null_a5, int null_a6, int null_a7, int null_a8, __int16 a9)
{
  int v9; // ecx@1
  __int32 *array14_ptr; // edx@1
  __int16 *array14_v11; // eax@1
  signed int size; // esi@1
  int v13; // ebx@2
  int i;


  array14_ptr = array14;
  array14_v11 = (__int16 *)((char *)&a2 + 2);
  for (i = 0; i < 14; i++)
  {
    v13 = *array14_v11;
    ++array14_v11;
    ++array14_ptr;
    *(array14_ptr - 1) = g_unc_array_3C84F0[i][v13];
  }
  if ( word_3D041C )
    array14[13] = g_unc_array_3C8870[a9];
}
