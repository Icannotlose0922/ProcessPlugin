#ifndef AES_H
#define AES_H

typedef unsigned char byte;
//128对应数组大小为16，192对应数组大小为24，256对应数组大小为32
static unsigned char aeskey[32] = { 0x2b, 0x7e, 0x15, 0x16,0x28, 0xae, 0xd2, 0xa6,0xab, 0xf7, 0x15, 0x88,0x09, 0xcf, 0x4f, 0x3c };

enum KeySize // key size, in bits, for construtor
{
    Bits128 = 16,
    Bits192 = 24,
    Bits256 = 32
};

class QFile;

class AES
{
public:
    AES();
    AES(int keySize, unsigned char* key);
    ~AES();

    bool FileCipher(QFile *fin, QFile *fout);
	bool FileInvCipher(QFile *fin, QFile *fout);

    void Cipher(unsigned char* input, unsigned char* output);
    void InvCipher(unsigned char * input, unsigned char * output);

    void Cipher(unsigned char* input, unsigned char* output,
                unsigned char *key, int keySize = Bits128);  // encipher 16-bit input
    void InvCipher(unsigned char * input, unsigned char * output,
                   unsigned char *key, int keySize = Bits128);  // decipher 16-bit input

private:
    static const unsigned char Sbox[16*16];
    static const unsigned char iSbox[16*16];
    static const unsigned char Rcon[11*4];

    int Nb;         // block size in 32-bit words.  Always 4 for AES.  (128 bits).
    int Nk;         // key size in 32-bit words.  4, 6, 8.  (128, 192, 256 bits).
    int Nr;         // number of rounds. 10, 12, 14.

    unsigned char key[32];      // the seed key. size will be 4 * keySize from ctor.
    unsigned char w[16*15];     // key schedule array. (Nb*(Nr+1))*4
    unsigned char State[4][4];  // State matrix

private:
    void RunKeyExpansion(int keySize, unsigned char* keyBytes);
    void SetNbNkNr(int keyS);
    void KeyExpansion();
    void AddRoundKey(int round);
    void SubWord(unsigned char * word,unsigned char* result);
    void RotWord(unsigned char * word,unsigned char* result);
    void SubBytes();
    void InvSubBytes();
    void ShiftRows();
    void InvShiftRows();
    void MixColumns();
    void InvMixColumns();
    unsigned char gfmultby01(unsigned char b);
    unsigned char gfmultby02(unsigned char b);
    unsigned char gfmultby03(unsigned char b);
    unsigned char gfmultby09(unsigned char b);
    unsigned char gfmultby0b(unsigned char b);
    unsigned char gfmultby0d(unsigned char b);
    unsigned char gfmultby0e(unsigned char b);

};

#endif // AES_H
