//
//  ViewController.m
//  DemoProject
//
//  Created by Mark on 2018/12/27.
//  Copyright © 2018年 Mark Chen. All rights reserved.
//

#import "ViewController.h"
#import "AESUtil.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    // 测试AES加密
    uint8_t key[] = "mvLBiZsiTbGwrfJB";
    NSData *dataKey = [NSData dataWithBytes:key length:16];
    NSString *content = @"ABCdefJ10cB3u7LaX+0s";
    NSData *contentData = [content dataUsingEncoding:NSUTF8StringEncoding];
    
    NSData *encryptedData = [AESUtil encryptAES:contentData key:dataKey];
    NSData *decryptData = [AESUtil decryptWithAESECB5Padding:encryptedData key:dataKey];
    
    // Print log
    NSString *encryptedString = [encryptedData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
    NSString *decryptedString = [[NSString alloc] initWithData:decryptData encoding:NSUTF8StringEncoding];
    NSLog(@"AES Test : content = %@, encryptedStr = %@ (%ld Byte), [After Decrypt] Content = %@", content, encryptedString, encryptedString.length, decryptedString);
    // END - 测试AES加密
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
