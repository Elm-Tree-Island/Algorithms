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
 
 @param content 要加密的字符串
 @param key 所使用的key
 @return 返回的字符串
 */
+ (NSString *)encryptAES:(NSString *)content key:(NSString *)key;

/**
 使用AES128/ECB/PKCS5Padding解密字符串
 
 @param encryptStr 要解密的字符串
 @param key 秘钥字符串
 @return 解密后字符串
 */
+ (NSString *)decryptWithAESECB5Padding:(NSString *)encryptStr key:(NSString *)key;

@end
