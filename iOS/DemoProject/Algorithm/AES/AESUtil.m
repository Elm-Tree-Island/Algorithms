//
//  AESUtil.m
//  BLEParser
//
//  Created by Mark on 2018/12/17.
//

#import "AESUtil.h"
#import <CommonCrypto/CommonCrypto.h>

@implementation AESUtil

/**
 对数据字符串使用AES128/ECB/PKCS5Padding进行加密

 @param content 要加密的字符串
 @param key 所使用的key
 @return 返回的字符串
 */
+ (NSString *)encryptAES:(NSString *)content key:(NSString *)key {
    NSData *contentData = [content dataUsingEncoding:NSUTF8StringEncoding];
    NSUInteger dataLength = contentData.length;
    
    // 为结束符'\0' +1
    int kKeySize = kCCKeySizeAES128;
    char keyPtr[kKeySize + 1];
    memset(keyPtr, 0, sizeof(keyPtr));
    [key getCString:keyPtr maxLength:sizeof(keyPtr) encoding:NSUTF8StringEncoding];
    
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
                                          contentData.bytes,
                                          dataLength,
                                          encryptedBytes,
                                          encryptSize,
                                          &actualOutSize);
    if (cryptStatus == kCCSuccess) {
        // 对加密后的数据进行 base64 编码
        NSString *result = [[NSData dataWithBytesNoCopy:encryptedBytes length:actualOutSize] base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
        
        return result;
    }
    
    free(encryptedBytes);
    encryptedBytes = NULL;
    return nil;
}

/**
 使用AES128/ECB/PKCS5Padding解密字符串

 @param encryptStr 要解密的字符串
 @param key 秘钥字符串
 @return 解密后字符串
 */
+ (NSString *)decryptWithAESECB5Padding:(NSString *)encryptStr key:(NSString *)key {
    NSData *encryptedData = [[NSData alloc] initWithBase64EncodedString:encryptStr options:NSUTF8StringEncoding];
    
    NSUInteger dataLength = encryptedData.length;
    
    // 为结束符'\0' +1
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
