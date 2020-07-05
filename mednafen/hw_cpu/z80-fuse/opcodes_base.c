/* opcodes_base.c: unshifted Z80 opcodes
   Copyright (c) 1999-2003 Philip Kendall

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

   Author contact information:

   E-mail: philip-fuse@shadowmagic.org.uk

*/

/* NB: this file is autogenerated by 'z80.pl' from 'opcodes_base.dat',
   and included in 'z80_ops.c' */

      case 0x00:		/* NOP */
         break;
      case 0x01:		/* LD BC,nnnn */
         C=Z80_RB_MACRO(PC++);
         B=Z80_RB_MACRO(PC++);
         break;
      case 0x02:		/* LD (BC),A */
         Z80_WB_MACRO(BC,A);
         break;
      case 0x03:		/* INC BC */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         BC++;
         break;
      case 0x04:		/* INC B */
         INC(B);
         break;
      case 0x05:		/* DEC B */
         DEC(B);
         break;
      case 0x06:		/* LD B,nn */
         B = Z80_RB_MACRO( PC++ );
         break;
      case 0x07:		/* RLCA */
         A = ( A << 1 ) | ( A >> 7 );
         F = ( F & ( Z80_FLAG_P | Z80_FLAG_Z | Z80_FLAG_S ) ) |
            ( A & ( Z80_FLAG_C | Z80_FLAG_3 | Z80_FLAG_5 ) );
         break;
      case 0x08:		/* EX AF,AF' */
         {
            uint16 wordtemp = AF; AF = AF_; AF_ = wordtemp;
         }
         break;
      case 0x09:		/* ADD HL,BC */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         ADD16(HL,BC);
         break;
      case 0x0a:		/* LD A,(BC) */
         A=Z80_RB_MACRO(BC);
         break;
      case 0x0b:		/* DEC BC */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         BC--;
         break;
      case 0x0c:		/* INC C */
         INC(C);
         break;
      case 0x0d:		/* DEC C */
         DEC(C);
         break;
      case 0x0e:		/* LD C,nn */
         C = Z80_RB_MACRO( PC++ );
         break;
      case 0x0f:		/* RRCA */
         F = ( F & ( Z80_FLAG_P | Z80_FLAG_Z | Z80_FLAG_S ) ) | ( A & Z80_FLAG_C );
         A = ( A >> 1) | ( A << 7 );
         F |= ( A & ( Z80_FLAG_3 | Z80_FLAG_5 ) );
         break;
      case 0x10:		/* DJNZ offset */
         contend_read_no_mreq( IR, 1 );
         B--;
         if(B) {
            JR();
         } else {
            contend_read( PC, 3 );
         }
         PC++;
         break;
      case 0x11:		/* LD DE,nnnn */
         E=Z80_RB_MACRO(PC++);
         D=Z80_RB_MACRO(PC++);
         break;
      case 0x12:		/* LD (DE),A */
         Z80_WB_MACRO(DE,A);
         break;
      case 0x13:		/* INC DE */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         DE++;
         break;
      case 0x14:		/* INC D */
         INC(D);
         break;
      case 0x15:		/* DEC D */
         DEC(D);
         break;
      case 0x16:		/* LD D,nn */
         D = Z80_RB_MACRO( PC++ );
         break;
      case 0x17:		/* RLA */
         {
            uint8_t bytetemp = A;
            A = ( A << 1 ) | ( F & Z80_FLAG_C );
            F = ( F & ( Z80_FLAG_P | Z80_FLAG_Z | Z80_FLAG_S ) ) |
               ( A & ( Z80_FLAG_3 | Z80_FLAG_5 ) ) | ( bytetemp >> 7 );
         }
         break;
      case 0x18:		/* JR offset */
         JR();
         PC++;
         break;
      case 0x19:		/* ADD HL,DE */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         ADD16(HL,DE);
         break;
      case 0x1a:		/* LD A,(DE) */
         A=Z80_RB_MACRO(DE);
         break;
      case 0x1b:		/* DEC DE */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         DE--;
         break;
      case 0x1c:		/* INC E */
         INC(E);
         break;
      case 0x1d:		/* DEC E */
         DEC(E);
         break;
      case 0x1e:		/* LD E,nn */
         E = Z80_RB_MACRO( PC++ );
         break;
      case 0x1f:		/* RRA */
         {
            uint8_t bytetemp = A;
            A = ( A >> 1 ) | ( F << 7 );
            F = ( F & ( Z80_FLAG_P | Z80_FLAG_Z | Z80_FLAG_S ) ) |
               ( A & ( Z80_FLAG_3 | Z80_FLAG_5 ) ) | ( bytetemp & Z80_FLAG_C ) ;
         }
         break;
      case 0x20:		/* JR NZ,offset */
         if( ! ( F & Z80_FLAG_Z ) ) {
            JR();
         } else {
            contend_read( PC, 3 );
         }
         PC++;
         break;
      case 0x21:		/* LD HL,nnnn */
         L=Z80_RB_MACRO(PC++);
         H=Z80_RB_MACRO(PC++);
         break;
      case 0x22:		/* LD (nnnn),HL */
         LD16_NNRR(L,H);
         break;
      case 0x23:		/* INC HL */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         HL++;
         break;
      case 0x24:		/* INC H */
         INC(H);
         break;
      case 0x25:		/* DEC H */
         DEC(H);
         break;
      case 0x26:		/* LD H,nn */
         H = Z80_RB_MACRO( PC++ );
         break;
      case 0x27:		/* DAA */
         {
            uint8_t add = 0, carry = ( F & Z80_FLAG_C );
            if( ( F & Z80_FLAG_H ) || ( ( A & 0x0f ) > 9 ) ) add = 6;
            if( carry || ( A > 0x99 ) ) add |= 0x60;
            if( A > 0x99 ) carry = Z80_FLAG_C;
            if( F & Z80_FLAG_N ) {
               SUB(add);
            } else {
               ADD(add);
            }
            F = ( F & ~( Z80_FLAG_C | Z80_FLAG_P ) ) | carry | parity_table[A];
         }
         break;
      case 0x28:		/* JR Z,offset */
         if( F & Z80_FLAG_Z ) {
            JR();
         } else {
            contend_read( PC, 3 );
         }
         PC++;
         break;
      case 0x29:		/* ADD HL,HL */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         ADD16(HL,HL);
         break;
      case 0x2a:		/* LD HL,(nnnn) */
         LD16_RRNN(L,H);
         break;
      case 0x2b:		/* DEC HL */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         HL--;
         break;
      case 0x2c:		/* INC L */
         INC(L);
         break;
      case 0x2d:		/* DEC L */
         DEC(L);
         break;
      case 0x2e:		/* LD L,nn */
         L = Z80_RB_MACRO( PC++ );
         break;
      case 0x2f:		/* CPL */
         A ^= 0xff;
         F = ( F & ( Z80_FLAG_C | Z80_FLAG_P | Z80_FLAG_Z | Z80_FLAG_S ) ) |
            ( A & ( Z80_FLAG_3 | Z80_FLAG_5 ) ) | ( Z80_FLAG_N | Z80_FLAG_H );
         break;
      case 0x30:		/* JR NC,offset */
         if( ! ( F & Z80_FLAG_C ) ) {
            JR();
         } else {
            contend_read( PC, 3 );
         }
         PC++;
         break;
      case 0x31:		/* LD SP,nnnn */
         SPL=Z80_RB_MACRO(PC++);
         SPH=Z80_RB_MACRO(PC++);
         break;
      case 0x32:		/* LD (nnnn),A */
         {
            uint16 wordtemp = Z80_RB_MACRO( PC++ );
            wordtemp|=Z80_RB_MACRO(PC++) << 8;
            Z80_WB_MACRO(wordtemp,A);
         }
         break;
      case 0x33:		/* INC SP */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         SP++;
         break;
      case 0x34:		/* INC (HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            contend_read_no_mreq( HL, 1 );
            INC(bytetemp);
            Z80_WB_MACRO(HL,bytetemp);
         }
         break;
      case 0x35:		/* DEC (HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            contend_read_no_mreq( HL, 1 );
            DEC(bytetemp);
            Z80_WB_MACRO(HL,bytetemp);
         }
         break;
      case 0x36:		/* LD (HL),nn */
         Z80_WB_MACRO(HL,Z80_RB_MACRO(PC++));
         break;
      case 0x37:		/* SCF */
         F = ( F & ( Z80_FLAG_P | Z80_FLAG_Z | Z80_FLAG_S ) ) |
            ( A & ( Z80_FLAG_3 | Z80_FLAG_5          ) ) |
            Z80_FLAG_C;
         break;
      case 0x38:		/* JR C,offset */
         if( F & Z80_FLAG_C ) {
            JR();
         } else {
            contend_read( PC, 3 );
         }
         PC++;
         break;
      case 0x39:		/* ADD HL,SP */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         ADD16(HL,SP);
         break;
      case 0x3a:		/* LD A,(nnnn) */
         {
            uint16 wordtemp;
            wordtemp = Z80_RB_MACRO(PC++);
            wordtemp|= ( Z80_RB_MACRO(PC++) << 8 );
            A=Z80_RB_MACRO(wordtemp);
         }
         break;
      case 0x3b:		/* DEC SP */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         SP--;
         break;
      case 0x3c:		/* INC A */
         INC(A);
         break;
      case 0x3d:		/* DEC A */
         DEC(A);
         break;
      case 0x3e:		/* LD A,nn */
         A = Z80_RB_MACRO( PC++ );
         break;
      case 0x3f:		/* CCF */
         F = ( F & ( Z80_FLAG_P | Z80_FLAG_Z | Z80_FLAG_S ) ) |
            ( ( F & Z80_FLAG_C ) ? Z80_FLAG_H : Z80_FLAG_C ) | ( A & ( Z80_FLAG_3 | Z80_FLAG_5 ) );
         break;
      case 0x40:		/* LD B,B */
         break;
      case 0x41:		/* LD B,C */
         B=C;
         break;
      case 0x42:		/* LD B,D */
         B=D;
         break;
      case 0x43:		/* LD B,E */
         B=E;
         break;
      case 0x44:		/* LD B,H */
         B=H;
         break;
      case 0x45:		/* LD B,L */
         B=L;
         break;
      case 0x46:		/* LD B,(HL) */
         B=Z80_RB_MACRO(HL);
         break;
      case 0x47:		/* LD B,A */
         B=A;
         break;
      case 0x48:		/* LD C,B */
         C=B;
         break;
      case 0x49:		/* LD C,C */
         break;
      case 0x4a:		/* LD C,D */
         C=D;
         break;
      case 0x4b:		/* LD C,E */
         C=E;
         break;
      case 0x4c:		/* LD C,H */
         C=H;
         break;
      case 0x4d:		/* LD C,L */
         C=L;
         break;
      case 0x4e:		/* LD C,(HL) */
         C=Z80_RB_MACRO(HL);
         break;
      case 0x4f:		/* LD C,A */
         C=A;
         break;
      case 0x50:		/* LD D,B */
         D=B;
         break;
      case 0x51:		/* LD D,C */
         D=C;
         break;
      case 0x52:		/* LD D,D */
         break;
      case 0x53:		/* LD D,E */
         D=E;
         break;
      case 0x54:		/* LD D,H */
         D=H;
         break;
      case 0x55:		/* LD D,L */
         D=L;
         break;
      case 0x56:		/* LD D,(HL) */
         D=Z80_RB_MACRO(HL);
         break;
      case 0x57:		/* LD D,A */
         D=A;
         break;
      case 0x58:		/* LD E,B */
         E=B;
         break;
      case 0x59:		/* LD E,C */
         E=C;
         break;
      case 0x5a:		/* LD E,D */
         E=D;
         break;
      case 0x5b:		/* LD E,E */
         break;
      case 0x5c:		/* LD E,H */
         E=H;
         break;
      case 0x5d:		/* LD E,L */
         E=L;
         break;
      case 0x5e:		/* LD E,(HL) */
         E=Z80_RB_MACRO(HL);
         break;
      case 0x5f:		/* LD E,A */
         E=A;
         break;
      case 0x60:		/* LD H,B */
         H=B;
         break;
      case 0x61:		/* LD H,C */
         H=C;
         break;
      case 0x62:		/* LD H,D */
         H=D;
         break;
      case 0x63:		/* LD H,E */
         H=E;
         break;
      case 0x64:		/* LD H,H */
         break;
      case 0x65:		/* LD H,L */
         H=L;
         break;
      case 0x66:		/* LD H,(HL) */
         H=Z80_RB_MACRO(HL);
         break;
      case 0x67:		/* LD H,A */
         H=A;
         break;
      case 0x68:		/* LD L,B */
         L=B;
         break;
      case 0x69:		/* LD L,C */
         L=C;
         break;
      case 0x6a:		/* LD L,D */
         L=D;
         break;
      case 0x6b:		/* LD L,E */
         L=E;
         break;
      case 0x6c:		/* LD L,H */
         L=H;
         break;
      case 0x6d:		/* LD L,L */
         break;
      case 0x6e:		/* LD L,(HL) */
         L=Z80_RB_MACRO(HL);
         break;
      case 0x6f:		/* LD L,A */
         L=A;
         break;
      case 0x70:		/* LD (HL),B */
         Z80_WB_MACRO(HL,B);
         break;
      case 0x71:		/* LD (HL),C */
         Z80_WB_MACRO(HL,C);
         break;
      case 0x72:		/* LD (HL),D */
         Z80_WB_MACRO(HL,D);
         break;
      case 0x73:		/* LD (HL),E */
         Z80_WB_MACRO(HL,E);
         break;
      case 0x74:		/* LD (HL),H */
         Z80_WB_MACRO(HL,H);
         break;
      case 0x75:		/* LD (HL),L */
         Z80_WB_MACRO(HL,L);
         break;
      case 0x76:		/* HALT */
         z80.halted=1;
         PC--;
         break;
      case 0x77:		/* LD (HL),A */
         Z80_WB_MACRO(HL,A);
         break;
      case 0x78:		/* LD A,B */
         A=B;
         break;
      case 0x79:		/* LD A,C */
         A=C;
         break;
      case 0x7a:		/* LD A,D */
         A=D;
         break;
      case 0x7b:		/* LD A,E */
         A=E;
         break;
      case 0x7c:		/* LD A,H */
         A=H;
         break;
      case 0x7d:		/* LD A,L */
         A=L;
         break;
      case 0x7e:		/* LD A,(HL) */
         A=Z80_RB_MACRO(HL);
         break;
      case 0x7f:		/* LD A,A */
         break;
      case 0x80:		/* ADD A,B */
         ADD(B);
         break;
      case 0x81:		/* ADD A,C */
         ADD(C);
         break;
      case 0x82:		/* ADD A,D */
         ADD(D);
         break;
      case 0x83:		/* ADD A,E */
         ADD(E);
         break;
      case 0x84:		/* ADD A,H */
         ADD(H);
         break;
      case 0x85:		/* ADD A,L */
         ADD(L);
         break;
      case 0x86:		/* ADD A,(HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            ADD(bytetemp);
         }
         break;
      case 0x87:		/* ADD A,A */
         ADD(A);
         break;
      case 0x88:		/* ADC A,B */
         ADC(B);
         break;
      case 0x89:		/* ADC A,C */
         ADC(C);
         break;
      case 0x8a:		/* ADC A,D */
         ADC(D);
         break;
      case 0x8b:		/* ADC A,E */
         ADC(E);
         break;
      case 0x8c:		/* ADC A,H */
         ADC(H);
         break;
      case 0x8d:		/* ADC A,L */
         ADC(L);
         break;
      case 0x8e:		/* ADC A,(HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            ADC(bytetemp);
         }
         break;
      case 0x8f:		/* ADC A,A */
         ADC(A);
         break;
      case 0x90:		/* SUB A,B */
         SUB(B);
         break;
      case 0x91:		/* SUB A,C */
         SUB(C);
         break;
      case 0x92:		/* SUB A,D */
         SUB(D);
         break;
      case 0x93:		/* SUB A,E */
         SUB(E);
         break;
      case 0x94:		/* SUB A,H */
         SUB(H);
         break;
      case 0x95:		/* SUB A,L */
         SUB(L);
         break;
      case 0x96:		/* SUB A,(HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            SUB(bytetemp);
         }
         break;
      case 0x97:		/* SUB A,A */
         SUB(A);
         break;
      case 0x98:		/* SBC A,B */
         SBC(B);
         break;
      case 0x99:		/* SBC A,C */
         SBC(C);
         break;
      case 0x9a:		/* SBC A,D */
         SBC(D);
         break;
      case 0x9b:		/* SBC A,E */
         SBC(E);
         break;
      case 0x9c:		/* SBC A,H */
         SBC(H);
         break;
      case 0x9d:		/* SBC A,L */
         SBC(L);
         break;
      case 0x9e:		/* SBC A,(HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            SBC(bytetemp);
         }
         break;
      case 0x9f:		/* SBC A,A */
         SBC(A);
         break;
      case 0xa0:		/* AND A,B */
         AND(B);
         break;
      case 0xa1:		/* AND A,C */
         AND(C);
         break;
      case 0xa2:		/* AND A,D */
         AND(D);
         break;
      case 0xa3:		/* AND A,E */
         AND(E);
         break;
      case 0xa4:		/* AND A,H */
         AND(H);
         break;
      case 0xa5:		/* AND A,L */
         AND(L);
         break;
      case 0xa6:		/* AND A,(HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            AND(bytetemp);
         }
         break;
      case 0xa7:		/* AND A,A */
         AND(A);
         break;
      case 0xa8:		/* XOR A,B */
         XOR(B);
         break;
      case 0xa9:		/* XOR A,C */
         XOR(C);
         break;
      case 0xaa:		/* XOR A,D */
         XOR(D);
         break;
      case 0xab:		/* XOR A,E */
         XOR(E);
         break;
      case 0xac:		/* XOR A,H */
         XOR(H);
         break;
      case 0xad:		/* XOR A,L */
         XOR(L);
         break;
      case 0xae:		/* XOR A,(HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            XOR(bytetemp);
         }
         break;
      case 0xaf:		/* XOR A,A */
         XOR(A);
         break;
      case 0xb0:		/* OR A,B */
         OR(B);
         break;
      case 0xb1:		/* OR A,C */
         OR(C);
         break;
      case 0xb2:		/* OR A,D */
         OR(D);
         break;
      case 0xb3:		/* OR A,E */
         OR(E);
         break;
      case 0xb4:		/* OR A,H */
         OR(H);
         break;
      case 0xb5:		/* OR A,L */
         OR(L);
         break;
      case 0xb6:		/* OR A,(HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            OR(bytetemp);
         }
         break;
      case 0xb7:		/* OR A,A */
         OR(A);
         break;
      case 0xb8:		/* CP B */
         CP(B);
         break;
      case 0xb9:		/* CP C */
         CP(C);
         break;
      case 0xba:		/* CP D */
         CP(D);
         break;
      case 0xbb:		/* CP E */
         CP(E);
         break;
      case 0xbc:		/* CP H */
         CP(H);
         break;
      case 0xbd:		/* CP L */
         CP(L);
         break;
      case 0xbe:		/* CP (HL) */
         {
            uint8_t bytetemp = Z80_RB_MACRO( HL );
            CP(bytetemp);
         }
         break;
      case 0xbf:		/* CP A */
         CP(A);
         break;
      case 0xc0:		/* RET NZ */
         contend_read_no_mreq( IR, 1 );
         if( ! ( F & Z80_FLAG_Z ) ) { RET(); }
         break;
      case 0xc1:		/* POP BC */
         POP16(C,B);
         break;
      case 0xc2:		/* JP NZ,nnnn */
         if( ! ( F & Z80_FLAG_Z ) ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xc3:		/* JP nnnn */
         JP();
         break;
      case 0xc4:		/* CALL NZ,nnnn */
         if( ! ( F & Z80_FLAG_Z ) ) {
            CALL();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xc5:		/* PUSH BC */
         contend_read_no_mreq( IR, 1 );
         PUSH16(C,B);
         break;
      case 0xc6:		/* ADD A,nn */
         {
            uint8_t bytetemp = Z80_RB_MACRO( PC++ );
            ADD(bytetemp);
         }
         break;
      case 0xc7:		/* RST 00 */
         contend_read_no_mreq( IR, 1 );
         RST(0x00);
         break;
      case 0xc8:		/* RET Z */
         contend_read_no_mreq( IR, 1 );
         if( F & Z80_FLAG_Z ) { RET(); }
         break;
      case 0xc9:		/* RET */
         RET();
         break;
      case 0xca:		/* JP Z,nnnn */
         if( F & Z80_FLAG_Z ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xcb:		/* shift CB */
         {
            uint8_t opcode2;
            opcode2 = Z80_RB_MACRO( PC );
            z80_tstates++;
            PC++;
            R++;
            switch(opcode2)
            {
#include "z80_cb.c"
            }
         }
         break;
      case 0xcc:		/* CALL Z,nnnn */
         if( F & Z80_FLAG_Z ) {
            CALL();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xcd:		/* CALL nnnn */
         CALL();
         break;
      case 0xce:		/* ADC A,nn */
         {
            uint8_t bytetemp = Z80_RB_MACRO( PC++ );
            ADC(bytetemp);
         }
         break;
      case 0xcf:		/* RST 8 */
         contend_read_no_mreq( IR, 1 );
         RST(0x08);
         break;
      case 0xd0:		/* RET NC */
         contend_read_no_mreq( IR, 1 );
         if( ! ( F & Z80_FLAG_C ) ) { RET(); }
         break;
      case 0xd1:		/* POP DE */
         POP16(E,D);
         break;
      case 0xd2:		/* JP NC,nnnn */
         if( ! ( F & Z80_FLAG_C ) ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xd3:		/* OUT (nn),A */
         { 
            uint16 outtemp;
            outtemp = Z80_RB_MACRO( PC++ ) + ( A << 8 );
            Z80_WP_MACRO( outtemp, A );
         }
         break;
      case 0xd4:		/* CALL NC,nnnn */
         if( ! ( F & Z80_FLAG_C ) ) {
            CALL();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xd5:		/* PUSH DE */
         contend_read_no_mreq( IR, 1 );
         PUSH16(E,D);
         break;
      case 0xd6:		/* SUB nn */
         {
            uint8_t bytetemp = Z80_RB_MACRO( PC++ );
            SUB(bytetemp);
         }
         break;
      case 0xd7:		/* RST 10 */
         contend_read_no_mreq( IR, 1 );
         RST(0x10);
         break;
      case 0xd8:		/* RET C */
         contend_read_no_mreq( IR, 1 );
         if( F & Z80_FLAG_C ) { RET(); }
         break;
      case 0xd9:		/* EXX */
         {
            uint16 wordtemp;
            wordtemp = BC; BC = BC_; BC_ = wordtemp;
            wordtemp = DE; DE = DE_; DE_ = wordtemp;
            wordtemp = HL; HL = HL_; HL_ = wordtemp;
         }
         break;
      case 0xda:		/* JP C,nnnn */
         if( F & Z80_FLAG_C ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xdb:		/* IN A,(nn) */
         { 
            uint16 intemp;
            intemp = Z80_RB_MACRO( PC++ ) + ( A << 8 );
            A=Z80_RP_MACRO( intemp );
         }
         break;
      case 0xdc:		/* CALL C,nnnn */
         if( F & Z80_FLAG_C ) {
            CALL();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xdd:		/* shift DD */
         {
            uint8_t opcode2;
            opcode2 = Z80_RB_MACRO( PC );
            z80_tstates++;
            PC++;
            R++;
            switch(opcode2) {
#define REGISTER  IX
#define REGISTERL IXL
#define REGISTERH IXH
#include "z80_ddfd.c"
#undef REGISTERH
#undef REGISTERL
#undef REGISTER
            }
         }
         break;
      case 0xde:		/* SBC A,nn */
         {
            uint8_t bytetemp = Z80_RB_MACRO( PC++ );
            SBC(bytetemp);
         }
         break;
      case 0xdf:		/* RST 18 */
         contend_read_no_mreq( IR, 1 );
         RST(0x18);
         break;
      case 0xe0:		/* RET PO */
         contend_read_no_mreq( IR, 1 );
         if( ! ( F & Z80_FLAG_P ) ) { RET(); }
         break;
      case 0xe1:		/* POP HL */
         POP16(L,H);
         break;
      case 0xe2:		/* JP PO,nnnn */
         if( ! ( F & Z80_FLAG_P ) ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xe3:		/* EX (SP),HL */
         {
            uint8_t bytetempl, bytetemph;
            bytetempl = Z80_RB_MACRO( SP );
            bytetemph = Z80_RB_MACRO( SP + 1 ); contend_read_no_mreq( SP + 1, 1 );
            Z80_WB_MACRO( SP + 1, H );
            Z80_WB_MACRO( SP,     L  );
            contend_write_no_mreq( SP, 1 ); contend_write_no_mreq( SP, 1 );
            L=bytetempl; H=bytetemph;
         }
         break;
      case 0xe4:		/* CALL PO,nnnn */
         if( ! ( F & Z80_FLAG_P ) ) {
            CALL();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xe5:		/* PUSH HL */
         contend_read_no_mreq( IR, 1 );
         PUSH16(L,H);
         break;
      case 0xe6:		/* AND nn */
         {
            uint8_t bytetemp = Z80_RB_MACRO( PC++ );
            AND(bytetemp);
         }
         break;
      case 0xe7:		/* RST 20 */
         contend_read_no_mreq( IR, 1 );
         RST(0x20);
         break;
      case 0xe8:		/* RET PE */
         contend_read_no_mreq( IR, 1 );
         if( F & Z80_FLAG_P ) { RET(); }
         break;
      case 0xe9:		/* JP HL */
         PC=HL;		/* NB: NOT INDIRECT! */
         break;
      case 0xea:		/* JP PE,nnnn */
         if( F & Z80_FLAG_P ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xeb:		/* EX DE,HL */
         {
            uint16 wordtemp=DE; DE=HL; HL=wordtemp;
         }
         break;
      case 0xec:		/* CALL PE,nnnn */
         if( F & Z80_FLAG_P ) {
            CALL();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xed:		/* shift ED */
         {
            uint8_t opcode2;
            opcode2 = Z80_RB_MACRO( PC );
            z80_tstates++;
            PC++;
            R++;
            switch(opcode2)
            {
#include "z80_ed.c"
            }
         }
         break;
      case 0xee:		/* XOR A,nn */
         {
            uint8_t bytetemp = Z80_RB_MACRO( PC++ );
            XOR(bytetemp);
         }
         break;
      case 0xef:		/* RST 28 */
         contend_read_no_mreq( IR, 1 );
         RST(0x28);
         break;
      case 0xf0:		/* RET P */
         contend_read_no_mreq( IR, 1 );
         if( ! ( F & Z80_FLAG_S ) ) { RET(); }
         break;
      case 0xf1:		/* POP AF */
         POP16(F,A);
         break;
      case 0xf2:		/* JP P,nnnn */
         if( ! ( F & Z80_FLAG_S ) ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xf3:		/* DI */
         IFF1=IFF2=0;
         break;
      case 0xf4:		/* CALL P,nnnn */
         if( ! ( F & Z80_FLAG_S ) ) {
            CALL();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xf5:		/* PUSH AF */
         contend_read_no_mreq( IR, 1 );
         PUSH16(F,A);
         break;
      case 0xf6:		/* OR nn */
         {
            uint8_t bytetemp = Z80_RB_MACRO( PC++ );
            OR(bytetemp);
         }
         break;
      case 0xf7:		/* RST 30 */
         contend_read_no_mreq( IR, 1 );
         RST(0x30);
         break;
      case 0xf8:		/* RET M */
         contend_read_no_mreq( IR, 1 );
         if( F & Z80_FLAG_S ) { RET(); }
         break;
      case 0xf9:		/* LD SP,HL */
         contend_read_no_mreq( IR, 1 );
         contend_read_no_mreq( IR, 1 );
         SP = HL;
         break;
      case 0xfa:		/* JP M,nnnn */
         if( F & Z80_FLAG_S ) {
            JP();
         } else {
            contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
         }
         break;
      case 0xfb:		/* EI */
         /* Interrupts are not accepted immediately after an EI, but are
            accepted after the next instruction */
               IFF1 = IFF2 = 1;
            z80.interrupts_enabled_at = z80_tstates;
            //event_add( z80_tstates + 1, z80_interrupt_event );
            break;
      case 0xfc:		/* CALL M,nnnn */
            if( F & Z80_FLAG_S ) {
               CALL();
            } else {
               contend_read( PC, 3 ); contend_read( PC + 1, 3 ); PC += 2;
            }
            break;
      case 0xfd:		/* shift FD */
            {
               uint8_t opcode2;
               opcode2 = Z80_RB_MACRO( PC );
               z80_tstates++;
               PC++;
               R++;
               switch(opcode2) {
#define REGISTER  IY
#define REGISTERL IYL
#define REGISTERH IYH
#include "z80_ddfd.c"
#undef REGISTERH
#undef REGISTERL
#undef REGISTER
               }
            }
            break;
      case 0xfe:		/* CP nn */
            {
               uint8_t bytetemp = Z80_RB_MACRO( PC++ );
               CP(bytetemp);
            }
            break;
      case 0xff:		/* RST 38 */
            contend_read_no_mreq( IR, 1 );
            RST(0x38);
            break;
