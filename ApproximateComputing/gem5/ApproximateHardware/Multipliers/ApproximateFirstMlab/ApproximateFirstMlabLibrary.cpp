#include<stdint.h>
int or (int a, int b){return (a | b);}
int and (int a, int b){return (a & b);}
int xor (int a, int b){return (a ^ b);}
int not (int a){return (a ^ 1);}
int buf (int a){return (a);}
void AND2_X1 ( int A1, int A2, int* ZN){
 *ZN=and(  A1, A2);
}

void AND2_X2 ( int A1, int A2, int* ZN){
 *ZN=and(  A1, A2);
}

void AND2_X4 ( int A1, int A2, int* ZN){
 *ZN=and(  A1, A2);
}

void AND3_X1 ( int A1, int A2, int A3, int* ZN){
 int i_4=and(  A1, A2);
 *ZN=and(  i_4, A3);
}

void AND3_X2 ( int A1, int A2, int A3, int* ZN){
 int i_4=and(  A1, A2);
 *ZN=and(  i_4, A3);
}

void AND3_X4 ( int A1, int A2, int A3, int* ZN){
 int i_4=and(  A1, A2);
 *ZN=and(  i_4, A3);
}

void AND4_X1 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_9=and(  A1, A2);
 int i_8=and(  i_9, A3);
 *ZN=and(  i_8, A4);
}

void AND4_X2 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_9=and(  A1, A2);
 int i_8=and(  i_9, A3);
 *ZN=and(  i_8, A4);
}

void AND4_X4 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_9=and(  A1, A2);
 int i_8=and(  i_9, A3);
 *ZN=and(  i_8, A4);
}

void ANTENNA_X1 ( int A){
}

void AOI211_X1 ( int A, int B, int C1, int C2, int* ZN){
 int i_14=and(  C1, C2);
 int i_13=or(  i_14, B);
 int i_12=or(  i_13, A);
 *ZN=not(  i_12);
}

void AOI211_X2 ( int A, int B, int C1, int C2, int* ZN){
 int i_14=and(  C1, C2);
 int i_13=or(  i_14, B);
 int i_12=or(  i_13, A);
 *ZN=not(  i_12);
}

void AOI211_X4 ( int A, int B, int C1, int C2, int* ZN){
 int i_24=and(  C1, C2);
 int i_23=or(  i_24, B);
 int i_22=or(  i_23, A);
 int i_21=not(  i_22);
 int i_20=not(  i_21);
 *ZN=not(  i_20);
}

void AOI21_X1 ( int A, int B1, int B2, int* ZN){
 int i_9=and(  B1, B2);
 int i_8=or(  A, i_9);
 *ZN=not(  i_8);
}

void AOI21_X2 ( int A, int B1, int B2, int* ZN){
 int i_9=and(  B1, B2);
 int i_8=or(  A, i_9);
 *ZN=not(  i_8);
}

void AOI21_X4 ( int A, int B1, int B2, int* ZN){
 int i_9=and(  B1, B2);
 int i_8=or(  A, i_9);
 *ZN=not(  i_8);
}

void AOI221_X1 ( int A, int B1, int B2, int C1, int C2, int* ZN){
 int i_18=and(  C1, C2);
 int i_17=or(  i_18, A);
 int i_19=and(  B1, B2);
 int i_16=or(  i_17, i_19);
 *ZN=not(  i_16);
}

void AOI221_X2 ( int A, int B1, int B2, int C1, int C2, int* ZN){
 int i_18=and(  C1, C2);
 int i_17=or(  i_18, A);
 int i_19=and(  B1, B2);
 int i_16=or(  i_17, i_19);
 *ZN=not(  i_16);
}

void AOI221_X4 ( int A, int B1, int B2, int C1, int C2, int* ZN){
 int i_28=and(  C1, C2);
 int i_27=or(  i_28, A);
 int i_29=and(  B1, B2);
 int i_26=or(  i_27, i_29);
 int i_25=not(  i_26);
 int i_24=not(  i_25);
 *ZN=not(  i_24);
}

void AOI222_X1 ( int A1, int A2, int B1, int B2, int C1, int C2, int* ZN){
 int i_22=and(  A1, A2);
 int i_23=and(  B1, B2);
 int i_21=or(  i_22, i_23);
 int i_24=and(  C1, C2);
 int i_20=or(  i_21, i_24);
 *ZN=not(  i_20);
}

void AOI222_X2 ( int A1, int A2, int B1, int B2, int C1, int C2, int* ZN){
 int i_22=and(  A1, A2);
 int i_23=and(  B1, B2);
 int i_21=or(  i_22, i_23);
 int i_24=and(  C1, C2);
 int i_20=or(  i_21, i_24);
 *ZN=not(  i_20);
}

void AOI222_X4 ( int A1, int A2, int B1, int B2, int C1, int C2, int* ZN){
 int i_32=and(  A1, A2);
 int i_33=and(  B1, B2);
 int i_31=or(  i_32, i_33);
 int i_34=and(  C1, C2);
 int i_30=or(  i_31, i_34);
 int i_29=not(  i_30);
 int i_28=not(  i_29);
 *ZN=not(  i_28);
}

void AOI22_X1 ( int A1, int A2, int B1, int B2, int* ZN){
 int i_13=and(  A1, A2);
 int i_14=and(  B1, B2);
 int i_12=or(  i_13, i_14);
 *ZN=not(  i_12);
}

void AOI22_X2 ( int A1, int A2, int B1, int B2, int* ZN){
 int i_13=and(  A1, A2);
 int i_14=and(  B1, B2);
 int i_12=or(  i_13, i_14);
 *ZN=not(  i_12);
}

void AOI22_X4 ( int A1, int A2, int B1, int B2, int* ZN){
 int i_13=and(  A1, A2);
 int i_14=and(  B1, B2);
 int i_12=or(  i_13, i_14);
 *ZN=not(  i_12);
}

void BUF_X1 ( int A, int* Z){
 *Z=buf(  A);
}

void BUF_X16 ( int A, int* Z){
 *Z=buf(  A);
}

void BUF_X2 ( int A, int* Z){
 *Z=buf(  A);
}

void BUF_X32 ( int A, int* Z){
 *Z=buf(  A);
}

void BUF_X4 ( int A, int* Z){
 *Z=buf(  A);
}

void BUF_X8 ( int A, int* Z){
 *Z=buf(  A);
}

void CLKBUF_X1 ( int A, int* Z){
 *Z=buf(  A);
}

void CLKBUF_X2 ( int A, int* Z){
 *Z=buf(  A);
}

void CLKBUF_X3 ( int A, int* Z){
 *Z=buf(  A);
}

void DFFRS_X1 ( int D, int RN, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void DFFRS_X2 ( int D, int RN, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void DFFR_X1 ( int D, int RN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void DFFR_X2 ( int D, int RN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void DFFS_X1 ( int D, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void DFFS_X2 ( int D, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void DFF_X1 ( int D, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void DFF_X2 ( int D, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void FA_X1 ( int A, int B, int CI, int* CO, int* S){
 int i_16=and(  A, B);
 int i_18=or(  A, B);
 int i_17=and(  CI, i_18);
 *CO=or(  i_16, i_17);
 int i_22=xor(  A, B);
 *S=xor(  CI, i_22);
}

void HA_X1 ( int A, int B, int* CO, int* S){
 *CO=and(  A, B);
 *S=xor(  A, B);
}

void INV_X1 ( int A, int* ZN){
 *ZN=not(  A);
}

void INV_X16 ( int A, int* ZN){
 *ZN=not(  A);
}

void INV_X2 ( int A, int* ZN){
 *ZN=not(  A);
}

void INV_X32 ( int A, int* ZN){
 *ZN=not(  A);
}

void INV_X4 ( int A, int* ZN){
 *ZN=not(  A);
}

void INV_X8 ( int A, int* ZN){
 *ZN=not(  A);
}

void LOGIC0_X1 ( int* Z){
}

void LOGIC1_X1 ( int* Z){
}

void MUX2_X1 ( int A, int B, int S, int* Z){
 int i_12=and(  S, B);
 int i_14=not(  S);
 int i_13=and(  A, i_14);
 *Z=or(  i_12, i_13);
}

void MUX2_X2 ( int A, int B, int S, int* Z){
 int i_12=and(  S, B);
 int i_14=not(  S);
 int i_13=and(  A, i_14);
 *Z=or(  i_12, i_13);
}

void NAND2_X1 ( int A1, int A2, int* ZN){
 int i_10=and(  A1, A2);
 *ZN=not(  i_10);
}

void NAND2_X2 ( int A1, int A2, int* ZN){
 int i_22=and(  A1, A2);
 *ZN=not(  i_22);
}

void NAND2_X4 ( int A1, int A2, int* ZN){
 int i_10=and(  A1, A2);
 *ZN=not(  i_10);
}

void NAND3_X1 ( int A1, int A2, int A3, int* ZN){
 int i_9=and(  A1, A2);
 int i_8=and(  i_9, A3);
 *ZN=not(  i_8);
}

void NAND3_X2 ( int A1, int A2, int A3, int* ZN){
 int i_9=and(  A1, A2);
 int i_8=and(  i_9, A3);
 *ZN=not(  i_8);
}

void NAND3_X4 ( int A1, int A2, int A3, int* ZN){
 int i_9=and(  A1, A2);
 int i_8=and(  i_9, A3);
 *ZN=not(  i_8);
}

void NAND4_X1 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_14=and(  A1, A2);
 int i_13=and(  i_14, A3);
 int i_12=and(  i_13, A4);
 *ZN=not(  i_12);
}

void NAND4_X2 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_14=and(  A1, A2);
 int i_13=and(  i_14, A3);
 int i_12=and(  i_13, A4);
 *ZN=not(  i_12);
}

void NAND4_X4 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_14=and(  A1, A2);
 int i_13=and(  i_14, A3);
 int i_12=and(  i_13, A4);
 *ZN=not(  i_12);
}

void NOR2_X1 ( int A1, int A2, int* ZN){
 int i_10=or(  A1, A2);
 *ZN=not(  i_10);
}

void NOR2_X2 ( int A1, int A2, int* ZN){
 int i_10=or(  A1, A2);
 *ZN=not(  i_10);
}

void NOR2_X4 ( int A1, int A2, int* ZN){
 int i_16=or(  A1, A2);
 *ZN=not(  i_16);
}

void NOR3_X1 ( int A1, int A2, int A3, int* ZN){
 int i_9=or(  A1, A2);
 int i_8=or(  i_9, A3);
 *ZN=not(  i_8);
}

void NOR3_X2 ( int A1, int A2, int A3, int* ZN){
 int i_9=or(  A1, A2);
 int i_8=or(  i_9, A3);
 *ZN=not(  i_8);
}

void NOR3_X4 ( int A1, int A2, int A3, int* ZN){
 int i_9=or(  A1, A2);
 int i_8=or(  i_9, A3);
 *ZN=not(  i_8);
}

void NOR4_X1 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_14=or(  A1, A2);
 int i_13=or(  i_14, A3);
 int i_12=or(  i_13, A4);
 *ZN=not(  i_12);
}

void NOR4_X2 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_14=or(  A1, A2);
 int i_13=or(  i_14, A3);
 int i_12=or(  i_13, A4);
 *ZN=not(  i_12);
}

void NOR4_X4 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_14=or(  A1, A2);
 int i_13=or(  i_14, A3);
 int i_12=or(  i_13, A4);
 *ZN=not(  i_12);
}

void OAI211_X1 ( int A, int B, int C1, int C2, int* ZN){
 int i_14=or(  C1, C2);
 int i_13=and(  i_14, A);
 int i_12=and(  i_13, B);
 *ZN=not(  i_12);
}

void OAI211_X2 ( int A, int B, int C1, int C2, int* ZN){
 int i_14=or(  C1, C2);
 int i_13=and(  i_14, A);
 int i_12=and(  i_13, B);
 *ZN=not(  i_12);
}

void OAI211_X4 ( int A, int B, int C1, int C2, int* ZN){
 int i_14=or(  C1, C2);
 int i_13=and(  i_14, A);
 int i_12=and(  i_13, B);
 *ZN=not(  i_12);
}

void OAI21_X1 ( int A, int B1, int B2, int* ZN){
 int i_9=or(  B1, B2);
 int i_8=and(  A, i_9);
 *ZN=not(  i_8);
}

void OAI21_X2 ( int A, int B1, int B2, int* ZN){
 int i_9=or(  B1, B2);
 int i_8=and(  A, i_9);
 *ZN=not(  i_8);
}

void OAI21_X4 ( int A, int B1, int B2, int* ZN){
 int i_9=or(  B1, B2);
 int i_8=and(  A, i_9);
 *ZN=not(  i_8);
}

void OAI221_X1 ( int A, int B1, int B2, int C1, int C2, int* ZN){
 int i_18=or(  C1, C2);
 int i_17=and(  i_18, A);
 int i_19=or(  B1, B2);
 int i_16=and(  i_17, i_19);
 *ZN=not(  i_16);
}

void OAI221_X2 ( int A, int B1, int B2, int C1, int C2, int* ZN){
 int i_18=or(  C1, C2);
 int i_17=and(  i_18, A);
 int i_19=or(  B1, B2);
 int i_16=and(  i_17, i_19);
 *ZN=not(  i_16);
}

void OAI221_X4 ( int A, int B1, int B2, int C1, int C2, int* ZN){
 int i_28=or(  C1, C2);
 int i_27=and(  i_28, A);
 int i_29=or(  B1, B2);
 int i_26=and(  i_27, i_29);
 int i_25=not(  i_26);
 int i_24=not(  i_25);
 *ZN=not(  i_24);
}

void OAI222_X1 ( int A1, int A2, int B1, int B2, int C1, int C2, int* ZN){
 int i_22=or(  A1, A2);
 int i_23=or(  B1, B2);
 int i_21=and(  i_22, i_23);
 int i_24=or(  C1, C2);
 int i_20=and(  i_21, i_24);
 *ZN=not(  i_20);
}

void OAI222_X2 ( int A1, int A2, int B1, int B2, int C1, int C2, int* ZN){
 int i_22=or(  A1, A2);
 int i_23=or(  B1, B2);
 int i_21=and(  i_22, i_23);
 int i_24=or(  C1, C2);
 int i_20=and(  i_21, i_24);
 *ZN=not(  i_20);
}

void OAI222_X4 ( int A1, int A2, int B1, int B2, int C1, int C2, int* ZN){
 int i_32=or(  A1, A2);
 int i_33=or(  B1, B2);
 int i_31=and(  i_32, i_33);
 int i_34=or(  C1, C2);
 int i_30=and(  i_31, i_34);
 int i_29=not(  i_30);
 int i_28=not(  i_29);
 *ZN=not(  i_28);
}

void OAI22_X1 ( int A1, int A2, int B1, int B2, int* ZN){
 int i_13=or(  A1, A2);
 int i_14=or(  B1, B2);
 int i_12=and(  i_13, i_14);
 *ZN=not(  i_12);
}

void OAI22_X2 ( int A1, int A2, int B1, int B2, int* ZN){
 int i_13=or(  A1, A2);
 int i_14=or(  B1, B2);
 int i_12=and(  i_13, i_14);
 *ZN=not(  i_12);
}

void OAI22_X4 ( int A1, int A2, int B1, int B2, int* ZN){
 int i_13=or(  A1, A2);
 int i_14=or(  B1, B2);
 int i_12=and(  i_13, i_14);
 *ZN=not(  i_12);
}

void OAI33_X1 ( int A1, int A2, int A3, int B1, int B2, int B3, int* ZN){
 int i_22=or(  A1, A2);
 int i_21=or(  i_22, A3);
 int i_24=or(  B1, B2);
 int i_23=or(  i_24, B3);
 int i_20=and(  i_21, i_23);
 *ZN=not(  i_20);
}

void OR2_X1 ( int A1, int A2, int* ZN){
 *ZN=or(  A1, A2);
}

void OR2_X2 ( int A1, int A2, int* ZN){
 *ZN=or(  A1, A2);
}

void OR2_X4 ( int A1, int A2, int* ZN){
 *ZN=or(  A1, A2);
}

void OR3_X1 ( int A1, int A2, int A3, int* ZN){
 int i_4=or(  A1, A2);
 *ZN=or(  i_4, A3);
}

void OR3_X2 ( int A1, int A2, int A3, int* ZN){
 int i_4=or(  A1, A2);
 *ZN=or(  i_4, A3);
}

void OR3_X4 ( int A1, int A2, int A3, int* ZN){
 int i_4=or(  A1, A2);
 *ZN=or(  i_4, A3);
}

void OR4_X1 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_9=or(  A1, A2);
 int i_8=or(  i_9, A3);
 *ZN=or(  i_8, A4);
}

void OR4_X2 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_9=or(  A1, A2);
 int i_8=or(  i_9, A3);
 *ZN=or(  i_8, A4);
}

void OR4_X4 ( int A1, int A2, int A3, int A4, int* ZN){
 int i_9=or(  A1, A2);
 int i_8=or(  i_9, A3);
 *ZN=or(  i_8, A4);
}

void SDFFRS_X1 ( int D, int RN, int SE, int SI, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void SDFFRS_X2 ( int D, int RN, int SE, int SI, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void SDFFR_X1 ( int D, int RN, int SE, int SI, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void SDFFR_X2 ( int D, int RN, int SE, int SI, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void SDFFS_X1 ( int D, int SE, int SI, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void SDFFS_X2 ( int D, int SE, int SI, int SN, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void SDFF_X1 ( int D, int SE, int SI, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void SDFF_X2 ( int D, int SE, int SI, int CK, int* Q, int* QN){
 *Q=buf(D);
 *QN=not(D);
}

void XNOR2_X1 ( int A, int B, int* ZN){
 int i_4=xor(  A, B);
 *ZN=not(  i_4);
}

void XNOR2_X2 ( int A, int B, int* ZN){
 int i_4=xor(  A, B);
 *ZN=not(  i_4);
}

void XOR2_X1 ( int A, int B, int* Z){
 *Z=xor(  A, B);
}

void XOR2_X2 ( int A, int B, int* Z){
 *Z=xor(  A, B);
}

