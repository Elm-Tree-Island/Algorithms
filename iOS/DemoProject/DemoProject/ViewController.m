//
//  ViewController.m
//  DemoProject
//
//  Created by Mark Chen on 2018/12/27.
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
    
    // BEGIN
    /******* Test NSString *******/
    NSString *key = @"mvLBiZsiTbGwrfJB";
    NSString *content = @"ABCdefJ10cB3u7LaX+0s";
    NSString *encryptedStr = [AESUtil encryptAESString:content key:key];
    NSString *decryptStr = [AESUtil decryptAESString:encryptedStr key:key];
    NSLog(@"AES NSString Test : content = %@, encryptedStr = %@ (%ld Byte), [After Decrypt] Content = %@", content, encryptedStr, encryptedStr.length, decryptStr);

    /******* Test NSData *******/
    uint8_t keyBytes[] = "mvLBiZsiTbGwrfJB";
    NSData *dataKey = [NSData dataWithBytes:keyBytes length:16];
    NSData *contentData = [content dataUsingEncoding:NSUTF8StringEncoding];
    
    NSData *encryptedData = [AESUtil encryptAESData:contentData key:dataKey];
    NSData *decryptData = [AESUtil decryptAESData:encryptedData key:dataKey];
    
    // Print log
    NSString *encryptedString = [encryptedData base64EncodedStringWithOptions:NSDataBase64EncodingEndLineWithLineFeed];
    NSString *decryptedString = [[NSString alloc] initWithData:decryptData encoding:NSUTF8StringEncoding];
    NSLog(@"AES NSData Test : content = %@, encryptedStr = %@ (%ld Byte), [After Decrypt] Content = %@", content, encryptedString, encryptedString.length, decryptedString);
    // ~ END
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
