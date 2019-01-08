//
//  AESUtil.h
//  BLEParser
//
//  Created by Mark on 2018/12/17.
//

#import <Foundation/Foundation.h>

@interface AESUtil : NSObject

/**
 对数据字符串使用AES128/ECB/PKCS5Padding进行加密
 
 @param content 要加密的内容
 @param key 所使用的key
 @return 加密后数据
 */
+ (NSData *)encryptAES:(NSData *)content key:(NSData *)key;

/**
 使用AES128/ECB/PKCS5Padding解密字符串
 
 @param encryptedData 要解密的内容
 @param key 秘钥
 @return 解密后数据
 */
+ (NSData *)decryptWithAESECB5Padding:(NSData *)encryptedData key:(NSData *)key;

@end
