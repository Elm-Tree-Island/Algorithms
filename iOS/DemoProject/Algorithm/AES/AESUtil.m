//
//  AESUtil.h
//
//  Created by Mark Chen on 2018/12/17.
//  Email: chenjian345@gmail.com
//

#import "AESUtil.h"
#import <CommonCrypto/CommonCrypto.h>

@implementation AESUtil

#pragma mark - NSData
+ (NSData *)encryptAESData:(NSData *)content key:(NSData *)key {
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

+ (NSData *)decryptAESData:(NSData *)encryptedData key:(NSData *)key {
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

#pragma mark - NSString

+ (NSString *)encryptAESString:(NSString *)content key:(NSString *)key {
    NSData *contentData = [content dataUsingEncoding:NSUTF8StringEncoding];
    NSUInteger dataLength = contentData.length;
    
    int kKeySize = kCCKeySizeAES128;
    char keyPtr[kKeySize + 1];
    memset(keyPtr, 0, sizeof(keyPtr));
    [key getCString:keyPtr maxLength:sizeof(keyPtr) encoding:NSUTF8StringEncoding];
    
    size_t encryptSize = dataLength + kCCBlockSizeAES128;
    void *encryptedBytes = malloc(encryptSize);
    size_t actualOutSize = 0;
    
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt,
                                          kCCAlgorithmAES,
                                          kCCOptionPKCS7Padding | kCCOptionECBMode,  // PKCS5Padding
                                          keyPtr,
                                          kKeySize,
                                          NULL,
                                          contentData.bytes,
                                          dataLength,
                                          encryptedBytes,
                                          encryptSize,
                                          &actualOutSize);
    if (cryptStatus == kCCSuccess) {
        // Encoding with base64
        NSString *result = [[NSData dataWithBytesNoCopy:encryptedBytes length:actualOutSize] base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
        
        return result;
    }
    
    free(encryptedBytes);
    encryptedBytes = NULL;
    return nil;
}

+ (NSString *)decryptAESString:(NSString *)encryptedStr key:(NSString *)key {
    // Decode with base64
    NSData *encryptedData = [[NSData alloc] initWithBase64EncodedString:encryptedStr options:NSUTF8StringEncoding];
    NSUInteger dataLength = encryptedData.length;
    int kKeySize = kCCKeySizeAES128;
    char keyPtr[kKeySize + 1];
    memset(keyPtr, 0, sizeof(keyPtr));
    [key getCString:keyPtr maxLength:sizeof(keyPtr) encoding:NSUTF8StringEncoding];
    
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
        NSString *result = [[NSString alloc] initWithData:[NSData dataWithBytes:decryptedBytes length:actualOutSize] encoding:NSUTF8StringEncoding];
        
        return result;
    }
    
    free(decryptedBytes);
    decryptedBytes = NULL;
    return nil;
}

@end
