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
    NSString *key = @"mvLBiZsiTbGwrfJB";
    NSString *content = @"ABCdefJ10cB3u7LaX+0s";
    NSString *encryptedStr = [AESUtil encryptAES:content key:key];
    NSString *decryptStr = [AESUtil decryptWithAESECB5Padding:encryptedStr key:key];
    NSLog(@"AES Test : content = %@, encryptedStr = %@ (%ld Byte), [After Decrypt] Content = %@", content, encryptedStr, encryptedStr.length, decryptStr);
    // END - 测试AES加密
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
