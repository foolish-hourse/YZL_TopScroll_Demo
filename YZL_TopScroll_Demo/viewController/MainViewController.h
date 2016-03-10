//
//  MainViewController.h
//  YZL_TopScroll_Demo
//
//  Created by YZL on 16/3/3.
//  Copyright © 2016年 YZL. All rights reserved.
//

#import "WMPageController.h"

@interface MainViewController : WMPageController
//内容页的首页应该是单例的，每次进程都只初始化一次
+ (UINavigationController *)standardNavi;
@end
