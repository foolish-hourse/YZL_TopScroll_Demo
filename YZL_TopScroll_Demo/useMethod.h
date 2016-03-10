/**
 * step1:导入WMPageController工具包
 * step2:创建一个视图时继承自WMPageController，作为主视图(如MainViewController，它是用来放滚动菜单栏的)
 * step3:（初始化时建议使用单例，且使用导航栏套在MainViewController上.使用- (instancetype)initWithViewControllerClasses:(NSArray<Class> *)classes andTheirTitles:(NSArray<NSString *> *)titles方法初始化MainViewController,其中classes是类名数组，如可以是@[[ContainerViewController class],[ContainerViewController class],[ContainerViewController class]]，titles是标题数组，如@[@"头条",@"体育",@"娱乐"]，但是标题数组与类数组数量必须相同.
 * step4:在初始化方法中设置主视图控制器对象mainVC的属性keys（这是用来帮控制器视图设置.h文件中的属性的）,如@[@"infoType",@"infoType",@"infoType"]（infoType就是属性名）,设置mainVC.values,这是每个key对应的属性值，如@[@(0),@(1),@(2)]
 * step5:可以在初始化方法下使用mainVC.xxx修改属性值设置样式，属性解释见下表1（如有不全自行查看WMPageController.h文件（以下属性均是可选属性，已有默认值）
 * step6:创建一个控制器视图ContainerViewController，在.h文件中声明一个NSNumber类型的属性infoType用来告诉控制器视图显示的样式
 * step7:在ContainerViewController.m中根据接收过来的infoType显示相应的页面。
 * step8:在要显示这个滚动视图的位置推出MainViewController即可（如直接在appdelegate中）
 *
 //如还有问题可参考原版demo
 
 下表1
 /**
 *  设置选中几号 item
 *  To select item at index
 */
@property (nonatomic, assign) int selectIndex;

/**
 *  点击相邻的 MenuItem 是否触发翻页动画 (当当前选中与点击Item相差大于1是不触发)
 *  Whether to animate when press the MenuItem, if distant between the selected and the pressed is larger than 1,never animate.
 */
@property (nonatomic, assign) BOOL pageAnimatable;

/**
 *  选中时的标题尺寸
 *  The title size when selected (animatable)
 */
@property (nonatomic, assign) CGFloat titleSizeSelected;

/**
 *  非选中时的标题尺寸
 *  The normal title size (animatable)
 */
@property (nonatomic, assign) CGFloat titleSizeNormal;

/**
 *  标题选中时的颜色, 颜色是可动画的.
 *  The title color when selected, the color is animatable.
 */
@property (nonatomic, strong) UIColor *titleColorSelected;

/**
 *  标题非选择时的颜色, 颜色是可动画的.
 *  The title's normal color, the color is animatable.
 */
@property (nonatomic, strong) UIColor *titleColorNormal;

/**
 *  标题的字体名字
 *  The name of title's font
 */
@property (nonatomic, copy) NSString *titleFontName;

/**
 *  导航栏高度
 *  The menu view's height
 */
@property (nonatomic, assign) CGFloat menuHeight;

/**
 *  下划线占总长比例
 *  The menu view's ratio 默认为1.0
 */
@property (nonatomic, assign) CGFloat menuUnderLineRatio;

// 当所有item的宽度加起来小于屏幕宽时，PageController会自动帮助排版，添加每个item之间的间隙以填充整个宽度
// When the sum of all the item's width is smaller than the screen's width, pageController will add gap to each item automatically, in order to fill the width.

/**
 *  每个 MenuItem 的宽度
 *  The item width,when all are same,use this property
 */
@property (nonatomic, assign) CGFloat menuItemWidth;

/**
 *  各个 MenuItem 的宽度，可不等，数组内为 NSNumber.
 *  Each item's width, when they are not all the same, use this property, Put `NSNumber` in this array.
 */
@property (nonatomic, copy) NSArray<NSNumber *> *itemsWidths;

/**
 *  导航栏背景色
 *  The background color of menu view
 */
@property (nonatomic, strong) UIColor *menuBGColor;

/**
 *  Menu view 的样式，默认为无下划线
 *  Menu view's style, now has two different styles, 'Line','default'
 */
@property (nonatomic, assign) WMMenuViewStyle menuViewStyle;

/**
 *  进度条的颜色，默认和选中颜色一致(如果 style 为 Default，则该属性无用)
 *  The progress's color,the default color is same with `titleColorSelected`.If you want to have a different color, set this property.
 */
@property (nonatomic, strong) UIColor *progressColor;
 
 /**
 *  是否作为 NavigationBar 的 titleView 展示，默认 NO
 *  Whether to show on navigation bar, the default value is `NO`
 */
@property (assign, nonatomic) BOOL showOnNavigationBar;

/** 下划线进度条的高度 */
@property (nonatomic, assign) CGFloat progressHeight;

/** WMPageController View' frame */
@property (nonatomic, assign) CGRect viewFrame;

/**
 *  Menu view items' margin / make sure it's count is equal to (controllers' count + 1),default is 0
 顶部菜单栏各个 item 的间隙，因为包括头尾两端，所以确保它的数量等于控制器数量 + 1, 默认间隙为 0
 */
@property (nonatomic, copy) NSArray<NSNumber *> *itemsMargins;

/**
 *  set itemMargin if all margins are the same, default is 0
 如果各个间隙都想同，设置该属性，默认为 0
 */
@property (nonatomic, assign) CGFloat itemMargin;

/** 顶部 menuView 和 scrollView 之间的间隙 */
@property (nonatomic, assign) CGFloat menuViewBottom;
 */
