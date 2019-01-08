//
//  AESUtil.m
//  BLEParser
//
//  Created by Mark on 2018/12/17.
//

#import "AESUtil.h"
#import <CommonCrypto/CommonCrypto.h>

@implementation AESUtil

+ (NSData *)encryptAES:(NSData *)content key:(NSData *)key {
    NSUInteger dataLength = content.length;
    
    // 为结束符'\0' +1
    int kKeySize = kCCKeySizeAES128;
    char keyPtr[kKeySize + 1];
    memset(keyPtr, 0, sizeof(keyPtr));
    memcpy(keyPtr, key.bytes, key.length);
    
    // 密文长度 <= 明文长度 + BlockSize
    size_t encryptSize = dataLength + kCCBlockSizeAES128;
    void *encryptedBytes = malloc(encryptSize);
    size_t actualOutSize = 0;
    
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt,
                                          kCCAlgorithmAES,
                                          kCCOptionPKCS7Padding | kCCOptionECBMode,  // PKCS5Padding
                                          keyPtr,
                                          kKeySize,
                                          NULL,
                                          content.bytes,
                                          dataLength,
                                          encryptedBytes,
                                          encryptSize,
                                          &actualOutSize);
    if (cryptStatus == kCCSuccess) {
        return [NSData dataWithBytesNoCopy:encryptedBytes length:actualOutSize];
    }
    
    free(encryptedBytes);
    encryptedBytes = NULL;
    return nil;
}

+ (NSData *)decryptWithAESECB5Padding:(NSData *)encryptedData key:(NSData *)key {
    NSUInteger dataLength = encryptedData.length;
    
    // 为结束符'\0' +1
    int kKeySize = kCCKeySizeAES128;
    char keyPtr[kKeySize + 1];
    memset(keyPtr, 0, sizeof(keyPtr));
    memcpy(keyPtr, key.bytes, key.length);
    
    // 密文长度 <= 明文长度 + BlockSize
    size_t decryptSize = dataLength + kCCBlockSizeAES128;
    void *decryptedBytes = malloc(decryptSize);
    size_t actualOutSize = 0;
    
    CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt,
                                          kCCAlgorithmAES,
                                          kCCOptionPKCS7Padding | kCCOptionECBMode,
                                          keyPtr,
                                          kKeySize,
                                          NULL,
                                          encryptedData.bytes,
                                          dataLength,
                                          decryptedBytes,
                                          decryptSize,
                                          &actualOutSize);
    if (cryptStatus == kCCSuccess) {
        return [NSData dataWithBytes:decryptedBytes length:actualOutSize];
    }
    
    free(decryptedBytes);
    decryptedBytes = NULL;
    return nil;
}

@end
