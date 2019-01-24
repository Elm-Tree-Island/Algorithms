//
//  AESUtil.h
//
//  Created by Mark Chen on 2018/12/17.
//  Email: chenjian345@gmail.com
//

#import <Foundation/Foundation.h>

@interface AESUtil : NSObject

#pragma mark - NSData
/*
 Encrypt NSData using AES128/ECB/PKCS5Padding.
 
 @param content NSData  Data need to encrypt
 @param key NSString    Encrypt key string
 @return NSData         Data after encrypt using AES
 */
+ (NSData *)encryptAESData:(NSData *)content key:(NSData *)key;

/**
 Decrypt NSData using AES128/ECB/PKCS5Padding.
 
 @param encryptedData NSData    The data need to decrypt.
 @param key NSString            Decrypt key string
 @return NSData
 */
+ (NSData *)decryptAESData:(NSData *)encryptedData key:(NSData *)key;

#pragma mark - NSString

/**
 Encrypt NSString using AES128/ECB/PKCS5Padding.
 The result is encoded using base64.
 
 @param content NSString, The string need to encrypt, Encoding-UTF8
 @param key NSString,  Encrypt key string
 @return NSString, Encoding-UTF8
 */
+ (NSString *)encryptAESString:(NSString *)content key:(NSString *)key;

/**
 Decrypt NSString using AES128/ECB/PKCS5Padding.

 @param encryptedStr NSString, The string need to decrypt.
 @param key NSString,  Key string
 @return NSString, Encoding-UTF8
 */
+ (NSString *)decryptAESString:(NSString *)encryptedStr key:(NSString *)key;

@end
