// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len) : Bitlen(len) 
{
	MemLen = ((len + (sizeof(int) * 8)-1) / (sizeof(int) * 8));
	pMem = new TELEM[MemLen];
	if (pMem != 0)
		for (int i = 0; i < MemLen;i++) 
			pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	if (pMem != 0)
		for (int i = 0; i < MemLen;i++)
pMem[i] = bf.Mem[i];
}

TBitField::~TBitField()
{
		delete [] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n >> (sizeof(int)) ;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << ( n % ((sizeof(int)*8)-1))
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return Bitlen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if ( ( n > -1) && ( n < Bitlen) )
          pMem[GetMemIndex(n)] | = GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if ( ( n > -1) && ( n < Bitlen) )
	      pMem[GetMemIndex(n)] & = ~ GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if ( ( n > -1) && ( n < Bitlen) )
		return pMem[GetMemIndex(n)] & GetMemMask(n);
	return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
}

TBitField TBitField::operator~(void) // отрицание
{
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
}
