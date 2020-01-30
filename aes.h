#include <stdint.h>

#ifndef _AES_Header_
#define _AES_Header_


//As this AES program woould support all modes of operation of AES so I defined macros to include/exclude the mode of operation according to your specific application

//ECB_M(Electronic Code Book) mode for AES.
//ECB_M is deterministic Encryption meaning it would always give the same output if key and the message is same everytime you encrypt them
#ifndef ECB_M
 #define ECB_M 1
#endif

//CBC_M(Cipher Block Chaining)  mode for AES.
//CBC_M is probablistic Encryption meaning it would not give same output it same key and same message are used.It involves randomness through IV(intial vector ) which is explained in the respective code part
#ifndef ECB_M
 #define CBC_M 1
#endif

//OFB_M(Output Feedback Block) mode for AES
//This mode is also probablistic but it is for use in Stream Ciphers
#ifndef ECB_M
 #define OFB_M 1
#endif



//Here AES parameters are defined based on key length



//AES keys 128,192 and 256  to include/exclude based on your application
#define AES_K_128 1
#define AES_K_192 1
#define AES_K_256 1

//Same for AES256,192 and 128 which  is block size for ecryption
#define AES_BLOCK_SIZE 128/8 // 16 Bytes while in DES it was 64 bits(8 bytes)
#define NmColumns 4 //4x4 box
//Note : Rijndael's key expansion.

        //Expands an 128,192,256 key into an 176,208,240 bytes key
        //expandedKey is a char list of large enough size,
        //key is the non-expanded key.

// parameters for AES_K_128
#if defined(AES_K_128) && (AES_K_128==1)
    #define AES_KEY_LENGTH 128/8 //16 Bytes key
    #define AES_EXPANDED_KEY 176 //176 bytes expanded key
    #define AES_ROUNDS 10 //10 rounds for 128 bits key
    #define NM32W 128/32 //4 number of 32-bit words
// parameters for AES_K_192
#elif defined(AES_K_192) && (AES_K_192==1)
    #define AES_KEY_LENGTH 192/8 //24 Bytes key
    #define AES_EXPANDED_KEY 208 //208 bytes expanded key
    #define AES_ROUNDS 12 //12 rounds for 192 bits key
    #define NM32W 192/32 //6 number of 32-bit words
// parameters for AES_K_256
#else
    #define AES_KEY_LENGTH 256/8 //32 Bytes key
    #define AES_EXPANDED_KEY 240 //240 bytes expanded key
    #define AES_ROUNDS 14 //14 rounds for 256 bits key
    #define NM32W 256/32 //4 number of 32-bit words
#endif


 // AES_ctx AES context to be initialized
struct AES_ctx
{
	
};