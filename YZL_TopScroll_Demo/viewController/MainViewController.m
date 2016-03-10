//
//  MainViewController.m
//  YZL_TopScroll_Demo
//
//  Created by YZL on 16/3/3.
//  Copyright © 2016年 YZL. All rights reserved.
//

#import "MainViewController.h"
#import "ContainerViewController.h"

@interface MainViewController ()

@end

@implementation MainViewController
/** 初始化页面 */
+ (UINavigationController *)standardNavi{
    static UINavigationController *navi = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        MainViewController *mainVC = [[MainViewController alloc] initWithViewControllerClasses:[self viewControllerClasses] andTheirTitles:[self itemNames]];
        navi = [[UINavigationController alloc] initWithRootViewController:mainVC];
        mainVC.menuViewStyle = WMMenuViewStyleLine;
        mainVC.menuBGColor = [UIColor yellowColor];
        mainVC.progressColor = [UIColor blueColor];
        mainVC.menuUnderLineRatio = 0.8;
        mainVC.selectIndex = 3;
        mainVC.showOnNavigationBar = YES;
        mainVC.keys = [self vcKeys];
        mainVC.values = [self vcValues];
    });
    return navi;
}

/** 提供题目数组 */
+ (NSArray *)itemNames{
    return @[@"头条",@"体育",@"娱乐",@"热点",@"汽车"];
}

/** 提供每个题目对应的控制器的类型。题目和类型数量必须一致 */
+ (NSArray *)viewControllerClasses{
    NSMutableArray *arr = [NSMutableArray new];
    for (int i = 0; i < [self itemNames].count; i++) {
        [arr addObject:[ContainerViewController class]];
    }
    return [arr copy];
}

/** 提供每个VC对应的values值数组 */
+ (NSMutableArray *)vcValues{
    NSMutableArray *arr = [NSMutableArray new];
    for (int i = 0; i < [self itemNames].count; i++) {
        //数值上，vc的infoType的枚举值 恰好和i值相同
        [arr addObject:@(i)];
    }
    return arr;
}
/** 提供每个VC对应的key值数组 */
+ (NSMutableArray *)vcKeys{
    NSMutableArray *arr = [NSMutableArray new];
    for (int i = 0; i < [self itemNames].count; i++) {
        [arr addObject:@"infoType"];
    }
    return arr;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    //为测showOnNavigationBar是否兼容导航栏按钮而设
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"right" style:UIBarButtonItemStyleDone target:nil action:nil];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"left" style:UIBarButtonItemStyleDone target:nil action:nil];
}

@end
