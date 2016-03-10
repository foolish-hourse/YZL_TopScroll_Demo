//
//  ContainerViewController.h
//  YZL_TopScroll_Demo
//
//  Created by YZL on 16/3/3.
//  Copyright © 2016年 YZL. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ContainerViewController : UIViewController
/** 接收外部传参，决定当前控制器显示哪种类型的信息 */
@property(nonatomic,strong) NSNumber *infoType;
@end
