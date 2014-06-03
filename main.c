
#include <stdio.h>
#include <stdint.h>
#include "dss.h"
#define __int8 int8_t
#define __int16 int16_t

#define DSS_CBUF_SIZE 21

unsigned int word_3D1264;
unsigned int word_3D1266;
unsigned int word_3D041C;
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
  __int16 *abuff_swap_ptr_v3; // eax@2
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
  int v56; // [sp+18h] [bp-20h]@9
  int v57; // [sp+1Ch] [bp-1Ch]@9
  int v58; // [sp+20h] [bp-18h]@9
  int v59; // [sp+24h] [bp-14h]@9
  int v60; // [sp+28h] [bp-10h]@9
  int v61; // [sp+2Ch] [bp-Ch]@9
  int v62; // [sp+30h] [bp-8h]@9
  int v63; // [sp+34h] [bp-4h]@9
  __int16 *reconstr_abuffa; // [sp+3Ch] [bp+4h]@0
  __int16 *reconstr_abuffb; // [sp+3Ch] [bp+4h]@7
  __int16 *abuff_swap_ptr; // [sp+40h] [bp+8h]@0
  __int16 *abuff_swap_ptra; // [sp+40h] [bp+8h]@12
  __int8 *abuff_swap_ptrb; // [sp+40h] [bp+8h]@22
  __int8 *abuff_swap_ptrc; // [sp+40h] [bp+8h]@27
  int i;

  v2 = 0;
  if ( word_3D041C )
  {
    abuff_swap_ptr_v3 = abuff_swap_ptr;
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
    abuff_swap_ptr_v3 = abuff_swap_ptr;
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

  reconstr_abuff_v4[19] = (abuff_swap_ptr_v3[3] >> 7) & 0x1F;
  *((_DWORD *)reconstr_abuff_v4 + 13) = *((_BYTE *)abuff_swap_ptr_v3 + 11)
		  + ((abuff_swap_ptr_v3[4] + ((abuff_swap_ptr_v3[3] & 0x7F) << 16)) << 8);
  reconstr_abuff_v4[24] = (abuff_swap_ptr_v3[5] >> 2) & 0x3F;
  reconstr_abuff_v4[35] = ((abuff_swap_ptr_v3[6] >> 15) & 1) + 2 * (abuff_swap_ptr_v3[5] & 3);
  reconstr_abuff_v4[36] = (abuff_swap_ptr_v3[6] >> 12) & 7;
  reconstr_abuff_v4[37] = (abuff_swap_ptr_v3[6] >> 9) & 7;
  reconstr_abuff_v4[38] = (abuff_swap_ptr_v3[6] >> 6) & 7;
  reconstr_abuff_v4[39] = (abuff_swap_ptr_v3[6] >> 3) & 7;
  reconstr_abuff_v4[40] = abuff_swap_ptr_v3[6] & 7;
  reconstr_abuff_v4[41] = (abuff_swap_ptr_v3[7] >> 13) & 7;

  reconstr_abuff_v4[20] = (abuff_swap_ptr_v3[7] >> 8) & 0x1F;

  reconstr_abuff_v4[11] = ((abuff_swap_ptr_v3[9] >> 9) & 0x7F)
		  + ((abuff_swap_ptr_v3[8] + (abuff_swap_ptr_v3[7] << 16)) << 7);
  reconstr_abuff_v4[42] = (abuff_swap_ptr_v3[9] >> 3) & 0x3F;
  reconstr_abuff_v4[53] = abuff_swap_ptr_v3[9] & 7;
  reconstr_abuff_v4[54] = (abuff_swap_ptr_v3[10] >> 13) & 7;
  reconstr_abuff_v4[55] = (abuff_swap_ptr_v3[10] >> 10) & 7;
  reconstr_abuff_v4[56] = (abuff_swap_ptr_v3[10] >> 7) & 7;
  reconstr_abuff_v4[57] = (abuff_swap_ptr_v3[10] >> 4) & 7;
  reconstr_abuff_v4[58] = (abuff_swap_ptr_v3[10] >> 1) & 7;
  reconstr_abuff_v4[59] = ((abuff_swap_ptr_v3[11] >> 14) & 3)
		  + 4 * (abuff_swap_ptr_v3[10] & 1);
  reconstr_abuff_v4[21] = (abuff_swap_ptr_v3[11] >> 9) & 0x1F;

  v23 = abuff_swap_ptr_v3[12] + ((abuff_swap_ptr_v3[11] & 0x1FF) << 16);
  v24 = ((abuff_swap_ptr_v3[13] >> 10) & 0x3F) + (v23 << 6);
  *((_DWORD *)reconstr_abuff_v4 + 31) = v24;

  reconstr_abuff_v4[60] = (abuff_swap_ptr_v3[13] >> 4) & 0x3F;
  reconstr_abuff_v4[71] = (abuff_swap_ptr_v3[13] >> 1) & 7;
  reconstr_abuff_v4[72] = ((abuff_swap_ptr_v3[14] >> 14) & 3)
		  + 4 * (abuff_swap_ptr_v3[14] & 1);
  reconstr_abuff_v4[73] = (abuff_swap_ptr_v3[14] >> 11) & 7;
  reconstr_abuff_v4[74] = (abuff_swap_ptr_v3[14] >> 8) & 7;
  reconstr_abuff_v4[75] = (abuff_swap_ptr_v3[14] >> 5) & 7;
  reconstr_abuff_v4[76] = (abuff_swap_ptr_v3[14] >> 2) & 7;
  reconstr_abuff_v4[77] = ((abuff_swap_ptr_v3[15] >> 15) & 1)
		  + 2 * (abuff_swap_ptr_v3[14] & 3);
  reconstr_abuff_v4[22] = (abuff_swap_ptr_v3[15] >> 10) & 0x1F;
  reconstr_abuffb = 0;


  reconstr_abuff_v4[20] = ((abuff_swap_ptr_v3[17] >> 11) & 0x1F)
		  + 32 * (abuff_swap_ptr_v3[16] + ((abuff_swap_ptr_v3[15] & 0x3FF) << 16));
  reconstr_abuff_v4[78] = (abuff_swap_ptr_v3[17] >> 5) & 0x3F;
  reconstr_abuff_v4[89] = (abuff_swap_ptr_v3[17] >> 2) & 7;
  reconstr_abuff_v4[90] = ((abuff_swap_ptr_v3[18] >> 15) & 1)
		  + 2 * (abuff_swap_ptr_v3[17] & 3);
  reconstr_abuff_v4[91] = (abuff_swap_ptr_v3[18] >> 12) & 7;
  reconstr_abuff_v4[92] = (abuff_swap_ptr_v3[18] >> 9) & 7;
  reconstr_abuff_v4[93] = (abuff_swap_ptr_v3[18] >> 6) & 7;
  reconstr_abuff_v4[94] = (abuff_swap_ptr_v3[18] >> 3) & 7;
  reconstr_abuff_v4[95] = abuff_swap_ptr_v3[18] & 7;
  v30 = &reconstr_abuff_v4[13];
  v53 = &reconstr_abuff_v4[13];

  v52 = 0;
  v55 = 4;
////////////////////////////////////////////////////////////////////
  while ( 1 )
  {
    v31 = *(_DWORD *)v30;
    v56[0] = 72;
    v56[1] = 2556;
    v56[2] = 59640;
    v56[3] = 1028790;
    v56[4] = 13991544;
    v56[5] = 156238908;
    v56[6] = 1473109704;
    v56[7] = -915885543;
    if ( v31 <= 1473109703 )
      if ( word_3D0C26 != v2 )
        goto LABEL_22;
    else
      word_3D0C26 = v2;

    v32 = &v56[7];
    v33 = 7;
    v30[8] = v2;
    abuff_swap_ptra = 71;
    v54 = &v56[7];
    for (i = 71; i >= 0; i--) {
      if ( (signed int)*(v32 - 1) <= v31 )
      {
        --v33;
        v32 = &v56[v33];
        v31 -= v56[v33];
        v54 = &v56[v33];
        reconstr_abuff_v4[v52 - v33 + 34] = abuff_swap_ptra;
        if (!v33)
          break;
      }
      --v56[0];
      if ( v33 > 1 )
      {
        v34 = &v56[1];
        v35 = v33 - 1;
        do
        {
          *v34 -= *(v34 - 1);
          ++v34;
          --v35;
        }
        while ( v35 );
        v32 = v54;
      }
    };


    if ( word_3D0C26 )
    {
      v30 = v53;
LABEL_22:
      v36 = *(_DWORD *)v30;
      v37 = 7;
      v38 = 71;
      v39 = 504;

      for (i = 7; i > 0; i--) {
        for ( ; v36 < g_unc_combinatorial_table[v39 + v38]; --v38 )
          ;
        v40 = v39 + v38;
        v39 -= 72;
        v36 -= g_unc_combinatorial_table[v40];
        v41 = 18 * (_DWORD)reconstr_abuffb - v37--;
        reconstr_abuff_v4[v41 + 35] = v38;
      }
    }
    v30 = v53 + 18;
    v42 = v55 == 1;
    reconstr_abuffb = (__int16 *)((char *)reconstr_abuffb + 1);
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

  v43 = abuff_swap_ptr_v3[19];
  v44 = &reconstr_abuff_v4[8];

  v46 = ((v43 << 8) + *((int8_t *)abuff_swap_ptr_v3 + 41)) / 151;
  reconstr_abuff_v4[15] = ((v43 << 8) + *((int8_t *)abuff_swap_ptr_v3 + 41)) % 151 + 36;
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
