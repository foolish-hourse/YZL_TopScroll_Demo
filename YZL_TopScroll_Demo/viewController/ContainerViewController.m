//
//  ContainerViewController.m
//  YZL_TopScroll_Demo
//
//  Created by YZL on 16/3/3.
//  Copyright © 2016年 YZL. All rights reserved.
//

#import "ContainerViewController.h"

@interface ContainerViewController ()

@end

@implementation ContainerViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setViewBgColorWithType:self.infoType.integerValue];
}

- (void)setViewBgColorWithType:(NSInteger)type {
    if (type == 0) {
        self.view.backgroundColor = [UIColor redColor];
    }else if (type == 1) {
        self.view.backgroundColor = [UIColor yellowColor];
    }else if (type == 2) {
        self.view.backgroundColor = [UIColor blueColor];
    }else if (type == 3) {
        self.view.backgroundColor = [UIColor greenColor];
    }else if (type == 4) {
        self.view.backgroundColor = [UIColor grayColor];
    }
    
}
@end
